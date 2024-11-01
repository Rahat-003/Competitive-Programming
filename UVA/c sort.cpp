#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int main(){
   int i,j;
   int c=10;
char *str[100];
    for (i=0; i<100; i++)
         str[i] = (char *)malloc(100 * sizeof(char));


    char *temp = (char *)malloc(100 * sizeof(char));
   for(i=0;i<c;i++)
      gets(str[i]);
   for(i=0;i<c;i++)
      for(j=i+1;j<c;j++){
         if(strcmp(str[i],str[j])>0){
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
         }
      }
   printf("Order of alphabetic order:\n");
   for(i=0;i<c;i++)
      puts(str[i]);

   return 0;
}
