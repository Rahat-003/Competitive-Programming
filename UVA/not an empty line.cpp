#include <bits/stdc++.h>

using namespace std;

int main(){

int t;
//cin>>t;
//while(t--){
        string line;
//        cin.ignore();
   // getline(cin,line);
    while(getline(cin,line)&&line!=""){
        int x;
        stringstream ss(line);
        while(ss>>x){
            cout<<x<<" ";
        }
        cout<<endl;
    }
//}

return 0;
}
