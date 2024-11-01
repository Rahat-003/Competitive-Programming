#include <bits/stdc++.h>
using namespace std;

string f(string s){
  int i = 0;
  for(i = 0;i<s.size(); i++)
    if(s[i]!='0') break;
  string m = s.substr(i);
  return m;
}

string sum(string a,string b){
  string ans;
  if(a.size()<b.size()) swap(a,b);
  int s,carry = 0;
  for(int i=a.size()-1, j = b.size()-1; i>=0 || j>=0; i--, j--){
    int x = a[i] - '0';
    if(j>=0){
    int y = b[j] - '0';
      s = x+y+carry;
      /*
      if(s>9)
      else carry = 0;
      */ carry = s/10;
      char c = s%10 + '0';
      ans.push_back(c);
    }
    else{
      s = x+carry;
      /*
      if(s>9)
      else carry = 0;
      */
      carry = s/10;
      char c = s%10 + '0';
      ans.push_back(c);
    }

  }
  if(carry) ans.push_back(carry + '0');
  reverse(ans.begin(),ans.end());

  return ans;


}

int main(){




string m,n;
vector<string> v;
while(cin>>m){
  if(m=="0")  break;
  v.push_back(m);
}

  string x = v[0],ans;
for(int i=1;i<v.size(); i++){
  string y = v[i];
  x = f(x);
  y = f(y);
  ans = sum(x,y);
  x = ans;
}

ans = f(ans);
cout<<ans<<endl;


return 0;
}

