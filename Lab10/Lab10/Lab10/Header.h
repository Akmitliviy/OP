#pragma once

#define N 100

struct book {

	char mAuthor[N];
	char mBook[N];
	int mYear;
	int mPages;
	int mPrice;

	struct book* mNext;
};

void SetStruct(char str[], struct book** SBook, struct book** SFirstBook);
void Show(struct book* SBook, struct book* SFirstBook);
void Sort(struct book** SBook, struct book* SFirstBook);
void GetConcrete(struct book** SBook, struct book* SFirstBook, int index);
void DeleteElement(struct book** SBook, struct book** SFirstBook, int index);
void AddElement(struct book** SBook, struct book** SFirstBookS);
void DeletePKL(struct book** SBook, struct book** SFirstBook);