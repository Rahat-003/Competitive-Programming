#include <bits/stdc++.h>
using namespace std;




int main(){

int a;
cin>>a;
        vector<int> fem;
    for(int i=0;i<a;i++){
       int f;cin>>f;fem.push_back(f);
    }
    int b;
    cin>>b;
//    vector<int>luchu;
    for(int i=0;i<b;i++){
       int d;
       cin>>d;
        int y=fem[lower_bound(fem.begin(),fem.end(),d)-fem.end()-1];
        if(binary_search(fem.begin(),fem.end(),y)){
            cout<<y<<" ";
        }
       else{
        cout<<"X"<<" ";
       }
       int z=fem[upper_bound(fem.begin(),fem.end(),d)-fem.begin()];
       if(binary_search(fem.begin(),fem.end(),z)){
        cout<<z<<endl;
       }
       else cout<<"X"<<endl;

    }



return 0;
}
