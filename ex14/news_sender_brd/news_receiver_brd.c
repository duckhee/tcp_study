#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define BUF_SIZE     30
void error_handling(char *message);

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in adr;
    int strl_len;
    char buf[BUF_SIZE];
    if(argc != 2)
    {
        printf("Usage : %s <PORT> \r\n", argv[0]);
        return -1;
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        error_handling("socket() error");
    }
    memset(&adr, 0, sizeof(adr));
    adr.sin_family = AF_INET;
    adr.sin_addr.s_addr = inet_addr(argv[1]);
    adr.sin_port = htons(atoi(argv[2]));

    if(bind(sock, (struct sockaddr *)&adr, sizeof(adr)) == -1)
    {
        error_handling("bind() error");
    }
    while(1)
    {
        strl_len = recvfrom(sock, buf, BUF_SIZE-1, 0, NULL, 0);
        if(strl_len < 0)
        {
            break;
        }
        buf[strl_len] = 0;
        fputs(buf, stdout);

    }
    close(sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}