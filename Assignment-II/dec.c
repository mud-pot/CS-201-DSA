#include <stdio.h>

int Add(int num1, int num2) {
  return num1 + num2;
}

int Mul(int num1, int num2) {
  return num1*num2;
}

int main() {
  int num1, num2;
    printf("Enter the first decimal number: ");
  scanf("%d", &num1);

  printf("Enter the second decimal number: ");
  scanf("%d", &num2);

int op;
    printf("Select any one operation(1.Addition  2.Multiplication): ");
    scanf("%d",&op);

  switch(op) {
    case 1:
      printf("The Sum is: %d\n", Add(num1, num2));
      break;
    
    case 2:
      printf("The Product is: %d\n", Mul(num1, num2));
      break;

    default:
      printf("Invalid Operation\n");
      return 0;
      break;
  }
  return 0;
}
