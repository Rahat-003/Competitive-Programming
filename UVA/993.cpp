
#include <bits/stdc++.h>
using namespace std;

vector<int> prime = {5,6,7,8,9,4,2,3};

bool cmp(string a,string b){
    if(a.size()!=b.size())
        return a.size()<b.size();
    return a<b;
}

bool check(string s,int n){
    int x = 1;
    for(int i = 0; i<s.size(); i++){
        int p = s[i] - '0';
        x*=p;
    }
    return x==n;
}

void factor(int n){

    string t;
    vector<string> v;
    int N = n;

    for(int i = 0; i<prime.size(); i++){
    string s;
    n = N;
        for(int j = i;j<prime.size(); j++){
        int p = prime[j];
        while(n%p==0){
            if(n==1)    break;
            s.push_back( p + '0');
            n/=p;
            }
        }
        if(s.size()){
        sort(s.begin(),s.end());

        v.push_back(s);
        }
    }

    sort(v.begin(),v.end(),cmp);

    bool fl = false;

    if(v.size()){
        for(auto i:v){
            if(check(i,N)){
                cout<<i<<endl;
                fl = true;
                break;
            }
        }

    }
    if(!fl)
        cout<<"-1"<<endl;
}


int main(){

//freopen("t.txt","r",stdin);

int t;
cin>>t;
    while(t--){
        int n;
      cin>>n;
      if(n==1 || !n){
        cout<<n<<endl;
        continue;
      }
    factor(n);
}



return 0;
}
