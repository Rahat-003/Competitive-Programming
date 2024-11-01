#include <bits/stdc++.h>
using namespace std;
string ar[1005];
vector <int> v(11,0);
string m(string a, int q){
    string b;
    stringstream ss;
    ss<<q;
    b=ss.str();
    if(a=="0" || b=="0")
        return "0";
    int i1=0,i2,carry;
    vector<int> v(a.size()+b.size(),0);
    for(int i=a.size()-1;i>=0;i--){
        carry =0;
        i2=0;
        for(int j=b.size()-1; j>=0;--j){
            int ans = (a[i] - '0')*(b[j] - '0') + v[i1+i2] +carry;
            carry = ans/10;
            v[i1+i2] = ans%10;
            i2++;
        }
        if(carry) v[i1+i2] += carry;
        i1++;
    }
int x= v.size()-1;
string s;
while(1){
    if(v[x]!=0)
    break;
    x--;
}
for(int i=x;i>=0;i--){
    s.push_back(v[i]+ '0');
}
return s;
}
void count(string s){

    for(int i=0;i<s.size();++i){
        for(int j=0;j<10;++j){
            if((s[i]- '0')==j){
                v[j]+=1;
                break;
            }
        }
    }
}
void fact(){
    string s;
    ar[0]="1";ar[1]="1";
    for(int i=2;i<=1001;i++){
        s= m(ar[i-1],i);
        ar[i]=s;
    }
}
int main(){
fact();
int n;
while(cin>>n){
    count(ar[n]);
    printf("%d! --\n",n);
    for(int i=0;i<10;i++){
    printf("  (%d)  %d",i,v[i]);
    if(i==4){
    cout<<endl;
}
v[i]=0;
}
    cout<<endl;

}
return 0;
}
