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

enum suits{SPADES, HEARTS, DIAMONDS, CLUBS};
enum faces{ACES,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

typedef struct{
	char *value;
	char *type;
}card;

int main(int argc, char *argv[])
{
	
	struct sockaddr_in serv_addr;
	char buffer[1024];
	const char *deal = "Deal";
	char write[2000];
	int mysock, valread;
	
	mysock = socket(AF_INET,SOCK_STREAM,0);
	
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	
	if((inet_pton(AF_INET,"127.0.0.1", &serv_addr.sin_addr))!= 1)
	{
		printf("Check address\n");
		
		exit(0);
	}
		
	if((connect(mysock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))!=0))

		{
			printf("Socket Connection failed\n");
			exit(0);
		}
		
		
	while(1){
		
		scanf("%s", write);
		
		int i, r;
		char name[4][9] = {{"diamonds"},{"clubs"},{"hearts"},{"spades"}};
		char number [13][6] = {{"ace"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"},{"jack"},{"queen"},{"king"}};
		
		card c[52];
		card temp;
		
		for (i = 0; i<52; i++)
		{
			c[i].type = name[i % 4];
			c[i].value = number [i % 52];
		}
		for (i = 0; i<52; i++)
		{
			r = rand() % 52;
			temp = c[i];
			c[i] = c[r];
			c[r] = temp;
		}
		for (i = 0;i<52;i++)
		{
			printf("%s %s\n", c[i].type, c[i].value);
		}
		
		valread = read(mysock, buffer, 1024);
		return (0);
	}
}
		
		
		
	
	
	
	


