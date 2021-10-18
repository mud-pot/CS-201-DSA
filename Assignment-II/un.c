#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int UnToDec(char num[MAX]) {
  int count=0;
  for(int i=0; i<MAX; i++)
    if(num[i] == 'I')
      count++;
  return count;
}

char *DecToUn(int n) {
  char *num = (char *) malloc((n+1) * sizeof(char));
  for(int i=0; i<n; i++)
    num[i] = 'I';
  num[n] = '\0';
  return num;
}

int Add(int num1, int num2) {
  return num1 + num2;
}

int Mul(int num1, int num2) {
  return num1*num2;
}

int main() {
  char Num1[MAX] = {0}, Num2[MAX] = {0};
  int num1, num2;
  
  printf("Enter the first number: ");
  scanf("%s", Num1);
  num1 = UnToDec(Num1);

  printf("Enter the second number: ");
  scanf("%s", Num2);
  num2 = UnToDec(Num2);

int op;
char *result;
    printf("Select any one operation(1.Addition  2.Multiplication): ");
    scanf("%d",&op);


  switch(op) {
    case 1:
      result = DecToUn(Add(num1, num2));
      printf("The Sum is: %s\n", result);
      break;
    
    case 2:
      result = DecToUn(Mul(num1, num2));
      printf("The product is: %s\n", result);
      break;

    default:
      printf("Invalid Operation\n");
      return 0;
      break;
  }
  free(result);
  return 0;
}
