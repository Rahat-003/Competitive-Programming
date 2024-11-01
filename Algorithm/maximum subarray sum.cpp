#include <bits/stdc++.h>
using namespace std;

vector<int> ar = {-1,8,-2,1,-3,4,-3,-2,6};

int maximumSubarraySum(int &x,int &y){
    int s = 0;
    int ans = -1000000;
    for(int i = 0;i<ar.size(); i++){
        if(s<0){
            s = 0;
            x = i;
        }
        s+=ar[i];
        if(s>=ans){
            ans = s;
            y = i;
        }

    }
return ans;
}


int main(){

int x,y;
///x and y is the range.

int ans = maximumSubarraySum(x,y);

cout<<ans<<" "<<x<<" "<<y<<endl;





return 0;
}
