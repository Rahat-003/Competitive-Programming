
///ajaira problem

#include <bits/stdc++.h>
using namespace std;

string s,ans,t;
vector<char> v = {'a','e','i','o','u','A','E','I','O','U'};

vector<char> ltr;

void func(int x,int y){
  auto it = find(v.begin(),v.end(),t[x+1]);
  if(it!=v.end()){
    for(int i=x+1;i<y;++i)
      ans.push_back(t[i]);
  }
  else {
    for(int i=x+2;i<y;++i)
      ans.push_back(t[i]);
    ans.push_back(t[x+1]);
  }
  ans += "ay";
}

bool letter_check(char c){
  auto it = find(ltr.begin(),ltr.end(),c);
  if(it!=ltr.end())
    return true;
  return false;
}



int main(){
//  freopen("tst.txt","r",stdin);

  for(int i=0;i<26;++i){
    ltr.push_back('a'+i);
    ltr.push_back('A' + i);
  }


while(getline(cin,s)){
  int x,y;
  t = " ";
  ans="";
  t+=s;
//  t.push_back(' ');
  for(int i=0;i<t.size();++i){
    if(!letter_check(t[i])){
      x = i;
      ans.push_back(t[i]);

      if(letter_check(t[i+1])){
      for(int j=i+1;j<t.size();++j){
        if(!letter_check(t[j])){
          y = j;
         break;
        }
        else if(j==t.size()-1){
            y = j+1;
          break;
      }
      }
    if(x<y)  func(x,y);
      }
    }
    }

  ans = ans.substr(1);
  cout<<ans<<endl;

}


return 0;
}
