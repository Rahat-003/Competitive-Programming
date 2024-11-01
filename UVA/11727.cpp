#include <iostream>
#include <vector>
#include<stdio.h>

using namespace std;
int main(){
    vector<int>v[10];
    int t,a,b,c;
    cin>>t;
    int m=0;
    while(t--){
        cin>>a>>b>>c;

    if((a<b&&b<c)||(c<b&&b<a))
        {
            printf("Case %d: %d\n",++m,b);
            }
    if((b<a&&a<c)||(c<a&&a<b)){
            printf("Case %d: %d\n",++m,a);
            }

    if((b<c&&c<a)||(a<c&&c<b)){
            printf("Case %d: %d\n",++m,c);
            }


    }


return 0;
}
