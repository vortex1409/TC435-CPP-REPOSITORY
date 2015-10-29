//C program to check odd or even using modulus operator
#include <stdio.h>
 
int main()
{
   int n;
 
   printf("Enter an integer\n");
   scanf("%d", &n);
 
   if (n%2 == 0)
      printf("Even\n");
   else
      printf("Odd\n");
 
   return 0;
}

//C program to check odd or even using bitwise operator
#include <stdio.h>
 
int main()
{
   int n;
 
   printf("Enter an integer\n");
   scanf("%d", &n);
 
   if (n & 1 == 1)
      printf("Odd\n");
   else
      printf("Even\n");
 
   return 0;
}

//Find odd or even using conditional operator
#include <stdio.h>
 
int main()
{
   int n;
 
   printf("Input an integer\n");
   scanf("%d", &n);
 
   n%2 == 0 ? printf("Even\n") : printf("Odd\n");
 
   return 0;
}

//C program to check odd or even without using bitwise or modulus operator
#include <stdio.h>
 
int main()
{
   int n;
 
   printf("Enter an integer\n");
   scanf("%d", &n);
 
   if ((n/2)*2 == n)
      printf("Even\n");
   else
      printf("Odd\n");
 
   return 0;
}
