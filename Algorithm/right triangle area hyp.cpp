#include <bits/stdc++.h>

using namespace std;
int cnt;

double equation(double b,double c){

return b*b*c*c-b*b*b*b;
}

double solve( double hyp, double area ){
double x = area*area*4;
double high = hyp;
double low = 0.0;
cnt = 0;
while(true){
cnt++;
    double base = (high+low)/2.0;

    if(abs(equation(base,hyp)-x)<=1e-15)
        return base;
    else if(equation(base,hyp)>x)
            high=base;
    else
        low=base;
}

}


int main(){

double hyp,area;
cin>>hyp>>area;
cout<<solve(hyp,area)<<" "<<sqrt(hyp*hyp-solve(hyp,area)*solve(hyp,area))<<" "<<endl;
return 0;

}
