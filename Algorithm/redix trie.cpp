#include <bits/stdc++.h>
using namespace std;

struct node{
  bool flag;
  node *child[26+1];
  node(){
  flag = false;
  for(int i=0;i<26;++i){
    child[i] = NULL;
  }
  }
};
node *root;

void insrt(string s){
  node *cn = root;
  for(int i=0;i<s.size();i++){
    int id = s[i] - 'a';
    if(cn->child[id]==NULL)
      cn->child[id] = new node();

    cn = cn->child[id];
  }
  cn->flag  =true;
}

bool srch(string a){
  node *cn = root;
  for(int i=0;i<a.size();++i){
    int id = a[i] - 'a';
    if(cn->child[id]==NULL)
      return false;
    cn = cn->child[id];
  }
return cn->flag;

}


int main(){
  root = new node;
int t;
cin>>t;
while(t--){
  string s;
  cin>>s;
  insrt(s);
}
int tt; cin>>tt;
while(tt--){
  string s;
  cin>>s;
  if(srch(s))
    cout<<"found \n";
  else cout<<"Not found\n";
}


return 0;
}
