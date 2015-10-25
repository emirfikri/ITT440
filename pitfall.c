 /* C socket server example */

#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>   //write
#include <sys/types.h>

int main (int argc, char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];

   //create socket 
   socket_desc = socket(AF_INET , SOCK_STREAM , 0);
   if(socket_desc == -1)
   {
     printf("Could not create socket");
   }
    puts("Socket created");
 
   //Prepare teh sockaddr_in structure
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons (8888);
  
   //pitfall 4
   server.sin_port = htons(3059);
   // end of pitfall 4

   //pitfall 3
   int on, ret;
   on =1;
   ret = setsockopt(socket_desc , SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  //end of pitfall 3
   
    //pitfall 5
   ret = write(socket_desc , "Message 1", 50);
   ret = write (socket_desc , "Message 2", 50);
   // end of pitfall 5

   //Bind
  if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server))<0)
    { 
      //print the error message 
      perror("bind failed. Error");
      return 1;
     }
    puts("bind done");

   //accept and incoming connection
   puts("waiting for incoming connection...");
  c = sizeof(struct sockaddr_in);

  //accept connection from incoming client
  client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
 if(client_sock < 0)
 {
   perror("accept failed");
   return 1;
 }
 puts("Connection accepted");  
   

}

