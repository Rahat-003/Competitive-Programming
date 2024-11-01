#include <bits/stdc++.h>
using namespace std;

struct node {
  bool flag;
  node *pa[26+1];    ///pointer array of node data type. And Extra one element for root node.
  node(){
    flag = false;
    for(int i=0;i<26;i++)
      pa[i] = NULL;
  }
};
node *root;

void insert(string s){
    node *current_node = root;

    for(int i = 0;i<s.size();i++){
      int id = s[i] - 'a';

      if(current_node->pa[id]==NULL)
        current_node->pa[id] = new node();
        current_node = current_node->pa[id];
    }
    current_node->flag = true;
}

bool search(string s){
  node *current_node = root;
  for(int i=0;i<s.size();i++){
    int id = s[i] - 'a';
    current_node = current_node->pa[id];
    if(current_node==NULL){
      return false;
//      break;
    }
  }
return current_node->flag;
}

void del(node *current){
  if(current==NULL) return;

  for(int i=0;i<26;i++)
    del(current->pa[i]);

  delete(current);
}

int main(){
    root = new node();

int t;  cin>>t;
while(t--){
  string s; cin>>s;
  insert(s);
}
int tt; cin>>tt;
while(tt--){
  string s; cin>>s;
  if(search(s)) cout<<"Found";
  else cout<<"Not found";
  cout<<endl;
}

return 0;
}
