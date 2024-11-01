#include <iostream>
using namespace std;
int GCD(int i ,int j){
while (i!=j){
if(i>j)
    i-=j;
else j-=i;
}
return i;
}


int main()
{
int N;
while(cin>>N&&N){
int i,j,G=0;
for(i=1;i<N;i++)
for(j=i+1;j<=N;j++)
{
G+=GCD(i,j);
}
cout<<G<<endl;
}

return 0;

}
