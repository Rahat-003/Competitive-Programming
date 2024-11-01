#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:\n",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("outpt.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100001
typedef pair<int,int> pp;

int block;

struct node{
    int l,r,id;
    bool operator < (const node &N) const{
        int b1 = 1+l/block,   b2 = 1+N.l/block;
        if(b1!=b2)  return b1<b2;
        if(b1&1)    return r<N.r;
        return r>N.r;
    }
};
vector<pp> query;
vector<node> v;
vector<int> ar;
int cnt[mx],n;

int add(int id){
    int ans = 0;
    cnt[ar[id]]++;
    if(cnt[ar[id]]==1)  ans++;
    return ans;
}
int remove(int id){
    int ans = 0;
    --cnt[ar[id]];
    if(cnt[ar[id]]==0)  --ans;
    return ans;
}

void fn(){
    int AL = 0,AR = 0,ans = 1;
//    cout<<endl;
    cnt[ar[0]]++;

    for(int i = 0; i<v.size(); i++){
        int l = v[i].l,r,id;
            r = v[i].r, id = v[i].id;

            while(true){
                if(AL==l && AR==r)  break;
                if(AL<l){
                    ans+=remove(AL);
                    AL++;
                }
                if(AL>l){
                    AL--;
                    ans+=add(AL);
                }
                if(AR<r){
                    AR++;
                    ans+=add(AR);
                }
                if(AR>r){
                    ans+=remove(AR);
                    AR--;
                }
            }
            query.push_back({id,ans});
    /*
        for(int j = 1; j<n; j++)
            cout<<j<<" "<<cnt[j]<<"\n";
        cout<<ans<<endl;
    cout<<endl<<endl;
    */
    }
    sort(query.begin(),query.end());
}


int main(){
//read;
//write;
int t,tc = 0;
scanf("%d",&t);
while(t--){
    int e;
    memset(cnt,0,sizeof cnt);
    scanf("%d%d",&n,&e);
    block = sqrt(n);
    ar = vector<int> (n);
    for(int i = 0; i<n; i++)    scanf("%d",&ar[i]);

    for(int i = 0; i<e; i++){
        int l,r;
        scanf("%d%d",&l,&r);
        --l;    --r;
        v.push_back({l,r,i});
    }

    sort(v.begin(),v.end());

    fn();
    case;
    for(int i = 0; i<query.size(); i++)
        printf("%d\n",query[i].second);
    query.clear();
    v.clear();
}



return 0;
}


