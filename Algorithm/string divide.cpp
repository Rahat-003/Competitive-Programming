#include <bits/stdc++.h>
using namespace std;
int main(){

string a;
int b;
while(cin>>a>>b){
    string ans;
    int x=0;
    for(int i=0;i<a.size();i++){
        x = 10*x + a[i]- '0';
        ans+= x/b+ '0';
        x=x%b;
    }
    int j;
    for(j=0;j<ans.size();++j){
        if(ans[j]!='0')   break;
    }
    if(j==ans.size()) ans = "0";
    else ans = ans.substr(j);

    cout<<ans<<" "<<x<<endl;
}



return 0;
}
