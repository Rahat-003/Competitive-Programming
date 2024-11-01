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
    node *next, *prev;
    node(int _val): val(_val), next(nullptr), prev(nullptr) {}
} *head, *tail;

void add(int data){
    node *newNode = new node(data);
    if(head==nullptr){
        head = newNode;
        head->next = nullptr;
        tail = head;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void display(){
    node *cur = head;

    // Forward Display
    printf("\n---Forward Display---\n");
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    printf("\n---Backward Display---\n");
    cur = tail;

    while(cur){
        cout << cur->val<< " ";
        cur = cur->prev;
    }
    cout << endl;
}

void delete_node(int data){
    node *cur = head, *prev = nullptr;

    while(cur && cur->val!=data){
        prev = cur;
        cur = cur->next;
    }

    if(cur==nullptr)    return;

    if(head==tail && cur==head){
        // Only 1 element left in linked list
        head = nullptr;
        tail = nullptr;
    }
    else if(cur==head){
        // First element of linked list
        head = cur->next;
        head->prev = nullptr;
    }
    else if(cur==tail){
        // Last element
        prev->next = nullptr;
        tail = prev;
    }
    else{
        // Middle element
        prev->next = cur->next;
        cur->next->prev = prev;
    }
    delete(cur);
}





int main(){
//read;

    head = nullptr;


    add(1);
    delete_node(3);
    display();



//    int n;
//    cin >> n;
//
//    for(int i = 0; i<n; i++){
//        int x;
//        cin >> x;
//        add(x);
//    }
//
//    display();

//    while(cin >> n){
//        if(n==0)   break;
//        delete_node(n);
//        display();
//        cout << endl;
//    }








    return 0;
}


