#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a%b==0)
        return b;
    else return gcd(b%a,a);

}

int main(){
int t,a;
cin>>t;
string s,sa;
getline(cin,sa);
while (t--){
        vector<int> v;
    getline(cin,s);
    istringstream ss(s);
    while(ss>>a){
        v.push_back(a);
    }
    int mxgcd=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(__gcd(v[i],v[j])>mxgcd)
                mxgcd=__gcd(v[i],v[j]);
        }
    }
    cout<<mxgcd<<endl;

}


return 0;
}
