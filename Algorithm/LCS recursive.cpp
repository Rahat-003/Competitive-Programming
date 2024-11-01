#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;



int dp[1005][1005];
char a[1005],b[1005];
int o = 0;

void p(){

      for(int i=0;i<3;++i){
         for(int j=0;j<3;++j)
            cout<<dp[i][j]<<" ";
         cout<<endl;
      }
   cout<<endl;
}


int lcs(int x,int y){
   cout<<"\n\t"<<x<<" "<<y<<endl;
   if( x==strlen(a)||y==strlen(b) )
     return 0;

   if(dp[x][y]!=-1)
//      int a;
      return dp[x][y];

   else if(a[x]==b[y])
      dp[x][y] = 1+lcs(x+1,y+1);

   else{
      int d = lcs(x+1,y), e = lcs(x,1+y) ;
     dp[x][y] = max(d,e);
   }

   return dp[x][y];
}

int main()
{
   while(scanf("%s %s",&a,&b))
   {
      memset(dp,-1,sizeof(dp));
      int ret=lcs(0,0);
      printf("%d\n",ret);
   p();
//   cout<<strlen(a);
   }
}
