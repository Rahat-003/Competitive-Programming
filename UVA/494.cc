#include <bits/stdc++.h>
using namespace std;
vector<char> letter;

int main(){
  for(int i=0;i<26;++i){
    letter.push_back('a'+i);
    letter.push_back('A'+i);
  }
string s;
while(getline(cin,s)){
  s.push_back(' ');
  int cnt=1;
  auto it = find(letter.begin(),letter.end(),s[0]);
    if(it==letter.end())  cnt=0;
  for(int i=0;i<s.size();++i){
    auto it = find(letter.begin(),letter.end(),s[i]);
    auto jt = find(letter.begin(),letter.end(),s[i+1]);
    if(it==letter.end() && jt==letter.end())
      continue;
    if(it==letter.end())
      cnt++;
  }
  cout<<cnt<<endl;
}




return 0;
}
