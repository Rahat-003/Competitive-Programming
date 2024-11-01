#include <bits/stdc++.h>
using  namespace std;
#define d 256
void rk(char txt[], char pat[], int prime){
    int P = strlen(pat);
    int T = strlen(txt);
    int B = 1;
    int ht=0, hp =0;

    for(int i=0;i<P-1;i++){
    B = (d*B)%prime;
    }

    cout<<B<<endl;

    for(int i=0;i<P;i++){
        hp = (d*hp + pat[i])%prime;
        ht = (d*ht + txt[i])%prime;
    }

    for(int i=0;i<=T-P;i++){
        if(hp==ht){
            int j;
            for(j=0; j<P;j++)
                if(txt[i+j]!=pat[j])    break;
            if(j==P) cout<<"Pattern found at index "<<i<<endl;
        }
        if(i<T-P){
            ht = ( (ht - B*txt[i])*d + txt[i+P] )%prime;
            if(ht<0) ht+=prime;
        }
    }
}



int main(){
char txt[930], pat[920];
while(cin>>txt>>pat){
    rk(txt,pat,19);
}


return 0;
}
