
#include <cstdio>
#include <cstring>
char ar[1003];

bool isMultiple(){
    int x = 0,y;
    for(int i = 0; i<strlen(ar); i++){
        int d = ar[i]-'0';
        if(d>9) continue;
        y = 10*x+(ar[i] - '0' );
        x = y%11;
    }

    return x==0;
}

int main(){


while(1==scanf("%s",ar)){
    if(ar[0]=='0' && strlen(ar)==1)   break;
    if(isMultiple()){
        printf("%s is a multiple of 11.\n",ar);
        continue;
    }
    printf("%s is not a multiple of 11.\n",ar);

}


return 0;
}

