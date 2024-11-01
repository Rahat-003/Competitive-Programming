#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
while(cin>>s){
int x = s.size();
vector<int>ar(x,0);
int i =0;
int j=1;
while(j<x){
    if(s[i]==s[j]){
        i++;
        ar[j]=i;
        j++;
    }
    else{
        if(i!=0) i = ar[i-1];
        else{
            ar[j] = 0;
            j++;
        }
    }
}

for(int i=0;i<x;i++)
    cout<<ar[i]<<" ";
cout<<endl;
ar.clear();
}
return 0;
}
