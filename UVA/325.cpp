
#include <bits/stdc++.h>
using namespace std;

bool check2(int x,string s){

  if(s[x]=='.') return false;

  for(int i=x;i<s.size()-1;i++){
    char c = s[i];
    if(i!=x && (c=='+' || c=='-' || c=='.') ) return false;
  }

  for(int i=0;i<x; i++){
    char c = s[i];
    if(i && (c=='+' || c=='-')) return false;
   // if(c=='e' || c=='E')  break;
  }


  return true;

}
bool check4(string s){
  int i;
  bool fl = false;
  for(i=0;i<s.size()-1; i++){
  char c = s[i];
    if(s[i]=='.') fl = true;
  if(i && (c=='+' || c=='-')) return false;

  }

  if(i==s.size()-1 && !fl)  return false;

  return true;
}

bool check3(int x,string s){
  for(int i=0;i<x; i++){
    char c = s[i];
    if(i && (c=='+' || c=='-')) return false;
    if(c=='e' || c=='E')  break;
  }
    return true;
}


bool check(string s){
    s.push_back('p');
    int e = -1, sz = s.size()-1;
    if(!isdigit(s[sz-1])) return false;
    int ne = 0;
    int dgt = 0,i;
    int idc = -1, ndc=0;

    for(i=0;i<s.size()-1; i++){
      char c = s[i];

      if(!isdigit(c) && c!='+' && c!='-' && c!='.' && c!='e' && c!='E')  return false;

      if(c=='e' || c=='E'){
        if(!isdigit(s[i+1]) && s[i+1]!='+' && s[i+1]!='-')  return false;
        e = i;
        ne++;
        if(ne>1)  return false;
        if( !check2(i+1,s)) return false;
      }

      if(isdigit(c))  dgt++;
      if(c=='.'){
        ndc++;
        if(!check3(i,s) || !isdigit(s[i+1])  ) return false;
        if(ndc>1 || !i || i==sz-1) return false;
        idc = i;
      }
      if(!isdigit(s[i]) && !isdigit(s[i+1]) && !i )  return false;

    }

    if(!e || s[e+1]=='p' || dgt==sz )  return false;

    if(e==-1  && !check4(s) )   return false;







return true;
}



string f(string s){
  int i,j;
  for( i=0;i<s.size();i++)
    if(s[i]!=' ') break;

  for( j=s.size()-1; j>=0;j--){
    if(s[j]!=' ') break;
  }
  s = s.substr(i,j-i+1);
  return s;

}

int main(){

  //freopen("tst.txt","r",stdin);

string s;
while(getline(cin,s)){

  string inp = f(s);
  if(inp[0]=='*' && inp.size()==1) break;


  bool a = check(inp);

  cout<<inp<<" is ";
  if(a) puts("legal.");
  else puts("illegal.");


}








return 0;
}
