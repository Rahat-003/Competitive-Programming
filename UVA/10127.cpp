#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int f(int n){
    if(!n)  return 0;
    string s(log10(n)+1, '1');
    int x = 0;
    for(int i = 0; i<s.size(); i++)
    {
        int ans = 10*x + (s[i] - '0');
        x = ans%n;
        if(i==s.size()-1 && x)  s.push_back('1');
    }
    return s.size();
}


int main(){
int n;
while(1==scanf("%d",&n)){

    printf("%d\n",f(n));
}


return 0;
}
