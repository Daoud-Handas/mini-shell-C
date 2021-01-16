#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //fork, pid_t
#include <sys/wait.h>  //wait
#include <stdlib.h>
#include <string.h>    //strstr

/*

                MINI SHELL - LANGAGE C
                   2ESGIA2 2020/2021
                       Groupe :

   Romain LETHUMIER  Daoud HANDAS  Hamza ID LAHCEN
      “ヽ(´▽｀)ノ”       (•̀ᴗ•́)و ̑̑       (っ▀¯▀)つ


*/


int main(int argc, char * argv[]) {

    int status = 0;
    char * programName = argv[1];
    char * variable[2] = {argv[1], NULL};
    char * buffer = NULL;
	size_t	buf_size = 2048;
	char * pipe [1] = {'|'};

        //fork
        pid_t pid = fork();
        if (pid == -1)
        {
            // Il y a une erreur
            perror("fork");
            return EXIT_FAILURE;

        } else if (pid > 0)
            {// On est dans le père

                wait(&status);
                perror("wait père");

                //Tant que l'user saisis
                while (getline(&buffer, &buf_size, stdin) > 0)
                {

                    //Execution de la commande
                    system(buffer);

                    //Status de la commande
                    if (strstr(buffer, pipe))
                        perror("Multi commandes");
                    else
                        perror("Commande");

                    //Prompt
                    write(1, "Daoud@root> ", 12);
                }

            } else {// On est dans le fils

                perror("fork fils");
                execvp(programName,variable);

        }
    printf("Fin du Shell");
    return EXIT_SUCCESS;
}
