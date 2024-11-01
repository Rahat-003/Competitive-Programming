#include <bits/stdc++.h>
using namespace std;

void make_ar(int ar[],char pat[]){
    int P = strlen(pat);
    int i =0;
    int j =1;
    while(j<P){
        if(pat[i]==pat[j]){
            i++;
            ar[j]=i;
            j++;
        }
        else{
            if(i!=0)    i =ar[i-1];
            else{
                ar[j] = 0;
                j++;
            }
        }
    }
}


void kmp(char txt[],char pat[],int ar[]){
    int T = strlen(txt);
    int P = strlen(pat);
    int j = 0;
    int i = 0;
    while(j<T){
        if(txt[j]==pat[i]){
            i++;
            j++;
        }
        if(i==P){
            cout<<"found at "<<j-i<<endl;
            i = ar[i-1];
        }
        else if(txt[j]!= pat[i]){
            if(i!=0){
                i = ar[i-1];
            }
            else j++;

        }
    }

}


int main(){

char txt[150],pat[130];
cin>>txt>>pat;
int ar[strlen(pat)];
ar[0] = 0;
make_ar(ar,pat);
kmp(txt,pat,ar);



for(int i=0;i<strlen(pat);++i)
    cout<<ar[i]<<" ";
//*/
return 0;
}
