#include <Crawler/Application.hpp>

Crawler::Application::Application ( ) :
	websiteManager ( * this ) ,
	workerManager ( * this )
{
}

void Crawler::Application::setRunning ( bool running )
{
	this->running = running ;
}

bool Crawler::Application::isRunning ( ) const
{
	return this->running ;
}

Crawler::WebsiteManager & Crawler::Application::getWebsiteManager ( )
{
	return this->websiteManager ;
}
const Crawler::WebsiteManager & Crawler::Application::getWebsiteManager ( ) const
{
	return this->websiteManager ;
}
			
Crawler::WorkerManager & Crawler::Application::getWorkerManager ( )
{
	return this->workerManager ;
}
const Crawler::WorkerManager & Crawler::Application::getWorkerManager ( ) const
{
	return this->workerManager ;
}

int Crawler::Application::main ( const std::vector <std::string> & arguments )
{
	this->arguments = arguments ;

	if ( ! this->onStartup ( ) )
		return -1 ;
		
	this->workerManager.spawnWorker ( ) ;
		
	while ( this->isRunning ( ) )
	{
		this->onMain ( ) ;
		
		bool allVisited = true ;
		
		for ( auto & worker : this->getWorkerManager ( ) )
		{
			if ( worker->getWebsite ( ) )
			{
				allVisited = false ;
				break ;
			}
		}
		
		for ( auto & website : this->getWebsiteManager ( ) )
		{
			if ( ! website.wasVisited ( ) )
			{
				allVisited = false ;
				break ;
			}
		}
		
		if ( allVisited )
			this->onVisitedWebsites ( ) ;
	}
	
	this->workerManager.despawnWorker ( ) ;
		
	this->onShutdown ( ) ;
	
	return 0 ;
}

bool Crawler::Application::onStartup ( )
{
	return true ;
}

void Crawler::Application::onMain ( )
{
}

void Crawler::Application::onShutdown ( )
{
}

void Crawler::Application::onSpawnWorker ( Crawler::Worker & worker )
{
}

void Crawler::Application::onDespawnWorker ( Crawler::Worker & worker )
{
}

void Crawler::Application::onUnsupportedProtocol ( Crawler::Worker & worker , Crawler::Website & website )
{
	website.setVisited ( true ) ;
}

bool Crawler::Application::onRequest ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Request & request )
{
	return true ;
}

bool Crawler::Application::onResponse ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Response & response )
{
	return true ;
}

bool Crawler::Application::onParsing ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , pugi::xml_document & document )
{
	return true ;
}

bool Crawler::Application::onReportLink ( const std::string & string )
{
	return true ;
}

bool Crawler::Application::onAddWebsite ( Crawler::Website & website )
{
	return true ;
}
		
bool Crawler::Application::onAddLink ( Crawler::Website & website , Crawler::Link & link )
{
	return true ;
}

void Crawler::Application::onVisitedWebsites ( )
{
	this->setRunning ( false ) ;
}

const std::vector <std::string> & Crawler::Application::getArguments ( ) const
{
	return this->arguments ;
}
