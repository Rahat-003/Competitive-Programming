#include <bits/stdc++.h>
using namespace std;

void funct(int& m, vector<int>&v){
for(int i=0;i<6;i++)
    cout<<" "<<v[i]<<endl;
}

int main(){
int a[]={1,2,3,4,5,6};
vector<int>v;
for(int i=1;i<=6;++i)
    v.push_back(2*i);
funct(5,v);

return 0;
}
