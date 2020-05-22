#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "task.h"
#include <iostream>
#include <pthread.h>
#include <list>
#include <vector>
using namespace std;

class Task_Queue{
	private:
		int queue_size;
		list<Task*>*queue;
		pthread_mutex_t mutex;
		pthread_cond_t cond;
	public:
		Task_Queue(){
			this->queue_size=0;
			this->queue=new list<Task*>();
			pthread_mutex_init(&mutex,NULL);
			pthread_cond_init(&cond,NULL);
		}
		int task_queue_size();
		void put(Task*);
		void banch_put(vector<Task*>);
		Task*pop();
		~Task_Queue(){};
};

#endif
