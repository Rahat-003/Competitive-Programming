#include <stdio.h>
#include <string.h>
#include <memory.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;


#define mx 102
ll dp[mx];

int fn(int x){
    if(x==0)    return 0;
    return x+fn(x-1);
}
char ar[30];

main(){
//read;
char a[] = "faa",b[102];
strcpy(b,a);
strrev(b);
puts(b);

return 0;
}
