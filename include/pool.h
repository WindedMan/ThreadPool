#ifndef __POOL_H__
#define __POOL_H__

#include "queue.h"
#include "task.h"
#include <pthread.h>

class ThreadPool{
	private:
		int _size;
		bool flag;
		Task_Queue *queue;
		pthread_t *pool;
	public:
		ThreadPool(int size);
		void process();
		void start();
		void stop();
		void join();
		void put(Task*);
		~ThreadPool(){
			delete queue;
			delete pool;
		}
};

void *wrapper(void *p);
#endif
