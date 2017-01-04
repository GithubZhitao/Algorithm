#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::cerr;

struct Node{
 public:
  int value;
  Node *left;
  Node *right;
  
 Node(int data){
  this->value = data;
  left=NULL;
  right = NULL;
 }  
};

struct NodeE{
int lm=1000000000;
int rm=1000000000;
};

void traverseTree(Node * h){
  
  if(!h)
   {}else{
  cerr<<h->value<<"	";
  if(h->left!=NULL)
  traverseTree(h->left);
  if(h->right !=NULL)
  traverseTree(h->right);
  }
 
}
void MaxTree(vector<int>&arr){
  // construct the 2 tree
  Node * h;
   vector<NodeE> nodes;
   stack<int> sta1;
   stack<int> sta2;
   if(arr.size()==0) return ;
  
  for(int i=0 ; i< arr.size(); i++)
  {
    NodeE p;
    nodes.push_back(p); 
  }
   
  for(int i =0 ; i< arr.size() ;i++ )
  {
      
  
   if(!sta1.empty())
   {    
     while(!sta1.empty()&&arr[i]>arr[sta1.top()])
     {
         assert(arr[i]!=arr[sta1.top()]);
         sta1.pop();
     }
     
     if(!sta1.empty())
     {
       nodes[i].lm =sta1.top(); 
     }
   }
   
    if(!sta2.empty())
   {    
     while(!sta2.empty()&&arr[arr.size()-1-i]>arr[sta2.top()])
     {
         assert(arr[arr.size()-1-i]!=arr[sta2.top()]);
         sta2.pop();
     }
     
     if(!sta2.empty())
     {
       nodes[arr.size()-i-1].rm =sta2.top(); 
     }
   }
   sta1.push(i);
   sta2.push(arr.size()-1-i);
  }
   int maxVa = arr[0];
  vector<Node *> rubish;
  for(int i =0 ; i< arr.size(); i++){  
   Node * pp = new Node(arr[i]); 
   rubish.push_back(pp);
   if(maxVa < arr[i])
     {
       h =pp;
       maxVa = arr[i];
     }
  }
   
  for(int i =0 ; i< arr.size(); ++i)
  {
     int father ;
    if(nodes[i].lm<100&&nodes[i].rm<100)
   {
     if(arr[nodes[i].lm] <arr[nodes[i].rm])
        father = nodes[i].lm;
     else
        father = nodes[i].rm;
   } 
     else
      father = std::min(nodes[i].lm,nodes[i].rm);
  
     
     if(father > 100)
       continue;
     // cerr<<" "<<father<<" ";
     if(rubish[father]->left==NULL)
       {
        rubish[father]->left= rubish[i];
       
       }
     else
       {
        rubish[father]->right= rubish[i];  
       
       }
 cerr<<father<<" <- " << i<<endl;
  }
 
  cout <<"the nodes number : "<<nodes.size()<<endl;
  traverseTree(h);
  // free the memery
  for(int i =0 ; i< rubish.size() ; ++i)
     delete rubish[i];

}


int main(){
vector<int> arr = {3 ,4 ,5 ,1 ,2};
MaxTree(arr);
return 0;
}



