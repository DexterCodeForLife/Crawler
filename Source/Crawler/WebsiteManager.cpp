#include <Crawler/WebsiteManager.hpp>

Crawler::WebsiteManager::WebsiteManager ( Crawler::Application & application ) :
	application ( application )
{
}

Crawler::Application & Crawler::WebsiteManager::getApplication ( )
{
	return this->application ;
}

const Crawler::Application & Crawler::WebsiteManager::getApplication ( ) const
{
	return this->application ;
}
		
Crawler::WebsiteManager::Iterator Crawler::WebsiteManager::begin ( )
{
	return this->websites.begin ( ) ;
}

Crawler::WebsiteManager::ConstIterator Crawler::WebsiteManager::begin ( ) const
{
	return this->websites.begin ( ) ;
}

Crawler::WebsiteManager::ConstIterator Crawler::WebsiteManager::cbegin ( ) const
{
	return this->websites.cbegin ( ) ;
}

Crawler::WebsiteManager::Iterator Crawler::WebsiteManager::end ( )
{
	return this->websites.end ( ) ;
}

Crawler::WebsiteManager::ConstIterator Crawler::WebsiteManager::end ( ) const
{
	return this->websites.end ( ) ;
}

Crawler::WebsiteManager::ConstIterator Crawler::WebsiteManager::cend ( ) const
{
	return this->websites.cend ( ) ;
}

bool Crawler::WebsiteManager::existsWebsite ( const Crawler::Website & website )
{
	for ( auto element : this->websites )
		if ( element == website )
			return true ;

	return false ;
}

void Crawler::WebsiteManager::addWebsite ( const Crawler::Website & website )
{
	if ( ! this->existsWebsite ( website ) )
		this->websites.push_back ( website ) ;
}

void Crawler::WebsiteManager::removeWebsite ( const Crawler::Website & website )
{
	for ( auto iterator = this->websites.begin ( ) ; iterator != this->websites.end ( ) ; ++iterator )
	{
		if ( * iterator == website )
		{
			this->websites.erase ( iterator ) ;
			break ;
		}
	}
}

Crawler::WebsiteManager::Iterator Crawler::WebsiteManager::removeWebsite ( Iterator iterator )
{
	return this->websites.erase ( iterator ) ;
}

const std::list <Crawler::Website> & Crawler::WebsiteManager::getWebsites ( ) const
{
	return this->websites ;
}

void Crawler::WebsiteManager::setWorkerPerWebsite ( std::size_t workerPerWebsite )
{
	this->workerPerWebsite = workerPerWebsite ;
}

std::size_t Crawler::WebsiteManager::getWorkerPerWebsite ( ) const
{
	return this->workerPerWebsite ;
}

void Crawler::WebsiteManager::reportLink ( const std::string & string )
{
}

Crawler::Website * Crawler::WebsiteManager::requestWebsite ( )
{
	return nullptr ;
}
