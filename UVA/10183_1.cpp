#include <bits/stdc++.h>
using namespace std;
#define MAX 483
vector<string> v(MAX);
vector<int> vv(MAX);
string sum(string a, string b){
  if(a.size()>b.size())
  swap(a,b);
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  string s="";
  int carry=0,ans;
  for(int i=0;i<a.size();i++){
     ans = (a[i] - '0') +(b[i] - '0') + carry;
     carry = ans/10;
     s.push_back(ans%10 + '0');
  }
  for(int i=a.size();i<b.size();i++){
     ans = (b[i] - '0') + carry;
     carry = ans/10;
     s.push_back(ans%10 + '0');
  }
  if(carry) s.push_back(carry + '0');
  reverse(s.begin(),s.end());
  return s;
}

string itos(int a){
  string s;
  stringstream ss;
  ss<<a;
  ss>>s;
  return s;
}


void fib(){
  v[0] = "0"; vv[1]=1;
  v[1] = "1"; vv[0]=1;
  for(int i=2;i<MAX;i++){

    v[i] =  sum( v[i-1] , v[i-2] );
    vv[i] = v[i].size();
  //  cout<<vv[i]<<" ";
  }

}
bool check(string a,string b){
  if(b==a)
    return true;
  if(b.size()>a.size())
    return true;
  for(int i=0;i<a.size();i++){

  }

  if(a.size()==b.size()){
    for(int i=0;i<a.size();i++){
      if( (a[i] + '0' ) )
    }
  }

}


int main(){
  //freopen("hi.txt","r",stdin);
fib();
int a,b;
while(cin>>a>>b){
  if(a==0 && b==0)  break;
  string sa = itos(a), sb = itos(b);
  int aa,bb;    aa = sa.size(); bb = sb.size();
  int xl = lower_bound(vv.begin(),vv.end(), aa ) - vv.begin();
  int xu = upper_bound(vv.begin(),vv.end(), aa+1 ) - vv.begin();

  for(int i = xl; i<xu;i++){
      if( check( v[i] , v[i+1]) )
  }

  int yl = lower_bound(vv.begin(),vv.end(), bb ) - vv.begin();
  int yu = upper_bound(vv.begin(),vv.end(), bb+1 ) - vv.begin();

}


return 0;
}
