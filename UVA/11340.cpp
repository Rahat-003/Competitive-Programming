#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 10003
int n;
vector< pair<char,pair<double,double>> >v;

int main(){
  freopen("11340_1.txt","r",stdin);
int t;
scanf("%d",&t);
while(t--){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c;
        double d;
        cin>>c>>d;
        v.push_back({c,{d,0.0}});
    }
    int line;
    scanf("%d",&line);
    cin.ignore();
    while(line--){
        char ar[MAX];
        cin.getline(ar,MAX);
        for(int i=0;i<strlen(ar);++i){
            for(auto it=v.begin();it!=v.end();++it){
                if(ar[i]==it->first){
                    it->second.second+=1.0;
                    break;
                }
            }
        }
    }
    double cnt=0.0;
    for(auto it=v.begin();it!=v.end();++it)
        cnt+= it->second.first * it->second.second;

        printf("%.2f$\n",cnt/100.0);
  //  cout<<fixed<<setprecision(2)<<cnt/100.00<<"$"<<endl;
    v.clear();
}





return 0;
}
