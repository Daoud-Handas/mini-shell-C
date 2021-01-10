#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

//Excve -> fork -> wait -> boucle d'interaction

int main(int argc, char * argv[])
{

        printf("%s",argv[0]);
        execvp(argv[1],&argv[1]);
        getchar();
        return 0;
}

