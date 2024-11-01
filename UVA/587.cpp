#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi (acos(-1.0))

double degToRad(double deg){
    return deg*pi/180.0;
}

double radTodeg(double rad){
return 180.0/pi*rad;
}
#define sin45 sin(degToRad(45))
double x,y;

string make(string s){
    string t;
    for(int i = 0; i<s.size(); i++){
        if(s[i]!=' ')   t.push_back(s[i]);
    }
    return t;
}

void cal(string s){
    string t;
    int p;
    double n;
    istringstream iss(s);
    iss>>p>>t;

    n = (double)p;

    t = make(t);
    if(t=="N")  y+=n;
    else if(t=="S")  y-=n;
    else if(t=="E")  x+=n;
   else if(t=="W")  x-=n;

    else if(t=="NW"){
        x-= n*sin45;
        y+= n*sin45;
    }

    else if(t=="NE"){
        x+= n*sin45;
        y+= n*sin45;
    }
    else if(t=="SE"){
        x+= n*sin45;
        y-= n*sin45;
    }
    else if(t=="SW"){
        x-= n*sin45;
        y-=n*sin45;
    }
}

int main(){

string s;
int tc = 0;
while(getline(cin,s)){
    if(s=="END")    break;
    x = 0;y = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i]==',' || s[i]=='.')  s[i] = ' ';
    }
    string t;
    istringstream iss(s);
    while(iss>>t)   cal(t);

    double dis = hypot(x,y);
//    if(tc)
    printf("Map #%d\n",++tc);
    printf("The treasure is located at (%.3f,%.3f).\n",x,y);
    printf("The distance to the treasure is %.3f.\n",dis);
        puts("");

}

return 0;
}

