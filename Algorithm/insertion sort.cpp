#include <iostream>
#include <vector>
using namespace std;


int main(){

int n,a,x;
while(cin>>n){
        /*vector< int > v;
        v.clear();*/
        int v[n],q=1;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int p=0;
        for(int j=0;j<i;j++){
            if(v[i]<v[j-1] && v[i]>v[j+1]){
                p=1;v[j]=v[i];
            }
          else if(p==1){
                q++;
                if(q>2){
                v[j]=v[j+1];}
            }


        }
    }
    for(int i=0;i<n;i++)
        {cout<<v[i]<<" ";}
    cout<<endl;
}




return 0;
}
