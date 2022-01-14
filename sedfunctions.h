#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int len(char *mass)
{
    /* Считает длинну строки.
       Аналог функции len() в Python.
       :mass - строка в которой нужно посчитать длинну;
    */
    int lenght = 0;
    while (mass[lenght] != '\0')
        lenght++;
    return lenght;
}

char *trimStr(char *mass)
{
    /* Задает динамическуму массиву размер по колличеству его символов,
        чтобы не занимать память просто так.
       :mass - строка в которой будем изменять ее размер;
    */
    return (char *)realloc(mass, len(mass));
}

int *trimInt(int *mass, int countElemenInMass)
{
    /* Задает динамическуму массиву размер по колличеству его символов,
        чтобы не занимать память просто так.
       :mass - массив чисел в котором будет изменён размер;
       :countElemenInMass - количество элементов массива;
    */
    return (int *)realloc(mass, countElemenInMass * sizeof(int));
}

float *trimFloat(float *mass, int countElemenInMass)
{
    /* Задает динамическуму массиву размер по колличеству его символов,
        чтобы не занимать память просто так.
       :mass - массив чисел с плавающей точкой в котором будет изменён размер;
       :countElemenInMass - количество элементов массива;
    */
    return (float *)realloc(mass, countElemenInMass * sizeof(float));
}

void scanDoubleMassElementStr(char **mass, int needCountToEnter)
{
    /* Считывает символьный двумерный массив с клавиатуры.
       :mass - двумерный массив символов в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    for (int i = 0; i < needCountToEnter; i++)
    {
        printf("Input mass element: ");
        mass[i] = (char *)malloc(100);
        gets(mass[i]);
        mass[i] = trimStr(mass[i]);
    }
}

void scanDoubleMassElementInt(int **mass, int needCountToEnter)
{
    /* Считывает целочисленный двумерный массив с клавиатуры.
       :mass - двумерный массив целых чисел в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    for (int i = 0; i < needCountToEnter; i++)
    {
        printf("Input mass element: ");
        mass[i] = (int *)malloc(25 * sizeof(int)); /* 25 * 4 == 100, но вдруг у кого-то int больше */
        scanf("%d\n", &mass[i]);
        mass[i] = trimInt(mass[i], sizeof(mass[i]) / sizeof(int));
    }
}

void scanDoubleMassElementFloat(float **mass, int needCountToEnter)
{
    /* Считывает с клавиатуры числа с плавающей точкой для двумерного массива.
       :mass - двумерный массив чисел с плавающей точкой в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    for (int i = 0; i < needCountToEnter; i++)
    {
        printf("Input mass element: ");
        mass[i] = (float *)malloc(25 * sizeof(float));
        scanf("%f\n", &mass[i]);
        mass[i] = trimFloat(mass[i], sizeof(mass[i]) / sizeof(float));
    }
}

void printDoubleMassStr(char **mass, int needCountToEnter)
{
    /* Выводит на экран строки двумерного массива.
       :mass - двумерный массив строк в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    printf("\n---------------------Array---------------------\n");
    for (int i = 0; i < needCountToEnter; i++)
        puts(mass[i]);
    printf("-----------------------------------------------\n");
}

void printDoubleMassInt(int **mass, int width, int height)
{
    /* Выводит на экран целые числа двумерного массива.
       :mass - двумерный массив целых чисел в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    printf("\n------------Array-------------");
    for (int i = 0; i < width; i++)
    {
        printf("\n");
        for (int j = 0; j < height; j++)
            printf(" %d ", mass[i][j]);
    }
    printf("\n------------------------------\n");
}

void printDoubleMassFloat(float **mass, int width, int height)
{
    /* Выводит на экран числа с плавающей точкой двумерного массива.
       :mass - двумерный массив чисел с плавающей точкой в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    printf("\n---------------------Array---------------------\n");
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            printf(" %f ", mass[i][j]);
    printf("-----------------------------------------------\n");
}

void reverse(char *mass)
{
    /* Переворачивает строку.
       Аналог функции replace() в Python.
       :mass - строка, которуб будем переворачивать;
    */
    unsigned long k = strlen(mass);
    char input[len(mass)];
    strcpy(input, mass);
    for (int i = 0; i < k; i++)
    {
        mass[i] = input[k - i - 1];
    }
    mass[k] = '\0';
}

void replace(char *mass, char oldSym, char newSym)
{
    /* Замена всех вхождений символа old на newSym.
       Аналог функции replace() в Python.
       :mass - строка в которой нужно заменять символ;
       :old - символ, который нужно заменить;
       :new - символ, который будет заменен.
    */
    for (int i = 0; i < len(mass); i++)
        if (mass[i] == oldSym)
            mass[i] = newSym;
}

int set(int *mass, int lenhtMass)
{
    /* Ф-ция удаляет из массива повторяющиеся элементы.
    Аналог ф-ции set() из python.
    Возвращает длину мн-ства.
    :b - указатель на массив;
    :k - длина массива;
    */
    for (int i = 0; i < lenhtMass; i++)
    {
        for (int r = i + 1; r < lenhtMass; r++)
        {
            if (mass[i] == mass[r])
            {
                for (int g = r; g < lenhtMass; g++)
                {
                    mass[g] = mass[g + 1];
                }
                lenhtMass--;
                r--;
            }
        }
    }
    return lenhtMass;
}

void sort(int *mass, int k)
{
    /* Функция сортировки массива по возрастанию.
     :mass - указатель на массив;
     :k - количество элементов в массиве.
    */
    int temp;
    for (int i = 0; i < k; i++)
    {
        for (int t = 0; t < k - i - 1; t++)
        {
            if (mass[t] > mass[t + 1])
            {
                temp = mass[t];
                mass[t] = mass[t + 1];
                mass[t + 1] = temp;
            }
        }
    }
}

long long int max(const long long int *mass, int k)
{
    /* Возвращает максимальный элемент массива.
       :mass - указатель на массив;
       :k - длинна массива;
    */

    long long int maxi = LONG_LONG_MIN;
    for (int i = 0; i < k; i++)
    {
        if (mass[i] > maxi)
        {
            maxi = mass[i];
        }
    }
    return maxi;
}

long long int min(const long long int *mass, int k)
{
    /* Функция нахождения минимума в массиве.
     Аналог функции min() в Python.
    :mass - указатель на массив;
    :k - длинна массива;
    */
    long long int mini = LONG_LONG_MAX;
    for (int i = 0; i < k; i++)
    {
        if (mass[i] < mini)
        {
            mini = mass[i];
        }
    }
    return mini;
}

long long int sum(const int *mass, int k)
{
    // TODO добавить поддержку float/double через макросы.
    /* Возвращает сумму элементов в целочисленном массиве.
     Аналог функции min() в Python.
    :mass - указатель на массив;
    :k - длинна массива;
    */
    long long int s = 0;
    for (int i = 0; i < k; i++)
    {
        s += mass[i];
    }
    return s;
}

char *removeSym(char *mass, char sym)
{
    /* Удаляет символ из строки.
     Аналог функции remove() в Python.
    :mass - строка, из которой будем удалять символ;
    :sym - символ, который нужно удалить;
    */
    char *res = (char *)malloc(len(mass));
    int j = 0;
    for (int i = 0; mass[i] != '\0'; i++)
    {
        res[j] = mass[i];
        if (res[j] != sym)
            j++;
    }
    res[j] = '\0';
    return res;
}

char *removeOneSym(char *mass, char sym)
{
    /* Удаляет символ из строки.
     Аналог функции remove() в Python.
    :mass - строка, из которой будем удалять символ;
    :sym - символ, который нужно удалить;
    */
    char *res = (char *)malloc(len(mass));
    int j = 0;
    for (int i = 0; mass[i] != '\0'; i++)
    {
        res[j] = mass[i];
        if (res[j] != sym)
        {
            j++;
            sym = '\n';
        }
    }
    res[j] = '\n';
    return res;
}

int *delitNum(int num, int &len)
{
    /* Поиск всех делителей числа.
    :num - число, у которого будем искать все делители;
    :len - длинна масива делителей, нужно, чтобы потом можно было пользоваться массивом делителей;
    */
    int *res = (int *)malloc(num * sizeof(int));
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            res[len] = i;
            len++;
        }
    }
    return res;
}

int countCharInStr(char *mass)
{
    /* Считает количество букв в строке.
    :mass - строка, в которой будем считать количество букв;
    */
    int count = 0;

    for (int i = 0; i < len(mass); i++)
    {
        if ((mass[i] >= 'a' && mass[i] <= 'z') || (mass[i] >= 'A' && mass[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}

void inputMatrix(int **m, int width, int height)
{
    /* Ввод матрицы с клавиатуры.
    :m - пустая матрица(динамический двумерный массив);
    :height - количество строк матрицы;
    :width - количество столбцов в строке;
    */
    for (int i = 0; i < width; i++)
    {
        m[i] = (int *)malloc(sizeof(int) * height);
        for (int j = 0; j < height; j++)
        {
            printf("Input matrix element: ");
            scanf("%d", &m[i][j]);
        }
    }
}

int **sumMatrix(int **m1, int **m2, int widthFirstMatrix, int heightFirstMatrix)
{
    /* Сумма двух ОДИНАКОВЫХ матриц.
    :m1 - первая заполненная матрицы(динамический двумерный массив);
    :m2 - вторая заполненная матрица(динамический двумерный массив);
    :heightFirstMatrix - количество строк матрицы;
    :widthFirstMatrix - количество столбцов в строке;
    */
    int **res = (int **)malloc(widthFirstMatrix * sizeof(int *));
    for (int i = 0; i < widthFirstMatrix; i++)
    {
        res[i] = (int *)malloc(sizeof(int) * heightFirstMatrix);
        for (int j = 0; j < heightFirstMatrix; j++)
            res[i][j] = m1[i][j] + m2[i][j];
    }
    return res;
}

float meanSquareOddItemMatrixUp(int **mass, int width, int heigth)
{
    /* Среднеарифметическая сумма нечетныхм элементов матрицы выше главной диагонали.
    :mass - заполненная матрицы(динамический двумерный массив);
    :heigth - количество строк матрицы;
    :width - количество столбцов в строке;
    */
    float res = 0; // среднеарифметическое всех нечетных чисел матрицы выше главной диагонали;
    int count = 0; // количество подходящих нам элементов матрицы;
    for (int i = 0; i < width; i++)
    {
        for (int j = i + 1; j < heigth; j++)
        {
            if (mass[i][j] % 2 != 0)
            {
                res += mass[i][j];
                count++;
            }
        }
    }
    return res / count;
}

float meanSquareEvenItemMatrixUp(int **mass, int width, int heigth)
{
    /* Среднеарифметическая сумма четныхм элементов матрицы выше главной диагонали.
    :mass - заполненная матрицы(динамический двумерный массив);
    :heigth - количество строк матрицы;
    :width - количество столбцов в строке;
    */
    float res = 0; // среднеарифметическое всех четных чисел матрицы выше главной диагонали;
    int count = 0; // количество подходящих нам элементов матрицы;
    for (int i = 0; i < width; i++)
    {
        for (int j = i + 1; j < heigth; j++)
        {
            if (mass[i][j] % 2 == 0)
            {
                res += mass[i][j];
                count++;
            }
        }
    }
    printf("count=%d\n", count);
    return res / count;
}

int find(char *mass, char sym)
{
    /* Поиск индекса символа в строке.
    :mass - массив символов(строка);
    :sym - символ, индекс которого мы будем искать;
    */
    int i = 0;
    for (; mass[i] != '\0'; i++)
        if (mass[i] == sym)
            return i;
    return -1;
}

int findC(char *mass, char sym)
{
    /* Поиск количества символа в строке.
    :mass - массив символов(строка);
    :sym - символ, индекс которого мы будем искать;
    */
    int k = 0;
    for (int i = 0; mass[i] != '\0'; i++)
        if (mass[i] == sym)
            k++;
    return k;
}

int findUnderStr(char *mass, char *underStr)
{
    /* Поиск индекса начала подстроки в строке.
    :mass - массив символов(строка);
    :underStr - подстрока индекс начала которой мы ищем;
    */
    int i = 0, j = 0;
    for (; mass[i] != '\0'; i++)
    {
        if (mass[i] == underStr[j])
            j++;
        if (j == len(underStr))
            return i - (len(underStr) - 1);
    }
    return -1;
}

int findCountUnderStr(char *mass, char *underStr)
{
    /* Поиск количества подстрок в строке.
    :mass - массив символов(строка);
    :underStr - подстрока;
    */
    int i = 0, j = 0, count = 1;
    for (; mass[i] != '\0'; i++)
    {
        if (mass[i] == underStr[j])
            j++;
        if (j == len(underStr))
        {
            count++;
            j = 0;
        }
    }
    return count - 1;
}

char *split(char *mass, char sym)
{
    /* Запоминает слово после символа(sym) разбивки строки и удаляет это слово из строки.
    :mass - массив символов(строка);
    :sym - символ, по которому мы будем разбивать на отдельные слова строку;
    */
    char *res = (char *)malloc(100);
    int k = 0;
    for (int i = 0; mass[i] != '\0'; i++)
    {
        if (mass[i] == sym)
        {
            for (int j = i + 1; mass[j] != '\0'; j++)
            {
                res[k] = mass[j];
                k++;
                mass[j] = ' ';
            }
        }
    }
    res = trimStr(res);
    return res;
}

char *removeUnderStr(char *mass, char *str)
{
    /* Удаляет подстроку из строки.
    :mass - массив символов(строка);
    :str - подстрока, которую будем удалять из строки;
    */
    int i = 0, tmp = 0;
    if (findUnderStr(mass, str) != -1)
    {
        i = findUnderStr(mass, str);
        tmp = i;
    }
    int k = len(str);
    int l = 0;
    while (k > 0)
    {
        i = tmp;
        for (i; i < mass[i] != '\0'; i++)
        {
            mass[i] = mass[i + 1];
        }
        str = removeOneSym(str, str[0]);
        str = trimStr(str);
        k--;
    }
    mass = trimStr(mass);
    return mass;
}

int doubleMassCountString(char **mass, int needCountToEnter, char sym)
{
    int countStrints = 0;
    for (int i = 0; i < needCountToEnter; i++)
        countStrints += findC(mass[i], sym);
    return countStrints;
}

char **splitDoubleMassBySym(char **mass, int needCountToEnter, char sym)
{
    int countStrints = doubleMassCountString(mass, needCountToEnter, 'A');
    char **res = (char **)malloc(countStrints * sizeof(char *));
    int i, j;
    for (i = 0, j = -1; i < needCountToEnter; i++)
    {
        if (findC(mass[i], sym))
        {
            j++;
            res[j] = mass[i];
        }
        else
        {
            int l = 0;
            for (l = 0; mass[i][l] != '\0'; l++)
                res[j][l + len(res[j])] = mass[i][l];
            res[j] = trimStr(res[j]);
            puts(res[j]);
        }
    }
    return res;
}