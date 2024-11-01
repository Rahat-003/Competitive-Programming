#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

map<int,int> mp;
void word(string s){

  string a;

  for(int i=0;i<s.size();++i){
    char c= s[i];
    int d = c;
    if( (d>=65 && d<=90 )|| (d>=97 && d<=122) || c=='\'' || c=='-' ){
      if(c!='\'' && c!='-' )  a.push_back(c);
    }
    else{
      if(a.size())  mp[a.size()]++;
      a="";
    }

  }
}

void print(){
  for(auto it = mp.begin();it!=mp.end();++it)
    cout<<it->first<<" "<<it->second<<endl;
}


int main(){

//freopen("tst.txt","r",stdin);


string s,t="";
bool fl = false;

while(getline(cin,s)){
  if(s[0]=='#'){

  word(t);

  t="";

  print();

  cout<<endl;
  mp.clear();
  continue;
  }
  else {
  int sz = s.size()-1;
  if(s[sz]!='\'' && s[sz]!='-') s.push_back(' ');
  t.append(s);
}
}





return 0;
}
