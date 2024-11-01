#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    int n,l;
while(cin>>n>>l){
    if(l==0){
        printf("%d %d:\n",n,l);
    }
    else{

        v.clear();
        int p;
    for(int i=1;i<=n;i++){
        p=0;
    for(int j=2;j*j<=i;j++){
        if(i%j==0){
            p=1;
            break;
        }
    }
    if(p==0){
        v.push_back(i);
    }
    }

if(2*l>=v.size()){
        printf("%d %d: ",n,l);
  for(auto i=v.begin();i!=v.end();++i){
    cout<<*i<<" ";
}
}
if(2*l<v.size()){
if(v.size()%2!=0){
        printf("%d %d: ",n,l);
    for(int k=v.size()/2-l/2; k<=v.size()/2+l/2; k++){
        cout<<v.at(k)<<" ";
    }
}
if(v.size()%2==0){
        printf("%d %d: ",n,l);
    for(int k=v.size()/2-l; k<v.size()/2+l;k++){
        cout<<v.at(k)<<" ";
    }
}

}
cout<<endl;
}
}
return 0;
}
