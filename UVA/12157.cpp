#include <iostream>
#include <cstdio>
using namespace std;



int main(){
int t,n,i=0;
cin>>t;
while(t--){
        i++;
        int pkg,m=0,j=0;

    cin>>n;
    while( n-- ){
        cin>>pkg;
        m+=1+pkg/30;
        j+=1+pkg/60;
//        m+=m;j+=j;
}


        if(10*m==j*15) printf("Case %d: Mile Juice %d\n",i,10*m);
        else if(10*m<j*15) cout<<"Case "<<i<<": Mile "<<10*m<<endl;
        else printf("Case %d: Juice %d\n",i,j*15);

}





return 0;
}
