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
			/// Default constructor
			/// \param mutex Reference to mutex which is used
			ScopedMutex ( sf::Mutex & mutex ) ;
			
			/// Default destructor
			~ScopedMutex ( ) ;
			
			/// \brief Copy constructor
			/// \param mutex ScopedMutex which is copied
			ScopedMutex ( const ScopedMutex & mutex ) = delete ;
			
			/// \brief Move constructor
			/// \param mutex ScopedMutex which is moved
			ScopedMutex ( ScopedMutex && mutex ) = delete ;
			
			/// \brief Copy assignment operator
			/// \param mutex ScopedMutex which is copied
			/// \return Reference to this
			ScopedMutex & operator = ( const ScopedMutex & mutex ) = delete ;
			
			/// \brief Move assignment operator
			/// \param mutex ScopedMutex which is moved
			/// \return Reference to this
			ScopedMutex & operator = ( ScopedMutex && mutex ) = delete ;
			
		private :
			sf::Mutex & mutex ;
	} ;
}
