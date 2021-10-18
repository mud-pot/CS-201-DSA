#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

char sym[13][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

int NumSize(char num[MAX]) {
  int size = MAX;
  for (int i=0; i<MAX; i++)
  {
    if (num[i] == '\0')
    {
      size = i;
      break;
    }
  }
  return size;
}

int RomToDec(char num[MAX]) {
  int count = 0;
  int size = NumSize(num);

  for (int i=0; i<size; i++) {
    for (int j=12; j>=0; j--) {
      if (num[i] == sym[j][0]) {
        if (sym[j][1] == '\0')
        {
          count += nums[j];
          break;
        }
        else if (i+1<size && num[i+1] == sym[j][1])
        {
          count += nums[j];
          i++;
          break;
        }
      }
    }
  }
  return count;
}

char *DecToRom(int n) {

  char *num = (char *)malloc((MAX) * sizeof(char));
  for (int i=0; i<MAX; i++)
    num[i] = 0;

  int index = 0;
  while (n)
  {
    for (int i=12; i>=0 && n; i--)
    {
      if (n >= nums[i])
      {
        n -= nums[i];

        num[index] = sym[i][0];
        index++;

        if (sym[i][1] >= 'A' && sym[i][1] <= 'Z')
        {
          num[index] = sym[i][1];
          index++;
        }

        break;
      }
    }
  }
  num[index] = '\0';
  return num;
}

int Add(int num1, int num2) {
  return num1 + num2;
}

int Mul(int num1, int num2) {
  return num1 * num2;
}

int main() {

  char Num1[MAX] = {0}, Num2[MAX] = {0};
  int num1, num2;

  printf("Enter the first roman number: ");
  scanf("%s", Num1);
  num1 = RomToDec(Num1);

  printf("Enter the second roman number: ");
  scanf("%s", Num2);
  num2 = RomToDec(Num2);

  int op;
char *result;
    printf("Select any one operation(1.Addition  2.Multiplication): ");
    scanf("%d",&op);

  switch (op) {
  case 1:
    result = DecToRom(Add(num1, num2));
    printf("The Sum is: %s\n", result);
    break;

  case 2:
    result = DecToRom(Mul(num1, num2));
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
