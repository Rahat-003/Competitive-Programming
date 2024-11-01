    #include <iostream>
    #include <cstdio>
    #include <cmath>
    #include <vector>
    #include <memory.h>
    #include <algorithm>
    #define read        freopen("tst.txt","r",stdin)
    #define write       freopen("out.txt","w",stdout)
    typedef long long ll;
    using namespace std;

    #define pi acos(-1)
    double dtor(double x){return x*pi/180.0;}
    double rtod(double x){return x*pi/180.0;}

    struct z{
        double r,t;
        z(double a,double b){r = a,t = b;}
    };


    int main(){
//        read;
    int e;
    double T;

    while(cin>>e>>T){
    //    vector<z> v;
        vector<double> ans;
        double x = 0,y = 0;

        for(int i = 0; i<e; i++){
            double r,t; cin>>r>>t;
            double theta = dtor(360*T/t);
            x+=r*cos(theta);
            y+=r*sin(theta);
            ans.push_back(hypot(x,y));
        }

        bool fl = false;
        for(auto i:ans){
            if(fl)  printf(" ");
            printf("%.4f",i);
            fl = true;
        }
        puts("");
        ans.clear();
    }

    return 0;
    }
