#include <iostream>
#include <set>
using namespace std;
set<int> s1={2,3,5,7};
set<int> s2={11, 13, 17, 31, 37, 71, 73, 79, 97};
set<int> s3={113, 131, 199, 311, 337, 373, 733, 919, 991};
int check(int n){
if(n/10==0){
    for(int i=n+1;i<=9;i++){
      if(  s1.find(i)!=s1.end())
        return i;
    }

}
else if(n/100==0){
    for(int i=n+1;i<=99;i++){
      if(  s2.find(i)!=s2.end())
        return i;



    }
}
else if(n/1000==0){
    for(int i=n+1;i<=999;i++){
      if(  s3.find(i)!=s3.end())
        return i;
    }
}
return 0;
}

int main(){
    int n;
while (cin>>n&&n){
    cout<<check(n)<<endl;
}




return 0;
}
