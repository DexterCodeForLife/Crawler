#pragma once

#include <Crawler/Linker.hpp>
#include <string>
#include <list>

namespace Crawler
{
	class Website ;

	class CRAWLER_API Link
	{
		public :
			Link ( ) = default ;
		
		private :
			Crawler::Website * website = nullptr ;
		
			std::string scheme ;
			std::string authority ;
			std::string path ;
			std::string query ;
			std::string fragment ;
		
			bool visitied = false ;
	} ;
}
