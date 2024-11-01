#include <bits/stdc++.h>
using namespace std;


int main(){
int a[]={1,2,3,4,5}    ;
vector<int>v(a,a+(sizeof a/ sizeof(a[0])));
for(int i=0;i<v.size();++i)
    cout<<v[i]<<" ";
return 0;
}
