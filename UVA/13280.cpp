#include <bits/stdc++.h>
using namespace std;
vector<string>v;

void rk(string txt, string pat){
    int T=txt.size();
    int P=pat.size();
    int prime=17;
    int ht=0,hp=0,B=1;
    for(int i=0;i<P-1;i++)
        B = (256*B)%prime;

    for(int i=0;i<P;i++){
        hp = (hp*256 + pat[i])%prime;
        ht = (ht*256 + txt[i])%prime;
    }
    int i,j;
    for(i=0;i<=T-P;i++){
        if(hp==ht){
            for(j=0;j<P;j++)
                if(txt[i+j]!=pat[j])break;
        }
        if(j==P){
        cout<<i<<endl;  break;
        }
        if(i<T-P){
            ht = ((ht-txt[i]*B)*256 - txt[i+P])%prime;
            if(ht<0)
                ht+=prime;
        }
    }
}
void makest(string s, int a){
      for(int i=0;i<=s.size()-a;i++){
        string t;
        t.assign(s.begin()+i,s.begin()+a+i);
        if(!count(v.begin(),v.end(),t)){
            v.push_back(t);
        }
      }

}



int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int cs;
    cin>>cs;

    while(cs--){
        v.clear();
      v.push_back("0");
      int a,b;
      cin>>a>>b;
    makest(s,a);
    int x=v.size();
    if(b>=x) cout<<"Not found"<<endl;
    else {
    string ss = v[b];
    rk(s,ss);
    }
    }
}



return 0;
}
