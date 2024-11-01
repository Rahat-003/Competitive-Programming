#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){

vector<pair<string,string>> v;
int n;
cin>>n;
string a[100];
for(int i=0;i<n;i++){

    cin>>a[i];
}
string bd[16]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to","you" };
if(n<=15){
    int i=0,j=0;
    while(j<=15){
        v.push_back(make_pair(a[i],bd[j]));
        i++;
        j++;
        if(i>n-1){
            i=0;
        }
    }
}
if(n>15){
    double x= ceil((double)n/16);
    (int)x;
    int y=0;
    int p=0,q=0;
    while(y<=16*x-1){
        v.push_back(make_pair(a[p],bd[q]));
        y++;
        q++;
        p++;
        if(p>n-1){
            p=0;
        }
        if(q>15){
            q=0;
        }
    }

}
for(auto it=v.begin(); it!=v.end(); ++it){
    cout<<it->first<<": "<<it->second<<endl;
}

return 0;
}
