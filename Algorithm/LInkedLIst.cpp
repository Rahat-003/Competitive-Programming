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



struct node
{
    int data;
    node *nextNode;
}*root;


node* insertLinkedList(node* root,int val)
{

    if(root==nullptr)
    {
        node* temp=new node();
        temp->data=val;
        temp->nextNode=NULL;
        root=temp;
//        cout<<root->data<<endl;
        return root;
    }
    node* currentNode=root;
    while(currentNode->nextNode!=NULL)
    {
        currentNode=currentNode->nextNode;
    }
//    cout<<"dfasf"<<val<<endl;3
    node* temp=new node();
    temp->data=val;
    temp->nextNode=NULL;
    currentNode->nextNode=temp;
    return root;
}

void traverse(node* currentNode)
{
//    cout<<currentNode->data<<endl;
    while(currentNode!=NULL)
    {
        cout<<currentNode->data<<" ";
        currentNode=currentNode->nextNode;
    }
//    cout<<endl;
}


int main(){
//read;
    int n;
    cin>>n;
    root=nullptr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root=insertLinkedList(root,x);
    }
    traverse(root);








    return 0;
}

