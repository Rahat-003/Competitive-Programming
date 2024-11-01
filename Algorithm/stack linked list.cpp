#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *prev,*next;
};
node *root,*tail;
//int top;

void push(int a){
  node *nn;
  if(root==NULL){
    root = new node();
    root->data = a;
    root->prev = NULL;
    root->next = NULL;
    tail = root;
  }
  else{
    nn = new node();
    nn->data = a;
    nn->prev = tail;
    nn->next = NULL;
    tail->next = nn;
    tail = nn;
  }
}
void pop(){
  node *tmp = tail->prev;
  tmp->next = NULL;
  delete(tail);
  tail = tmp;
}

int top(){
  return tail->data;
}
void print(){
  node *current_node = root;
  while(current_node != NULL){
    cout<<current_node->data<<" ";
    current_node = current_node->next;
  }
  cout<<endl;
}

int main(){

for(int i = 1;i<10;i++)
  push(i);

print();
cout<<top()<<endl;
pop();
print();
cout<<top()<<endl;

return 0;
}
