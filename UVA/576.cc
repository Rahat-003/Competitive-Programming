#include <bits/stdc++.h>
using namespace std;
string w = "aeiouy";
vector<char> vowel;
int func(string s){
  s.push_back(' ');
  int cnt = 0;
  for(int i=0;i<s.size()-1;++i){
    auto it = find(vowel.begin(),vowel.end(),s[i]);
    auto jt = find(vowel.begin(),vowel.end(),s[i+1]);
  if(it!=vowel.end() && jt!=vowel.end())  continue;
  if(it!=vowel.end()) cnt++;
  }
  return cnt;
}

int syllable(string t){
  vector<string> v;
  string s = " ";
  s +=t;
  s.push_back(' ');
  int i1=0;
  for(int i=0;i<s.size()-1;++i){
    if(s[i]==' ' && s[i+1]!=' '){
      int x = i+1,y;
      for(int j=x;j<s.size();++j){
        if(s[j]==' '){
          y=j;
          break;
        }
      }
      if(x<y){
        string m = s.substr(x,y-x);
        v.push_back(m);
      }
    }
  }
  int cnt=0;
  for(int i=0;i<v.size();++i){
    cnt += func(v[i]);
  }

  return cnt;
}

int main(){
for(int i=0;i<w.size();++i)
  vowel.push_back(w[i]);

string s;
while(getline(cin,s)){
  if(s=="e/o/i")  break;
  vector<int> y;
  s.push_back(' ');
  int i1=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='/' || i==s.size()-1){
      string p = s.substr(i1,i-i1);
      i1 = i+1;
     int t = syllable(p);
     y.push_back(t);
    }
  }
  bool fl = true;
  for(int i=0;i<y.size();++i){
    if(i%2==0 && y[i]!=5){
      cout<<i+1<<endl;
      fl = false;
      break;
    }
    if(i==1 && y[i]!=7){
      cout<<i+1<<endl;
      fl = false;
      break;
    };
  }
  if(fl)  cout<<"Y\n";
}
return 0;
}
