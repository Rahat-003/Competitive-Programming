
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(string s){
    int ans = 0;
    for(int i = 0; i<3; i++){
        int d = s[i] - 'A';
        if(d==0)    continue;
        double p = pow(26,2-i);
        ans+= (ll) d*p;
    }
        return ans;
}

int main(){
int t;
scanf("%d",&t);
while(t--){
    string d,s;
    cin>>s;
    for(int i = s.size()-4; i<s.size(); i++)
        d.push_back(s[i]);
    int L = f(s);
    int D = atoi(d.c_str());
    int dif = abs(L-D);
    if(dif<=100)    puts("nice");
    else puts("not nice");
}




return 0;
}
