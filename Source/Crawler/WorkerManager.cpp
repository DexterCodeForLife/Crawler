#include <Crawler/WorkerManager.hpp>

Crawler::WorkerManager::WorkerManager ( Application & application ) :
	application ( application )
{
}
			
Crawler::Application & Crawler::WorkerManager::getApplication ( )
{
	return this->application ;
}
			
const Crawler::Application & Crawler::WorkerManager::getApplication ( ) const
{
	return this->application ;
}

void Crawler::WorkerManager::setAmountOfWorker ( std::size_t amountOfWorker )
{
	this->amountOfWorker = amountOfWorker ;
}
			
std::size_t Crawler::WorkerManager::getAmountOfWorker ( ) const
{
	return this->amountOfWorker ;
}
			
void Crawler::WorkerManager::spawnWorker ( )
{
	this->worker.push_back ( std::unique_ptr <Crawler::Worker> ( new Crawler::Worker ( * this ) ) ) ;
}
			
void Crawler::WorkerManager::despawnWorker ( )
{
}

const std::list <std::unique_ptr <Crawler::Worker>> & Crawler::WorkerManager::getWorker ( ) const
{
	return this->worker ;
}
