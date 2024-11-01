#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};
node *root = NULL;

void append(int a){

node *nn,*cn;
  if(root==NULL){
    root = new node();
    root->data = a;
    root->next = NULL;
  }
  else{
  cn = root;
  while(cn->next!= NULL){
    cn = cn->next;
  }
  nn = new node();
  nn->data = a;
  nn->next = NULL;
  cn->next = nn;
  }
}

void print(){
  node *cn = root;
  while(cn!=NULL){
    cout<<cn->data<<" ";
    cn = cn->next;
  }

}
void dl(int a){
  node *pn,*cn,*tmp;
  cn = root;
  pn = NULL;
  while(cn->data != a){
    pn = cn;
    cn = cn->next;
  }
  if(cn==root){
    tmp = root;
    root = root->next;
    delete(tmp);
  }

  else{
    pn->next = cn->next;
    delete(cn);
  }

}

void add_after(int a,int b){

  node *new_node = new node(), *current_node = root,*tmp;
  new_node->data = b;
  new_node->next = NULL;

  while(current_node->data != a)
      current_node = current_node->next;

  tmp = current_node->next;
  current_node->next = new_node;
  new_node->next = tmp;
}

void add_before(int a,int b){
    node *new_node = new node(), *current_node = root, *tmp, *previous_node = NULL;
    new_node->data = b;
    new_node->next = NULL;
    while(current_node->data != a){
      previous_node = current_node;
      current_node = current_node->next;
    }
    if(current_node != root){
    previous_node->next = new_node;
    new_node->next = current_node;
    }
   else {

    new_node->next = root;
    root = new_node;
    }
}

int main(){

for(int i=1;i<10;i++){
  append(i);
}
print();
cout<<endl;
int a,b;

while(cin>>a>>b){
 /// add_after(a,b);
    add_before(a,b);
  print();
  dl (b);
  cout<<endl;
}

return 0;
}
