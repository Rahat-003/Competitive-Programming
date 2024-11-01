#include <stdio.h>
#include <string.h>
using namespace std;
char s[200005];

bool is_palin(int a,int b){
  while(a<b){
    if(s[a]!=s[b-1])  return false;
    a++;  b--;
  }
  return true;
}

int main(){
// freopen("test.txt","r",stdin);
int t;
scanf("%d",&t);
while(t--){
  scanf("%s",s);
//  puts(s);
  bool palin = false;
  bool alin = false;
  int sz = strlen(s);
  for(int i=0;i<sz-1;++i){

    if(s[0]==s[i] && s[i+1]==s[sz-1]){
      if(!is_palin(0,i+1))
        continue;
      if(!is_palin(i+1,sz))
        continue;
      puts("alindrome");
      alin = true;
      break;
    }
  }
  if(!alin){
  if(is_palin(0,sz)) puts("palindrome");
  else puts("simple");
}
}
return 0;
}
