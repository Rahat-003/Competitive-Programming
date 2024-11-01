#include <bits/stdc++.h>
using namespace std;

void naive(string a, string s){
    int P = s.size();
    int T = a.size();
    int i=0,j;
    while(i<=T-P){
        for( j=0;j<P;j++)
            if(a[i+j]!=s[j])
            break;

        if(j==P) cout<<"found at "<<i<<endl;
        if(j==0) i++;
        else i+=j;
    }
}
int main(){
    clock_t tStart = clock();
    /* Do your stuff here */
    string a,s;
a="rahatannan"; s="a";
naive(a,s);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCS_PER_SEC);
return 0;
}
