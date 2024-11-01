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
    node *next, *prev;
    node(int _data){
        data = _data;
        next = nullptr;
        prev = nullptr;
    }
};

node *head, *tail;

void add(int val){
    node *newNode = new node(val);
    if(head==nullptr){
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void print(){
    node *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
}

void del(int val){
    node *cur = head, *prev;

    while(cur && cur->data!=val){
        prev = cur;
        cur = cur->next;
    }

    if(cur==nullptr)    return;

    if(cur==head && head==tail){
        /// Only 1 element in linklist
        head = nullptr;
        tail = nullptr;
    }
    else if(cur==head){
//        puts("HI");
        head = cur->next;
        head->prev = nullptr;
    }
    else if(cur==tail){
        prev->next = nullptr;
        tail = prev;
    }
    else{
        /// middle element
        prev->next = cur->next;
        cur->next->prev = prev;
    }

    delete cur;
}


int main(){
//read;

//    for(int i = 1; i<=10; i++)  add(i);

    add(1);
    add(2);

    del(1);
    del(2);

    print();







    return 0;
}


