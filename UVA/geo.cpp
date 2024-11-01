#include <bits/stdc++.h>

using namespace std;

int main(){

int t;
cin>>t;
while(t--){
    double r1,r2,r3;
    cin>>r1>>r2>>r3;
    double m1=r2+r3;
    double m2=r1+r3;
    double m3=r1+r2;
    double theta1=acos((m2*m2+m3*m3-m1*m1)/(2*m2*m3));
        double theta2=acos((m1*m1+m3*m3-m2*m2)/(2*m1*m3));
            double theta3=acos((m2*m2+m1*m1-m3*m3)/(2*m2*m1));
double per=(m1+m2+m3)/2.0;
double areaoftri=sqrt(per*(per-m1)*(per-m2)*(per-m3));
double areaof=(.5*r1*r1)+(.5*r2*r2)+(.5*r3*r3);
cout<<fixed<<setprecision(5)<<areaoftri-areaof<<endl;


}

return 0;
}
