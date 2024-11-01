#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;

void letter(string s){
  for(int i=0;i<s.size();++i){
    char c = s[i];
    int d = c;
    if(d>=97 && d<=122)
      mp[c] = c - 'a' + 1;
  }
}

int main(){

string s;

while(getline(cin,s)){
  if(!s.size()) break;
  letter(s);

}









return 0;
}
