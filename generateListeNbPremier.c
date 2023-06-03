#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
  if (n < 0 || n == 1)
    return 0;
  int div = 2;
  while (div < n)
  {
    if (n % div == 0)
      return 0;
    div++;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  // check the validity of the arguments
  if (argc < 2)
  {
    printf("missing arguments\n");
    exit(0);
  }

  if (!atoi(argv[1]))
  {
    printf("argument isn't an int!\n");
    exit(0);
  }

  int primesNum = atoi(argv[1]);

  // open the file
  FILE *file;
  file = fopen("listeNbPremier.txt", "w");
  if (file == NULL)
  {
    perror("failed to open listeNbPremier.txt");
    exit(EXIT_FAILURE);
  }

  // generate prime numbers an append them into the file
  int num = 2;
  while (primesNum > 0)
  {
    if (isPrime(num))
    {
      char text[20];
      sprintf(text, "%d\n", num);
      fputs(text, file);
      primesNum--;
    }
    num++;
  }
  fclose(file);
  return 0;
}