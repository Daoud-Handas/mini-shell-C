/*

                MINI SHELL - LANGAGE C
                   2ESGIA2 2020/2021
                       Groupe :

   Romain LETHUMIER  Daoud HANDAS  Hamza ID LAHCEN
      “ヽ(´▽｀)ノ”       (•̀ᴗ•́)و ̑̑       (っ▀¯▀)つ


*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //fork, pid_t
#include <sys/wait.h>  //wait
#include <stdlib.h>
#include <string.h>    //strstr

#define MAXLIST 100 // nombre maximum de commandes à prendre en charge

#define clear() printf("\033[H\033[J") //Equivalent de la commande clear en UNIX

// Affichage de bienvenue du SHELL
void beginShell()
{
    clear();
    char* username = "Darnuria";
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t****MINI SHELL****");
    printf("\n\n\t-BIENVENUE %s !-", username);
    printf("\n\n\n\n*******************"
        "***********************");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    sleep(3);
    clear();
}

int main(int argc, char * argv[]) {

    int status = 0;
    char * programName = argv[1];
    char * variable[2] = {argv[1], NULL};
    char * buffer = NULL;
	size_t	buf_size = 2048;
	char * pipe [1] = {'|'};
	char * path = NULL;

    //Lancement du Shell
    beginShell();

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
            write(1, "Darnuria@root> ", 15);

            //Tant que l'user saisis
            while (getline(&buffer, &buf_size, stdin) > 0)
            {

                //cd


                //Execution de la commande
                system(buffer);

                //Status de la commande
                if (strstr(buffer, pipe))
                    perror("Multi commandes");
                else
                    perror("commande");

                //Prompt
                write(1, "Darnuria@root> ", 15);
            }

        } else {// On est dans le fils

            perror("fork fils");
            execvp(programName,variable);

    }
    printf("Fin du Shell");
    return EXIT_SUCCESS;
}
