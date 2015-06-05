#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/Link.hpp>
#include <Crawler/Worker.hpp>
#include <string>
#include <list>

namespace Crawler
{
	class WebsiteManager ;

	class CRAWLER_API Website
	{
		public :
			using Iterator = std::list <Crawler::Link>::Iterator ;
			using ConstIterator = std::list <Crawler::Link>::ConstIterator ;
		
			/// \brief Default constructor
			Website ( ) = default ;
		
			/// \brief Constructor
			/// \param websiteManager Assigned website manager
			/// \param authority Authority, for instance the domain name, of the website
			Website ( websiteManager & websiteManager , const std::string & authority ) ;
			
			/// \brief Constructor
			/// \param authority Authority, for instance the domain name, of the website
			Website ( const std::string & authority ) ;
			
			/// \brief Checks if a website manager is assigned
			/// \return True if website manager is assigned
			bool hasWebsiteManager ( ) const ;
			
			/// \brief Returns assigned website manager
			/// \return Reference to website manager
			Crawler::WebsiteManager & getWebsiteManager ( ) ;
			
			/// \brief Returns assigned website manager
			/// \return Reference to website manager
			const Crawler::WebsiteManager & getWebsiteManager ( ) const ;
			
			/// \brief Assigns a website manager
			/// \param Reference to website manager
			void setWebsiteManager ( Crawler::WebsiteManager & websiteManager ) ;
			
			/// \brief Checks if website was visited (all links have been visited)
			/// \return True of website was visited
			bool wasVisited ( ) const ;
			
			/// \brief Changes if website was visited
			/// \param visited Value of visited
			void setVisited ( bool visited ) ;
			
			/// \brief Returns authority
			/// \return Reference to authority
			const std::string & getAuthority ( ) const ;
			
			/// \brief Checks if link exists
			/// \param link Link which is checked
			void existsLink ( const Crawler::Link & link ) ;
			
			/// \brief Adds a link to the website
			/// \param link Link which is added
			void addLink ( const Crawler::Link & link ) ;
			
			/// \brief Removes a link from the website
			/// \param link Link which is removed
			void removeLink ( const Crawler::Link & link ) ;
			
			/// \brief Removes a link from the website
			/// \param iterator Iterator (link) which is removed
			/// \return Last iterator in the list
			Iterator removeLink ( Iterator link ) ;
			
			/// \brief Returns the list of links
			/// \return Reference to the list of links
			const std::list <Crawler::Link> & getLinks ( ) const ;
			
			/// \brief Registers a worker
			/// \param worker Worker which gets registered
			void registerWorker ( Crawler::Worker & worker ) ;
			
			/// \brief Unregisters a worker
			/// \param worker Worker which gets unregistered
			void unregisterWorker ( Crawler::Worker & worker ) ;
			
			/// \brief Returns all assigned workers
			/// \return Vector of all assigned worker
			const std::vector <Crawler::Worker &> & getWorker ( ) const ;
			
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
		
		private :
			Crawler::WebsiteManager * websiteManager = nullptr ;
			bool visited = false ;
			std::string authority ;
			std::list <Crawler::Link> links ;
			std::vector <Worker &> worker ;
			sf::Mutex mutex ;
	} ;
}
