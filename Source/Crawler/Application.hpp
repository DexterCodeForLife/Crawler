#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/WebsiteManager.hpp>
#include <Crawler/WorkerManager.hpp>
#include <vector>
#include <string>

namespace Crawler
{
	class CRAWLER_API Application
	{
		public :
			Application ( ) ;
			virtual ~Application ( ) = default ;
			
			Crawler::WebsiteManager & getWebsiteManager ( ) ;
			const Crawler::WebsiteManager & getWebsiteManager ( ) const ;
			
			Crawler::WorkerManager & getWorkerManager ( ) ;
			const Crawler::WorkerManager & getWorkerManager ( ) const ;
			
			int main ( const std::vector <std::string> & arguments ) ;
			
			virtual bool onStartup ( ) ;
			virtual void onShutdown ( ) ;
			
		protected :
			const std::vector <std::string> & getArguments ( ) const ;
			
		private :
			std::vector <std::string> arguments ;
		
			Crawler::WebsiteManager websiteManager ;
			Crawler::WorkerManager workerManager ;
	} ;
}

#define CRAWLER_APPLICATION(x) int main ( int argc , char ** argv ) \
{ \
	std::vector <std::string> arguments ; \
 \
	for ( int i = 0 ; i < argc ; ++i ) \
		arguments.push_back ( argv [ i ] ) ; \
 \
 	x instance ; \
 	return instance.main ( ) ; \
}
