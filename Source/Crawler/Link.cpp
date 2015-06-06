#include <Crawler/Link.hpp>
#include <Crawler/Website.hpp>
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

Crawler::Link::Link ( const std::string & path , const std::string & query , const std::string & fragment )
{
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

bool Crawler::Link::wasVisited ( ) const
{
	return this->visited ;
}

void Crawler::Link::setVisited ( bool visited )
{
	this->visited = visited ;
}

const std::string & Crawler::Link::getPath ( ) const
{
	return this->path ;
}

void Crawler::Link::setPath ( const std::string & path )
{
	this->path = path ;
	
	if ( this->path [ 0 ] != '/' )
		this->path.insert ( this->path.begin ( ) , '/' ) ;
}

const std::string & Crawler::Link::getQuery ( ) const
{
	return this->query ;
}

void Crawler::Link::setQuery ( const std::string & query )
{
	this->query = query ;
}

const std::string & Crawler::Link::getFragment ( ) const
{
	return this->fragment ;
}

void Crawler::Link::setFragment ( const std::string & fragment )
{
	this->fragment = fragment ;
}

std::string Crawler::Link::toString ( ) const
{
	std::string string = this->getPath ( ) ;
	string += ! this->getQuery ( ).empty ( ) ? "?" + this->getQuery ( ) : "" ;
	string += ! this->getFragment ( ).empty ( ) ? "#" + this->getFragment ( ) : "" ;

	return string ;
}

bool Crawler::operator == ( const Crawler::Link & left , const Crawler::Link & right )
{
	return left.getPath ( ) == right.getPath ( ) &&
		   left.getQuery ( ) == right.getQuery ( ) &&
		   left.getFragment ( ) == right.getFragment ( ) ;
}
bool Crawler::operator != ( const Crawler::Link & left , const Crawler::Link & right )
{
	return ! ( left == right ) ;
}
