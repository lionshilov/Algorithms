#include <stdio.h>
#include<stdlib.h>

struct spisssok {
	int VALUE;
	struct spisssok *PEREHOD;
} spisssok;

struct spisok_1 {
	struct spisssok* BEGIN;
} spisok_1;

int isEmpty(struct spisok_1* spisok)
{
	return spisok->BEGIN == NULL;
}

struct spisssok* POISK(struct spisok_1* spisok, int value)
{
	struct spisssok *TEMP = spisok->BEGIN;
	while (TEMP->VALUE != value) {
		if (TEMP->PEREHOD != NULL)
			TEMP = TEMP->PEREHOD;
		else
			return 0;
	}
	return TEMP;
}

void init(struct spisok_1* spisok, int value)
{
	struct spisssok* TMP;
	TMP = (struct spisssok*)malloc(sizeof(struct spisssok));
	TMP->VALUE = value;
	TMP->PEREHOD = NULL;
	spisok->BEGIN = TMP;
}

int BACK(struct spisok_1* spisok, int x)
{
	if (isEmpty(spisok) == 1)
		init(spisok, x);
	else
	{
		struct spisssok* TMP = (struct spisssok*)malloc(sizeof(struct spisssok));
		TMP->VALUE = x;
		TMP->PEREHOD = NULL;
		struct spisssok* TEMP = spisok->BEGIN;
		while (TEMP->PEREHOD != NULL)
			TEMP = TEMP->PEREHOD;
		TEMP->PEREHOD = TMP;
	}
	return 0;
}

int FIRST(struct spisok_1* spisok, int x)
{
	if (isEmpty(spisok) == 1)
		init(spisok, x);
	else
	{
		struct spisssok *TMP = (struct spisssok*)malloc(sizeof(struct spisssok));
		TMP->VALUE = x;
		TMP->PEREHOD = spisok->BEGIN;
		spisok->BEGIN = TMP;
	}
	return 0;
}

int CLEAR(struct spisok_1* spisok)
{
	if (isEmpty(spisok) == 1)
	{
		struct spisssok *TMP = spisok->BEGIN;
		struct spisssok *TEMP = NULL;
		while (TMP != NULL)
		{
			TEMP = TMP->PEREHOD;
			free(TMP);
			TMP = TEMP;
		}
		spisok->BEGIN = NULL;
	}
}

void _DELETE(struct spisok_1* spisok, struct spisssok *TMP) {
	if (TMP != NULL) {
		if (TMP == spisok->BEGIN)
			spisok->BEGIN = TMP->PEREHOD;
		else
		{
			struct spisssok *TEMP = (struct spisssok*)malloc(sizeof(struct spisssok));
			TEMP = spisok->BEGIN;
			while (TEMP->PEREHOD != TMP)
				TEMP = TEMP->PEREHOD;
			TEMP->PEREHOD = TMP->PEREHOD;
		}
		free(TMP);
	}
}

int DELETE_FIRST(struct spisok_1* spisok, int x)
{
	struct spisssok* ELEM = POISK(spisok, x);
	if (ELEM != NULL) {
		_DELETE(spisok, ELEM);
		return 0;
	}
	return -1;
}

int DOV_POS(struct spisok_1* spisok, int num, int value)
{
	struct spisssok *TEMP = malloc(sizeof(spisssok));
	TEMP->VALUE = value;

	struct spisssok* TMP = spisok->BEGIN;
	struct spisssok* PREVIEW_TMP = spisok->BEGIN;

	for (int i = 1; i<num + 1; i++)
	{
		PREVIEW_TMP = TMP;
		TMP = TMP->PEREHOD;
		if (TMP == NULL)
			return -1;
	}
	PREVIEW_TMP->PEREHOD = TEMP;
	TEMP->PEREHOD = TMP;
	return 0;
}

void PRINT(struct spisok_1* spisok)
{
	struct spisssok* TMP = spisok->BEGIN;
	while (TMP->PEREHOD != NULL)
	{
		printf("%d ", TMP->VALUE);
		TMP = TMP->PEREHOD;
	}
	printf("%d\n", TMP->VALUE);
}

int main()
{
	int n, a;
	struct spisok_1* spisok = (struct spisok_1*)malloc(sizeof(struct spisok_1));
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a);
		BACK(spisok, a);
	}
	PRINT(spisok);

	int mk[3];
	for (int i = 0; i<3; i++) {
		scanf("%d", &mk[i]);
		if (POISK(spisok, mk[i]) != NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	int back;
	scanf("%d", &back);
	BACK(spisok, back);
	PRINT(spisok);

	int first;
	scanf("%d", &first);
	FIRST(spisok, first);
	PRINT(spisok);

	int j, x;
	scanf("%d%d", &j, &x);
	DOV_POS(spisok, j, x);
	PRINT(spisok);

	int DELETE;
	scanf("%d", &DELETE);
	DELETE_FIRST(spisok, DELETE);
	PRINT(spisok);
	CLEAR(spisok);
	return 0;
}
