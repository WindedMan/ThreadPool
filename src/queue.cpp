#include "queue.h"

int Task_Queue::task_queue_size(){
	return this->queue_size;
}

void Task_Queue::put(Task*item){
	pthread_mutex_lock(&mutex);
	queue->push_back(item);
	queue_size++;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond);
}

void Task_Queue::banch_put(vector<Task*>Tasks){
	for(int i=0;i<Tasks.size();i++)
		put(Tasks[i]);
}

Task* Task_Queue::pop(){
	pthread_mutex_lock(&mutex);
	while(this->queue_size==0)
		pthread_cond_wait(&cond,&mutex);
	Task*temp=queue->front();
	queue->pop_front();
	queue_size--;
	pthread_mutex_unlock(&mutex);
	return temp;
}
