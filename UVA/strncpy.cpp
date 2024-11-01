#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;
int main ()
{
  char str1[]= "To be or not to be";
  char str2[40];
  char str3[40];

  /* copy to sized buffer (overflow safe): */
  strncpy ( str2, str1, sizeof(str2) );

  /* partial copy (only 5 chars): */
  strncpy ( str3, str1, 5 );
  str3[5] = '\0';   /* null character manually added */

 // puts (str1);
  //cout<<str2<<endl;
  cout<<strlen(str3)<<endl;
  cout<<str3[7];

  return 0;
}
