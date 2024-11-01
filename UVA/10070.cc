#include <bits/stdc++.h>
//#include <string.h>
using namespace std;
#define mx 1000005
int main(){
//  freopen("tst.txt","r",stdin);
string s;
bool fl =false;
while(cin>>s){
    if(fl)  printf("\n");
//    cin>>s;
    fl = true;
    string ans,rem;
    int x=0,y=0,z = 0, hx=0, bx=0;
    bool ly = false, hulu = false, bulu = false;

    for(int i=0;i<s.size();++i){
    x = 10*x + s[i] - '0';
    y = 10*y + s[i] - '0';
    z = 10*z + s[i] - '0';
   hx = 10*hx+ s[i] - '0';
   bx = 10*bx+ s[i] - '0';

    x = x%4;
    y = y%100;
    z = z%400;
    hx = hx%15;
    bx = bx%55;
  }
  if(!z || (y && !x))
    ly = true;

  if(ly)  puts("This is leap year.");
  if(!hx){
    puts("This is huluculu festival year.");
  hulu = true;
  }
  if(ly && !bx){
    puts("This is bulukulu festival year.");
  bulu = true;
  }
  if(!ly && !hulu && !bulu) puts("This is an ordinary year.");


}

return 0;
}
