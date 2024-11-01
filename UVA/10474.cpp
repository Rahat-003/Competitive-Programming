#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int>v;
int  n,x,k=0;
while(cin>>n>>x&&n&&x){
        v.clear();
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
sort(v.begin(),v.end());
printf("CASE# %d:\n",++k);
while(x--){
    int b;
    cin>>b;
    if(!binary_search(v.begin(),v.end(),b))
        cout<<b<<" not found"<<endl;

    else
        {
            int c=lower_bound(v.begin(),v.end(),b)-v.begin();
            printf("%d found at %d\n",b,c+1);
        }
}
}
return 0;
}
