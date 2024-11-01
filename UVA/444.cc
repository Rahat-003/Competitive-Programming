#include <bits/stdc++.h>
using namespace std;
vector<char> ch;
vector<int> in;
vector<int> num = {0,1,2,3,4,5,6,7,8,9};
int main(){
for(int i=0;i<26;++i){
  ch.push_back('a'+i);
  in.push_back(97+i);
  ch.push_back('A'+i);
  in.push_back(65+i);
}
string symbol = "!, .:;?" ,s;
for(int i=0;i<symbol.size();++i){
  int x = symbol[i];
  char c = x;
  ch.push_back(c);
  in.push_back(x);
}
while(getline(cin,s)){
  string ans;
  int m =0;
  for(int i=s.size()-1;i>=0;--i){
    int x = s[i];
    if(x>=48 && x<=57){      ///ASCII value of 0 is 48 and ASCII value of 9 is 57.
      m = 10*m + s[i]- '0';
      auto it = find(in.begin(),in.end(),m);
      if(it!=in.end()){
        for(int j=0;j<in.size();++j){
          if(in[j]==m){
            char d = m;
            ans.push_back(d);
            m=0;
            break;
          }
        }
      }

    }
    else{
      string p;
      stringstream ss(p);
      ss<<x;
      p = ss.str();
      reverse(p.begin(),p.end());
      ans+= p;
    }

  }
  cout<<ans<<endl;

}




return 0;
}
