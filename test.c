#include<stdio.h>
#include<string.h>
#include<conio.h>
int main() {
   char pass[] = "1234";
   char answer[100];
   int buffer = 0;
   int i = 0;
   printf("Hello, I am E.D.I.T.H.\n");
   printf("Your A.I. secretary.\n");
   printf("Type to talk with me.\n");
   printf("But first,press the password:");
   for (i = 0;buffer != 13; i++) {
      answer[i] = getch();
      if (answer[i] == '\0') {
         i--;
         continue;
      }
      putch('*');
      buffer = (int)answer[i];
   }
   answer[i-1] = '\0';
   if (strcmp(pass, answer) == 0)
      printf("\nRight password\n");
   else
      printf("\nWrong password\n");
   return 0;
}
