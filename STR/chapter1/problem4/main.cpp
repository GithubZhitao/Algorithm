#include"DogCatQueue.cpp"



int main(){
  DogCatQueue dcqueue;
  
  Dog dog;
  Cat cat;
  int ii=0;
  for(int i = 1 ; i <=3; i++)
 {
  dog.setNo(ii++);
  dcqueue.add(dog);
  cat.setNo(ii++);
  dcqueue.add(cat);
 }
 for(int i =1 ; i<=3 ; i++)
 {
 // cout << "petNo. "<< dcqueue.front().getNo()<<" "<<dcqueue.front().getPetType()<<endl;
  dcqueue.pollDog();
 }
  for(int i =1 ; i<=3 ; i++)
 {
  cout << "petNo. "<< dcqueue.front().getNo()<<" "<<dcqueue.front().getPetType()<<endl;
  dcqueue.pollCat();
 }
  
  return 0;
 }
