#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<char>T(MAX);
vector<char>R(MAX);


void palin(char T[]){
    int t = strlen(T);
    for(int i =t-1, j=0;i>=0; j++,i--){
        R[j] = T[i];
    }
    int c=0;
    int rest=-1,j=-2;

for(int i=0; i<t;i++){
    if(T[i]==R[0]){
        rest = t-i;
        for(j=0;;j++){
            if(T[i+j]!=R[j])    break;
            if(j==rest) break;
        }
    }
    if(j!=rest) cout<<T[i];

}
    cout<<R<<endl;

}
int main(){


while(scanf("%s",T)){
    palin(T);
    memset(T,'\0',sizeof(T));
    memset(R,'\0',sizeof(R));
}



return 0;
}
