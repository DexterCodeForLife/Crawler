#pragma once

#include <Crawler/Linker.hpp>
#include <list>

namespace Crawler
{
	class CRAWLER_API Website
	{
		public :
		
		private :
			std::list <Crawler::Link> links ;
			
			std::size_t workers = 0 ;
	} ;
}
