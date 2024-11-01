
#include <bits/stdc++.h>
using namespace std;

vector<int> v = {1,5,10,25,50};

int ar[1002];
int tr[1003];

int main(){

for(int i = 1;i<=1000;i++){
    ar[i] = 2e8;
    for(int j = 0;j<v.size();j++){
        int c = v[j];
        if(i-c>=0 && (ar[i-c]+1)<ar[i] ){
        ar[i] = ar[i-c]+1;
        tr[i] = c;
        }
    }
}

int a;

while(cin>>a){
    cout<<ar[a]<<endl;

    for(int i = a;tr[i]; i-=tr[i] )
        cout<<tr[i]<<" ";
        puts("");
}

return 0;
}
