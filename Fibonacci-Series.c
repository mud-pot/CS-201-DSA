/*
    Mini Project-I: C Program for Large Fibonacci Number
    Name: Mudra Das
    Scholar ID: 2012011
    Data Structures
    CS - 201
    Department of Computer Science and Engineering 
    National Institute of Technology, Silchar
*/


#include <stdio.h>
#define max 4500

char f1[max];
char f2[max];
char result[max];


void sum(char a[], char b[], char result[]){
  int carry = 0;
  for (int i=max-1; i>=0; i--){
    int temp = (a[i] - '0') + (b[i] - '0') + carry;
    result[i] = (temp%10) + '0';
    carry = temp/10;
  }
}

void copy(char a[], char b[]){
  for (int i = max-1; i>=0; i--)
    a[i] = b[i];
}

int main()
{
  for (int i=0; i<max; i++){
    f1[i]=f2[i]=result[i]='0';
  }
  f2[max - 1]='1';

  int n;
  printf("Enter the nth term: \n");
  scanf("%d", &n);

  if (n==1 || n==0){
    printf("%c", n +'0');
    }

  else{
    for (int i = 2; i <= n; i++){
      sum(f1, f2, result);
      copy(f1, f2);
      copy(f2, result);
    }

    int NumStart = 0;
    for (int i=0; i<max; i++)
    {
      if (NumStart==0 && result[i]=='0')
        continue;

      if (NumStart==0 && result[i] !='0')
        NumStart = 1;
      printf("The %dth Fibonacci Number is: %c", n, result[i]);
    }
     printf("\n");
  }
  return 0;
}
