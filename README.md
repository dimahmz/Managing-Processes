## Managing Processes in C
# Execrice 1 : 
  Ecrire un programme qui crée 2 processus l’un faisant la commande ls –l , l’autre ps –l.
  Le père devra attendre la fin de ses deux fils et afficher quel a été le premier processus à terminer.
 Reponse :
  implimenté dans le fichier MultiProcessMonitor.c
  pour executer le fichier sous linux : 
  (gcc doit être installer déja.)
  $gcc   MultiProcessMonitor.c
  $./a.out
