#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ar;

#define num 256

void make_ar(string s){
    ar[0][s[0]] =1;
  int lps = 0;
  for(int i=1;i<ar.size();++i){
    for(int j=0;j<num;++j)
      ar[i][j] = ar[lps][j];
    ar[i][s[i]] = i+1;
    cout<<lps<<" ";
    if(i<s.size())
      lps = ar[lps][s[i]];
  }
cout<<endl;
}

void search(string t,string p){
  int j=0;
  for(int i=0;i<t.size(); ++i){
    j = ar[j][t[i]];
    if(j==p.size())
      cout<<"found at "<<i-j+1<<endl;
  }
}

int main(){

string txt,pat;
cin>>txt>>pat;
ar.assign(pat.size()+1, vector<int>(num,0));
make_ar(pat);
search(txt,pat);



return 0;
}
