
#include<string>
using std::string;

class Pet{

public:
  Pet(string type){
    this->type = type;
 }
  string getPetType(){
    return this->type;
  }
  void setNo(int nm){crr = nm;}  // to test the code
  int getNo(){return crr;} // to test the code
private:
  string type;
  int crr;      // to test the code

};


class Dog:public Pet
{

  public:
    Dog():Pet(string("Dog"))
    {
     
    }
};


class Cat:public Pet
{
  public:
    Cat():Pet(string("Cat"))
   {

   }

};


