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
	this->worker.back ( )->launch ( ) ;
}
			
void Crawler::WorkerManager::despawnWorker ( )
{
	auto worker = this->worker.begin ( ) ;
	( * worker )->terminate ( ) ;
	this->worker.erase ( worker ) ;
}

const std::list <std::unique_ptr <Crawler::Worker>> & Crawler::WorkerManager::getWorker ( ) const
{
	return this->worker ;
}

Crawler::WorkerManager::ConstIterator Crawler::WorkerManager::begin ( ) const
{
	return this->worker.begin ( ) ;
}
Crawler::WorkerManager::ConstIterator Crawler::WorkerManager::cbegin ( ) const
{
	return this->worker.cbegin ( ) ;
}
Crawler::WorkerManager::ConstIterator Crawler::WorkerManager::end ( ) const
{
	return this->worker.end ( ) ;
}
Crawler::WorkerManager::ConstIterator Crawler::WorkerManager::cend ( ) const
{
	return this->worker.cend ( ) ;
}
