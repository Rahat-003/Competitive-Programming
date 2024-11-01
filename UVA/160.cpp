
#include <bits/stdc++.h>
using namespace std;

#define mx 105
int ar[105];

void factor(){

    for(int i = 2; i<mx; i+=2)
        ar[i] = 2;

    for(int i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(int j = i;j<mx; j+=i)
                ar[j] = i;
        }
    }
    for(int i = 2; i<mx; i++)
        if(!ar[i])
            ar[i] = i;

}

void make(int n, map<int,int> &mp){
    while(n){
        if(ar[n]){
        mp[ar[n]]++;
            n/=ar[n];
        }
        else break;
    }
}

int main(){

//freopen("tst.txt","w",stdout);


int n;

factor();

while(cin>>n){
        if(!n)  break;
    int x = log10(n);

    string s(2-x,' ');
    cout<<s<<n<<"! =";

    map<int,int> mp;

    for(int i = 2; i<=n; i++)
    if(ar[i]==i)
        mp[i] = 0;

    for(int i = 2; i<=n;i++){
        make(i,mp);
    }

    int cnt = 0;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        int x = log10(it->second);
        string s(2-x,' ');
        if(cnt && cnt%15==0 && cnt<mp.size()){
            printf("\n");
            string y(8,' ');
            cout<<y;
        }
        else cout<<s;
        cnt++;
        cout<<it->second;
    }


cout<<endl;
mp.clear();
}

return 0;
}
