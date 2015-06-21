#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/Website.hpp>
#include <SFML/System.hpp>
#include <list>

namespace Crawler
{
	class Application ;

	class CRAWLER_API WebsiteManager
	{
		public :
			using Iterator = typename std::list <Crawler::Website>::iterator ;
			using ConstIterator = typename std::list <Crawler::Website>::const_iterator ;
		
			/// \brief Constructor
			/// \param application Reference to assigned application
			WebsiteManager ( Crawler::Application & application ) ;
			
			/// \brief Copy constructor
			/// \param websiteManager WebsiteManager which is copied
			WebsiteManager ( const WebsiteManager & websiteManager ) = delete ;
			
			/// \brief Move constructor
			/// \param websiteManager WebsiteManager which is moved
			WebsiteManager ( WebsiteManager && websiteManager ) = delete ;
			
			/// \brief Copy assignment operator
			/// \param websiteManager WebsiteManager which is copied
			/// \return Reference to this
			WebsiteManager & operator = ( const WebsiteManager & workerManager ) = delete ;
			
			/// \brief Move assignment operator
			/// \param websiteManager WebsiteManager which is moved
			/// \return Reference to this
			WebsiteManager & operator = ( WebsiteManager && workerManager ) = delete ;
			
			/// \brief Returns assigned application
			/// \return Reference to assigned application
			Crawler::Application & getApplication ( ) ;
			
			/// \brief Returns assigned application
			/// \return Reference to assigned application
			const Crawler::Application & getApplication ( ) const ;
		
			/// \brief Returns begin iterator
			/// \return Begin iterator
			Iterator begin ( ) ;
			
			/// \brief Returns begin iterator
			/// \return Begin iterator
			ConstIterator begin ( ) const ;
			
			/// \brief Returns begin iterator
			/// \return Begin iterator
			ConstIterator cbegin ( ) const ;
			
			/// \brief Returns end iterator
			/// \return End iterator
			Iterator end ( ) ;
			
			/// \brief Returns end iterator
			/// \return End iterator
			ConstIterator end ( ) const ;
			
			/// \brief Returns end iterator
			/// \return End iterator
			ConstIterator cend ( ) const ;
			
			/// \brief Checks if website exists
			/// \param website Reference to website object
			/// \return True if website exists
			bool existsWebsite ( const Crawler::Website & website ) ;
			
			/// \brief Add website to manager
			/// \param website Reference to website object which is added
			void addWebsite ( const Crawler::Website & website ) ;
			
			/// \brief Remove website from manager
			/// \param website Reference to website object which is removed
			void removeWebsite ( const Crawler::Website & website ) ;
			
			/// \brief Remove website from manager
			/// \param website Iterator to website object which is removed
			/// \return Iterator to iterator - 1
			Iterator removeWebsite ( Iterator iterator ) ;
			
			/// \brief Returns list of websites
			/// \return Reference to list of websites
			const std::list <Crawler::Website> & getWebsites ( ) const ;
			
			/// \brief Changes the amount of workers per website
			/// \param workerPerWebsite Amount of workers per website
			void setWorkerPerWebsite ( std::size_t workerPerWebsite ) ;
			
			/// \brief Returns the amount of workers per website
			/// \return Amount of workers per website
			std::size_t getWorkerPerWebsite ( ) const ;

			/// \brief Report a link to website manager
			/// \param link Link which is reported
			void reportLink ( const std::string & string ) ;
			
			/// \brief Requests a new website from the list which is handled by the worker
			/// \param worker Worker which is registered
			/// \return Pointer to website which is handled by the worker
			Crawler::Website * requestWebsite ( Crawler::Worker * worker ) ;
		
		private :
			Crawler::Application & application ;
			std::list <Crawler::Website> websites ;
			std::size_t workerPerWebsite = 0 ;
			sf::Mutex mutex ;
	} ;
}
