/// uva 12541 Birthdates

#include <bits/stdc++.h>
using namespace std;

class node{
  int y,m,d;
public:
  string s;
  node(int W=0,int A = 0, int B = 0,string  S=""){
  m = A;
  d = B;
  y = W;
  s = S;
  }
  bool operator<(const node& n) const {
    if(y<n.y) return true;
    if(y==n.y && m<n.m) return true;
    if(y==n.y && m==n.m && d<n.d) return true;
    return false;
  }
};
///ABOUT OVERLOADING-----
/**

যদি  sort(v.begin(),v.end()); এর পরিবর্তে    sort( v.begin(),v.end(),less<node>() >; use করি তাহলে  overloading
er somoy obosshoi (MUST)
  bool operator < (const node &n) const {
    //code here..

  }
ei member function/method ta je accessor seta bujhay deyar jonno second bracket shurur age const likhte hobe..
ebong arguement eo const likhte hobe

ar sort( v.begin(),v.end() ) use korle  accessor ki na seta na bujhaleo cholbe.. ebong function er arguement
e const na likhleo cholbe... optional.. jeta mone chay. Iccha... Teo Teo.. :) :) :D

tobe recommended hocche sobsomoy const likhe accessor method bujhano..
ar argument eo const use kora..At least overloading function gulo te..

method means member function....

Methods are of 2 types..
  1. Accessor method:
        Jei function gulo shudhu member variable access kore.. kono maan change kore na..
  2. Update method:
        Jei function gulo member variable er maan update korte pare...

Overloading 2 types..
  1. Unary operator overloading
  2. Binary operator overloading

  Unary operator overloading temon lage na..
  Unary operator overloading er method e kono argument jabe na.. khali faka bracket ()....teo teo.. :)

  Unary operator means je operator ekta operand er upor kaaj kore .. jemon +5, -2..
  Binary operator means je operator 2 ta operand er upor kaaj kore..
    jemon 5+2, 2<5 etc.....
*/

int main(){
vector<node> v;
int m,d,y;
string n;
int e;
cin>>e;
while(e--){
  cin>>n>>d>>m>>y;
  node person(y,m,d,n);
  v.push_back(person);
}
sort( v.begin(),v.end(), less<node>()  ); ///since less is default it can be omitted.. Like this...
                                          /// sort( v.begin(),v.end() );

string snr = v[0].s;
string jnr = v[v.size()-1].s;
cout<<jnr<<endl;
cout<<snr<<endl;

return 0;
}
