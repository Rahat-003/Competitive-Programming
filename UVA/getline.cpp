#include <bits/stdc++.h>
using namespace std;
int main(){

string s;
getline(cin,s);
istringstream ss(s);
int a;
while(ss>>a)
    cout<<a*2<<" ";

return 0;
}
