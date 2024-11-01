#include <bits/stdc++.h>
#define prt_cs                  printf("Case %lld: ",cs)
#define sqr(x)                  (x)*(x)
#define ms(a,b)                 memset(a, b, sizeof(a))
#define db                      double
#define ll                      long long int
#define MOD                     100000007
#define PI                      acos(-1.0)
#define pii                     pair< int, int >
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               (((a)*(b))/gcd(a,b))
#define MAX                     10000005

using namespace std;

vector<ll> p;
bool mark[MAX];

void sieve()
{
    for(int i=4;i<MAX;i+=2)mark[i]=1;
    for(int i=3;i*i<MAX;i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<MAX;j+=2*i)
            {
                mark[j]=1;
            }
        }
    }
    p.push_back(1);
    p.push_back(2);
    for(int i=3;i<MAX;i+=2)
        if(!mark[i])p.push_back(i);
}

ll dp[MAX][2];

void solve(ll N,int player)
{
    if(N==1)
    {
        pp[player]++;
        return;
    }
    ll L=(ll)ceil(N/2.0);
//    ll L = (ll)ceil(N/2.0);
    ll k = lower_bound(p.begin(),p.end(),L)-p.begin();
    if(p[k]>L)k--;
    if(k<1)
        solve(N-1,player^1);
    for(int i=1;i<=k;i++)
            solve(N-p[i],player^1);
}


int main()
{
//    READ;
//    WRITE;
    sieve();
    int ts;
    scanf("%d",&ts);
    while(ts--)
    {
        ms(pp,0);
        ll N;
        scanf("%lld",&N);
        int ans=0;
        solve(N,0);
        if(pp[1]<pp[0])printf("first\n");
        else printf("second\n");
    }
    return 0;
}
