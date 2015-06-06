#include <Crawler/Worker.hpp>
#include <Crawler/Website.hpp>
#include <Crawler/WorkerManager>
//#include <uriparser/Uri.h> 

Crawler::Worker::Worker(){}


WorkerManager& Crawler::Worker::getWorkerManager(){

	return Crawler::WorkerManager; 
	
}



const WorkerManager& Crawler::Worker::getWorkerManager() const{

	return Crawler::WorkerManager; 
}



bool Crawler::Worker::hasWebsite() const{
	
	return this->website != NULL; 
}



void Crawler::Worker::setWebsite( const Website& website){

	this->mutex.lock(); 
	this->website = website; 
	this.mutex.unlock(); 
}



Website& Crawler::Worker::getWebsite(){

	return * this->website; 
}



const Website& Crawler::Worker::getWebsite()const{
	
	return * this->website; 
}



bool Crawler::Worker::hasWebsite()const{
	return ; 
}



bool Crawler::Worker::isRunning()const{
	return ; 
}



void Crawler::Worker::setRunning(bool running){}



void Crawler::Worker::launch(){}



void Crawler::Worker::terminate(){}



void Crawler::Worker::wait(){}



void Crawler::Worker::wait(){}



void Crawler::Worker::kill(){}



void Crawler::Worker::main(){}
