#include <Crawler/ScopedMutex.hpp>
#include <SFML/System.hpp>

Crawler::ScopedMutex::ScopedMutex ( sf::Mutex & mutex ) :
	mutex ( mutex )
{
	this->mutex.lock ( ) ;
}
Crawler::ScopedMutex::~ScopedMutex ( )
{
	this->mutex.unlock ( ) ;
}
