
#include<iostream>
#include<stack>
using std::stack;
class Mystack{

 public: 
  int pop();
  
  void push(int e);

  int getMin();
   
 private:

   stack<int> data;
 
    
};


