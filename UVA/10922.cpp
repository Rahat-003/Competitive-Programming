
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char ar[1003];

bool isMultiple(){
    int x = 0,y;
    for(int i = 0; i<strlen(ar); i++){
        int d = ar[i]-'0';
        if(d>9) continue;
        y = 10*x+(ar[i] - '0' );
        x = y%9;
    }
    return x==0;
}

int sum( string a ){
    int x=0;
    for(int i = 0 ; i<a.size(); i++){
        int d = a[i]-'0';
        if(d>9) continue;
        x+=d;
    }
    return x;
}

int main(){


while(1==scanf("%s",ar)){
    if(ar[0]=='0' && strlen(ar)==1)   break;
    string s = ar;

    bool fl = isMultiple();
    int x = 1;
    if(!fl){
        printf("%s is not a multiple of 9.\n",ar);
        continue;
    }


    while(fl){
        int tot = sum(s);
        if(tot==9)  break;
        s = to_string(tot);
        x++;
    }
    printf("%s is a multiple of 9 and has 9-degree %d.\n",ar,x);

}

return 0;
}

