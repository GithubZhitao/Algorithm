#include<iostream>
#include<stack>
#include<string>
using std::stack;
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;


  static int count =0;
 void move(stack<int> &a , stack<int> &b, string s1, string s2)
  {
     if(a.empty()) cerr<<"move from a empty stack"<<endl; 
     else
     {
       cout << "move "<<a.top()<<" from "<<s1<<" to "<<s2<<endl;
       b.push(a.top());
       a.pop();
       count++;
     }
  }
 
  void HanoiSolv(stack<int> &a , stack<int> &o  , stack<int> &b,string sa,string so,string sb ,int n){
    if(n==1)
    {
      move(a,o,sa,so);
      move(o,b,so,sb);
    }else
    {
      HanoiSolv(a , o , b , sa , so , sb , n-1);
      move(a,o,sa,so);
      HanoiSolv(b , o , a , sb , so , sa , n-1);
      move(o,b,so,sb);
      HanoiSolv(a , o , b , sa , so , sb , n-1);
    }
     
  }
  



int main()
{
  stack<int> A;
  stack<int> O;
  stack<int> B;
  int num;
  cin>>num;
  for(int i = num ; i>=1 ; i--)
    A.push(i);
  HanoiSolv(A,O,B,"A","O","B",num);
  cout<<"It will move "<<count<<" steps"<<endl;
}
