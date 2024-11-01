
#include <cstdio>
#include <cstring>
using namespace std;
char s[105];
bool check(){
  int m=0;
  for(int i=0;s[i];i++)
    m=((m*10)+(s[i]-'0'))%17;
  return !m;
//  return true;
}
int main(){
while(scanf("%s",s)&&s[0]!='0'){
if(check())
  puts("1");
else
  puts("0");
}
return 0;
}
