#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// print lines in file
void printNumbers(FILE *file, char *lines)
{
  int i;
  if (lines == NULL)
    i = 10000;
  else
    i = atoi(lines);
  char line[10];
  int j = 0;
  while (fgets(line, sizeof(line), file) != NULL && j < i)
  {
    printf("%s", line);
    j++;
  }
}

int main()
{

  FILE *file;
  file = fopen("listeNbPremier.txt", "r");
  if (file == NULL)
  {
    printf("file doesn't exit\n");
    exit(1);
  }

  char line[10];
  int count = 0;
  // displaying 12 prime numbers
  printf("The parent is displaying the first 12 prime number :\n");
  printNumbers(file, "12");
  int pid = fork();
  count = 0;

  // The child is displaying the next 18 prime numbers
  if (pid == 0)
  {
    printf("The Child is displaying the next 18 prime numbers :\n");
    printNumbers(file, "18");
    exit(0);
  }

  // The parent is waiting untile the child terminates
  wait(NULL);
  printf("The prent is displaying th rest od the prime numbers :\n");
  printNumbers(file, NULL);

  // closing the file
  fclose(file);
  return 0;
}