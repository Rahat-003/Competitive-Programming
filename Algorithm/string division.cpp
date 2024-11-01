#include <bits/stdc++.h>
using namespace std;
string sub(string a, string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    string s;
    int dif=a.size()-b.size();

    for(int i=0;i<b.size();i++){
        int d1=(a[i]-'0');
        int d2=(b[i]-'0');
        if(d1<d2){
            d1+=10;
            carry+=1;
        }
        int ans=d1-d2-carry;
        s.push_back(ans+'0');
    }
    for(int i=0;i<dif;++i){
        s.push_back('0');
    }
    for(int i=b.size();i<a.size();i++){
        int d1=(a[i]-'0');
        int d2=(b[i]-'0');
        if(d1<d2){
            d1+=10;
            carry+=1;
        }
        int ans=d1-carry;
        s.push_back(ans+'0');
    }



reverse(s.begin(),s.end());
return s;
}
/*
void div(string a,string b){



}*/
int main(){
string a,b;
cin>>a>>b;
cout<<sub(a,b);

return 0;
}
