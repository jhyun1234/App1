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
	printf("��ǻ�Ͱ� ������ �ִ� �� :");

	scanf_s("%d", &answer);

}
void Render()
{


	if (computer == answer)
	{
		printf("\n���߼̽��ϴ�. �¸�\n");
		exit(1);
	}
	else if (computer > answer)
	{
		printf("\n��ǻ�Ͱ� ���� ������ �۽��ϴ�.\n");
		life--;
	}
	else if (computer < answer)
	{
		printf("\n��ǻ�Ͱ� ���� ������ Ů�ϴ�.\n");
		life--;
	}
	if (life <= 0)
	{
		printf("���ӿ��� �й��Ͽ����ϴ�.\n");
	}
}




int main()
{
#pragma region ���� �Լ�
	// 0 ~ 32367 ������ ���� ���� ��ȯ�ϴ� �Լ��̴�.

	// 1970�� 1��1�Ϻ��� ���۵ȴ�
	//int seed = 0;
	//srand(time(NULL));
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	seed = rand() % 10 + 1;
	//	printf("seed�� �� : %d\n", seed);
	//}

#pragma endregion

#pragma region Up-Down ����


	//int Guessnumber, guess, attempts= 0;
	//	int HP = 5;
	//
	//
	//
	//// ���� �õ� �ʱ�ȭ
	//
	//srand(time(0));
	//// 1 ~ 50 ������ �� 
	//Guessnumber = rand() % 100 + 1;
	//printf("��ǻ�Ͱ� ���ڸ� ���Ͽ����ϴ�.\n");
	//printf("����� 5���Դϴ�.\n");
	//
	//do
	//{
	//	printf("���ڸ� �Է����ּ���.\n");
	//	scanf_s("%d", &guess);
	//	
	//	attempts++;
	//	HP--;
	//		
	//		if (guess > Guessnumber)
	//		{
	//			printf("��ǻ�Ͱ� ���� ���ں��� Ů�ϴ�.\n");
	//			printf("HP�� 1�����Ǿ����ϴ�.%d\n", HP--);
	//		}
	//		else if (guess < Guessnumber)
	//		{
	//			printf("��ǻ�Ͱ� ���� ���ں��� �۽��ϴ�.\n");
	//			printf("HP�� 1�����Ǿ����ϴ�.&d\n", HP--);
	//		}
	//		else if (HP = 0)
	//		{
	//			printf("HP�� ���� �����Ǿ����ϴ�.�й�\n");
	//		}
	//		else
	//		{
	//			printf("�����մϴ�! ���߼̽��ϴ�.�¸�\n");
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

#pragma region Up-Down ����
	// ���� ������ �ʱ�ȭ
	Init();

	while (life > 0)
	{
		// ���� ������Ʈ �Լ�
		Update();

		// ���� ������ �Լ�
		Render();



	}

#pragma endregion


	return 0;
}

#pragma once
