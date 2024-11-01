
#include <bits/stdc++.h>
using namespace std;

void cal(int &a,int &b,int n,string s){
    string t;
if(n){

    for(int i = 0;i<s.size()-n; i++)
     if(s[i]!='.')   t.push_back(s[i]);
    int x1,x2;
    x1 = atoi(t.c_str());
    int l = s.find('.');
    int afterdec = s.size()-1-l;
    int d = afterdec - n;

    double y1 = (pow(10,d));
    t.clear();

    for(int i = 0;i<s.size(); i++)
        if(s[i]!='.')   t.push_back(s[i]);

    x2 = atoi(t.c_str());
    d = afterdec;
    double y2 = (pow(10,d));
    int mm = x2-x1;
    int nn = (int)(y2-y1);
    t.clear();
    int g = __gcd(mm,nn);
//    cout<<mm<<" "<<nn<<endl;


    a = mm/g;
    b = nn/g;
}
    else{
            int i;
        for(i = s.size()-1; i>=0; i--){
            if(s[i]!=0) break;
        }
        t = s.substr(0,i+1);
        int d = t.find('.');
        int afterdec = t.size()-1-d;
        string p;
        for(int i = 0; i<t.size(); i++)
            if(t[i]!='.')   p.push_back(t[i]);


        int x = 1;
        for(int i = 0; i<afterdec; i++)
            x*=10;
        int y = atoi(p.c_str());
        int g = __gcd(x,y);
        a = y/g;
        b = x/g;

    }

}
int main(){

int n;
int t = 0;
while(cin>>n){
    string s;
    if(n==-1)   break;
    cin>>s;
    int a,b;
    cal(a,b,n,s);

    printf("Case %d: ",++t);
   cout<<a<<"/"<<b<<endl;


}


return 0;
}
