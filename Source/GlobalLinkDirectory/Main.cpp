#include <Crawler.hpp>
#include <iostream>

class Application : public Crawler::Application
{
	public :
		bool onStartup ( )
		{
			// Check if URI was given
			if ( this->getArguments ( ).size ( ) < 2 )
			{
				std::cout << "Usage: " << this->getArguments ( ) [ 0 ] << " <URI> <THREADS>\n" ;
				return false ;
			}
			
			// Check if URI is correct
			this->website = Crawler::Website ( this->getArguments ( ) [ 1 ] ) ;
			if ( this->website.getScheme ( ).empty ( ) || this->website.getAuthority ( ).empty ( ) )
			{
				std::cout << "URI not correct!\n" ;
				return false ;
			}
			
			// Check if amount of threads is given and set the amount of worker
			// based on the command line argument
			if ( this->getArguments ( ).size ( ) > 2 )
				this->getWorkerManager ( ).setAmountOfWorker ( std::atoi ( this->getArguments ( ) [ 2 ].c_str ( ) ) ) ;
			
			// Report the link to the website manager
			this->getWebsiteManager ( ).reportLink ( this->getArguments ( ) [ 1 ] ) ;
		
			return true ;
		}
		
		bool onResponse ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Response & response )
		{
			// Print all responses
			std::cout << & worker << std::dec << " " << static_cast <std::size_t> ( response.getStatus ( ) ) 
				<< " " << website.getScheme ( ) + "://" + website.getAuthority ( )
				<< link.toString ( ) << " " << response.getBody ( ).size ( ) << " Bytes\n" ;
			return true ;
		}
		
		bool onAddWebsite ( Crawler::Website & website )
		{
			// Do not visit any other sites, beside our seed site
			if ( website != this->website )
				website.setVisited ( true ) ;
		
			return true ;
		}
		
		bool onAddLink ( Crawler::Website & website , Crawler::Link & link )
		{
			// Do not visit any links, beside our seed site
			if ( website != this->website )
				link.setVisited ( true ) ;
		
			return true ;
		}
		
		void onVisitedWebsites ( )
		{
			// Print recursively all websites and their links
			for ( auto & website : this->getWebsiteManager ( ) )
			{
				for ( auto & link : website )
					std::cout << website.getScheme ( ) << "://" << website.getAuthority ( ) << link.toString ( ) << "\n" ;
			}
			
			// Shutdown the crawler	
			Crawler::Application::onVisitedWebsites ( ) ;
		}
	
	private :
		Crawler::Website website ;
} ;

CRAWLER_APPLICATION ( Application )
