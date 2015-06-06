#include <Crawler.hpp>
#include <iostream>

int main ( int argc , char ** argv )
{
	Crawler::Website website ;
	Crawler::Link link ( "/directory/file?query#fragment" ) ;
	website.addLink ( link ) ;
	link = Crawler::Link ( "/directory2/file2?query2#fragment2" ) ;
	website.addLink ( link ) ;
	
	for ( link : website )
		std::cout << link.toString ( ) << "\n" ;
	
	return 0 ;
}
