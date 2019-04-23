#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE     1024
void error_handling(char *message);

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    FILE *readfp;
    FILE *writefp;

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char buf[BUF_SIZE];

    if(argc != 2)
    {
        printf("Usage : %s <PORT> \r\n", argv[0]);
        return -1;
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
    {
        error_handling("socket() error");
    }
    memset(&serv_addr, 9, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        error_handling("bind() error");
    }
    if(listen(serv_sock, 5) == -1)
    {
        error_handling("listen() error");
    }
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&serv_addr, &clnt_addr_size);
    if(clnt_sock == -1)
    {
        error_handling("accept() error");
    }

    readfp = fdopen(clnt_sock, "r");
    writefp = fdopen(clnt_sock, "w");

    fputs("FROM SERVER : Hi~ Client ? \r\n", writefp);
    fputs("I live all of the world \r\n", writefp);
    fputs("You are awesome ! \r\n", writefp);
    fflush(writefp);

    fclose(writefp);
    fgets(buf, sizeof(buf), readfp);
    fputs(buf, stdout);
    fclose(readfp);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}