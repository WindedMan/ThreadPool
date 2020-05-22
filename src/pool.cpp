#include "pool.h"

void *wrapper(void *p){
	ThreadPool* pool=(ThreadPool*) p;
	pool->process();
}

ThreadPool::ThreadPool(int size){
	if(size==0)size=4;
	_size=size;
	flag=true;
	queue=new Task_Queue();
	pool=new pthread_t(_size);
	for(int  i=0;i<_size;i++){
		pthread_create(&pool[i],NULL,wrapper,this);
	}
}

void ThreadPool::start(){
}

void ThreadPool::process(){
	while(flag){
		Task*temp=queue->pop();
		int result=temp->callable();
		temp->set_result(result);
	}
}

void ThreadPool::put(Task*task){
	queue->put(task);
}

void ThreadPool::stop(){
	flag=false;
}

void ThreadPool::join(){
	for(int i=0;i<_size;i++)
		pthread_join(pool[i],NULL);
}
