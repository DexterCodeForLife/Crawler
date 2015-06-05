#include <Crawler.hpp>
#include <iostream>

int main ( int argc , char ** argv )
{
	Crawler::Link link ( argv [ 1 ] ) ;
	
	std::cout << link.requestContent ( ) << "\n" ;
			  
	return 0 ;
}
