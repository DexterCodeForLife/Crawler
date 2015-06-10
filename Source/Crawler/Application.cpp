#include <Crawler/Application.hpp>

Crawler::Application::Application ( ) :
	websiteManager ( * this ) ,
	workerManager ( * this )
{
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
		
	this->onShutdown ( ) ;
	
	return 0 ;
}

bool Crawler::Application::onStartup ( )
{
	return true ;
}
void Crawler::Application::onShutdown ( )
{
}

const std::vector <std::string> & Crawler::Application::getArguments ( ) const
{
	return this->arguments ;
}
