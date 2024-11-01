#include <bits/stdc++.h>
using namespace std;

map<char,vector<char> > mp;

int main(){
  //freopen("12582.txt","r",stdin);
int z;  cin>>z;
for(int tc=1;tc<=z;tc++){
    stack<char> st;
  mp.clear();
  string s;
  cin>>s;
  st.push(s[0]);
  for(int i=1;i<s.size();i++){
    char n = s[i];
    char tp = st.top();
    if(n!=tp){
      mp[tp].push_back(n);
      mp[n].push_back(tp);
      st.push(n);
    }
    else{
      st.pop();
    }
  }
  printf("Case %d\n",tc);
  for(auto it = mp.begin();it!=mp.end();++it){
    cout<<it->first<<" = "<<mp[it->first].size()<<endl;
   // mp[it->first].clear();
  }
}


return 0;
}
