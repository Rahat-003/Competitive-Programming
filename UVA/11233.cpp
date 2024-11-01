#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
cin>>a>>b;
    map <string , string > mp;
    while(a--){
        string c,d;
        cin>>c>>d;
        mp[c] = d;
    }
    vector<string>v;
    for(int i=0;i<b;i++){
    string e;   cin>>e;
    v.push_back(e);
    }
    for(int i=0;i<b;i++){
        string s = v[i];
        int x = s.size();
        auto it = mp.find(s);
        if(it!=mp.end())
            v[i] = it->second;
        else{
            if(s[x-1]== 'y' && (s[x-2]!= 'a' && s[x-2]!= 'e' && s[x-2]!= 'i' && s[x-2]!= 'o' && s[x-2]!= 'u') ){
                s.erase(x-1);   s.push_back('i'); s.push_back('e'); s.push_back('s');
                v[i] = s;
        }
    else if((s[x-1]=='o'||s[x-1]=='s'||s[x-1]=='x'|| s[x-1]=='h' )){
            if(s[x-1]=='h' &&(s[x-2]=='c' ||s[x-2]=='s')){
                s.push_back('e'); s.push_back('s');
                v[i]=s;
                }
              if(s[x-1]!= 'h'){  s.push_back('e'); s.push_back('s');
                v[i]=s;
              }
           }
        else {
            s.push_back('s');
            v[i]=s;
        }

        }

        cout<<v[i]<<endl;
    }
v.clear(); mp.clear();


return 0;
}
