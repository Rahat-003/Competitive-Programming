#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v,u;
unordered_map<ll,ll> fb;

void make(){

ll fib = 1;
v.push_back(1);
v.push_back(2);
fb[1] = 1;
fb[2] = 2;

ll id = 2;
while(true){

  fib = v[v.size()-1] + v[v.size()-2];
  fb[fib] = ++id;
  v.push_back(fib);
  if(fib> pow(2,32) ) break;

}


}

string cut(string s){
  int i;
  for(i=s.size()-1; i>=0; i--)
    if(s[i]!=' ') break;

  s = s.substr(0,i+1);
  return s;

}



int main(){


make();

int tc;
 cin>>tc;

  while(tc--){
    int a;
    cin>>a;

    cin.ignore();

    string b;
    getline(cin,b);

  istringstream iss(b);
  while(a--){
    ll c;
    iss>>c;
    u.push_back(c);
  }

  string s;

  getline(cin,s);

  string ans(203,' ');
  ll id = 0;
  for(int i = 0;i<s.size(); i++){
    int c = s[i];
    char d = c;
    if(c>=65 && c<=90){
      ll n = u[id];
      ans[ fb[n] - 1 ] = d;
      id++;
    }
    if(id==u.size())  break;
  }

  ans = cut(ans);
  cout<<ans<<endl;
  u.clear();

 }







return 0;
}
