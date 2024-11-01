#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;


int main(){

float h,u,d,f;
while(cin>>h>>u>>d>>f){
        if(h==0) break;
    int day=0;
    float ff,today,total,ini=0,mul;
    ff=1-f/100;
    while(1){
        day++;
        if(day==1){
            today=u;
            total=ini+today;
        }
        ini=total-d;
        cout<<day<<". "<<today<<" "<<total;
        if(total>h){
            break;
        }

        mul=ff*u;
        today= mul;
        total=ini+today;
        u=today;
        cout<<" -> "<<ini<<endl;
        if(ini<0){
            break;
        }

        }
        cout<<endl;
    }



return 0;
}
