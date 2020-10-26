//Arianna Martinez
//10/26/2020
//Client


#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>


int(int argc, char *argv[] ){
	
	struct sockaddr_in serv_addr;
	char buffer[1024];
	const char *deal = "Deal";
	
	
	mysock = socket(AF_INET,SOCK_STREAM,0);
	
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	
	if(inet_pton(AF_INET,"172.17.2.240", &serv_addr.sin_addr)!= 1){
		printf("Check address\n");
		
		exit(0);
	}
		
	if(connect(mysock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)!=0);{
		printf("Connection Error\n");
		
		exit(0);
	}
	
	
	
	


