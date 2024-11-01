#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *left;
  node *right;
  node(){
  node *left = NULL;
  node *right = NULL;
  }

};

node *root;
void insert(int a){
node *new_node,*parent,*current;
  if(root==NULL){
    root = new node();
    root->data = a;
  }
  else{
    current = root;
    while(current!=NULL){
      if( current->data < a ) {
       parent = current;
       current = current->left;
      }
      else {
        parent = current;
        current = current->right;
    }
      }
      new_node = new node();
      new_node->data = a;
      if( a < parent->data )  parent->left = new_node;
      else parent->right = new_node;
    }
  }

void print(node *current){
  if(current==NULL)
    return ;
  cout<<current->data<<" ";
  print(current->left);
  print(current->right);
}



int main(){
  insert(100);
  insert(50);
  insert(150);
  insert(10);
  print(root);


return 0;
}
