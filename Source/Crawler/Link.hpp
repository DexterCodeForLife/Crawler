#pragma once

#include <Crawler/Linker.hpp>
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
		
			/// \brief Constructor for setting each member but the assigned website
			/// \param path Path ("/directory/file.extension"; "/index.html")
			/// \param query Query ("?Key1=Value1&Key2=Value2")
			/// \param fragment Fragment ("#Fragment")
			Link ( const std::string & path , const std::string & query , const std::string & fragment ) ;
		
			/// \brief Constructor for parsing a link
			/// \param link String which gets parsed
			Link ( const std::string & link ) ;
			
			/// \brief Checks if link was visited
			/// \return True if link was visited
			bool wasVisited ( ) const ;
			
			/// \brief Changes if link was visitied
			/// \param visited Value which defines if link was visited
			void setVisited ( bool visited ) ;
			
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
			/// \param fragment New fragment
			void setFragment ( const std::string & fragment ) ;
			
			/// \brief Returns the link as a string
			/// \param Link in string format
			std::string toString ( ) const ;
			
		private :
			bool visited = false ;
			std::string path ;
			std::string query ;
			std::string fragment ;
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
