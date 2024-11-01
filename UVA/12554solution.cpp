#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
cin>>n;
vector<pair<string,string>>mp;
string a[100];
for(int i=0;i<n;i++){
    cin>>a[i];
}
string bd[16]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to","you" };
if(n<=16){
    int j=0,i=0;
    while(j<=15){
        mp.push_back(make_pair(a[i],bd[j]));
        i++;
        j++;
        if(i>n-1)
            i=0;
    }
}
    if(n>16){
        double x=ceil((double)n/16);
        (int)x;
        int i=0,j=0,k=0;
        while(i<=16*x-1){
            mp.push_back(make_pair(a[k],bd[j]));
                i++;
                j++;
                k++;
            if(j>15)
                j=0;
            if(k>n-1)
                k=0;

        }
    }
        for(auto it=mp.begin();it!=mp.end();++it){
        cout<<it->first<<": "<<it->second<<endl;

}
return 0;
}
