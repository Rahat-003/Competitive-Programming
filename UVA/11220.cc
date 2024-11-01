#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;

cin.ignore();
cin.ignore();

bool fl = false;
for(int tc=1;tc<=t;++tc){
    if(fl)  cout<<endl;
  fl = true;
  string s,ans,t;
  while(getline(cin,s)){
    if(s.size()==0)   break;
    t = " ";
    t= t+s;
    t.push_back(' ');
    int i1=0,x,y;
    for(int i=0;i<t.size();++i){
      if(t[i]==' '){
        string b;
        x=i+1;
      if(t[x]!=' '){
      for(int j=x;j<t.size();++j){
        if(t[j]==' '){
          y = j-1;
          b = t.substr(x,j-x);
          break;
        }
      }
      if(i1<b.size() && x<=y){
        ans.push_back(b[i1]);
        i1++;
        b="";
      }
      }
      }
    }
    ans.push_back('\n');
  }

  printf("Case #%d:\n",tc);
  cout<<ans;


}





return 0;
}
