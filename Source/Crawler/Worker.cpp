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
	//assuming that the getWorkerManager is shard Memorey
	//maybe need to use mutex lock and unlock
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
	if(websiteManager.existsWebsite){
		website = *iter; 
		if(website->wasVisited()){
			iter++; 
			getWebsite(); 
		}
		return * this->website; 
		
	}
		
}
	

const Crawler::Website & Crawler::Worker::getWebsite ( ) const
{	
	if(!website->visited){
		return * this->website ;
	}
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
	this->running = true; 
	this->getwebsite(); 
	website->links::lIter = website->links.begin(); 
	
}

void Crawler::Worker::terminate ( )
{
	this->running  = false; 
	this->website = NULL;
	delete website;  
	
}

void Crawler::Worker::wait ( )
{
}

void Crawler::Worker::kill ( )
{
	this->running = false; 
	this->website = NULL; 
	delete website; 
}

void Crawler::Worker::main ( )
{
	this->launch(); 
	for(lIter!=websites->links.end(); lIter++){
		if(!lIter->wasVisited()){
			lIter->setVisited(true); 
			
		}
		
	} 
}
