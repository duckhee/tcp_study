/**
 * 두개의 프로그램이 실행 되는 것이다. 
 */ 

#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char **argv)
{
    pid_t pid;
    int lval = 20;
    gval++, lval += 5;
    pid = fork();

    if(pid == 0)
    {
        gval += 2, lval += 2;
    }else{
        gval -= 2, lval -= 2;
    }

    if(pid == 0)
    {
        printf("Child Proc : [%d, %d] \r\n", gval, lval);
        printf("pid : %d \r\n", pid);
    }else{
        printf("Parent Proc : [%d, %d] \r\n", gval, lval);
        printf("pid : %d \r\n", pid);
    }

    return 0;
}