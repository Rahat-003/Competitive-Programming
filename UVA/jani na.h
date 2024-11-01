#include <iostream>
#include <vector>
using namespace std;
int maxi(vector<int>v,int n){
    int m;
    m=v[0];
    for (int i=1;i<n;i++){
        if(m<v[i]){
            m=v[i];
        }
    }
    return m;
}
int mini(vetor<int>v,int n){
    int m;
    m=v[0];
    for(int i=1;i<n;i++){
            if(v[i]<m){
                m=v[i];
            }
    }
return m;
}


int main(){
int t;
cin>>t;
vector<int>v;
int n,b;
while(t--){
    v.clear();
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>b;
       v.push_back(b);
    }
cout<<(maxi(v,n)-mini(v,n))*2<<endl;
}



return 0;
}
