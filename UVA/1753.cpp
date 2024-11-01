#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
double n,t;
typedef pair<double,double> pp;
vector<pp> v;
#define mx 1000000000
#define EPS 1e-7
/*
int go(double m){
    double lhs = 0,rhs = t;
    for(int i = 0; i<v.size(); i++){
        double p = v[i].first,  q = v[i].second;
//        if(fabs(m+q)<EPS)   return 1;
        lhs+=p/(m+q);
    }
//    cout<<lhs<<" "<<rhs<<" "<<m<<endl;
    if(fabs(lhs-rhs)<EPS)   return 0;
    if(lhs>rhs) return 1;
    return -1;
}
*/
double bin(double l,double h){
    /*
    double m = (l+h)/2.0;
    int g = go(m);
//    cout<<l<<" "<<h<<" "<<m<<endl;
    if(g==0)    return m;
    if(fabs(h-l)<EPS)   return m;
    if(g==-1)   return bin(l,m);
    else return bin(m,h);
    */
    double m;
    while(h-l>1e-9){
        m = (h+l)/2.0;
        double p=0;
        for(int i = 0; i<v.size(); i++) p+=v[i].first/(m+v[i].second);
        if(p>t)    l=m;
        else h=m;
    }
//    return (h+l)/2.0;
    return m;
}

int main(){

while(cin>>n>>t){
double l = mx;

while(n--){
    double a,b; cin>>a>>b;  v.push_back(pp(a,b));
    l = min(l,b);
}
	
    double ans = bin(-l,mx);
    printf("%.10f\n",ans);
//    cout<<x<<" "<<t<<endl;
    v.clear();
}



return 0;
}

