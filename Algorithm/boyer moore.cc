#include <bits/stdc++.h>
using namespace std;
#define mx 1000
char txt[mx], pat[mx];
int bcs[256]; ///bad character skip

void boyer_moore(){
  char *new_pos = txt;
  int tsz= strlen(txt), psz = strlen(pat);
  for(int i=0;i<256;++i)
    bcs[i] = psz;
  for(int i=0;i<psz-1;++i)
    bcs[pat[i]] = psz-1-i;

  while(tsz>=psz){
    for(int i=psz-1; new_pos[i]==pat[i]; --i){
      if(i==0)
        cout<<new_pos-txt<<" ";
    }
    tsz     -= bcs[new_pos[psz-1]];
    new_pos += bcs[new_pos[psz-1]];

  }




}



int main(){
cin>>txt>>pat;

boyer_moore();




return 0;
}
