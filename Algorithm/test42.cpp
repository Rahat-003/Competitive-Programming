#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
cin>>s;
int x =s.size();
int ar[x];
int i = 0;
int j = 1;
while(j<x){
    if(s[j]==s[i]){
        i++;
        ar[j]=i;
        j++;
    }
    else{
    if(i!=0)
        i = ar[i-1];
    else{
        ar[j] = 0;
        j++;
    }

    }
}








for(int i=0;i<x;i++)
    cout<<ar[i]<<" ";



return 0;
}
