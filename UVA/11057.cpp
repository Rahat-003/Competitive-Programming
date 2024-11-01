#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
int n;
vector<int> v;
while(cin>>n && n){
        v.clear();
   int a,b,c,d,e,f;
   for(int i=0;i<n;i++){
    int c;
    cin>>c;
    v.push_back(c);
   }
    sort(v.begin(),v.end());
    cin>>b;
    for(int i=0; i<n-1; i++){
        for (int j=i+1;j<n;j++){
            if(v[i]+v[j]==b){
                 e=v[i];
                 f=v[j];

            }
        }
    }
printf("Peter should buy books whose prices are %d and %d.\n",e,f);
cout<<endl;
}
return 0;
}
