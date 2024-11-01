#include <bits/stdc++.h>
using namespace std;

int pour(int a,int b, int p){
    int from = a;
    int to = 0;
    int step = 1;

    while(from!=p && to!=p){

        int temp = min(from,b-to);

        from-=temp;
        to+=temp;

        step++;

        if(from==p || to==p)    break;

        if(from==0){
            from = a;
            step++;
        }

        if(to==b){
            to = 0;
            step++;
        }
//   cout<<"b";
    }
//    cout<<endl;
    return step;
}


int main(){

int m,n,p;
cin>>m>>n>>p;

int x = pour(m,n,p);
int y = pour(n,m,p);


cout<<x<<" "<<y<<endl;




return 0;
}
