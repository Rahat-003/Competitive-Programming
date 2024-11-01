#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void subset(int k,int n){
    if(k==n){
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
    return;
    }

    subset(k+1,n);
    v.push_back(k);
    subset(k+1,n);
    v.pop_back();

}


int main(){

subset(0,3);
//cout<<v.size()<<endl;
return 0;
}
