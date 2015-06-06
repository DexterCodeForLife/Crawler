#include <Crawler/Worker.hpp>
#include <Crawler/Website.hpp>
#include <Crawler/WorkerManager.hpp>

Crawler::Worker::Worker ( Crawler::WorkerManager & workerManager ) :
	workerManager ( workerManager ) ,
	thread ( & Crawler::Worker::main , this )
{
}

Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( )
{
	return this->workerManager ;
}

const Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( ) const
{
	return this->workerManager ;
}

bool Crawler::Worker::hasWebsite ( ) const
{
	return this->website ;
}

Crawler::Website & Crawler::Worker::getWebsite ( )
{
	return * this->website ;
}

const Crawler::Website & Crawler::Worker::getWebsite ( ) const
{
	return * this->website ;
}

bool Crawler::Worker::isRunning ( ) const
{
	return this->running ;
}

void Crawler::Worker::setRunning ( bool running )
{
	this->running = running ;
}

void Crawler::Worker::launch ( )
{
}

void Crawler::Worker::terminate ( )
{
}

void Crawler::Worker::wait ( )
{
}

void Crawler::Worker::kill ( )
{
}

void Crawler::Worker::main ( )
{
}
