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
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node *root;

void add(int x){
    if(root==NULL){
        root = new node(x);
    }
    else{
        node *cur = root;

        while(cur->next!=NULL){
            cur = cur->next;
        }
        node *tmp = new node(x);
        cur->next = tmp;
    }
}

void print(){
    node *cur = root;
    while(cur!=NULL){
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}

void del(int x){
    node *prv, *cur = root;

    if(root==nullptr)   return;
    if(cur->data==x){
        root = cur->next;
        delete cur;
    }
    else{
        while(cur && cur->data!=x){
            prv = cur;
            cur = cur->next;
        }
        if(cur==nullptr)    return;
        prv->next = cur->next;
        delete(cur);
    }

}

void reverse(){
    node *prev = nullptr, *cur = root;

    if(cur==nullptr)   return;

    while(cur){
        node *nxt = cur->next;
        // cur->next ta save kore rakhthe hbe ekta pointer variable *nxt diye
        // *tmp = cur rekhe, pore cur = tmp->next dile hobe na, karon cur->next = prev assign korar sathe sathei
        // tmp->next o change hoye gese



        cur->next = prev;

        prev = cur;
        cur = nxt;
    }
    root = prev;
}


int main(){
//read;

    for(int i = 1; i<=10; i++){
        add(i);
    }

    for(int i = 1; i<=20; i+=2)     del(i);

    reverse();

    print();

//    add(1);
//    add(6);
//    add(7);
//    add(3);
//    add(9);
//
//    del(7);
////    add(5);
//
//    print();
//
//    reverse();
//
//    print();






    return 0;
}


