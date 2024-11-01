#include <bits/stdc++.h>
using namespace std;
string num = "0123456789";
string ltr = "OIZEASGTBP";

int main(){

int t;
cin>>t;
bool fl = false;

  cin.ignore();

while(t--){
  string s,ans;
  if(fl) cout<<endl;

  fl = true;

  while(getline(cin,s)){

    if(s.size()==0){
      break;
    }
    for(int i=0;i<s.size(); i++){
        int x = s[i] - '0';
      if(x<10 && x>=0){
        ans.push_back(ltr[x]);
      }
      else ans.push_back(s[i]);

    }
    ans.push_back('\n');
  }
      cout<<ans;

}

return 0;
}
