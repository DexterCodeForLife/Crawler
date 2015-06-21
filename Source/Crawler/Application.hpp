#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/WebsiteManager.hpp>
#include <Crawler/WorkerManager.hpp>
#include <SFML/Network.hpp>
#include <pugixml.hpp>
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
			/// \param application Application which gets copied
			Application ( const Application & application ) = delete ;
			
			/// \brief Move constructor
			/// \param application Application which gets moved
			Application ( Application && application ) = delete ;
			
			/// \brief Copy assignment operator
			/// \param application Application which gets copied
			/// \return Reference to this
			Application & operator = ( const Application & application ) = delete ;
			
			/// \brief Move assignment operator
			/// \param application Application which gets moved
			/// \return Reference to this
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
			
			/// \brief Gets called when a worker spawns	
			/// \param worker Worker which is spawned
			virtual void onSpawnWorker ( Crawler::Worker & worker ) ;
			
			/// \brief Gets called when a worker despawns
			/// \param worker Worker which is despawned
			virtual void onDespawnWorker ( Crawler::Worker & worker ) ;
			
			/// \brief Gets called when an unsupported protocol is accessed
			/// \param worker Worker which accesses the unsupported protocol
			/// \param website Website with the unsupported protocol
			virtual void onUnsupportedProtocol ( Crawler::Worker & worker , Crawler::Website & website ) ;
		
			/// \brief Gets called when a HTTP request is sent
			/// \param worker Worker which parses the document
			/// \param website Website the document refers to
			/// \param link Link the document refers to
			/// \param client HTTP client which sends the request
			/// \param request Request which is sent by the client
			/// \return True if worker will send the request and receive the response
			virtual bool onRequest ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Request & request ) ;
			
			/// \brief Gets called when a HTTP response is received
			/// \param worker Worker which received the response
			/// \param website Website the document refers to
			/// \param link Link the document refers to
			/// \param client HTTP client which received the response
			/// \param response Response which was received by the client
			/// \return True if worker will parse the body of the response
			virtual bool onResponse ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , sf::Http & client , sf::Http::Response & response ) ;

			/// \brief Gets called when the document is parsed
			/// \param worker Worker which parses the document
			/// \param website Website the document refers to
			/// \param link Link the document refers to
			/// \param document XML document of the link
			/// \return True if worker will report all links
			virtual bool onParsing ( Crawler::Worker & worker , Crawler::Website & website , Crawler::Link & link , pugi::xml_document & document ) ;
			
			/// \brief Gets called when a Link is reported
			/// \param string Link which is reported
			/// \return True if reportLink continues the handling of the link
			virtual bool onReportLink ( const std::string & string ) ;

			/// \brief Gets called when a new website is added
			/// \param website Website which is added to website manager
			/// \return True if website will be added to website manager
			virtual bool onAddWebsite ( Crawler::Website & website ) ;
		
			/// \brief Gets called when a new link to a website is added
			/// \param website Website which link refers to
			/// \param link Link which is added to website
			/// \return True if link will be added to website
			virtual bool onAddLink ( Crawler::Website & website , Crawler::Link & link ) ;
			
			/// \brief Gets called when all websites has been visited
			virtual void onVisitedWebsites ( ) ;
			
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
