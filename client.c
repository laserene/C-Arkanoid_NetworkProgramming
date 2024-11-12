// #include "stdio.h"
// #include "stdlib.h"
// #include "sys/types.h"
// #include "sys/socket.h"
// #include "netinet/in.h"
// #include "arpa/inet.h"
// #include "string.h"
// #include "unistd.h"
//
// #define BUFF_SIZE 1024
//
// int main(int argc, char *argv[]) {
//     if (argc != 3) {
//         printf("Invalid arguments.\n");
//         return 1;
//     }
//
//     int SERV_PORT = atoi(argv[2]);
//     char SERV_IP[15];
//     strcpy(SERV_IP, argv[1]);
//
//     int client_sock1;
//     int client_sock2;
//     char *buff = (char *) malloc(BUFF_SIZE);
//     struct sockaddr_in server_addr;
//
//     //Step 1: Construct a UDP socket
//     if ((client_sock1 = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
//         /* calls socket() */
//         perror("\nError: ");
//         exit(0);
//     }
//
//     if ((client_sock2 = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
//         /* calls socket() */
//         perror("\nError: ");
//         exit(0);
//     }
//
//     //Step 2: Define the address of the server
//     bzero(&server_addr, sizeof(server_addr));
//     server_addr.sin_family = AF_INET;
//     server_addr.sin_port = htons(SERV_PORT);
//     server_addr.sin_addr.s_addr = inet_addr(SERV_IP);
//
//     //Step 3: Communicate with server
//     while (1) {
//         printf("\nInsert string to send:");
//         memset(buff, '\0', (strlen(buff) + 1));
//         fgets(buff, BUFF_SIZE, stdin);
//
//         if (strcmp(buff, "#\n") == 0 || strcmp(buff, "@\n") == 0) break;
//
//         socklen_t sin_size = sizeof(struct sockaddr);
//
//         ssize_t bytes_sent = sendto(client_sock2, buff, strlen(buff), 0, (struct sockaddr *) &server_addr, sin_size);
//         if (bytes_sent < 0) {
//             perror("Error: ");
//             close(client_sock2);
//             free(buff);
//             return 0;
//         }
//
//         bytes_sent = sendto(client_sock1, buff, strlen(buff), 0, (struct sockaddr *) &server_addr, sin_size);
//         if (bytes_sent < 0) {
//             perror("Error: ");
//             close(client_sock1);
//             free(buff);
//             return 0;
//         }
//
//         const ssize_t bytes_received = recvfrom(client_sock2, buff, BUFF_SIZE - 1, 0, (struct sockaddr *) &server_addr,
//                                                 &sin_size);
//         if (bytes_received < 0) {
//             perror("Error: ");
//             free(buff);
//             return 0;
//         }
//
//         buff[100] = '\0';
//         printf("Reply from server: %s\n", buff);
//     }
//
//     free(buff);
//     close(client_sock1);
//     close(client_sock2);
//
//     return 0;
// }