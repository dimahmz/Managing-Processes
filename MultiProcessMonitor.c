#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
  __pid_t pid1 = fork();
  if (pid1 == -1)
  {
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  if (pid1 == 0)
  {
    execlp("ls", "ls", "-l", NULL);
    // The message will display just if there is an error
    perror("Erreur lors de l'exécution de la commande ls -l");
    exit(EXIT_FAILURE);
  }
  __pid_t pid2 = fork();
  if (pid2 == -1)
  {
    perror("fork error");
    exit(EXIT_FAILURE);
  }
  if (pid2 == 0)
  {
    execlp("ps", "ps", "-l", NULL);
    // The message will display just if there is an error
    perror("Erreur lors de l'exécution de la commande ls -l");
    exit(EXIT_FAILURE);
  }

  int pid1_res = waitpid(pid1, NULL, 0);
  int pid2_res = waitpid(pid2, NULL, 0);
  if (pid1_res == -1 || pid1_res == -1)
  {
    perror("waitpid error");
    exit(EXIT_FAILURE);
  }

  printf("I finished first\nMy childs are:\n *First one : %d \n *Second one : %d\n", pid2_res, pid1_res);
}