#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define N 100
#define STR 200

typedef struct book {

	char m_Author[N];
	char m_Book[N];
	int m_Year;
	int m_Pages;
	int m_Price;

	struct book* mNext;
} SBook;

void SetStruct(SBook** SFirstBook, char* str);
void Show(SBook* SFirstBook);
void Sort(SBook** SFirstBook);
SBook* GetConcrete(SBook* SFirstBook, int index);
void DeleteElement(SBook** SFirstBook, int index);
void AddElement(SBook** SFirstBookS);
void DeletePKL(SBook** SFirstBook);
SBook* GetLast(SBook* SFirstBook);