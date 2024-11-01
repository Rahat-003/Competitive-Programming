#include <bits/stdc++.h>
using namespace std;

#define mx 1e5+3
vector<int> ar;


void make_ar(){
  for(int i=0;i<ar.size();++i)
  ar[i] = i;
}

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int main(){
//  freopen("tst.txt","r",stdin);
int a,b;

int cnt=0;
ar.assign(mx,0);
make_ar();

string s;

while(getline(cin,s)){
  if(!s.size()) continue;

    istringstream iss(s);
    iss>>a;

  if(a==-1) {
  cout<<cnt<<endl;

  make_ar();
    cnt=0;
    continue;
  }

  iss>>b;

  int px = f(a);
  int py = f(b);

  if(px!=py)
    ar[py]=px;
  else cnt++;

}



return 0;
}
