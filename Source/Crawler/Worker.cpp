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
    
        if(!website->wasVisited(){
        
		}
		return * this->website;
		
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
	
}

void Crawler::Worker::terminate

void Crawler::Worker::wait ( )
{
	//not sure why this is needed also
}

void Crawler::Worker::kill ( )
{
	//not sure why this is needed
    //kills the thread
}

void Crawler::Worker::main ( )
{
	this->launch();
    
    http.setHost(//fetch link);
    resquest(website->toString);//would this be the right method to use?
    response = http.sendRequest(resquest);
    status = response.getStatus();
    if(status == sf::Http::Response::Ok){
        document = response.getBody();
    }
    else
    {
        std::cout<<"Error" << status << std::endl;
    }
    char* page_position;
    page_position = strstr(document.c_str(),'<a');
    page_position = strstr(page_position, '>');
    *page_position = '\0'
    Link currentLink(document.c_str(), 'href');
    website->links.push_back(currentLink);
			//fetch document from links
			//scrape links from document
    //maybe this is where we empty out the links and they get put put in the website vector
    //
			
}
			
