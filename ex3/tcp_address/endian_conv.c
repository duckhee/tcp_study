#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("Host ordered port : %#x \r\n", host_port);
    printf("Network ordered port :%#x\r\n", net_port);
    printf("Host ordered address: %#lx\r\n", host_addr);
    printf("Network ordered address : %#lx\r\n", net_addr);

    return 0;
}