#include <Crawler/Link.hpp>
#include <Crawler/Website.hpp>
#include <SFML/Network.hpp>
#include <exception>

Crawler::Link::Link ( Crawler::Website & website , const std::string & scheme , const std::string & authority , const std::string & path , const std::string & query , const std::string & fragment ) :
	Link ( scheme , authority , path , query , fragment )
{
	this->setWebsite ( website ) ;
}

Crawler::Link::Link ( const std::string & scheme , const std::string & authority , const std::string & path , const std::string & query , const std::string & fragment )
{
	this->setScheme ( scheme ) ;
	this->setAuthority ( authority ) ;
	this->setPath ( path ) ;
	this->setQuery ( query ) ;
	this->setFragment ( fragment ) ;
}

Crawler::Link::Link ( const std::string & link )
{
}

bool Crawler::Link::hasWebsite ( ) const
{
	return this->website == nullptr ;
}

Crawler::Website & Crawler::Link::getWebsite ( )
{
	return this->website ;
}

const Crawler::Website & Crawler::Link::getWebsite ( ) const
{
	return this->website ;
}

void Crawler::Link::setWebsite ( Crawler::Website & website )
{
	this->mutex.lock ( ) ;
	this->website = & website ;
	this->mutex.unlock ( ) ;
}

bool Crawler::Link::wasVisited ( ) const
{
	return this->visited ;
}

void Crawler::Link::setVisited ( bool visited )
{
	this->mutex.lock ( ) ;
	this->visited = visited ;
	this->mutex.unlock ( ) ;
}

const std::string & Crawler::Link::getScheme ( ) const
{
	return this->scheme ;
}

void Crawler::Link::setScheme ( const std::string & scheme )
{
	this->mutex.lock ( ) ;
	this->scheme = scheme ;
	this->mutex.unlock ( ) ;
}

const std::string & Crawler::Link::getAuthority ( ) const
{
	return this->authority ;
}

void Crawler::Link::setAuthority ( const std::string & authority )
{
	this->mutex.lock ( ) ;
	this->authority = authority ;
	this->mutex.unlock ( ) ;
}

const std::string & Crawler::Link::getPath ( ) const
{
	return this->path ;
}

void Crawler::Link::setPath ( const std::string & path )
{
	this->mutex.lock ( ) ;
	this->path = path ;
	this->mutex.unlock ( ) ;
}

const std::string & Crawler::Link::getQuery ( ) const
{
	return this->query ;
}

void Crawler::Link::setQuery ( const std::string & query )
{
	this->mutex.lock ( ) ;
	this->query = query ;
	this->mutex.unlock ( ) ;
}

const std::string & Crawler::Link::getFragment ( ) const
{
	return this->fragment ;
}

void Crawler::Link::setFragment ( const std::string & fragment )
{
	this->mutex.lock ( ) ;
	this->fragment = fragment ;
	this->mutex.unlock ( ) ;
}

std::string Crawler::Link::toString ( ) const
{
	return "" ;
}

std::string Crawler::Link::requestContent ( ) const
{
	if ( this->scheme == "http" )
	{
		
	}
	
	throw std::exception ( "PROTOCOL NOT IMPLEMENTED (" + this->fragment + ")!" ) ;
	
	// workaround for vs
	return "" ;
}

bool Crawler::operator == ( const Crawler::Link & left , const Crawler::Link & right )
{
	return left.getScheme ( ) == right.getScheme ( ) &&
		   left.getAuthority ( ) == right.getAuthority ( ) &&
		   left.getPath ( ) == right.getPath ( ) &&
		   left.getQuery ( ) == right.getQuery ( ) &&
		   left.getFragment ( ) == right.getFragment ( ) ;
}
bool Crawler::operator != ( const Crawler::Link & left , const Crawler::Link & right )
{
	return ! left == right ;
}
