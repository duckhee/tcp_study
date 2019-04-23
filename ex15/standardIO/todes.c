#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    FILE *fp;
    int fd = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1)
    {
        fputs("file open error \r\n", stdout);
        return -1;
    }

    printf("First file descriptor : %d \r\n", fd);
    fp = fdopen(fd, "w");
    fputs("TCP/IP SOCKET PROGRAMMING \r\n", fp);
    printf("Sencode file descriptor : %d \r\n", fileno(fp));
    fclose(fp);
    
    return 0;

}