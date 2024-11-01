#include <bits/stdc++.h>
using namespace std;

string palin(string s){
    int x = s.size();
    int k=x-1,c=0;
    for(int i =0;i<x;i++){

        if(s[i]==s[x-1]){
            c=1;
            k=i;
            int l = x-i;
            for(int j=0;j<l;j++){
                if(s[i+j]!=s[x-j-1]){
                    c=0;
                    break;
                }
            }

        }
        if(c==1) break;
    }
   // if(c==0)
    for(int i=k-1;i>=0;i--)
        s.push_back(s[i]);


        return s;
}


int main(){
string s;
while(cin>>s){
    if(s=="")   break;
    string t = palin(s);
    cout<<t<<endl;
}




return 0;
}
