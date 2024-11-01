#include <bits/stdc++.h>
using namespace std;
char s[1000005];
string normal = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
string dvorak = "`123qjlmfp/[]456.orsuyb;=789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";

char func(char c){
  if(c=='\\')  return c;
//  char d;
  for(int i=0;i<normal.size();++i){
    if(c==normal[i])
      return dvorak[i];
  }
}

int main(){
//  freopen("tst.txt","r",stdin);
//  freopen("tt.txt","w",stdout);


while(gets(s)){
    string ans;
  for(int i=0; s[i] ;++i){

    char c = func(s[i]);
    ans.push_back(c);
  }
  cout<<ans<<endl;

}


return 0;
}

