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
		}
		
		void onShutdown ( )
		{
			Crawler::Application::onShutdown ( ) ;
		}
		
		void onSpawnWorker ( Crawler::Worker & worker )
		{
			Crawler::Application::onSpawnWorker ( worker ) ;
		}
		
		void onDespawnWorker ( Crawler::Worker & worker )
		{
			Crawler::Application::onDespawnWorker ( worker ) ;
		}
		
		void onUnsupportedProtocol ( Crawler::Worker & worker , Crawler::Website & website )
		{
			Crawler::Application::onUnsupportedProtocol ( worker , website ) ;
		}
		
		bool onRequest ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Request & request )
		{
			return Crawler::Application::onRequest ( worker , website , link , client , request ) ;
		}

		bool onResponse ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Response & response )
		{
			return Crawler::Application::onResponse ( worker , website , link , client , response ) ;
		}
			
		bool onParsing ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , pugi::xml_document & document )
		{
			return Crawler::Application::onParsing ( worker , website , link , document ) ;
		}
		
		bool onReportLink ( const std::string & string )
		{
			return Crawler::Application::onReportLink ( string ) ;
		}
		
		bool onAddWebsite ( Crawler::Website & website )
		{
			return Crawler::Application::onAddWebsite ( website ) ;
		}
		
		bool onAddLink ( Crawler::Website & website , Crawler::Link & link )
		{
			return Crawler::Application::onAddLink ( website , link ) ;
		}
		
		void onVisitedWebsites ( )
		{
			Crawler::Application::onVisitedWebsites ( ) ;
		}
} ;

CRAWLER_APPLICATION ( Application )
