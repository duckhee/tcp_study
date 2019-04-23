#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE   30

void error_handling(char *message);

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in board_adr;
    FILE *fp;
    char buf[BUF_SIZE];
    int so_brd = 1;
    if(argc != 3)
    {
        printf("Usage : %s <Boradcast IP> <PORT> \r\n", argv[0]);
        return -1;
    }
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
    {
        error_handling("socket() error");
    }
    memset(&board_adr, 0, sizeof(board_adr));
    board_adr.sin_family = AF_INET;
    board_adr.sin_addr.s_addr = inet_addr(argv[1]);
    board_adr.sin_port = htons(atoi(argv[2]));
    setsockopt(serv_sock, SOL_SOCKET, SO_BROADCAST, (void*)&so_brd, sizeof(so_brd));
    if((fp = fopen("news.txt", "r")) == NULL)
    {
        error_handling("fopen() error");
    }
    while(!feof(fp))
    {
        fgets(buf, BUF_SIZE, fp);
        sendto(serv_sock, buf, strlen(buf), 0, (struct sockaddr *)&board_adr, sizeof(board_adr));
        sleep(2);
    }
    close(serv_sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}