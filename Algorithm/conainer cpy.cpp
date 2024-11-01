#include <bits/stdc++.h>
using namespace std;
int main(){
int v[] = {1,2,3,4,5};
int w[5];
copy_n(v,5,w);
for(int i=0;i<5;i++)
    cout<<w[i]<<" ";
return 0;
}
