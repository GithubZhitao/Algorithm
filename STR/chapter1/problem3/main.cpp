#include<stack>
#include<iostream>

using std::cout;
using std::endl;
using std::stack;
int getThelastAndRemove(stack<int> &st){
  int top = st.top();
  st.pop();
  if(st.empty())
  {
    return top;
  } else
  {
    int last= getThelastAndRemove(st);
    st.push(top);
    return last;
  }
   
}

void reverse(stack<int>&st){
  if(!st.empty())
  {
    int last = getThelastAndRemove(st);
    reverse(st);
    st.push(last);
  }else
   return;
 
}
int main(){

stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
reverse(st);
while(!st.empty()){
 cout<<st.top()<<"	";
 st.pop();
}
 cout<<endl;
return 0;
}
