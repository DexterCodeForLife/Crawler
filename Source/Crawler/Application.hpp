#pragma once

#include <Crawler/Linker.hpp>

namespace Crawler
{
	class CRAWLER_API Application
	{
		public :
			virtual ~Application ( ) ;
			
			void main ( ) ;
			
		protected :
			Application ( ) = default ;
				
			virtual bool onLinkAdd ( Crawler::Link & link ) ;
			
			/// \brief Method which gets called when a worker wants to add
			virtual bool onWebsiteAdd ( Crawler::Website & website ) ;
		
		private :
	} ;
}
