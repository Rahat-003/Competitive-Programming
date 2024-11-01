
#include <bits/stdc++.h>
using namespace std;
int main(){

int b;
char c;
string s;
getline(cin,s);
for(int i=0;i<s.size();++i){
  if(s[i]==',')
    s[i]=' ';

}
stringstream ss(s);
int a;
while(ss>>a)
  cout<<a+1<<" ";



return 0;
}
