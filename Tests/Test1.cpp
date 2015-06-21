#include <Crawler.hpp>
#include <iostream>

class Application : public Crawler::Application
{
	public :
		bool onStartup ( )
		{
			return Crawler::Application::onStartup ( ) ;
		}
		
		void onMain ( )
		{
			Crawler::Application::onMain ( ) ;
			
			this->setRunning ( false ) ;
		}
		
		void onShutdown ( )
		{
			Crawler::Application::onShutdown ( ) ;
		}
		
		void onSpawnWorker ( Crawler::Worker & worker )
		{
			Crawler::Application::onSpawnWorker ( worker ) ;
			
			std::cout << & worker << " spawned!\n" ;
		}
		
		void onDespawnWorker ( Crawler::Worker & worker )
		{
			Crawler::Application::onDespawnWorker ( worker ) ;
			
			std::cout << & worker << " despawned!\n" ;
		}
} ;

CRAWLER_APPLICATION ( Application )
