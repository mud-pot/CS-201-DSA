#include <stdio.h>
#define MAX 100

int FloatValid(char n[])
{
  int ValidFloat = 0;
  for (int i=0; i<MAX-1; i++)
  {
    if (n[i] == '.' && n[i + 1] != 0)
      ValidFloat = 1;
  }
  return ValidFloat;
}

int main()
{
  char n[MAX] = {0};
  printf("Enter the number: ");
  scanf("%s", n);
  printf("The floating point number is %s\n", ((FloatValid(n)) ? "valid" : "invalid"));
  return 0;
}
