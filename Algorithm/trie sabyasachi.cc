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
#define MAX                     1005
#define ROOT                    0
using namespace std;

int trie[MAX][26],mark[MAX];//For 'a' to 'z'
string key;
int sz=0;

void insert_trie(string key)
{
    int root=ROOT,idx;
    for(int i=0;i<key.size();i++)
    {
        idx=key[i]-'a';
        if(trie[root][idx]==-1)
        {
            trie[root][idx]=++sz;
        }
        root=trie[root][idx];
    }
    mark[root]=1;
}

bool search_trie(string key)
{
    int root=ROOT,idx;
    for(int i=0;i<key.size();i++)
    {
        cerr<<"root: "<<root<<endl;
        idx=key[i]-'a';
        if(trie[root][idx]==-1)
        {
            return false;
        }
        root=trie[root][idx];
    }
    return mark[root];
}

int main()
{
//    READ;
//    WRITE;
    ms(mark,0);
    ms(trie,-1);
    insert_trie("cat");
    insert_trie("hello");
    insert_trie("okay");
    cout<<search_trie("hi")<<endl;
    cout<<search_trie("hello")<<endl;
    cout<<search_trie("cat")<<endl;
    cout<<search_trie("catch")<<endl;

    return 0;
}
