#include <bits/stdc++.h>
using namespace std;
#define d 256
void rk(char txt[],char pat[],int prime){
    int tt= strlen(txt);
    int pp= strlen(pat);
    int B=1;
    int ht=0,hp=0;
    for(int i=0; i<pp-1;i++)
        B = (B*d)%prime;
    for(int i=0;i<pp;i++){
        hp = (hp*d + pat[i] ) %prime;
        ht = (ht*d + txt[i] ) %prime;
    }
    for(int i=0;i<=tt-pp;i++){
        if(hp==ht){
                int j;
            for(j = 0; j<pp;j++)
                if(txt[i+j]!=pat[j]) break;
        if(j==pp) cout<<"Pattern found at "<<i<<endl;
        }
    if(i<tt-pp){
        ht = (256*(ht-txt[i]*B) + txt[i+pp])%prime;
        if(ht<0)    ht+=prime;
    }

    }




}

int main(){

char txt[30],pat[20];
cin>>txt>>pat;
rk(txt,pat,17);



return 0;
}
