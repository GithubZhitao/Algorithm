#include<vector>
#include<iostream>
using std::vector;
using std::cout;
using std::endl;

void slideWindowMax(vector<int>&arr, vector<int>&res, int w){
  typedef vector<int>::size_type size_a;
  size_a i =0 ;
  int maxValue = -100;
  for(; i < arr.size()&&i<w ; ++i ){
    if(arr[i] > maxValue)
      maxValue = arr[i];
  }  
  res.push_back(maxValue);
  while(i<arr.size()){ 
     if(arr[i-w]==maxValue){
       maxValue = arr[i-w+1];
       for(int j = i-w+1 ; j <=i ; ++j)
          if(arr[j]>maxValue)
            maxValue = arr[j];
     }
     else if(arr[i-w]<maxValue&&arr[i]>maxValue)
       maxValue=arr[i];
       res.push_back(maxValue);
     i++;
        
  }

}

int main(){
 vector<int> input = {4 ,3 ,5 ,4 , 3 , 3 , 6, 7};
 vector<int> res;
 slideWindowMax(input , res , 3);
 for(auto &iter : res) 
  cout<<iter<<"	";
 cout<<endl;
return 0;
}
