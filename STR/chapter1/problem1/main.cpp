#include "Mystack.h"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
Mystack st;
st.push(1);
st.push(2);
st.push(5);
st.push(4);

cout << st.getMin()<<endl;



return 0;
}
