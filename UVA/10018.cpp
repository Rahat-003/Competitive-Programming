#include <bits/stdc++.h>
using namespace std;

bool check(string s){
  int j = s.size()-1;
  for(int i=0;i<s.size();++i){
    if(s[i]!=s[j]){
      return false;
    }
    j--;
  }
  return true;
}

string sum(string a, string b){
    if(a.size()>b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int c=0,ans;
    string ss;
    ss.clear();
    for(int i=0;i<a.size();i++){
        ans=(a[i]-'0')+(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
    for(int i=a.size();i<b.size();++i){
         ans=(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
if(c) ss.push_back(c+'0');
reverse(ss.begin(),ss.end());
return ss;
}

int main(){
int t;
cin>>t;
while(t--){
  string s;
  cin>>s;
  int cnt = 0;
  while(!check(s)){
    cnt++;
    string t = s;
    reverse(t.begin(),t.end());
    s = sum(s,t);
  }
cout<<cnt<<" "<<s<<endl;
}
return 0;
}
