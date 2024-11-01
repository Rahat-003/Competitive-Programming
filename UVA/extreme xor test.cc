#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

struct node{
    vector<int> v;
    node(){};
    node(vector<int> &x){
        v =  x;
    }
};
int cnt[1000];
vector<node> ar;

void fn(){
    /*
    cout<<ar.size()<<endl;
    */
    if(ar.size()==1){
    for(int i = 0; i<ar.size(); i++){
        sort(ar[i].v.begin(),ar[i].v.end());

        if(ar[i].v.size()){
        cout<<"(";
        for(int j = 0;j<ar[i].v.size(); j++){
            if(j)   cout<<",";
                cout<<ar[i].v[j];
        }
        cout<<") ";
        }

        }

    }

//    cout<<endl;


    if(ar.size()<=1)    return;
//    for(int i = 0; i<20; i++)   cnt[i] = 0;
    vector<node> tmp;
    tmp = vector<node> (ar.size()-1);

    for(int i = 1; i<ar.size(); i++){
        memset(cnt,0,sizeof cnt);
        for(int j = 0; j<ar[i].v.size(); j++ ){
            cnt[ar[i].v[j]]++;
        }
        for(int j = 0; j<ar[i-1].v.size(); j++)
            cnt[ar[i-1].v[j]]++;
        for(int j = 0; j<ar[i-1].v.size(); j++ ){
            if(cnt[ar[i-1].v[j]] & 1) tmp[i-1].v.push_back(ar[i-1].v[j]);
        }
        for(int j = 0; j<ar[i].v.size(); j++ ){
            if(cnt[ar[i].v[j]] & 1) tmp[i-1].v.push_back(ar[i].v[j]);
        }

    }


    ar.clear();
    ar = tmp;
    /*
    for(int i = 0; i<tmp.size(); i++){
        vector<int> x;
        for(int j:tmp[i].v)   x.push_back(j);

        ar.push_back(node(x));
    }
*/
    tmp.clear();
    if(ar.size()>=1) fn();

}

int main(){
int t,tc = 0;

int n;
while(true){
cin>>n;
        if(n==0)    return 0;
ar.clear();
//for(int j = n; j<=t; j++) {
    memset(cnt,0,sizeof cnt);
//cout<<j<<endl;
for(int i = 1; i<=n; i++){
    cnt[i]++;
    vector<int> x;
    x.push_back(i);
    ar.push_back(node(x));
}
fn();
cout<<endl<<endl;

//}

}

return 0;
}

