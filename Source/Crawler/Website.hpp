#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/Link.hpp>
#include <SFML/System/Mutex.hpp>
#include <string>
#include <list>

namespace Crawler
{
	class WebsiteManager ;
	class Worker ;

	class CRAWLER_API Website
	{
		public :
			using Iterator = std::list <Crawler::Link>::iterator ;
			using ConstIterator = std::list <Crawler::Link>::const_iterator ;
		
			/// \brief Default constructor which adds the root as default entry
			Website ( ) ;
		
			/// \brief Constructor
			/// \param scheme Scheme or protocol ("http"; "ftp")
			/// \param authority Provider or server ("localhost:80"; "127.0.0.1"; "username@host.de:5000")
			Website ( const std::string & scheme , const std::string & authority ) ;
			
			/// \brief Constructor for parsing a website
			/// \param website String which gets parsed
			Website ( const std::string & website ) ;			
			
			/// \brief Checks if website was visited (all links have been visited)
			/// \return True of website was visited
			bool wasVisited ( ) const ;
			
			/// \brief Changes if website was visited
			/// \param visited Value of visited
			void setVisited ( bool visited ) ;
			
			/// \brief Returns scheme
			/// \return Reference to scheme
			const std::string & getScheme ( ) const ;
			
			/// \brief Changes scheme
			/// \param scheme New scheme
			void setScheme ( const std::string & scheme ) ;
			
			/// \brief Returns authority
			/// \return Reference to authority
			const std::string & getAuthority ( ) const ;
			
			/// \brief Changes authority
			/// \param scheme New authority
			void setAuthority ( const std::string & authority ) ;
			
			/// \brief Checks if link exists
			/// \param link Link which is checked
			/// \return True if link exists
			bool existsLink ( const Crawler::Link & link ) ;
			
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
			const std::list <Crawler::Worker *> & getWorker ( ) const ;
			
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
			
			/// \brief Requests link from website
			///        The function marks the website automatically as visited if all links has been visited
			/// \return Next link of website which has not been visited or nullptr
			Crawler::Link * requestLink ( ) ;
		
		private :
			bool visited = false ;
			std::string scheme ;
			std::string authority ;
			std::list <Crawler::Link> links ;
			std::list <Worker *> worker ;
	} ;
	
	/// \brief Compares two websites together
	/// \param left First website
	/// \param right Second website
	/// \return True if they are equal
	CRAWLER_API bool operator == ( const Crawler::Website & left , const Crawler::Website & right ) ;
	
	/// \brief Compares two websites together
	/// \param left First website
	/// \param right Second website
	/// \return False if they are equal
	CRAWLER_API bool operator != ( const Crawler::Website & left , const Crawler::Website & right ) ;
}
