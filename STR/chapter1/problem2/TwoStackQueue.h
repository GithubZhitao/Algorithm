
#include<stack>

using std::stack;

class TwoStackQueue{

public:

   void add(int e);
   void poll();
   int peek();
   bool adjustStack();


private:
  stack<int> stackPush;
  stack<int> stackPop;

};
