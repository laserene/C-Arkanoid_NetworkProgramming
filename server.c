// #include "stdio.h"
// #include "stdlib.h"
// #include "sys/types.h"
// #include "sys/socket.h"
// #include "netinet/in.h"
// #include "arpa/inet.h"
// #include "string.h"
// #include "unistd.h"
// #include "ctype.h"
//
// #define BUFF_SIZE 1024
//
// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("Missing server port value.\n");
//         return 1;
//     }
//
//     const int SERV_PORT = atoi(argv[1]);
//
//     int server_sock;
//     char *buff = (char *) malloc(BUFF_SIZE);
//     struct sockaddr_in server;
//     struct sockaddr_in client1;
//     struct sockaddr_in client2;
//
//     // 1. Construct UDP socket
//     if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
//         perror("\nError: ");
//         exit(0);
//     }
//
//     // 2. Bind addr to socket
//     server.sin_family = AF_INET;
//     server.sin_port = htons(SERV_PORT);
//     server.sin_addr.s_addr = INADDR_ANY;
//     bzero(&(server.sin_zero), 8);
//
//     if (bind(server_sock, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {
//         perror("\nError: ");
//         exit(0);
//     }
//
//     // 3. Communicate with clients
//     while (1) {
//         int include_spec_char = 0;
//         socklen_t sin_size = sizeof(struct sockaddr);
//         ssize_t bytes_received = recvfrom(server_sock, buff, BUFF_SIZE - 1, 0, (struct sockaddr *) &client2,
//                                           &sin_size);
//
//         bytes_received = recvfrom(server_sock, buff, BUFF_SIZE - 1, 0, (struct sockaddr *) &client1,
//                                   &sin_size);
//
//         if (bytes_received < 0)
//             perror("\nError: ");
//         else {
//             buff[bytes_received] = '\0';
//
//             // Remove digit
//             int j = 0;
//             for (int i = 0; buff[i] != '\0' && buff[i] != '\n'; i++) {
//                 if (isalpha(buff[i])) {
//                     buff[j++] = buff[i]; // Copy alphabet characters
//                 } else if (!isdigit(buff[i])) {
//                     include_spec_char = 1;
//                     break;
//                 }
//             }
//
//             if (include_spec_char) {
//                 strcpy(buff, "Error: Special characters.\n");
//             } else {
//                 // Reverse string
//                 int length = strlen(buff) - 1;      // Exclude the ending '\n'
//                 int start = 0;
//                 int end = length - 1;
//
//                 while (start < end) {
//                     // Swap the characters at the start and end
//                     char temp = buff[start];
//                     buff[start] = buff[end];
//                     buff[end] = temp;
//                     start++;
//                     end--;
//                 }
//             }
//
//             printf("Processed: %s\n", buff);
//         }
//
//         /* send to the client welcome message */
//         const ssize_t bytes_sent = sendto(server_sock, buff, bytes_received, 0, (struct sockaddr *) &client2,
//                                           sin_size);
//         printf("Processed: %s\n", buff);
//         if (bytes_sent < 0) {
//             perror("\nError: ");
//             break;
//         }
//     }
//
//     close(server_sock);
//     free(buff);
//
//     return 0;
// }