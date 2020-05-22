#ifndef __TASK_H__
#define __TASK_H__

#include<iostream>
#include<pthread.h>

#define MOD 100

class Task{
	private:
		int result;
		bool done;
		pthread_mutex_t mutex;
		pthread_cond_t cond;
	public:
		Task(){
			this->done=false;
			pthread_mutex_init(&mutex,NULL);
			pthread_cond_init(&cond,NULL);
		}
		void set_result(int result);
		int get_result();
		int callable();
		~Task(){
			std::cout<<"delete Task:"<<this<<std::endl;
		}
};
#endif
