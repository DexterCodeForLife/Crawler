#pragma once

#include <Crawler/Linker.hpp>
#include <SFML/System.hpp>
#include <string>

namespace Crawler
{
	class Website ;

	/// \brief Utility class which represents a link
	class CRAWLER_API Link
	{
		public :
			/// \brief Default constructor
			Link ( ) = default ;
		
			/// \brief Constructor for setting each member
			/// \param website Reference to a website the link belongs to
			/// \param scheme Scheme or protocol ("http"; "ftp")
			/// \param authority Provider or server ("localhost:80"; "127.0.0.1"; "username@host.de:5000")
			/// \param path Path ("/directory/file.extension"; "/index.html")
			/// \param query Query ("?Key1=Value1&Key2=Value2")
			/// \param fragment Fragment ("#Fragment")
			Link ( Crawler::Website & website , const std::string & scheme , const std::string & authority , const std::string & path , const std::string & query , const std::string & fragment ) ;
		
			/// \brief Constructor for setting each member but the assigned website
			/// \param scheme Scheme or protocol ("http"; "ftp")
			/// \param authority Provider or server ("localhost:80"; "127.0.0.1"; "username@host.de:5000")
			/// \param path Path ("/directory/file.extension"; "/index.html")
			/// \param query Query ("?Key1=Value1&Key2=Value2")
			/// \param fragment Fragment ("#Fragment")
			Link ( const std::string & scheme , const std::string & authority , const std::string & path , const std::string & query , const std::string & fragment ) ;
		
			/// \brief Constructor for parsing a link
			/// \param link String which gets parsed
			Link ( const std::string & link ) ;
		
			/// \brief Method to check if a website is assigned to link
			/// \return True if a website is assigned
			bool hasWebsite ( ) const ;
			
			/// \brief Returnsassigned website
			/// \return Reference to assigned website
			Crawler::Website & getWebsite ( ) ;
			
			/// \brief Returns assigned website
			/// \return Reference to the assigned website
			const Crawler::Website & getWebsite ( ) const ;
			
			/// \brief Changes the assigned website
			/// \param website Website which is assigned to the link
			void setWebsite ( Crawler::Website & website ) ;
			
			/// \brief Checks if link was visited
			/// \return True if link was visited
			bool wasVisited ( ) const ;
			
			/// \brief Changes if link was visitied
			/// \param visited Value which defines if link was visited
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
			
			/// \brief Returns path
			/// \return Reference to path
			const std::string & getPath ( ) const ;
			
			/// \brief Changes path
			/// \param scheme New path
			void setPath ( const std::string & path ) ;
			
			/// \brief Returns query
			/// \return Reference to query
			const std::string & getQuery ( ) const ;
			
			/// \brief Changes query
			/// \param scheme New query
			void setQuery ( const std::string & query ) ;
			
			/// \brief Returns fragment
			/// \return Reference to fragment
			const std::string & getFragment ( ) const ;
			
			/// \brief Changes fragment
			/// \param scheme New fragment
			void setFragment ( const std::string & fragment ) ;
			
			/// \brief Returns the link as a string
			/// \param Link in string format
			std::string toString ( ) const ;
			
			/// \brief Requests the content from the link using a HTTP Socket
			/// \exception std::exception Is thrown when the protocol is unsupported
			/// \return Content of specific link
			std::string requestContent ( ) const ;
			
		private :
			Crawler::Website * website = nullptr ;
			bool visited = false ;
			std::string scheme ;
			std::string authority ;
			std::string path ;
			std::string query ;
			std::string fragment ;
			sf::Mutex mutex ;
	} ;
	
	/// \brief Compares two links together
	/// \param left First link
	/// \param right Second link
	/// \return True if they are equal
	bool operator == ( const Crawler::Link & left , const Crawler::Link & right ) ;
	
	/// \brief Compares two links together
	/// \param left First link
	/// \param right Second link
	/// \return False if they are equal
	bool operator != ( const Crawler::Link & left , const Crawler::Link & right ) ;
}
