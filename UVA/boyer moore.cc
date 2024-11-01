
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
 char haystack[1000];
/* Returns a pointer to the first occurrence of "needle"
 * within "haystack", or NULL if not found. Works like
 * memmem().
 */

/* Note: In this example needle is a Cstring. The ending
 * 0x00 will be cut off, so you could call this example with
 * boyermoore_horspool_memmem(haystack, hlen, "abc", sizeof("abc"))
 */


 int cnt=0;
void boyermoore_horspool_memmem( char* haystacks,size_t hlen,char* needle,size_t nlen){
    size_t scan = 0;
    size_t bad_char_skip[UCHAR_MAX + 1]; /* Officially called:
                                          * bad character shift */
//cout<<haystacks<<endl;
    /* Sanity checks on the parameters
    if (nlen <= 0 || !haystacks || !needle)
        return NULL;
    */

    /* ---- Preprocess ---- */
    /* Initialize the table to default value */
    /* When a character is encountered that does not occur
     * in the needle, we can safely skip ahead for the whole
     * length of the needle.
     */
    for (scan = 0; scan <= UCHAR_MAX; scan = scan + 1) bad_char_skip[scan] = nlen;

    /* C arrays have the first byte at [0], therefore:
     * [nlen - 1] is the last byte of the array. */
    size_t last = nlen - 1;

    /* Then populate it with the analysis of the needle */
    for (scan = 0; scan < last; scan = scan + 1) bad_char_skip[needle[scan]] = last - scan;

    /* ---- Do the matching ---- */

    /* Search the haystack, while the needle can still be within it. */
    while (hlen >= nlen){
        /* scan from the end of the needle */
//        cout<<haystacks[last]<<endl;
        for (scan = last; haystacks[scan] == needle[scan]; scan = scan - 1){
            /* If the first byte matches, we've found it. */
            if (scan == 0)
            {
//                 cout<<haystacks-haystack<<" ";
//                    return haystack;
            }
        }
//        cout<<endl;
      cout<<haystacks<<" ";
        hlen      -= bad_char_skip[haystacks[last]];
        haystacks += bad_char_skip[haystacks[last]];
//        cout<<hlen<<" ";

    }

    //return NULL;
}

int main(){
     char needle[1000];
    cin>>haystack>>needle;
  int needle_length = strlen(needle),
    haystack_length = strlen(haystack);

//  cout<<needle_length<<" "<<haystack_length<<endl;;
  boyermoore_horspool_memmem( haystack, haystack_length, needle, needle_length);

//  int pos = result - haystack ;
//    cout<<pos<<endl;
}










