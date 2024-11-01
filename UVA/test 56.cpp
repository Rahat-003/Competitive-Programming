#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
while(getline(cin,s)){
    if(s=="")break;
 string y,u;
 int f=s.find(" ");
 y=s.substr(0,f);
 u=s.substr(f+1);
 cout<<y<<" "<<u<<endl;

}








return 0;
}
