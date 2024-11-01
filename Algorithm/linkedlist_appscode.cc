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
#define read                    freopen("input.txt","r",stdin)
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


struct node{
    int val;
    node *next;
    node(int _val): val(_val), next(nullptr) {};
} *root;


void add(int data) {
    node *newNode = new node(data);
    if(root==nullptr){
        root = newNode;
        return;
    }
    node *tmp = root;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void display(){
    node *tmp = root;
    printf("\n---------Display---------\n");
    while(tmp){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    printf("---------Display---------");

    cout << endl;
}

void delete_node(int data){
    node *cur_node = root, *prev_node = nullptr;

    while(cur_node && cur_node->val!=data){
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

//    cout << cur_node << endl;
    if(cur_node==nullptr)   return;

    if(cur_node==root){
        node *tmp = root;
        root = root->next;
        delete(tmp);
    }
    else{
        prev_node->next = cur_node->next;
        delete(cur_node);
    }
}


int main(){
//read;

    root = nullptr;
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        add(x);
    }

    display();

    cin >> n;

    delete_node(n);

    display();




    return 0;
}

