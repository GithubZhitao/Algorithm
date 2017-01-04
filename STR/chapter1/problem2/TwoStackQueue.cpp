#include"TwoStackQueue.h"
#include<iostream>

void TwoStackQueue::add(int e){
     stackPush.push(e);
}

void TwoStackQueue::poll(){
	if(adjustStack())
  	stackPop.pop();
        else
        std::cerr<<"error: poll from an empty queue"<<std::endl;         
     

}

int TwoStackQueue::peek(){
      if(adjustStack())
       return stackPop.top();
	
       std::cerr<<"no elements in the queue"<<std::endl;
       return -1; 
        
}

bool TwoStackQueue::adjustStack(){
  if(stackPop.empty()&&!stackPush.empty()){
    while(!stackPush.empty()){
            stackPop.push(stackPush.top());
	    stackPush.pop();
	}
  }
  if(stackPop.empty()&&stackPush.empty())
	return false;
  return true;	
}
