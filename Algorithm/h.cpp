#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define MAX     1000005


vector<int> v;

int mark[MAX];

void fn(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
//            if(!mark[i])
//            {
                v.push_back(i);
                mark[i]=1;
//            }
//            if(!mark[n/i])
//            {
                v.push_back(n/i);
                mark[n/i]=1;
//            }
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}

main(){
//read;


int n;
cin>>n;
fn(n);
//cerr<<v.size()<<endl;
vector<int> ans;
for(int i=v.size()-1;i>=0;i--)
{
    int ok=1;
    for(int j=0;j<ans.size();j++)
    {
        if(ans[j]%v[i]!=0)
        {
            ok=0;
            break;
        }
    }
    if(ok)ans.push_back(v[i]);
}
sort(ans.begin(),ans.end());
for(int i=ans.size()-1;i>=0;i--)
{
    cout<<ans[i]<<" ";
}
cout<<endl;

return 0;
}


