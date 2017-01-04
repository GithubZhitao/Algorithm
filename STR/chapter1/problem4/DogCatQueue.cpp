
#include"Pet.cpp"
#include<queue>
#include<iostream>
using std::queue;
using std::cout;
using std::endl;

class DogCatQueue{

public:
  void add(Pet p){
     pets.push(p);
  }
  void pollAll(){
     pets.pop();
  }
  void pollDog(){
     poll("Dog");
  }
  void pollCat(){
   poll("Cat");
  }
  void poll(string anim){
   queue<Pet> t_sta;
    int i =0 ;
    while(!pets.empty())
    {
	     if(pets.front().getPetType()!=anim){
	     t_sta.push(pets.front());
	     pets.pop();
	     }else
	     {
	      //int aDog = pets.front(); // do not save the pop element
	      pets.pop();
		if (i==0) return ;
	       while(!pets.empty())
	       {
		t_sta.push(pets.front());
		pets.pop();
	       }
               pets = t_sta;
               return ;
	     }
       i++;
    }
   cout <<"nothing here in the queue"<<endl;
  }
  bool isEmpty(){
   if(pets.empty())
    return true;
   else
    return false;
  }
  bool isDogEmpty(){
     queue<Pet> t_sta;
     bool isE = true;
     while(!pets.empty()){
     if(pets.front().getPetType()==string("Dog"))
       isE = false;
     t_sta.push(pets.front());
     t_sta.pop();
     }
     pets = t_sta;
     return isE;
     
  }
  bool isCatEmpty(){
   queue<Pet> t_sta;
     bool isE = true;
     while(!pets.empty()){
     if(pets.front().getPetType()==string("Cat"))
       isE = false;
     t_sta.push(pets.front());
     t_sta.pop();
     }
     pets = t_sta;
     return isE;
  }
  Pet front(){
   return pets.front();
  }
private:
 queue<Pet> pets;   
};
