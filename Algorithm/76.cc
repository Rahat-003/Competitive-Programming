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
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
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

int c2i(char p)
{
    int x = p - 'a';
    if(x>=0 && x<26)    return x;
    return 26 + p - 'A';
}

int sv[26*2];
int tv[26*2];

class Solution {
public:
    pair<int, int> leftRight(string s)
    {
        int svcpy [26*2];
        memcpy(svcpy, sv, sizeof svcpy);

        int start = left2right(s);
        int last = right2left(s);

        memcpy(sv, svcpy, sizeof svcpy);
        return make_pair(start, last);

    }

    pair<int, int> rightLeft(string s)
    {
        int svcpy [26*2];
        memcpy(svcpy, sv, sizeof svcpy);

        int last = right2left(s);
        int start = left2right(s);

        memcpy(sv, svcpy, sizeof svcpy);
        return make_pair(start, last);

    }

    int left2right(string s)
    {

        int start = 0;
        // left to right
        for (int i = 0; i < s.size(); i++)
        {
            start = i;
            if (sv[c2i(s[i])] > tv[c2i(s[i])])
            {
                sv[c2i(s[i])]--;
            }
            else
            {
                break;
            }
        }
        return start;
    }

    int right2left(string s)
    {
        int last = s.size() - 1;
        // right to left
        for (int i = s.size() - 1; i >= 0; i--)
        {
            last = i;
            if (sv[c2i(s[i])] > tv[c2i(s[i])])
            {
                sv[c2i(s[i])]--;
            }
            else
            {
                break;
            }
        }
        return last;
    }
    string minWindow(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            sv[c2i(s[i])]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            tv[c2i(t[i])]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (tv[c2i(t[i])] >     sv[c2i(t[i])])
            {
                return "";
            }
        }
        auto p1 = leftRight(s);
        auto p2 = leftRight(s);

        string a = s.substr(p1.first, p1.second - p1.first + 1);
        string b = s.substr(p2.first, p2.second - p2.first + 1);

        if (a.size() < b.size())
        {
            return a;
        }
        return b;
    }
};



main()
{
//read;



    Solution s;
    cout << s.minWindow("ab", "a") << "\n";





    return 0;
}

