#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/Worker.hpp>
#include <SFML/System.hpp>
#include <list>
#include <memory>

namespace Crawler
{
	class Application ;

	class CRAWLER_API WorkerManager
	{
		public :
			using ConstIterator = std::list <std::unique_ptr <Crawler::Worker>>::const_iterator ;
		
			/// \brief Constructor
			/// \param application Reference to application object
			WorkerManager ( Application & application ) ;
			
			/// \brief Copy constructor
			WorkerManager ( const WorkerManager & workerManager ) = delete ;
			
			/// \brief Move constructor
			WorkerManager ( WorkerManager && workerManager ) = delete ;
			
			/// \brief Copy assignment operator
			WorkerManager & operator = ( const WorkerManager & workerManager ) = delete ;
			
			/// \brief Move assignment operator
			WorkerManager & operator = ( WorkerManager && workerManager ) = delete ;
			
			/// \brief Returns application
			/// \return Reference to application
			Crawler::Application & getApplication ( ) ;
			
			/// \brief Returns application
			/// \return Reference to application
			const Crawler::Application & getApplication ( ) const ;

			/// \brief Changes amount of worker
			/// \param amountOfWorker Value of amount of worker
			void setAmountOfWorker ( std::size_t amountOfWorker ) ;
			
			/// \brief Returns amount of worker
			/// \return Amount of worker
			std::size_t getAmountOfWorker ( ) const ;
			
			/// \brief Spawns a worker
			void spawnWorker ( ) ;
			
			/// \brief Despawns a worker
			void despawnWorker ( ) ;
			
			/// \brief Returns list of workers
			/// \return Reference to list of workers
			const std::list <std::unique_ptr <Crawler::Worker>> & getWorker ( ) const ;
			
			/// \brief Returns begin iterator
			/// \return Begin iterator
			ConstIterator begin ( ) const ;
			
			/// \brief Returns begin iterator
			/// \return Begin iterator
			ConstIterator cbegin ( ) const ;
			
			/// \brief Returns end iterator
			/// \return End iterator
			ConstIterator end ( ) const ;
			
			/// \brief Returns end iterator
			/// \return End iterator
			ConstIterator cend ( ) const ;

		private :
			Crawler::Application & application ;
			std::list <std::unique_ptr <Crawler::Worker>> worker ;
			std::size_t amountOfWorker = 10 ;
			sf::Mutex mutex ;
	} ;
}
