#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> frnd;
unordered_map<string,string> ar;

string f(string a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int main(){

int t;
cin>>t;
while(t--){
  int e;
  cin>>e;
vector<string> v;
    ar.clear();
    frnd.clear();
  while(e--){
    string a,b;
    cin>>a>>b;
    ar[a] = a;
    ar[b] = b;
    v.push_back(a);
    v.push_back(b);
  }
  for(int i=1;i<v.size();++i){
    string a,b;
    int fl = 0;
    if(i%2==1){
    a = v[i-1];
    b = v[i];
    if(frnd[a]==0)  frnd[a] = 1;
    if(frnd[b]==0)  frnd[b] = 1;
    string pa = f(a);
    string pb = f(b);

    if(pa!=pb){
    frnd[pa]+= frnd[pb];
    frnd[pb] = frnd[pa];
    ar[pa] = pb;
    if(frnd[ar[a]]> frnd[ar[b]])
        cout<<frnd[ar[a]]<<endl;
    else cout<<frnd[ar[b]]<<endl;
    fl = 1;
    }
    if(!fl) cout<<frnd[ar[a]]<<endl;
//    if(frnd[a]>frnd[b])    cout

    }

}
  }

return 0;
}
