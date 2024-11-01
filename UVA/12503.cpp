#include <iostream>
#include <cstdio>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,a[1000],cnt=0,f;
    cin>>n;
    for (int i=0;i<n;i++){
    char c;
    scanf("%*c",&c);
    if(c=='L'){
        a[i]=-1;
        cnt+=a[i];
    }
    else if(c=='R'){
        a[i]=1;
        cnt+=a[i];
    }


    }
   cout<<cnt<<endl;

}




return 0;
}
