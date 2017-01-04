#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;
using std::cin;
using std::cerr;
// sort a stack  using a another stack
int main()
{
 stack<int> myStack;
// -1 end the input
int in=-2;
 while(in!=-1)
 {
   cin >>in;
   if(in==-1)
    break;
   myStack.push(in); 
 }

 stack<int> tempS;
 while(!myStack.empty()){
  int top =myStack.top();
  myStack.pop();
  
  if(tempS.empty()){
   tempS.push(top);
  }else
  {
    while(tempS.empty()&&top>tempS.top())
    {
       myStack.push(tempS.top());
       cerr<<tempS.top()<<endl;
       tempS.pop();
       
    }
    tempS.push(top);     
  }
 }
 myStack = tempS;
 cout <<"after sort : "<<endl;
 while(!myStack.empty()){
   cout <<myStack.top()<<"	";
   myStack.pop();
 }
 return 0;
}
