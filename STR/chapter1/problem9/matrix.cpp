#include<iostream>
#include<vector>
#include<assert.h>
using std::cout;
using std::endl;
using std::vector;
//using std::cerr;
struct couple{
 couple(int cc_b , int cc_e , int rr_b , int rr_e){
    c_b = cc_b;
    c_e = cc_e;
    r_b = rr_e;
    rr_e =rr_e;
 } 
  int c_b;
  int c_e;
  int r_b;
  int r_e;
};


class matrix{
public:

   vector<vector<int> > mat;
  // constructor
   matrix( vector<vector<int> > imat){
     mat = imat;
    }
 // maxvalue
   int max(int a , int b){
     if(a>b)
      return a;
     else
      return b; 
   }
  //minvalue
   int min(int a , int b){
     if(a>b)
       return b;
     else
       return a;
   }

   int matrixSize(couple &mat){
      return (mat.c_e-mat.c_b+1)*(mat.r_b - mat.r_e+1);
   }
  // merge line with matrix
   bool mergeMatrix(couple &sub1, couple &sub2,couple &resul){
    assert(sub2.c_b == sub2.c_e);
    if(sub2.c_b-sub1.c_e==1){
      resul.c_b = sub1.c_b;
      resul.c_e = sub2.c_e;
      if(sub1.r_b>=sub2.r_b&&sub1.r_b<=sub2.r_e|| sub1.r_e>=sub2.r_b&&sub1.r_e<=sub2.r_e){
      resul.r_b = min(sub1.r_b , sub2.r_b) ;
      resul.r_e = max(sub1.r_e, sub2.r_e);   
       return true;  
      } else
       return false;
    }else{
      return false;
    }
   }
   
  // max sub matrix
int MaxSubMap(){
   vector<couple> submats; 
   int maxSize=0;
  //cerr <<"funck you"<endl;
   for(int i =0 ; i < mat.size() ; ++i )
   {
 //cerr <<"come here "<<mat.size()<<endl; 
   //  cout <<maxSize<<endl;
     // if there is no matrix here
    // if(!submats.empty())
     //{
       int j =0;
      while(j<mat[i].size())
      {
         
         while(j<mat[i].size()&&mat[i][j]==0)
             j++;
           int b_j;
           if(j!=mat[i].size())
	   int b_j = j ;
           else
           break;

	   while(j<mat[i].size()&&mat[i][j]==1)
              j++;
	   if(j!=b_j)
           {
             couple line(i,i,b_j,j-1);
             for(vector<couple>::iterator m_i = submats.begin() ; m_i !=submats.end() ;++m_i)
             {
                couple resul(-1,-1,-1,-1) ;
                if(mergeMatrix(*m_i, line , resul))
                {
                if(matrixSize(resul)>maxSize)
                  maxSize  = matrixSize(resul);
                  m_i =  submats.erase(m_i);
                  submats.insert(m_i,resul);
                }
               cout <<"come here"<<endl;  
               cout <<maxSize<<endl;
             }
             submats.push_back(line); 
                      
   
           }  
         
      }
    // }
   }
      return maxSize; 
   }
  
}; 
   
   




