#include <Crawler/Worker.hpp>
#include <Crawler/Website.hpp>
#include <Crawler/WorkerManager.hpp>
#include <Crawler/Application.hpp>
#include <Crawler/ScopedMutex.hpp>
#include <pugixml.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

Crawler::Worker::Worker ( Crawler::WorkerManager & workerManager ) :
	workerManager ( workerManager ) ,
	thread ( std::unique_ptr <sf::Thread> ( new sf::Thread ( & Crawler::Worker::main , this ) ) )
{
}

Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( )
{
	return this->workerManager ;
}

const Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( ) const
{
	return this->workerManager ;
}

Crawler::Website * Crawler::Worker::getWebsite ( )
{
	return this->website;
}
	
const Crawler::Website * Crawler::Worker::getWebsite ( ) const
{	
	return this->website ;
}

bool Crawler::Worker::isRunning ( ) const
{
	return this->running ;
}

void Crawler::Worker::setRunning ( bool running )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	this->running = running ;
}

void Crawler::Worker::launch ( )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	this->thread->launch ( ) ;
}

void Crawler::Worker::terminate ( )
{
	this->setRunning ( false ) ;
	this->wait ( ) ;
}

void Crawler::Worker::wait ( )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	this->thread->wait ( ) ;
}

void Crawler::Worker::kill ( )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	this->thread->terminate ( ) ;
}

void Crawler::Worker::main ( )
{
	while ( this->isRunning ( ) )
	{
		Crawler::Website * website = this->workerManager.getApplication ( ).getWebsiteManager ( ).requestWebsite ( this ) ;
		
		if ( website )
		{
			this->website = website ;
		
			if ( website->getScheme ( ) == "http" )
			{
				sf::Http client ( website->getScheme ( ) + "://" + website->getAuthority ( ) ) ;
				
				Crawler::Link * link = nullptr ;
				
				while ( ( link = website->requestLink ( ) ) && ! website->wasVisited ( ) && this->isRunning ( ) )
				{
					sf::Http::Request request ;
					
					request.setUri ( link->toString ( ) ) ;
					
					if ( ! this->getWorkerManager ( ).getApplication ( ).onRequest ( * this , * website , * link , client , request ) )
						continue ;
					
					sf::Http::Response response = client.sendRequest ( request ) ;
					
					if ( ! this->getWorkerManager ( ).getApplication ( ).onResponse ( * this , * website , * link , client , response ) )
						continue ;
					
					pugi::xml_document document ;
					document.load_string ( response.getBody ( ).c_str ( ) , pugi::parse_full ) ;
					
					if ( ! this->getWorkerManager ( ).getApplication ( ).onParsing ( * this , * website , * link , document ) )
						continue ;
				
					pugi::xpath_node_set nodes = document.select_nodes ( "//a[@href]" ) ;
					
					for( pugi::xpath_node_set::const_iterator iterator = nodes.begin ( ) ; iterator != nodes.end ( ) ; ++iterator )
					{
						std::string string = iterator->node ( ).attribute ( "href" ).value ( ) ;
						
						Crawler::Website newWebsite ( string ) ;
						Crawler::Link newLink ( string ) ;
						
						if ( newWebsite.getScheme ( ).empty ( ) )
							newWebsite.setScheme ( website->getScheme ( ) ) ;
						
						if ( newWebsite.getAuthority ( ).empty ( ) )
							newWebsite.setAuthority ( website->getAuthority ( ) ) ;
		
						this->getWorkerManager ( ).getApplication ( ).getWebsiteManager ( ).reportLink ( newWebsite.getScheme ( ) + "://" + newWebsite.getAuthority ( ) + newLink.toString ( ) ) ;
					}
				}
			}
			else
				this->getWorkerManager ( ).getApplication ( ).onUnsupportedProtocol ( * this , * website ) ;
		
			this->website = nullptr ;
			
			website->unregisterWorker ( * this ) ;
		}
		else
		{
			bool allVisited = true ;
		
			for ( auto & worker : this->getWorkerManager ( ) )
			{
				if ( worker->getWebsite ( ) )
				{
					allVisited = false ;
					break ;
				}
			}
		
			for ( auto & website : this->getWorkerManager ( ).getApplication ( ).getWebsiteManager ( ) )
			{
				if ( ! website.wasVisited ( ) )
				{
					allVisited = false ;
					break ;
				}
			}
		
			
			if ( allVisited )
			{
				Crawler::ScopedMutex mutex ( Crawler::Worker::onVisitedWebsitesMutex ) ;
				
				if ( ! Crawler::Worker::onVisitedWebsitesCalled )
				{
					Crawler::Worker::onVisitedWebsitesCalled = true ;
					this->getWorkerManager ( ).getApplication ( ).onVisitedWebsites ( ) ;
				}
			}
		}
	}
}

sf::Mutex Crawler::Worker::onVisitedWebsitesMutex ;
bool Crawler::Worker::onVisitedWebsitesCalled = false ;
