#include<stdio.h>
#include<stdlib.h>
#include<String.h>


/* ---------------tic tac toe game----------------------
1. Menu options including player names, start game, exit
2. Put the character X/O in the user defined position
3. if 3 positions get filled first in the way such that X/O game works, that player wins
*/

char board1[][];
char board2[][];

void menu(char* name1, char* name2)
{
	int n;
	printf("GAME MENU \n");
	printf("PRESS 1 TO START THE GAME OR 0 TO EXIT \n");
	scanf("%d", n);
	if(n == 1)
	{
		startgame(name1, name2);
	}
	else if(n == 0)
	{
		exitgame();
	}
}

void startgame(char* player1, char* player2)
{
	int i, j, p1pos1, p1pos2, p2pos1, p2pos2;
	char xo1, xo2;
	char board1[3][3];
	char board2[3][3];
	printf("GAME IS STARTING \n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			board1[i][j] = 'N';
		}
	}
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			board2[i][j] = 'N';
		}
	}
	for(i=0; i<5; i++)
	{
		printf("PLAYER 1 chance \n");
		scanf("%d %d %s", p1pos1, p1pos2, xo1);
		playX_O(p1pos1, p1pos2, xo1, board1);
		printf("PLAYER 2 chance \n");
		scanf("%d %d %s", p2pos1, p2pos2, xo1);
		playX_O(p2pos1, p2pos2, xo2, board2);
		
		if(board1[0][0] == 'X' && board1[0][1] == 'X' && board1[0][2] == 'X' || board1[0][0] == 'X' && board1[1][0] == 'X' && board1[2][0] == 'X' || 
		board1[1][0] == 'X' && board1[1][1] == 'X' && board1[1][2] == 'X' || board1[2][0] == 'X' && board1[2][1] == 'X' && board1[2][2] == 'X' || 
		board1[0][1] == 'X' && board1[1][1] == 'X' && board1[2][1] == 'X' || board1[0][2] == 'X' && board1[1][2] == 'X' && board1[2][2] == 'X' ||
		board1[0][0] == 'X' && board1[1][1] == 'X' && board1[2][2] == 'X' || board1[0][2] == 'X' && board1[1][1] == 'X' && board1[2][1] == 'X')
		{
			printf("PLAYER 1 WINS \n");
			return;
		}
		else if(board2[0][0] == 'O' && board2[0][1] == 'O' && board1[0][2] == 'O' || board2[0][0] == 'O' && board2[1][0] == 'O' && board2[2][0] == 'O' || 
		board2[1][0] == 'O' && board2[1][1] == 'O' && board2[1][2] == 'O' || board2[2][0] == 'O' && board2[2][1] == 'O' && board2[2][2] == 'O' || 
		board2[0][1] == 'O' && board2[1][1] == 'O' && board2[2][1] == 'O' || board2[0][2] == 'O' && board2[1][2] == 'O' && board2[2][2] == 'O' ||
		board2[0][0] == 'O' && board2[1][1] == 'O' && board2[2][2] == 'O' || board2[0][2] == 'O' && board2[1][1] == 'O' && board2[2][1] == 'O')
		{
			printf("PLAYER 1 WINS \n");
			return;
		}
		else
		{
			continue;
		}
	}
	printf("GAME DRAW \n");
	return;
}
 
void playX_O(int index1,int index2, char type)
{
	if(type == 'X')
	{
		board1[index1][index2] = type;
	}
	else if(type == 'O')
	{
		board2[index1][index2] = type;

	}
}

void main()
{
	printf("WELCOME TO TIC TAC TOE \n");
	printf("PLAYER 1: ENTER YOUR NAME \n");
	char name1[24];
	char name2[24];
	char *ptr1 = name1;
	char *ptr2 = name2;
	//take player names
	scanf("%s", name1);
	printf("PLAYER 2: ENTER YOUR NAME \n");
	scanf("%s", name2);
	
	//call menu to proceed with the game
	menu(name1, name2);
}