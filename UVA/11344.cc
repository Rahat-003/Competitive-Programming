#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

bool check(string s,int n){
    int x = 0;

    for(int i = 0; i<s.size(); i++){
        int ans = 10*x+(s[i] - '0');
        x = ans%n;
    }
    return x==0;
}
    vector<int> v;

bool func(string s){
    for(auto i:v){
        if(!check(s,i)) return false;
    }
    return true;

}



int main(){
string s; int n,t;
cin>>t;
while(t--){
    cin>>s>>n;
    while(n--){
        int a;  cin>>a;
        v.push_back(a);
    }
        printf("%s",s.c_str());

    if(func(s)) puts(" - Wonderful.");

    else puts(" - Simple.");
v.clear();
//    if(check(s,n))  puts("true");
}




return 0;
}
