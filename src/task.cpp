#include "task.h"

#include<stdlib.h>
#include<time.h>

void Task::set_result(int result){
	pthread_mutex_lock(&mutex);
	this->result=result;
	this->done=true;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond); 
}

int Task::get_result(){
	pthread_mutex_lock(&mutex);
	int temp;
	if(this->done)
		temp=result;
	else{
		pthread_cond_wait(&cond,&mutex);
		temp=result;
	}
	pthread_mutex_unlock(&mutex);
	return temp;
}

int Task::callable(){
	srand((int)time(0));
	int num=rand()%MOD;
	return num;
}
