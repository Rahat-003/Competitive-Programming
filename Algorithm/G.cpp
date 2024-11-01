#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;



string ar[103];
set<int> st;

main(){
//read;

int n,m;
cin>>n>>m;
for(int i = 0; i<n; i++)
    cin>>ar[i];

for(int i = 0; i<m; i++){
    int p = 0;
    for(int j = 0; j<n; j++){
        int x = ar[j][i] - '0';
        p = max(p,x);
    }
    for(int j = 0; j<n; j++){
        if(ar[j][i] - '0' == p)
            st.insert(j);
    }
}
cout<<st.size()<<endl;

return 0;
}

