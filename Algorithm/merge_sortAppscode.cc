#pragma                         GCC optimize("O3","unroll-loops")
#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define sl(a)                   scanf("%lld",&a)
#define sll(a,b)                scanf("%lld %lld",&a,&b)
#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
#define rep(i,a,b)              for(ll i = a; i<=b;  i++)
#define un(x)                   x.erase(unique(all(x)), x.end())
#define TT                      long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
#define read                    freopen("output.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define infi                    0x3f3f3f3f
#define infl                    0x3f3f3f3f3f3f3f3f
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


void merge(vector<int> &v,int left,int mid,int right){
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for(int i = 0; i<n1; i++)   L[i] = v[left+i];
    for(int i = 0; i<n2; i++)   R[i] = v[mid+1+i];

    int i = 0,j = 0,k = left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        v[k++] = L[i++];
    }
    while(j<n2){
        v[k++] = R[j++];
    }
}



void mergeSort(vector<int> &v, int left,int right){
    if(left>=right) return;
    int mid = left + right >> 1;
    mergeSort(v,left,mid);
    mergeSort(v,mid+1,right);
    merge(v,left,mid,right);
}




int main(){
//read;

    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i<n; i++){
        int x;
         cin >> x;
         v.pb(x);
    }

    cout << endl;

    mergeSort(v,0,n-1);

    bool fl = 1;

    for(int i = 1; i<n; i++){
        if(v[i-1] > v[i]){
            fl = 0;
            break;
        }
    }


    puts(fl==0 ? "NO" : "YES");




    return 0;
}



