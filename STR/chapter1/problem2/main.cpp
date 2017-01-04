#include "TwoStackQueue.h"
#include<iostream>
using std::endl;
using std::cout;

int main(){
TwoStackQueue myqueue;
myqueue.add(1);
myqueue.add(2);
myqueue.add(3);
myqueue.add(4);
myqueue.add(5);
myqueue.add(6);
cout<<"the peek : "<<myqueue.peek()<<endl;
myqueue.poll();
cout<<"after poll ,the peek : "<<myqueue.peek()<<endl;
myqueue.add(10);
cout<<"after add , the peek : "<<myqueue.peek()<<endl;

return 0;
}
