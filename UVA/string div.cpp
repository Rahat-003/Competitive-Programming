#include <bits/stdc++.h>
using namespace std;
int stoi(string s){
    int i;
    stringstream ss(s);
    ss>>i;
    return i;
}
string itos(int i){
    string s;
    stringstream ss;
    ss<<i;
    s=ss.str();
    return s;
}
char itoc(int i){
    string s;
    stringstream ss;
    ss<<i;
    s=ss.str();
    for(int i=0;i<s.size();i++){
        return s[i];
    }
}
string div(string a, int b){
    string s;
    int c;
    string result;
    for(int i=0;i<a.size();i++){
    s.push_back(a[i]);
    c = stoi(s);
    if(c>=b){
    int p=c/b;
    result.push_back(itoc(p));
    s.clear();
    int q=c%b;
       s.push_back(itoc(q));
    }
    else result.push_back('0');
    }

    return result;
}


int main(){
string s;
int i;
while(cin>>s>>i)
cout<<div(s,i)<<endl;


return 0;
}
