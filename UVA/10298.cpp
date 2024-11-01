#include <bits/stdc++.h>
using namespace std;

int make_ar(string s){
    int S = s.size();
    int i =0;
    int  j =1;
    int ar[S];
    ar[0] = 0;
    while(j<S){
        if(s[i]==s[j]){
            i++;
            ar[j] =i;
            j++;
        }
        else{
            if(i!=0)    i =ar[i-1];
            else{
                ar[j] = 0;
                j++;
            }
        }
    }
    return ar[S-1];


}

int main(){
string s;
while(cin>>s){
    if(s==".")  break;
    int x = make_ar(s);
    cout<< s.size()/(s.size()-x)<<endl;
}




return 0;
}
