#include <bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next,*prev;
};
node *root,*tail;
int front;
void push(int a){
  node *nn;
  if(root==NULL){
    root = new node();
    root->data = a;
    root->prev = NULL;
    root->next = NULL;
    tail = root;
    front = root->data;
  }
  else{
    nn = new node();
    nn->data = a;
    tail->next = nn;
    nn->prev = tail;
    nn->next = NULL;
    tail = nn;
  }
}
void print(){
  node *current_node = root;
  while(current_node!=NULL){
    cout<<current_node->data<<" ";
    current_node = current_node->next;
  }
  cout<<endl;
}
void pop(){
  node *tmp = root->next;
  delete(root);
  root = tmp;
  root->prev = NULL;
  front = root->data;
}

int main(){
for(int i=1;i<10;i++)
  push(i);

print();
cout<<front<<endl;;
pop();
print();
cout<<front<<endl;

return 0;
}
