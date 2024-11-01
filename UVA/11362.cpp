#include <bits/stdc++.h>
using namespace std;

struct node{
  bool flag;
  node *pa[9+1];   ///Extra one element for root node.
  node(){
    flag = false;
    for(int i=0;i<=9;i++)
      pa[i] = NULL;
  }
} *root;

void insert(string s){
  node *current = root;
  for(int i=0;i<s.size();i++){
    int id = s[i] - '0';
    if(current->pa[id]==NULL)
      current->pa[id] = new node();
    current = current->pa[id];
  }
current->flag = true;
}
void del(node *current){
  if(current==NULL)
  return ;

  for(int i=0;i<=9;i++){

  if(current!=NULL)
    del(current->pa[i]);

  }
  delete(current);
}
bool check(string s){
  node *current = root;
  for(int i=0;i<s.size();i++){
    int id = s[i] - '0';
    current = current->pa[id];
  }
  bool a = false;
  for(int j=0;j<10;++j){
    if(current->pa[j]!=NULL){
      a= true;
      break;
    }
  }
  return a;
}

int main(){

vector<string> v;

int t;cin>>t;

while(t--){
root = new node();
 int d; cin>>d;
 while(d--){
  string s;
  cin>>s;   v.push_back(s);
  insert(s);
 }
bool ojib = true;
for(int i=0;i<v.size();i++){
  //node *ptr = check(v[i]);
  if(check(v[i])){
    ojib = false;
    break;
  }
}
if(ojib) cout<<"YES\n";
  else cout<<"NO\n";
del(root);
v.clear();
}

return 0;
}
