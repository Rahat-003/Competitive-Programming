#include <bits/stdc++.h>
using namespace std;

int GCD(int m, int n) {
    if (m%n) return GCD(n, m%n);
    return n;
}

int main(){
//    FileIn  ("test"); FileOut("test");
//    freopen ("10407.txt","r",stdin);
    int a,b,rs;
    while (scanf("%d", &a) && a){
        rs = 0;
        while (scanf("%d", &b) && b) {
            if (rs==0) rs = abs(b-a);
            else {
                if (abs(b-a)==0) continue;
                rs = GCD(rs, abs(b - a));
            }
            a = b;
        }
        printf("%d\n", rs);
    }


return 0;
}
