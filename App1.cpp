#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#define WIDTH 11
#define HEIGHT 11

struct Player
{
	int x;
	int y;
	const char* shape;
};

// 좌표 이동 함수
void gotoXY(int x, int y)
{
	// x, y 좌표 설정 
	COORD position = { x,y };

	// 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

// 미로 맵 데이터

char maze[WIDTH][HEIGHT];

// 미로 맵 생성

void CreateMaze()
{
	// 0 : 빈 공간 ("  ")

	// 1 : 벽 ("■")

	// 2 : 탈출구 ("◎")

	strcpy(maze[0], "11111111");
	strcpy(maze[1], "11110011");
	strcpy(maze[2], "11000111");
	strcpy(maze[3], "11010111");
	strcpy(maze[4], "11010101");
	strcpy(maze[5], "11100101");
	strcpy(maze[6], "11001101");
	strcpy(maze[7], "11010102");
	strcpy(maze[8], "11000001");
	strcpy(maze[9], "11111111");

}

void Renderer()
{
	

	for (int i = 0; i < WIDTH; i++)
    {
	   for (int j = 0; j <HEIGHT; j++)
	   {
		   if (maze[i][j] == '0')
		   {
			   printf("  ");
			}
		   else if (maze[i][j] == '1')
		   {
			   printf("■");
		   }
		   else if (maze[i][j] == '2')
		   {
			   printf("◎");
		   }
	   }
	   printf("\n");
    }
}

void KeyBoard(char map[WIDTH][HEIGHT], Player * player)
{
	 char key = 0;
	 int x = 5;
	 int y = 5;
	 
	 //  Update()
	 while(1)
	 {
	 	gotoXY(x, y);
	 	printf("★");
	 
	 	if (_kbhit()) // 키보드 입력을 확인하는 함수
	 	{
	 
	 		key = _getch();
	 		if (key == -32)
	 		{
	 			key = _getch();
	 		}
	 
	 
	 		switch (key)
	 		{
			case UP: if (map[player->y - 1][player->x / 2] != '1')
			{
				player->y--;
			}
	 			break;
			case LEFT:if (map[player->y][player->x / 2 - 1] != '1')
			{
				player->x -= 2;
			}	
	 			break;
			case RIGHT:if (map[player->y][player->x / 2 + 1] != '1')
			{
				player->x += 2;
			}				
	 			break;
			case DOWN:if (map[player->y + 1][player->x / 2] != '1')
			{
				player->y++;
			}
				
	 			break;
	 		
	 		}
	 		// 스크린을 지우는 함수
	 		system("cls");
	 	}
	 	
	 	// Sleep : 1/1000의 1초로 계산된다.
	 
	 }

}
int main()
{
	Player player = { 4,2, "★" };

	CreateMaze();
	while (1)
	{
		Renderer();
		KeyBoard(maze, &player);

		gotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");
	}
	

	return 0;
}

