
#include <bits/stdc++.h>
using namespace std;

string f(string s){
  int i;
  for( i=0;i<s.size(); i++)
    if(s[i]!='0') break;

  string m = s.substr(i);
  return m;
}

int carry(string s,string t){
  int cnt = 0, cry = 0;
  for(int i = t.size()-1, j =s.size()-1; i>=0 || j>=0; i--,j--){
       int x = t[i] - '0';
    if(j>=0){
       int y = s[j] - '0';
       int sum = x+y+cry;
       if(sum>9 ){
        cnt++;
       }
        cry = sum/10;
    }
    else{
      if(cry+x>9){
        cnt++;
      }
        cry = (x+cry)/10;

    }

  }

  return cnt;
}

int main(){

string s,t;

while(cin>>s>>t){
  if(s=="0" && t=="0")  break;
  s = f(s);
  t = f(t);
  if(s.size()>t.size()) swap(s,t);

//  cout<<s<<" "<<t<<endl;

  int ans = carry(s,t);
  if(ans) printf("%d",ans);
  else printf("No");
  printf(" carry operation");

  if(ans>1) puts("s.");
  else puts(".");
}





return 0;
}
