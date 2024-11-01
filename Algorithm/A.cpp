#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define MAX 1000005


bool mark[MAX];
vector<int> p;
map<int,int> mp;
int A[MAX],sz;


void sieve()
{
    for(int i=4;i<MAX;i+=2)mark[i]=1;
    for(int i=3;i*i<MAX;i+=2)
    {
        if(!mark[i])
        for(int j=i*i;j<MAX;j+=2*i)
        {
            mark[j]=1;
        }
    }
    p.push_back(2);
    for(int i=3;i<MAX;i+=2)if(!mark[i])p.push_back(i);
//    for(int i=0;p[i]<100;i++)
//        cerr<<p[i]<<endl;
}

int nod(int n)
{
    if(n==1)return 1;
    if(!mark[n])return 2;
    int x=n;
    int cnt=1;
    for(int i=0;p[i]<sqrt(n)+1 && i<p.size();i++)
    {
        int k=0;
        while(x%p[i]==0)
        {
            k++;
            x/=p[i];
        }
        cnt*=(k+1);
    }
    if(x>2)
        cnt*=2;
    return cnt;
}

void gen_res()
{
    A[0]=1;
    A[1]=2;
    for(int i =2;i <100000;i++)
    {
        A[i]=A[i-1]+nod(A[i-1]);
//        sz++;
        if(A[i]>1000000)
        {
            sz=i;
            break;
        }
    }
//    for(int i=0;A[i]<=100;i++)
//    {
//        cerr<<A[i]<<endl;
//    }
}

main(){
//read;
sieve();
gen_res();
int ts;
cin>>ts;
for(int cs=1;cs<=ts;cs++)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int k=lower_bound(A,A+sz,a)-A;
    int l=upper_bound(A,A+sz,b)-A;
    printf("Case %d: %d\n",cs,(l-k));
}



return 0;
}


