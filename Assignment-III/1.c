#include <stdio.h>
#define MAX 1000

long long int hashString(char s[MAX]) {

  long long int hash = 0;
  for(int i=0; i<MAX && s[i]!='\0'; i++){
    hash+= (i+1)*s[i];
  }
  return hash;
}

int main(){
  char s[MAX] = {0};
  printf("Enter the string: ");
  scanf("%[^\n]", s);
  printf("The hash value is: %lld\n", hashString(s));

  return 0;
}
