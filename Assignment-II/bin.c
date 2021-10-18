#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int log2(int n) {
  return (n>1) ? (1 + log2(n/2)) : 0;
}

int BinToDec(char num[MAX]) {
  int count = 0;
  for(int i=0; i<MAX; i++) {
    if(num[i] == '1') {
      count*=2;
      count+=1;
    } else if (num[i] == '0')
      count*=2;
  }

  return count;
}

char *DecToBin(int n) {

  int size = log2(n) + 1;
  char *num = (char *) malloc((size + 1) * sizeof(char));

  for(int i = size-1; i>=0; i--) {
    num[i] = (n%2) + '0';
    n/=2;
  }

  num[size] = '\0';
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
  
  printf("Enter number 1 ");
  scanf("%s", Num1);
  num1 = BinToDec(Num1);

  printf("Enter number 2 > ");
  scanf("%s", Num2);
  num2 = BinToDec(Num2);

  int op;
  printf("\n");
  printf("1. Addition\n");
  printf("2. Multiplication\n");
  printf("Enter operation 1/2 > ");
  scanf("%d", &op);

  char *result;
  switch(op) {
    case 1:
      result = DecToBin(Add(num1, num2));
      printf("Result > %s\n", result);
      break;
    
    case 2:
      result = DecToBin(Mul(num1, num2));
      printf("Result > %s\n", result);
      break;

    default:
      printf("Invalid Operation\n");
      return 0;
      break;
  }
  free(result);
  return 0;
}
