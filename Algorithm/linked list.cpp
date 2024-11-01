/**
    Singly linked list
    Insertion,Deletion complexity O(n)

*/

#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};
node *root = NULL;

void append(int roll){

  if(root==NULL){
    root = new node();
    root->data = roll;
    root->next = NULL;
  }
  else{
    node *current_node = root;
    while(current_node->next != NULL){
      current_node = current_node->next;
    }
    /**
        *current_node hocche last node pointer er ager *node ta
    */

    node *new_node = new node();
    new_node->data = roll;
    new_node->next = NULL;
    current_node->next = new_node;
  }
}
void print(){

  node *current_node = root;

  while(current_node != NULL){
    cout<<current_node->data<<endl;
    current_node = current_node->next;
  }

}

void delete_node( int roll ){
    node *current_node = root,
         *previous_node = NULL;

    while(current_node && current_node->data != roll){
      previous_node = current_node;
      current_node = current_node->next;
    }

    if(current_node==nullptr)   return; /// To check if the given no. exist in the linked list or not

    if(current_node==root){
      node *temp = root;
      root = root->next;
      delete(temp);
    }
    else{
      previous_node->next = current_node->next;
      delete(current_node);
    }

}

int main(){

  for(int i=1;i<=10;i++)
    append(i);

delete_node(3);

print();


return 0;
}
