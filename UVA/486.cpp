#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string s = "negative, zero, one, two, three, four, five, six, seven, eight, nine, ten,eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety, hundred,thousand, million ";
vector<int> v;
vector<string> ss,wrd;

void word(string w){
 // w.insert(0," ");
  w.push_back(' ');
  string a = "";
  for( int i=0;i<w.size(); ++i ){
    if(w[i]!=' ') a.push_back(w[i]);
    else{
      if(a.size())  wrd.push_back(a);
      a = "";
    }
  }
  /*
  for(int i=0;i<wrd.size();++i)
    cout<<wrd[i]<<" ";
*/
}

void vv(){
int j=-1;
while(j<=100){
  v.push_back(j);
  if(j>=20) j+=10;
  else j++;
}
}




int main(){

  //freopen("tst.txt","r",stdin);

  string a = "";

for(int i=0;i<s.size();++i){
  if(s[i]!=',' && s[i]!=' ')
    a.push_back(s[i]);
  else {
   if(a.size()) ss.push_back(a);
    a="";
  }
}
vv();
v.push_back(1000);
v.push_back(1000000);

for(int i=0;i<v.size(); ++i)
  mp[ss[i]] = v[i];

string g;

while(getline(cin,g)){
  word(g);
  int ans = 0,i=0,w;
  w = 0;
  if( wrd[0]=="negative") w=1;

  int ans2=0;
  int bb=0;
  for(int i=w;i<wrd.size();++i){
    string unit  = wrd[i];

    if(unit=="hundred"|| unit=="thousand" || unit=="million"){

    if(ans<mp[unit]){
      ans*=mp[unit];

     // ans2 = ans;
    }
    else{

      bb = (ans - ans2)*mp[unit];
      ans = ans2 + bb;
    }
    if(unit!="hundred") ans2 = ans;


    }

    else ans+=mp[unit];

//    cout<<ans<<"\n";
  }

  if(wrd[0]=="negative")  ans*=-1;
//  cout<<" = "<<ans<<endl;




cout<<ans<<endl;










/*
  for(int i=0;i<wrd.size();++i)
    cout<<wrd[i]<<" ";
//cout<<endl;
for(auto it = mp.begin();it!=mp.end();++it)
  cout<<it->first<<" "<<it->second<<endl;
    */

wrd.clear();

}







return 0;
}
