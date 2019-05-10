#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

////////////Очередь/////////////

typedef struct Line
{
    int value;
    struct Line *next;
    struct Line *prev;
} Line;

typedef struct OptLine
{
    Line *head;
    Line *tail;
} OptLine;

OptLine *InitOptLine()
{
    struct Line *tmp;

    tmp = malloc(sizeof(struct Line));
    tmp -> value = -1;
    tmp -> next = NULL;
    tmp -> prev = NULL;

    struct OptLine *tmp1;

    tmp1 = malloc(sizeof(struct OptLine));
    tmp1 -> head = tmp;
    tmp1 -> tail = tmp;

    return tmp1;
}

int isEmptyLine(OptLine *h)
{
    if ((h -> head -> value == -1))
        return 1;
    else
        return 0;
}

void AddInLine(int a, OptLine *h)
{
    {
        if (h -> head -> value == -1)
        {
            h -> head -> value = a;
        }
        else
        {
            struct Line *tmp = malloc(sizeof(struct Line));
            h -> tail -> next = tmp;
            tmp -> value = a;
            tmp -> prev = h -> tail;
            tmp -> next = NULL;
            h -> tail = tmp;
        }
    }
}

void DeleteLine(OptLine *h)
{
    if (h -> head != NULL)
    {
        Line *tmp = h -> head;
        Line *n = NULL;
        int i = 1;
        for (i; tmp != NULL ; i++)
        {
            n = tmp -> next;
            tmp = NULL;
            tmp = n;
        }
        h -> head = NULL;
        h -> tail = NULL;
        h = NULL;
    }
    else printf("Empty Line1\n");
}
void DeleteFirstInLine(OptLine *h)
{
    for (;;){
    if (h -> head != h -> tail)
    {
        Line *tmp = h -> head;
        h -> head = h -> head -> next;
        h -> head -> prev = NULL;
        free(tmp);
        break;
    }

    if ((h -> head == h -> tail) && (h -> head -> value != -1))
    {
        h -> head -> value = -1;
        h -> head -> next = NULL;
        h -> head -> prev = NULL;
        break;
    }

    if (isEmptyLine(h) == 1)
    {
        printf("Empty Line2\n");
        break;
    }
    }
}

int ShowFirstInLine(OptLine *h)
{
    if (isEmptyLine(h) == 0)
    {
        int val = h -> head -> value;
        //DeleteFirstInLine(h);
        return val;
    }
    else printf("Empty Line3\n");
}

void Show(OptLine *h)
{
    printf("\nOCHERED\n");
    Line *tmp = h->head;
    while (tmp!=NULL)
    {
        printf("%d ", tmp->value);
        tmp=tmp->next;
    }
}

///////////////Граф////////////////

//Структура описания связи
typedef struct Connect
{
    int weight;
    int value;
    struct Connect *next;
    struct Connect *prev;
} Connect;

//Структура вершин
typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
    Connect *StrucStart; //Ссылка на начало списка связей
    Connect *StrucEnd;
} Node;

//Структура, хранящая начало и конец цепочки вершин
typedef struct HTNode
{
    Node *head;
    Node *tail;
} HTNode;

//Инициализация списка вершин
HTNode *CreateList()
{
    Node *tmp = malloc(sizeof(Node));

    tmp -> value = -1;
    tmp -> next = NULL;
    tmp -> prev = NULL;
    tmp -> StrucStart = NULL;
    tmp -> StrucEnd = NULL;

    HTNode *tmp1 = malloc(sizeof(HTNode));

    tmp1 -> head = tmp;
    tmp1 -> tail = tmp;

    return tmp1;
}

//Добавление вершины в список
void AddInList(int a, HTNode *h)
{
    if (h -> head -> value == -1)
    {
        h -> head -> value = a;
    }
    else
    {
        Node *list = malloc(sizeof(Node));

        list -> value = a;
        list -> next = NULL;
        list -> StrucStart = NULL;
        list -> StrucEnd = NULL;
        list -> prev = h -> tail;
        list -> prev -> next = list;
        h -> tail = list;
    }
}

//Добавление связи для вершины
void AddConnect(int a, int b, Node *tmp)
{
    Connect *t = malloc(sizeof(Connect));

    t -> value = a;
    t -> weight = b;
    t -> next = NULL;

    if (tmp -> StrucStart == NULL)
    {
        tmp -> StrucStart = t;
        tmp -> StrucEnd = t;
        t -> prev = NULL;
    }
    else
    {
        t -> prev = tmp -> StrucEnd;
        tmp -> StrucEnd = t;
        t -> prev -> next = t;
    }
}

//Поиск вершины по номеру
Node *SearchNode(int a, HTNode *h)
{
    Node *tmp = h -> head;

    while (tmp != NULL)
    {
        int tmpValue = tmp -> value;

        if (tmpValue == a)
        {
            return tmp;
        }

        tmp = tmp -> next;
    }
}

//Вывод всех вершин и их связей
void PrintAll(int quantity, HTNode *temp)
{
    Node *tmp = temp -> head;
    Connect *t = NULL;
    int i, j;

    for (i = 1; i <= quantity; i++)
    {
        t = tmp -> StrucStart;
        printf("\nNode %d ", i);
        while (t != NULL)
        {
            printf("\nConnect with: %d Weight: %d", t -> value, t -> weight);
            t = t -> next;
        }
        tmp = tmp -> next;
    }
    printf("\n");
}

//Ввод кол. связей для вершин
int InputA (int quantity)
{
    int a;

    scanf("%d", &a);

    if ((a > quantity - 1) || (a < 0))
    {
        printf("The number of communications can't be more number of nods or less then zero. Try again.\n");
        InputA(quantity);
    }
    else
    {
        return a;
    }
}

//Ввод вершины, с которой будет свзяь
int InputB(int a, int quantity)
{
    int b;

    scanf("%d", &b);

    if ((b > quantity) || (b < 1) || (b == a))
    {
        printf("Error. Try again.\n");
        InputB(a, quantity);
    }
    else
    {
        return b;
    }
}

//Ввод веса
int InputC()
{
    int c;

    scanf("%d", &c);

    if (c < 0)
    {
        printf("Weight can not be less than zero. Try again.\n");
        InputC();
    }
    else
    {
        return c;
    }
}

//Короткий путь
void ShortWay(int quantity, HTNode *t, int arr2[][quantity])
{
    Node *tmp = t -> head;
    OptLine *Ochered1 = InitOptLine();

    int i, k, j;
    int arr[quantity];
    for (i = 0; i < quantity; i++)
    {
        arr[i] = 0;
    }

    for (i = 0; i < quantity; i++)
    {
        Node *tmp2 = tmp;
        for (;;)
        {
            Connect *tmpc = tmp2 -> StrucStart;
            while (tmpc != NULL)
            {
                if (arr[tmpc -> value - 1] == 0)
                {
                    AddInLine(tmpc -> value, Ochered1);
                    arr[tmpc -> value - 1] = 1;
                }
                tmpc = tmpc -> next;
            }

            tmpc = tmp2 -> StrucStart;

            k = arr2[i][tmp2 -> value - 1];

            while (tmpc != NULL)
            {
                if (arr2[i][tmpc -> value - 1] > tmpc -> weight + k)
                {
                    arr2[i][tmpc -> value - 1] = tmpc -> weight + k;
                }
                tmpc = tmpc -> next;
            }
            if (isEmptyLine(Ochered1) == 1) break;
            tmp2 = SearchNode(ShowFirstInLine(Ochered1), t);
            DeleteFirstInLine(Ochered1);
        }

        for (j = 0; j < quantity; j++)
        {
            arr[j] = 0;
        }

        tmp = tmp -> next;
    }
}

int FindMinString (int string, int quantity, int arr2[][quantity], int isklJ)
{
    int i, min = INT_MAX;

    for (i = 0; i < quantity; i++)
    {
        if ((i == string) || (arr2[string][i] == -1) || (i == isklJ))
        {
            continue;
        }
        else
        {
            if (arr2[string][i] < min ) min = arr2[string][i];
        }
    }
    return min;
}

int FindMinColumn (int column, int quantity, int arr2[][quantity], int isklI)
{
    int i, min = INT_MAX;

    for (i = 0; i < quantity; i++)
    {
        if ((i == column) || (arr2[i][column] == -1) || (i == isklI))
        {
            continue;
        }
        else
        {
            if (arr2[i][column] < min ) min = arr2[i][column];
        }
    }
    return min;
}

int circuit(int quantity, int arr2[][quantity])
{
    int i,j;
    for (i = 0; i < quantity; i++)
    {
        for (j = 0; j < quantity; j++)
        {
            if (arr2[i][j] == INT_MAX) return -1;
        }
    }
    int min;
    int quantity2 = quantity;
    int weight = 0;

    int arr3[quantity][quantity];
    for (i = 0; i < quantity; i++)
    {
        for (j = 0; j < quantity; j++)
        {
            arr3[i][j] = arr2[i][j];
        }
    }

    while (quantity2 != 0)
    {
        //отнимаем от строк
        for (i = 0; i < quantity; i++)
        {
            min = FindMinString(i, quantity, arr2, -1);
            if (min != INT_MAX)
            {
                for (j = 0; j < quantity; j++)
                {
                    if ((i == j) || (arr2[i][j] == -1)) continue;
                    arr2[i][j]-=min;
                }
            }
        }

        //отнимаем столбцы
        for (i = 0; i < quantity; i++)
        {
            min = FindMinColumn(i, quantity, arr2, -1);
            if (min != INT_MAX)
            {
                for (j = 0; j < quantity; j++)
                {
                    if ((i == j) || (arr2[i][j] == -1)) continue;
                    arr2[j][i]-=min;
                }
            }
        }

        //ищем макс оценку
        int assessment = -1;
        int check1, check2, r;
        int j0, i0;
        for (i = 0; i < quantity; i++)
        {
            for (j = 0; j < quantity; j++)
            {
                if ((i == j) || (arr2[i][j] == -1)) continue;
                if (arr2[i][j] == 0)
                {
                    check1 = FindMinColumn(j, quantity, arr2, i);
                    check2 = FindMinString(i, quantity, arr2, j);

                    if ((check1 == INT_MAX) || (check2 == INT_MAX))
                    {
                        r = INT_MAX;
                    }
                    else
                    {
                        r = check1 + check2;
                    }

                    if (assessment <= r)
                    {
                        assessment = r;
                        i0 = i;
                        j0 = j;
                    }
                }
            }
        }

        //редукция
        for (i = 0; i < quantity; i++)
        {
            arr2[i0][i] = -1;
        }

        for (i = 0; i < quantity; i++)
        {
            arr2[i][j0] = -1;
        }

        //отсечка обратного пути
        if (quantity != 2)
        {
            arr2[j0][i0] = -1;
        }

        weight += arr3[i0][j0];
        quantity2-=1;
    }
    return weight;
}

int main()
{
    HTNode *List1 = CreateList();
    int quantity, i, j, a, b, c;

    printf("G: [The number of nods][The number of communications for a node][Connect with][Weight]\n");
    scanf("%d", &quantity);

    for (i = 1; i <= quantity; i++)
    {
        AddInList(i, List1);
        a = InputA(quantity);
        for (j = 1; j <= a; j++)
        {
            b = InputB(i, quantity);
            c = InputC();
            AddConnect(b,c,List1 -> tail);
        }
    }

    PrintAll(quantity, List1);

/////////////////////////////////////////
    int arr2[quantity][quantity];
    for (i = 0; i < quantity; i++)
    {
        for (j = 0; j < quantity; j++)
        {
            if (i == j)
            {
                arr2[i][j] = 0;
            }
            else
            {
                arr2[i][j] = INT_MAX;
            }
        }
    }

    ShortWay(quantity, List1, arr2);

    //printf("\nshort path weight = %d\n", circuit(quantity, arr2));

    FILE *TXTFILE;
    TXTFILE = fopen ("graph.txt", "w");
    if (TXTFILE == NULL) {printf("graph.txt not found"); exit(0);}

    for (int i = 0; i < quantity; i++)
    {
        fprintf(TXTFILE, "\n");
        for (int j = 0; j < quantity; j++)
        {
            if (arr2[i][j] == INT_MAX) {fprintf(TXTFILE, "- ");}
            else
                fprintf(TXTFILE,"%d ", arr2[i][j]);
        }
    }
    fprintf(TXTFILE, "\n%d", circuit(quantity, arr2));
    fclose(TXTFILE);
    printf("\nsuccessful retention in graph.txt\n");
    return 0;
}

