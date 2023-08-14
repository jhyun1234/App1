#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int life;
int computer;
int answer;

void Init()
{
	srand(time(NULL));

	life = 5;
	computer = rand() % 50 + 1;
}

void Update()
{
	printf("컴퓨터가 가지고 있는 값 :");

	scanf_s("%d", &answer);

}
void Render()
{


	if (computer == answer)
	{
		printf("\n맞추셨습니다. 승리\n");
		exit(1);
	}
	else if (computer > answer)
	{
		printf("\n컴퓨터가 정한 값보다 작습니다.\n");
		life--;
	}
	else if (computer < answer)
	{
		printf("\n컴퓨터가 정한 값보다 큽니다.\n");
		life--;
	}
	if (life <= 0)
	{
		printf("게임에서 패배하였습니다.\n");
	}
}




int main()
{
#pragma region 랜덤 함수
	// 0 ~ 32367 사이의 난수 값을 반환하는 함수이다.

	// 1970년 1월1일부터 시작된다
	//int seed = 0;
	//srand(time(NULL));
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	seed = rand() % 10 + 1;
	//	printf("seed의 값 : %d\n", seed);
	//}

#pragma endregion

#pragma region Up-Down 게임


	//int Guessnumber, guess, attempts= 0;
	//	int HP = 5;
	//
	//
	//
	//// 랜덤 시드 초기화
	//
	//srand(time(0));
	//// 1 ~ 50 사이의 값 
	//Guessnumber = rand() % 100 + 1;
	//printf("컴퓨터가 숫자를 정하였습니다.\n");
	//printf("목숨은 5개입니다.\n");
	//
	//do
	//{
	//	printf("숫자를 입력해주세요.\n");
	//	scanf_s("%d", &guess);
	//	
	//	attempts++;
	//	HP--;
	//		
	//		if (guess > Guessnumber)
	//		{
	//			printf("컴퓨터가 정한 숫자보다 큽니다.\n");
	//			printf("HP가 1차감되었습니다.%d\n", HP--);
	//		}
	//		else if (guess < Guessnumber)
	//		{
	//			printf("컴퓨터가 정한 숫자보다 작습니다.\n");
	//			printf("HP가 1차감되었습니다.&d\n", HP--);
	//		}
	//		else if (HP = 0)
	//		{
	//			printf("HP가 전부 차감되었습니다.패배\n");
	//		}
	//		else
	//		{
	//			printf("축하합니다! 맞추셨습니다.승리\n");
	//
	//		}		
	//	
	//	
	//} while (guess != Guessnumber);
	//{
	//
	//}
	//while (HP == 0);
	//{
	//
	//}

#pragma endregion

#pragma region Up-Down 게임
	// 게임 테이터 초기화
	Init();

	while (life > 0)
	{
		// 게임 업데이트 함수
		Update();

		// 게임 렌더링 함수
		Render();



	}

#pragma endregion


	return 0;
}

#pragma once
