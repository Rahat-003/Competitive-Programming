#include <bits/stdc++.h>
using namespace std;
#define MAX 100
string store[MAX];
map<string,int>mp;
int index=0;
int push(){

    for(int i=0;i<26;i++){

        char a= i + 'a';
        string letter;
        letter = a;
        store[i+1]= letter;
        index=i+1;
    }
    int i1=0,c;
    while(index<80){
        i1++;
        string currSt;
        for(int i = 1; i<=26; i++){
            currSt = store[i1];
            char last = currSt[currSt.size()-1];
            char newCh= last + i;
            c=index;
            if( (newCh - 'z')>0) continue;
        else{

            index+=1;
            string ss;
            ss= currSt + newCh;
            store[index] = ss;
        }
        }
        index=c;
    }
    return c;
}
int main(){
cout<<push()<<endl;
for(int i=0;i<80;i++)
    cout<<store[i]<<endl;


return 0;
}
