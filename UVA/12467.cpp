
#include <stdio.h>
#include <string.h>
using namespace std;
#define mx 1000005
char s[mx],r[mx];
int ar[mx];
void make_ar(int sz){
  int i=0,j=0;
  int imx = 0;
  while(j<sz){
    if(r[j]==s[i]){
      j++;
      ar[j] = i;
      i++;
      //cout<<i<<" ";
      if(imx<=i)  imx = i;
    }
    else{

      if(i!=0)  i = ar[i-1];

      else {
        ar[j] = 0;
        j++;
      }

    }

  }
  if(!imx)  imx+=1;
  for(int k = imx-1;k>=0;k--)
    printf("%c",s[k]);

  printf("\n");


}

int main(){

  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%s",s);
    int sz = strlen(s);
    for(int i = 0; i<sz;++i)
      r[i] = s[sz-1-i];

    make_ar(sz);

  }

return 0;
}
