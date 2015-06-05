#pragma once 

namespace Crawler 
{
	class CRAWLER_API Worker
	{
		public: 
			//brief
			Crawler::Worker::Worker();
			
			//brief reference to WorkerManager object
			WorkerManager& getWorkerManager();
			
			//brief reference to WorkerManager object
			const WorkerManager& getWorkerManager() const;
			
			//brief
			bool hasWebsite() const;
			
			//brief
			//param
			void setWebsite( const Website website&);
			
			//brief reference to Website object
			Website& getWebsite();
			
			//brief reference to Website object
			const Website& getWebsite()const;
			
			//brief boolean determining if Worker object has a website
			bool hasWebsite()const;
			
			//brief sets a specified Website for the Worker
			//param reference to a Website 
			void setWebsite(const Website& website);
			
			//brief reference to a Website object
			Website& getWebsite();
			
			//brief reference to a Website object
			const Website& getWebsite()const;
			
			//brief boolean that specifies whether the Worker is active 
			bool isRunning()const;
			
			//brief starts the Worker
			void setRunning(bool running);
			
			//brief 
			void launch();
			
			//brief
			void terminate();
			
			//brief
			void wait();
			
			//brief
			void kill();
			
			//brief
			void main();

				
		private: 
		
			WorkerManger& workerManager;
			sf::Thread thread;
			Website* website;
			bool running; 
			sf::Mutex mutex; 
			

}