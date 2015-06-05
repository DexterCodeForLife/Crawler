#include <Crawler/Website.hpp>

Crawler::Website::Website ( Crawler::WebsiteManager & websiteManager , const std::string & scheme , const std::string & authority ) :
	Website ( scheme , authority )
{
	this->setWebsiteManager ( websiteManager ) ;
}
			
Crawler::Website::Website ( const std::string & scheme , const std::string & authority )
{
	this->setScheme ( scheme ) ;
	this->setAuthority ( authority ) ;
}
			
bool Crawler::Website::hasWebsiteManager ( ) const
{
	return this->websiteManager ;
}
			
Crawler::WebsiteManager & Crawler::Website::getWebsiteManager ( )
{
	return * this->websiteManager ;
}
			
const Crawler::WebsiteManager & Crawler::Website::getWebsiteManager ( ) const
{
	return * this->websiteManager ;
}
			
void Crawler::Website::setWebsiteManager ( Crawler::WebsiteManager & websiteManager )
{
	this->websiteManager = & websiteManager ;
}
			
void Crawler::Website::setWebsiteManager ( Crawler::WebsiteManager * websiteManager )
{
	this->websiteManager = websiteManager ;
}
			
bool Crawler::Website::wasVisited ( ) const
{
	return this->visited ;
}
			
void Crawler::Website::setVisited ( bool visited )
{
	this->visited ;
}
			
const std::string & Crawler::Website::getScheme ( ) const
{
	return this->scheme ;
}
			
void Crawler::Website::setScheme ( const std::string & scheme )
{
	this->scheme = scheme ;
}
			
const std::string & Crawler::Website::getAuthority ( ) const
{
	return this->authority ;
}
			
void Crawler::Website::setAuthority ( const std::string & authority )
{
	this->authority = authority ;
}
			
bool Crawler::Website::existsLink ( const Crawler::Link & link )
{
	for ( auto element : this->links )
		if ( element == link )
			return true ;
			
	return false ;
}
			
void Crawler::Website::addLink ( const Crawler::Link & link )
{
	if ( ! this->existsLink ( link ) )
		this->links.push_back ( link ) ;
}
			
void Crawler::Website::removeLink ( const Crawler::Link & link )
{
	for ( auto iterator = this->links.begin ( ) ; iterator != this->links.end ( ) ; ++iterator )
		if ( * iterator == link )
			this->links.erase ( iterator ) ;
}
			
Crawler::Website::Iterator Crawler::Website::removeLink ( Iterator link )
{
	return this->links.erase ( link ) ;
}
			
const std::list <Crawler::Link> & Crawler::Website::getLinks ( ) const
{
	return this->links ;
}
			
void Crawler::Website::registerWorker ( Crawler::Worker & worker )
{
	/*for ( auto element : this->worker )
		if ( * element == & worker )
			return ;*/
			
	this->worker.push_back ( & worker ) ;
}

void Crawler::Website::unregisterWorker ( Crawler::Worker & worker )
{
	for ( auto iterator = this->worker.begin ( ) ; iterator != this->worker.end ( ) ; ++iterator )
		if ( * iterator == & worker )
		{
			this->worker.erase ( iterator ) ;
			return ;
		}
}
			
const std::list <Crawler::Worker *> & Crawler::Website::getWorker ( ) const
{
	return this->worker ;
}
			
Crawler::Website::Iterator Crawler::Website::begin ( )
{
	return this->links.begin ( ) ;
}
			
Crawler::Website::ConstIterator Crawler::Website::begin ( ) const
{
	return this->links.begin ( ) ;
}
			
Crawler::Website::ConstIterator Crawler::Website::cbegin ( ) const
{
	return this->links.cbegin ( ) ;
}
			
Crawler::Website::Iterator Crawler::Website::end ( )
{
	return this->links.end ( ) ;
}
			
Crawler::Website::ConstIterator Crawler::Website::end ( ) const
{
	return this->links.end ( ) ;
}
			
Crawler::Website::ConstIterator Crawler::Website::cend ( ) const
{
	return this->links.cend ( ) ;
}
