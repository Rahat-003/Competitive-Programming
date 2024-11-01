#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s,r,temp,rtemp;
    cin>>s;
    r=s;
    int cnd=0;
    reverse(r.begin(),r.end());
    int x=s.size();
    int i;
    for(i=1;i<s.size();i++){
        temp="",rtemp="";
    temp.assign(s.begin(),s.end()-i);
    rtemp=temp;
    reverse(rtemp.begin(),rtemp.end());
        if(temp==rtemp && i!=x){
                cnd=1;
                break;}
    }
    if(cnd==1){
        string tmp,rtmp;
        tmp.assign(s.begin()+i,s.end());
        rtmp=tmp;
        reverse(rtmp.begin(),rtmp.end());
        if(rtmp==tmp)
            cout<<"alindrome\n";
        else cout<<"simple\n";
    }
    else if(cnd==0){
        if(s==r) cout<<"palindrome\n";
        else cout<<"simple\n";

    }
}


return 0;
}
