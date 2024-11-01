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
#define write                   freopen("input.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;




int mx = 1000;


main(){
//read;

write;

	int q = 200;
	int a,b,c,d;
	cout << q << endl;
	
	puts("2 15 233 992 23412");
	puts("13 61 234 121 324");
	puts("7 7 45 49 -1722");
	
	for(int i = 0; i<q-3; i++){
		int x = rand()%4543 + rand()%2323 + rand()%234;
		if(rand()%3==0)	x*=-1;
		a = rand()%23 + rand()%49165 + rand()%42,b = rand()%3532 + rand()%366 + rand()%1505003;
		c = rand()%457654 + rand()%212345 + rand()%213,d = rand()%345 + rand()%21 + rand()%653;
		a%=mx;
		b%=mx;
		c%=mx;
		d%=mx;
		a++;b++;c++;d++;
		if(a>c)	swap(a,c);
		if(b>d)	swap(b,d);
		
		cout << a << " " << b << " " << c << " " << d << " " << x << endl;
	}
	
	puts("\n\n\n");
	cout << q << endl;
	while(q--){
		a = rand()%23 + rand()%465 + rand()%442,b = rand()%3532 + rand()%36436 + rand()%345346;
		c = rand()%457654 + rand()%2345 + rand()%213,d = rand()%345 + rand()%2311 + rand()%34653;
		a%=mx;
		b%=mx;
		c%=mx;
		d%=mx;
		a++;b++;c++;d++;
		if(a>c)	swap(a,c);
		if(b>d)	swap(b,d);
		cout << a << " " << b << " " << c << " " << d << endl;
	}
	
	
	
	






return 0;
}

