#include <Crawler/Link.hpp>
#include <Crawler/Website.hpp>
#include <uriparser/Uri.h>
#include <exception>

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
	UriParserStateA state ;
	UriUriA parsedURI ;
	
	state.uri = & parsedURI ;
	
	if ( uriParseUriA ( & state , link.c_str ( ) ) == URI_SUCCESS )
	{
		this->setScheme ( getString ( parsedURI.scheme ) ) ;
		
		std::string userInfo = getString ( parsedURI.userInfo ) ;
		std::string hostText = getString ( parsedURI.hostText ) ;
		std::string portText = getString ( parsedURI.portText ) ;
		
		std::string authority = ! userInfo.empty ( ) ? userInfo + "@" : "" ;
		authority += hostText + ( ! portText.empty ( ) ? ":" + portText : "" ) ;
		this->setAuthority ( authority ) ;
				
		std::string path ;
		UriPathSegmentA * iterator = parsedURI.pathHead ;
		while ( iterator != nullptr )
		{
			path += "/" + getString ( iterator->text ) ;
			iterator = iterator->next ;
		}
		this->setPath ( path ) ;
				
		this->setQuery ( getString ( parsedURI.query ) ) ;
		this->setFragment ( getString ( parsedURI.fragment ) ) ;
	}

	uriFreeUriMembersA ( & parsedURI ) ;
}

bool Crawler::Link::hasWebsite ( ) const
{
	return this->website == nullptr ;
}

Crawler::Website & Crawler::Link::getWebsite ( )
{
	return * this->website ;
}

const Crawler::Website & Crawler::Link::getWebsite ( ) const
{
	return * this->website ;
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
	std::string string = ! this->getScheme ( ).empty ( ) ? this->getScheme ( ) + "://" : "" ;
	string += this->getAuthority ( ) + this->getPath ( ) ;
	string += ! this->getQuery ( ).empty ( ) ? "?" + this->getQuery ( ) : "" ;
	string += ! this->getFragment ( ).empty ( ) ? "#" + this->getFragment ( ) : "" ;

	return string ;
}

sf::Http::Response Crawler::Link::sendRequest ( sf::Http::Request & request ) const
{
	request.setUri ( this->getPath ( ) + "?" + this->getQuery ( ) + "#" + this->getFragment ( ) ) ;
	
	sf::Http server ( this->getScheme ( ) + "://" + this->getAuthority ( ) ) ;
	
	return server.sendRequest ( request ) ;
}
std::string Crawler::Link::requestContent ( ) const
{
	if ( this->scheme == "http" || this->scheme == "https" )
	{
		sf::Http server ( this->getScheme ( ) + "://" + this->getAuthority ( ) ) ;
		
		sf::Http::Request request ;
		sf::Http::Response response = this->sendRequest ( request ) ;
		
		return response.getBody ( ) ;
	}
	
	throw std::runtime_error ( ( "Protocol is not implemented (" + this->fragment + ")!" ).c_str ( ) ) ;
	
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
	return ! ( left == right ) ;
}
