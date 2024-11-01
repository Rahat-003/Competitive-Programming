#include <bits/stdc++.h>
using namespace std;

void func(string s){
  s.insert(0,"q");
  string ans;
  string x;
  vector<string> v;
  int sp = 0, tb = 0;
  for(int i=1;i<s.size();++i){
    int c = s[i];
    int d = s[i-1];
    if( (c==32 && d==32) ) continue;
    else ans.push_back(s[i]);


  }
  //ans = f(ans);
  cout<<ans<<endl;

}


int main(){
  /*
  freopen("tst.txt","r",stdin);
  freopen("t.txt","w",stdout);
*/
int T;
cin>>T;
bool fl = false;
for(int tc=1;tc<=T;++tc){
  int t;
  cin>>t;
  if(fl)  cout<<endl;
  fl = true;
  printf("Case %d:\n",tc);

    cin.ignore();
    while(t--){
    string s;
    getline(cin,s);
    //string ans =
     func(s);
    //cout<<ans<<endl;
  }


}






return 0;
}
