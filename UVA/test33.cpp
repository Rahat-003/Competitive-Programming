#include <bits/stdc++.h>
using namespace std;
string grt(string a, string b){
    if(a==b) return a;
    if( a.size()>b.size())
        return a;
    if(a.size()<b.size()) return b;

    for(int i=0;i<a.size();i++){
     int x= a[i]-'0';
     int y= b[i]-'0';
     if(x!=y){
        if(x>y) {
            return a;  break;
        }
        else {
            return b;  break;
        }
     }
    }
}
string sml(string a, string b){

    if(a==b) return a;
    if( a.size()<b.size())
        return a;
    if(a.size()>b.size()) return b;

    for(int i=0;i<a.size();i++){
     int x= a[i]-'0';
     int y= b[i]-'0';
     if(x!=y){
        if(x<y) {
            return a;  break;
        }
        else {
            return b;  break;
        }
     }
    }
}


int main(){
  //  freopen("10407.txt","r",stdin);
string a,b;
while(cin>>a>>b){

    cout<<grt(a,b)<<endl;
    cout<<sml(a,b)<<endl;

}


return 0;
}
