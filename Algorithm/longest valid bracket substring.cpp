#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <stack>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

string s;

int fn(){
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='(')   stk.push(i);
        else{
            stk.pop();
            if(stk.size())  ans = max(ans,i-stk.top())  ;
            else stk.push(i);
        }
    }
return ans;
}


int main(){
int t,tc = 0;

s = "(()))())(";
//   .....
cout<<fn()<<endl;

return 0;
}

