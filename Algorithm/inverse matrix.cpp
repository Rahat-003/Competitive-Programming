#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

double M[4][4],ans[4][4];

double mm(double p[2][2]){
    return p[0][0]*p[1][1] - p[0][1]*p[1][0];
}


double exc(int a,int b){
    double t[3][3];
    int r= 0,c = 0;
    for(int i = 0; i<3; i++){
        if(i==a)    continue;
        c = 0;
        for(int j = 0; j<3; j++){
            if(j==b)    continue;
            t[r][c++] = M[i][j];
        }
        r++;
    }
    return t[0][0]*t[1][1] - t[0][1]*t[1][0];
}

void inv(){
    double m = M[0][0]*exc(0,0) - M[0][1]*exc(0,1)+M[0][2]*exc(0,2);
    double R[4][4];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            R[i][j] = exc(i,j);
            if(i%2==0 && j&1)   R[i][j]*=-1;
            if(i&1 && j%2==0)   R[i][j]*=-1;
            ans[j][i] = R[i][j];
        }
    }
    puts("");
    /*
    for(int j = 0; j<3; j++){
        for(int i = 0; i<3; i++)
            ans[j][i] = R[i][j];
    }
    */
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    puts("");
    cout<<"|A| = "<<m<<endl;
    puts("");
}

int main(){

int tc = 0,r=3,c=3;

while(true){
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>M[i][j];
        }
    }
    inv();
    /*
    int a,b;
    while(cin>>a>>b)
        exc(a,b);
    */
}



return 0;
}

