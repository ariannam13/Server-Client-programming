//Arianna Martinez
//
//


#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

extern int randperm(int*, int);


int main(int argc, char *argv[])
{
	
	struct sockaddr_in address;
	int mysock, newsocket, rval, deckofcards[52];
	int addrlen = sizeof(address);
	char buffer[1024];
	const char *deal = "Deal";
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(atoi(argv[1]));
	
	
	mysock = socket(AF_INET,SOCK_STREAM,0);
	

	if (bind(mysock, (struct sockaddr*) &address, sizeof(address))!= 0)
	{
		printf("Binding Error\n");
		
		exit(1);
	}
	
	if(listen(mysock, 10)!=0)
	{
		printf("Listening Error\n");
		
		exit(1);
	}
	
	if (newsocket = accept(mysock, (struct sockaddr*) &address, (socklen_t*) &addrlen) < 0)
	{
		printf("Not accepted\n");
		
		exit(1);
	}
	
	rval = read(newsocket, buffer, sizeof(buffer));
	
	int checkstring = strcmp(buffer, deal);
	
	
	if (checkstring == 0){
		sprintf(buffer, "Server Deal has started\n");
		send(newsocket, buffer, strlen(buffer), 0);
		
		for(int c=0; c<52; c++)
		{
			deckofcards[c] = c+1;
		}
		
		randperm(deckofcards, 52);
		
		for(int d=0; d<52; d++)
		{
			sprintf(buffer, "Card %d %d\r\n", d+1, deckofcards[d]);
			send(newsocket, buffer, strlen(buffer), 0);
		}
	}
	else {
		sprintf(buffer, "Server Deal is not working\n");
		send(newsocket, buffer, strlen(buffer), 0);
	}
	
	return(0);
}
		
		
	
	
	

	
