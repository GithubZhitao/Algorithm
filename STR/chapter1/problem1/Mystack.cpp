#include "Mystack.h"


int Mystack::pop(){
  if(data.empty())
  {
   return -1;
  }
  else
  {
    data.pop();
    int tt =data.top();
    data.pop();
    return tt;
  }
  
}


void Mystack::push(int e){

  if(data.empty())
   {
	data.push(e);
	data.push(e);
   }
   else
    {
  	int topT= data.top();
        if(e < topT)
	{
           data.push(e);
	   data.push(e);
  	}else
	{
           data.push(e);
	   data.push(topT);
        }
    }
}


int Mystack::getMin(){

   if(data.empty())
    {
      return -1;
    }
    else
    {
      return data.top();
    }

}
