#pragma once 

#include <Crawler/Linker.hpp>
#include <SFML/System.hpp>
#include <string>
#include <memory>

namespace sf
{
	class Thread ;
}

namespace Crawler
{
	class WorkerManager ;
	class Website ;
	class WebsiteManager; 

	class CRAWLER_API Worker
	{
		public: 
			/// \brief Constructor
			/// \param workerManager Worker manager the worker belongs to
			Worker ( Crawler::WorkerManager & workerManager ) ;
			
			/// \brief Copy constructor
			/// \param worker Worker which is copied
			Worker ( const Worker & worker ) = delete ;
			
			/// \brief Move constructor
			/// \param worker Worker which is moved
			Worker ( Worker && worker ) = delete ;
			
			/// \brief Copy assignment operator
			/// \param worker Worker which is copied
			/// \return Reference to this
			Worker & operator = ( const Worker & worker ) = delete ;
			
			/// \brief Move assignment operator
			/// \param worker Worker which is moved
			/// \return Reference to this
			Worker & operator = ( Worker && Worker ) = delete ;
			
			/// \brief Returns reference to worker manager
			/// \return Reference to worker manager
			Crawler::WorkerManager & getWorkerManager ( ) ;
			
			/// \brief Returns reference to worker manager
			/// \return Reference to worker manager
			const Crawler::WorkerManager & getWorkerManager ( ) const ;
			
			/// \brief Returns the assigned website
			/// \return Reference to the assigned website
			Crawler::Website * getWebsite ( ) ;
			
			/// \brief Returns the assigned website
			/// \return Reference to the assigned website
			const Crawler::Website * getWebsite ( ) const ;
			
			/// \brief Checks if the worker is running
			/// \return True if the worker is running
			bool isRunning ( ) const;
			
			/// \brief Sets if the worker is running
			/// \param running Value of running
			void setRunning ( bool running ) ;
			
			/// \brief Launches the worker
			void launch ( ) ;
			
			/// \brief Terminates the worker
			void terminate ( ) ;
			
			/// \brief Wait until the worker finishes (this blocks the thread which executes this method so be carefull)
			void wait ( ) ;
			
			/// \brief Kills the worker immediately
			void kill ( ) ;

		private :
			/// \brief Workers main function
			void main ( ) ;
			
			Crawler::WorkerManager & workerManager ;
			std::unique_ptr <sf::Thread> thread ;
			Crawler::Website * website = nullptr ;
			bool running = true ;
			sf::Mutex mutex ;
	} ;
}
