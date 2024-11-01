#include <bits/stdc++.h>
#include <vector>
#define ma 1000
using namespace std;
vector<bool> a;
a.push_back(false);
a[1]=true;
for(int i = 2; i<1000;i++){
    a.push_back(true);
}
//vector<bool>v;

void prime(int n){
for (int i=2;i*i<=n;i++){
    for(int j=2*i;j<ma;j+=i){
        a.push_back(j);
    }
}
}
int main()
{
int n,r;
while(cin>>n>>r){


}


return 0;
}
