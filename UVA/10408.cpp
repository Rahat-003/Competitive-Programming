#include <cstdio>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    double p;
    int x,y;

    node(double _p = 0, int _x = 0, int _y = 0){
    p = _p;
    x = _x;
    y = _y;
    }


    bool operator < (node &n1){
        if(p!=n1.p) return p<n1.p;
    }

};

int main(){


int n,b;
while(2==scanf("%d %d",&n,&b)){
  /*
    if(n==b){
        puts("1/1");
        continue;
    }
*/
    vector<node> v;
    if(n>1)
    for(int i = 1; i<n; i++){
        for(int j = i+1; j<=n; j++){
            if(i==1){
                double m = (double)i/(double)j;
                v.push_back(node(m,i,j));
            }
            else{
                if(__gcd(i,j)==1){
                double m = (double)i/(double)j;
                v.push_back(node(m,i,j));
                }
            }
        }
    }
    else{
        v.push_back(node(0,0,1));
//        v.push_back(1,1,1)
    }
    v.push_back(node(1,1,1));
    sort(v.begin(),v.end());
    printf("%d/%d\n",v[b-1].x,v[b-1].y);
}





return 0;
}
