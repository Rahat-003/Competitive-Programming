#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;
vector<ll> s;

int main(){
ll a,b;
while(cin>>a&&a){
    s.clear();
    b=a;
    if(a==2){
    s.push_back(-1);
    a/=2;
}
        int m=0;
        if(a%2==0){
while(a%2==0){
    m++;
    if(m==1){s.push_back(2);}

    a/=2;
}
        }
for(int i=3;i<=b/2;i+=2){
        int n=0;
if(a%i==0){
    while(a%i==0){
        n++;
      if(n==1) { s.push_back(i);}
        a/=i;
    }
}
continue;
}
if(a>2){
    s.push_back(-1);
}
cout<<s.at(s.size()-1)<<endl;
    s.clear();

}
return 0;
}
