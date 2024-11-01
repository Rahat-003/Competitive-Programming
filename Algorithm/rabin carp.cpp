#include <bits/stdc++.h>
using namespace std;

#define d 256

void rabinkarp(char wrd[], char pat[], int prime){
    int psz = strlen(pat);
    int wsz = strlen(wrd);
    int hw=0, hp= 0, B=1;
    for(int i=0; i<psz-1;i++){
        B = (B*d) % prime;
    }
    for(int i = 0;i<psz;i++){
        hp = (hp*d + pat[i])%prime;
        hw = (hw*d + wrd[i])%prime;
    }
    for(int i=0; i<=wsz-psz; i++){
        if(hw==hp){
                int j;
        for(j=0;j<psz; j++){
            if(pat[j]!=wrd[i+j])    break;
            }
        if(j==psz)    cout<<"Found at "<<i<<endl;
        }

        if(i<(wsz-psz)){
            hw = ( d*( hw- wrd[i]*B) + wrd[i+psz] ) % prime;

            if(hw<0) hw += prime;
        }


    }



}



int main(){
char wrd[30],pat[20];
while(cin>>wrd>>pat){
    rabinkarp(wrd,pat,11);

}



return 0;
}
