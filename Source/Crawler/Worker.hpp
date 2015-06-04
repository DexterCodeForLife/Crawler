#pragma once 

namespace Crawler 
{
	class CRAWLER_API Worker
	{
		public: 
			//brief
			Crawler::Worker::Worker();
			
			//brief reference to WorkerManager object
			WorkerManager& Crawler::Worker::getWorkerManager();
			
			//brief reference to WorkerManager object
			const WorkerManager& Crawler::Worker::getWorkerManager() const;
			
			//brief
			bool Crawler::Worker::hasWebsite() const;
			
			//brief
			//param
			void Crawler::Worker::setWebsite( const Website website&);
			
			//brief reference to Website object
			Website& Crawler::Worker::getWebsite();
			
			//brief reference to Website object
			const Website& Crawler::Worker::getWebsite()const;
			
			//brief boolean determining if Worker object has a website
			bool Crawler::Worker::hasWebsite()const;
			
			//brief sets a specified Website for the Worker
			//param reference to a Website 
			void Crawler::Worker::setWebsite(const Website& website);
			
			//brief reference to a Website object
			Website& Crawler::Worker::getWebsite();
			
			//brief reference to a Website object
			const Website& Crawler::Worker::getWebsite()const;
			
			//brief boolean that specifies whether the Worker is active 
			bool Crawler::Worker::isRunning()const;
			
			//brief starts the Worker
			void Crawler::Worker::setRunning(bool running);
			
			//brief 
			void Crawler::Worker::launch();
			
			//brief
			void Crawler::Worker::terminate();
			
			//brief
			void Crawler::Worker::wait();
			
			//brief
			void Crawler::Worker::wait();
			
			//brief
			void Crawler::Worker::kill();
			
			//brief
			void Crawler::Worker::main();

				
		private: 
		
			WorkerManger& workerManager;
			sf::Thread thread;
			Website* website;
			bool running; 
			sf::Mutex mutex; 
			

}