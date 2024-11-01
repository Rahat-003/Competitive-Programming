#include <algorithm>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool pp(char a,char b){
    if(a!=b)    return a>b;
//    return true;
}

string make(string s){
    int x = count(s.begin(),s.end(), '0');
    s = s.substr(x);
//    cout<<s<<endl;
    string t;
    for(int i = 0; i<x; i++)
        t.push_back('0');
    s.insert(1,t);

return s;
}

int main(){
    freopen("t.txt","r",stdin);
ll n;
string s;
while(cin>>n){
    s = to_string(n);
//    int n = atoi(s.c_str());
//    cout<<s<<endl;
    sort(s.begin(),s.end(),greater<char>());
    ll q = stoll(s.c_str());

    sort(s.begin(),s.end());
    s = make(s);

    ll p = atoi(s.c_str());



    if(p>q) swap(p,q);
    printf("%lld - %lld = %lld = 9 * %lld\n",q,p,q-p, (q-p)/9 );


}



return 0;
}

