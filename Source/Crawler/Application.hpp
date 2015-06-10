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
			/// \brief Default constructor
			Application ( ) ;
			
			/// \brief Default destructor
			virtual ~Application ( ) = default ;
			
			/// \brief Copy constructor
			Application ( const Application & application ) = delete ;
			
			/// \brief Move constructor
			Application ( Application && application ) = delete ;
			
			/// \brief Copy assignment operator
			Application & operator = ( const Application & application ) = delete ;
			
			/// \brief Move assignment operator
			Application & operator = ( Application && application ) = delete ;
			
			/// \brief Changes if application is running
			/// \param running Value of running
			void setRunning ( bool running ) ;
			
			/// \brief Returns if application is running
			/// \return True if application is running
			bool isRunning ( ) const ;
			
			/// \brief Returns website manager
			/// \return Reference to website manager			
			Crawler::WebsiteManager & getWebsiteManager ( ) ;
			
			/// \brief Returns website manager
			/// \return Reference to website manager
			const Crawler::WebsiteManager & getWebsiteManager ( ) const ;
			
			/// \brief Returns worker manager
			/// \return Reference to worker manager
			Crawler::WorkerManager & getWorkerManager ( ) ;
			
			/// \brief Returns worker manager
			/// \return Reference to worker manager
			const Crawler::WorkerManager & getWorkerManager ( ) const ;
			
			/// \brief Applications entry point
			/// \param arguments Command line arguments
			/// \return Error code for operating system
			int main ( const std::vector <std::string> & arguments ) ;
			
			/// \brief Gets called when application starts up
			/// \return True if startup was successfull
			virtual bool onStartup ( ) ;
			
			/// \brief Gets called inside the main function
			virtual void onMain ( ) ;
			
			/// \brief Gets called when application shuts down
			virtual void onShutdown ( ) ;
			
		protected :
			/// \brief Returns command line arguments
			/// \return Reference to a vector with command line arguments
			const std::vector <std::string> & getArguments ( ) const ;
			
		private :
			bool running = true ;
			std::vector <std::string> arguments ;
			Crawler::WebsiteManager websiteManager ;
			Crawler::WorkerManager workerManager ;
	} ;
}

#define CRAWLER_APPLICATION(x) int main ( int argc , char ** argv ) \
{ \
	std::vector <std::string> arguments ; \
	arguments.reserve ( argc ) ; \
 \
	for ( int i = 0 ; i < argc ; ++i ) \
		arguments.push_back ( argv [ i ] ) ; \
 \
 	x instance ; \
 	return instance.main ( arguments ) ; \
}
