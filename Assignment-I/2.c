#include<stdio.h>

int main(){

  char email[100];
  printf("Enter the email address: ");
  scanf("%s",email);

  int i=0, flag = 0, count = 0, AtIndex = -1, DotIndex = -1;

  while(email[i]!='\0')
  {
    if((email[i] >= 'A' && email[i] <= 'Z') 
        || (email[i]>='a' && email[i]<='z') 
        || (email[i]>='0' && email[i]<='9') 
        || (email[i]=='.' || email[i]=='-'  || email[i]=='_' || email[i]=='@') 
        && (i!=0 && email[i+1]!='\0')){
      flag = 1;
    }
    else{
      flag = 0;
      break;
    }
    if(email[i]=='@'){
      count++;
      AtIndex = i;
    } 
    if(email[i]=='.'){
      DotIndex = i;
    }
    i++;
  }

  if(flag && (DotIndex - AtIndex)>3 && count==1){
    printf("The email address is valid\n");
  } 
  else{
    printf("The email address is not valid\n");
  }
  return 0;
}
