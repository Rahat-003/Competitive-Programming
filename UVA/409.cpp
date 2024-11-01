#include <bits/stdc++.h>
using namespace std;

vector<string> excuse, sentence;
vector<int> num;

map<string,bool> mp1;
//map<string,

int mx = -1;

void clr(){
  excuse.clear();
  sentence.clear();
  num.clear();
  mp1.clear();
}

void word(string s, int id){

  transform(s.begin(),s.end(),s.begin(),::tolower);

  string a = "";

  map<string,int> mp2;

  for(int i=0;i<excuse.size();++i)
    mp2[excuse[i] ] = 1;


  for(int i=0;i<s.size(); ++i){
    int x = s[i];

    if( a.size() && mp1[a] && mp2[a]==1  )  {
        num[id]++;
        mp2[a]++;
    }
    if(x>=97 && x<=122) a.push_back(s[i]);

    else{
      a="";
    }
  }

  if(mx<num[id])  mx = num[id];

}


int main(){

int tc = 0;
int a,b;

while(cin>>a>>b){

    mx = -1;
  while(a--){
    string s; cin>>s;
    excuse.push_back(s);
    mp1[s] = true;
  }
  cin.ignore();
  num.assign(b,0);
  while(b--){
    string s;
    getline(cin,s);
    sentence.push_back(s);
  }
  for(int i=0;i<sentence.size();++i){
    word( sentence[i], i );
  }


  printf("Excuse Set #%d\n",++tc);
    for(int i=0;i<sentence.size(); ++i){
    if(num[i]==mx)
      cout<<sentence[i]<<endl;
  }
  cout<<endl;
  clr();
}








return 0;
}
