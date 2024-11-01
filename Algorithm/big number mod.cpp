#include <bits/stdc++.h>
using namespace std;

int main(){
string s;
int a;
while(cin>>s>>a){
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum*=10;
        sum = (sum+(s[i]- '0'))%a;
    }
    cout<<sum<<endl;

}





return 0;
}
