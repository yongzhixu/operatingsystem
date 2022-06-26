#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    if (argc != 2) {
	fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }
    int cntvar = atoi(argv[1]); 
    int cntval = atoi(argv[1]);
    printf("first parent cnt %d\n", cntvar);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        cntvar++;
        printf("child var cnt %d\n", cntvar);
        printf("child val cnt %d\n", cntval);
    } else {
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        cntvar+=2;
        printf("parent cnt %d\n", cntvar);
    }
    
    printf("final cnt %d\n", cntvar);
    return 0;
}