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
    int x;
    node* next;
    node(int a){
        x = a;
        next = NULL;
    }
};


node* root = NULL;

void insertFirst(node* &head,int val){
    if(head==NULL){
        head = new node(val);
        return;
    }
    node *cur = new node(val);
    cur->next = head->next;
    head = cur; // head pointer er reference neya lagbe. karon originally root ke change kora lagbe.

    /** Or
        node *cur = new node(val);
        cur->next = root->next;
        root = cur;
//    */

}

void insertLast(node* head,int val){
    if(root==NULL){
        root = new node(val);
        return;
    }
    node* n = new node(val);
    node* tmp = head;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = n;

//    n->x = val;
//    n->next = NULL;
}

void print(node* head){
    if(head==NULL)    return;
    cout << head->x << " ";
    print(head->next);
}


void del(int val){
    node* cur_node = root, *prev_node = NULL;
    while(cur_node->x!=val){
        prev_node = cur_node;
        cur_node = cur_node->next;
    }
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


// Reversing a LinkedList
void rev(){
    node *cur = root, *next = NULL, *prev = NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
}

main(){
//read;


    for(int i = 1; i<10; i++){
        insertLast(root,i);
    }
    insertFirst(root,-13);
    del(6);
    print(root);
    cout << endl;
    rev();
    print(root);
    cout << endl;



    return 0;
}



