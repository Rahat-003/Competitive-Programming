#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next, *prev;
};
node *root,*tail;

void append(int a){
  node *new_node;

  if(root==NULL){
    root = new node();
    root->data = a;
    root->next = NULL;
    root->prev = NULL;
    tail = root;
  }
  else{
    new_node = new node();
    tail->next = new_node;
    new_node->data = a;
    new_node->next = NULL;
    new_node->prev = tail;
    tail = new_node;
  }

}

void print(){
  node *current_node = root;
  while(current_node!= NULL){
    cout<<current_node->data<<" ";
    current_node = current_node->next;
  }
  cout<<endl;
}


int main(){
    int x;
    for(int i=1;i<10;i++)
        append(i);



    print();

return 0;
}
