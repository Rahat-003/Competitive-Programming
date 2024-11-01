#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 104
int ar[mx];
string s = "+-*/";
int target;
#define MX 32000
int p;
int dp[100][4][64005];
char ch[]={'+','-','*','/'};

//bool flag=0;
bool flag=0;

void fn(int pos,int tot,int state,vector<int> v){
    if(flag)return;
    if(pos==p){
//            cerr<<tot<<endl;
        if(tot==target)
        {
            flag=1;
            for(int i=0;i<v.size();i++)
            {
                if(i==0)
                {
                    if(!v[i])
                    {
                        cout<<ch[v[i]]<<ar[i];
                    }
                    else cout<<ar[i];
                }
                else
                {
                        cout<<ch[v[i]]<<ar[i];
                }
            }
        }
        return;
    }
    if(tot>MX || tot<-MX)return;
    int x = ar[pos];
    if(pos==0){
        v.push_back(0);
        fn(pos+1,tot+x,0,v);
        v.pop_back();
        v.push_back(1);
        fn(pos+1,tot-x,1,v);
        v.pop_back();
        return;
    }

        v.push_back(0);
    fn(pos+1,tot+x,0,v);
        v.pop_back();
        v.push_back(1);
    fn(pos+1,tot-x,1,v);
        v.pop_back();
        v.push_back(2);
    fn(pos+1,tot*x,2,v);
        v.pop_back();
    if(tot%x==0)
    {
        v.push_back(3);
        fn(pos+1,tot/x,3,v);
        v.pop_back();
    }
//    return ret=fl;
}

vector<int> v;


main(){
//read;

int t;
cin>>t;
while(t--){
//    ms(dp,0)
    v.clear();
    flag=0;
    memset(dp,-1,sizeof dp);
    cin>>p;
    for(int i = 0; i<p; i++)
        cin>>ar[i];
    cin>>target;
    fn(0,0,0,v );
//    cout<<ans<<endl;
    if(!flag)printf("NO EXPRESSION\n");
    else
    {
//        solve(0,0,0,v);
        printf("=%d\n",target);
    }
}



return 0;
}

