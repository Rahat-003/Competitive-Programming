#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;


vector<int> vv;

void fn(int x)
{
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            vv.push_back(i);
            vv.push_back(x/i);
        }
    }
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
}


main(){
//read;

int a,b,q,g;
cin>>a>>b>>q;
g = __gcd(a,b);
fn(g);
//for(int i=0;i<vv.size();i++)
//    cerr<<vv[i]<<" ";
//cerr<<endl;
while(q--)
{
    int L,R;
    cin>>L>>R;
    int i = lower_bound(vv.begin(),vv.end(),L)-vv.begin();
    int j = upper_bound(vv.begin(),vv.end(),R)-vv.begin();
    if(j-i>0)
    {
        cout<<vv[j-1]<<endl;;
//        printf(vv[j-1]")
    }
    else printf("-1\n");
}



return 0;
}


