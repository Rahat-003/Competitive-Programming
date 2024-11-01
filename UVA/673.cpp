#include <bits/stdc++.h>
using namespace std;
int main(){
 /* freopen("673.txt","r",stdin);
  freopen("print.txt","w",stdout);
*/
int t;  cin>>t;
  cin.ignore();
while(t--){
  stack<char> stk;
  string s;
  getline(cin,s);
      int i=0;
  for( i=0;i<s.size();i++){
    if(s[i]=='[' || s[i]=='(')
        stk.push(s[i]);
    else if(s[i]==')'){
      if(stk.empty()) break;
      char c1 = stk.top();
      if(c1=='(') stk.pop();
      else break;
    }
    else if(s[i]==']'){
      if(stk.empty()) break;
      char c2 = stk.top();
      if(c2=='[' ) stk.pop();
      else break;
    }
  }
  if(i==s.size() && stk.empty()) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}


return 0;
}
