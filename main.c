//#define _GNU_SOURCE // GNU_SOURCE pour avoir getline qui permet de borner la lecture de ligne
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //fork, pid_t
#include <sys/wait.h> //wait du parent
#include <stdlib.h>


int main(int argc, char * argv[]) {

    int status = 0;
    char * programName = argv[1];
    char * variable[2] = {argv[1], NULL};
    char * buffer = NULL;
	size_t	buf_size = 2048;

        //fork
        pid_t pid = fork();
        if (pid == -1)
        {
            // Il y a une erreur
            perror("fork a echoue");
            return EXIT_FAILURE;

        } else if (pid > 0)
        {
            // On est dans le père
            wait(&status);
            perror("fork");
            while (getline(&buffer, &buf_size, stdin) > 0)
            {
                system(buffer);
                write(1, "Daoud@root> ", 12);
            }

        } else {
            // On est dans le fils
            perror("fork");
            execvp(programName,variable);

        }
    printf("Fin du Shell");
    return EXIT_SUCCESS;
}
