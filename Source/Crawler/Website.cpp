#include <Crawler/Website.hpp>
#include <Crawler/Worker.hpp>
#include <Crawler/ScopedMutex.hpp>
#include <uriparser/Uri.h>

namespace
{
	std::string getString ( const char * first , const char * last )
	{
		return std::string ( first , last ) ;
	}

	std::string getString ( const UriTextRangeA & text )
	{
		return getString ( text.first , text.afterLast ) ;
	}
}
	
Crawler::Website::Website ( )
{
	this->addLink ( Crawler::Link ( "/" , "" , "" ) ) ;
}
		
Crawler::Website::Website ( const std::string & scheme , const std::string & authority ) :
	Website ( )
{
	this->setScheme ( scheme ) ;
	this->setAuthority ( authority ) ;
}
	
Crawler::Website::Website ( const std::string & website )
{
	UriParserStateA state ;
	UriUriA parsedURI ;
	
	state.uri = & parsedURI ;
	
	if ( uriParseUriA ( & state , website.c_str ( ) ) == URI_SUCCESS )
	{
		this->setScheme ( getString ( parsedURI.scheme ) ) ;
		
		std::string userInfo = getString ( parsedURI.userInfo ) ;
		std::string hostText = getString ( parsedURI.hostText ) ;
		std::string portText = getString ( parsedURI.portText ) ;
		
		std::string authority = ! userInfo.empty ( ) ? userInfo + "@" : "" ;
		authority += hostText + ( ! portText.empty ( ) ? ":" + portText : "" ) ;
		this->setAuthority ( authority ) ;
	}

	uriFreeUriMembersA ( & parsedURI ) ;
}

Crawler::Website::Website ( const Website & website )
{
	this->visited = website.visited ;
	this->scheme = website.scheme ;
	this->authority = website.authority ;
	this->links = website.links ;
}

Crawler::Website::Website ( Website && website )
{
	Crawler::ScopedMutex ( website.mutex ) ;
	std::swap ( this->visited , website.visited ) ;
	std::swap ( this->scheme , website.scheme ) ;
	std::swap ( this->authority , website.authority ) ;
	std::swap ( this->links , website.links ) ;
	std::swap ( this->worker , website.worker ) ;	
}			

Crawler::Website & Crawler::Website::operator = ( const Website & website )
{
	Crawler::ScopedMutex ( this->mutex ) ;
	this->visited = website.visited ;
	this->scheme = website.scheme ;
	this->authority = website.authority ;
	this->links = website.links ;
	this->worker.clear ( ) ;
	
	return * this ;
}

Crawler::Website & Crawler::Website::operator = ( Website && website )
{	
	Crawler::ScopedMutex ( website.mutex ) ;
	Crawler::ScopedMutex ( this->mutex ) ;
	std::swap ( this->visited , website.visited ) ;
	std::swap ( this->scheme , website.scheme ) ;
	std::swap ( this->authority , website.authority ) ;
	std::swap ( this->links , website.links ) ;
	std::swap ( this->worker , website.worker ) ;	
	
	return * this ;
}
	
bool Crawler::Website::wasVisited ( ) const
{
	return this->visited ;
}
			
void Crawler::Website::setVisited ( bool visited )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	this->visited = visited ;
}
			
const std::string & Crawler::Website::getScheme ( ) const
{
	return this->scheme ;
}
			
void Crawler::Website::setScheme ( const std::string & scheme )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
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
	for ( auto & element : this->links )
		if ( element == link )
			return true ;
			
	return false ;
}
			
void Crawler::Website::addLink ( const Crawler::Link & link )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	if ( ! this->existsLink ( link ) )
	{
		this->links.push_back ( link ) ;
		this->visited = false ;
	}
}
			
void Crawler::Website::removeLink ( const Crawler::Link & link )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	for ( auto iterator = this->links.begin ( ) ; iterator != this->links.end ( ) ; ++iterator )
	{
		if ( * iterator == link )
		{
			this->links.erase ( iterator ) ;
			break ;
		}
	}
}
			
Crawler::Website::Iterator Crawler::Website::removeLink ( Iterator link )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	return this->links.erase ( link ) ;
}
			
const std::list <Crawler::Link> & Crawler::Website::getLinks ( ) const
{
	return this->links ;
}
			
void Crawler::Website::registerWorker ( Crawler::Worker & worker )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	for ( auto & element : this->worker )
		if ( element == & worker )
			return ;
			
	this->worker.push_back ( & worker ) ;
}

void Crawler::Website::unregisterWorker ( Crawler::Worker & worker )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	for ( auto iterator = this->worker.begin ( ) ; iterator != this->worker.end ( ) ; ++iterator )
	{
		if ( * iterator == & worker )
		{
			this->worker.erase ( iterator ) ;
			return ;
		}
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

Crawler::Link * Crawler::Website::requestLink ( )
{
	Crawler::ScopedMutex mutex ( this->mutex ) ;
	for ( auto & link : this->links )
	{
		if ( ! link.wasVisited ( ) )
		{
			link.setVisited ( true ) ;
			return & link ;
		}
	}
	
	this->visited = true ;
	
	return nullptr ;
}

bool Crawler::operator == ( const Crawler::Website & left , const Crawler::Website & right )
{
	return left.getScheme ( ) == right.getScheme ( ) &&
		   left.getAuthority ( ) == right.getAuthority ( ) ;
}
bool Crawler::operator != ( const Crawler::Website & left , const Crawler::Website & right )
{
	return ! ( left == right ) ;
}
