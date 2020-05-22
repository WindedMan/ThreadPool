#include "task.h"
#include "pool.h"
#include "queue.h"

#include<iostream>
#define LEN  20
using namespace std;
int main(){
	ThreadPool*threadpool=new ThreadPool(4);
	
	vector<Task*> tasks;
	for(int  i=0;i<LEN;i++){
		Task* task=new Task();
		tasks.push_back(task);
	}
	for(auto t:tasks)threadpool->put(t);
	for(int i=0;i<tasks.size();i++)
	{
		int result=tasks[i]->get_result();
		cout<<"Get result from task [" <<i<<"],result=    "<<result<<endl;
		delete tasks[i];
	}
	threadpool->stop();
	threadpool->join();
	delete threadpool;
	return 0;
}
