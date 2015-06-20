#pragma once

#include <Crawler/Linker.hpp>

namespace sf
{
	class Mutex ;
}

namespace Crawler
{
	class CRAWLER_API ScopedMutex
	{
		public :
			ScopedMutex ( sf::Mutex & mutex ) ;
			~ScopedMutex ( ) ;
			
		private :
			sf::Mutex & mutex ;
	} ;
}
