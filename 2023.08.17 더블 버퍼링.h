#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#pragma region ���� ���۸�
// HANDLE �ε����� �����ؼ� ���۸� ��ü��Ű�� ����
int screenIndex = 0;

// ������ ũ��
int width = 100;
int height = 60;

// ���� ����
HANDLE Screen[2];

// [0] : Fornt Buffer
// [1] : Back Buffer

struct Player
{
	int x;
	int y;
	const char* shape;

};

// ���۸� �ʱ�ȭ�ϴ� �Լ�
void Init()
{
	CONSOLE_CURSOR_INFO cursor;

	// ������ ���� ������, ������ ���� ������
	COORD size = { width,height };

	// LEFT , TOP, RIGHT , BOTTOM
	SMALL_RECT rect = { 0,0,width - 1,height - 1 };

	// ȭ�� 2���� �����Ѵ�.
	// FRONT BUFFER
	Screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL

	);
	SetConsoleScreenBufferSize(Screen[0], size);

	SetConsoleWindowInfo(Screen[0], TRUE, &rect);

	// BACK BUFFER
	Screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL

	);
	SetConsoleScreenBufferSize(Screen[1], size);

	SetConsoleWindowInfo(Screen[1], TRUE, &rect);

	// Ŀ���� Ȱ��ȭ ����
	// false : ����
	// true : ��
	cursor.bVisible = false;
	SetConsoleCursorInfo(Screen[0], &cursor);
	SetConsoleCursorInfo(Screen[1], &cursor);
}

// ���۸� ��ü�ϴ� �Լ�
void Flipping()
{
	// ���۴� �ϳ��� Ȱ��ȭ��ų �� �ִ�.
	SetConsoleActiveScreenBuffer(Screen[screenIndex]);

	// true 1  Back
	// false 0 Front

	screenIndex = !screenIndex;
}

// ��ü�� ���۸� �����ִ� �Լ�
void Clear()
{
	COORD coord = { 0,0 };

	DWORD dw;

	FillConsoleOutputCharacter
	(
		Screen[screenIndex],
		' ',
		width * height,
		coord,
		&dw

	);

}

// ���۸� �����ϴ� �Լ�
void ReleaseScreen()
{
	CloseHandle(Screen[0]);
	CloseHandle(Screen[1]);
}

// ���۸� �̿��ؼ� ����ϴ� �Լ�
void ShowBuffer(int x, int y, const char* string)
{
	COORD cursorPosition = { x,y };

	DWORD dw;

	SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

	WriteFile
	(
		Screen[screenIndex],
		string,
		strlen(string),
		&dw,
		NULL
	);

}


#pragma endregion



int main()
{
#pragma region ���� ���۸�



	//char key = 0;
	//
	//Player player = { 5,5,"��" };
	//
	//// 1. ���� �ʱ�ȭ
	//Init();
	//
	//while (1)
	//{
	//	if(_kbhit())
	//	{
	//
	//	  key = _getch();
	//	  switch (key)
	//	  {
	//	  case UP:
	//		  if (player.y <= 0) break;
	//		  player.y--;
	//		  break;
	//	  case LEFT:
	//		  if (player.x <= 0) break;
	//		  player.x--;
	//		  break;
	//	  case RIGHT: player.x++;
	//		  break;
	//	  case DOWN:  player.y++;
	//		  break;
	//	  }
	//	}
	//
	//	ShowBuffer(player.x, player.y, player.shape);
	//
	//	// 2. ���� ��ü
	//	Flipping();
	//
	//	// 3. ��ü�� ������ ������ �����մϴ�.
	//	Clear();
	//
	//
	//}
	//// 4. ���۸� �����մϴ�.
	//ReleaseScreen();
#pragma endregion

#pragma region �ִ� �����
	int x = 0;
	int y = 0;
	int a = 0; // ������� ��
	int i = 0;
	printf("������ �Է��ϼ���. : ");
	scanf_s("%d%d", &x, &y);
	for (i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			a = i;
		}



	}
	printf("�ִ� ����� : %d\n", a);


#pragma endregion

	return 0;
}

