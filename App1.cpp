#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void ReadTextFile(const char * fileName)
{
	FILE* readfile = fopen(fileName, "r");

	char buffer[10000] = { 0, };

	// fread()
	// 첫 번째 매개변수 : 크기를 가지는 배열을 가리키는 포인터 이다.
	// 두 번째 매개변수 : 읽어들일 원소의 크기로 단위는 바이트 이다.
	// 세 번째 매개변수 : 읽어들일 원소들의 개수로 각 원소의 크기 이다.
	// 네 번째 매개변수 : 데이터를 입력받을 스트림의 FILE 객체를 가리키는 포인터 이다.

	fread(buffer, 1, 10000, readfile);
	printf("%s", buffer);

	fclose(readfile);
}

int main()
{
#pragma region 파일 입출력
	// 보조 기억장치(디스크)로 부터 데이터를 
	// 읽어오거나 저장하는 과정이다.

	// fopen("파일 이름","파일 모드")
	// "w" : 파일쓰기
	// FILE * filePtr=fopen("data.txt","w");
	// 
	// char content[10] = "Content";
	// 
	// fputs(content, filePtr);
	// 
	// 
	// FILE* fileReader = fopen("data.txt", "r");
	// fgets(content,sizeof(content), fileReader);
	// printf("%s", content);
	// 
	// //fprintf(filePtr, "%s\n", "Data");
	// 
	// fclose(fileReader); // 파일 닫아주기

#pragma endregion

	// ReadTextFile("Resources/bbb.TXT");

	while (1)
	{
		ReadTextFile("Resources/data.TXT");

		system("cls");
	}
	
	return 0;
}

