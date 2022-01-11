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

void printDoubleMassInt(int **mass, int height, int width)
{
    /* Выводит на экран целые числа двумерного массива.
       :mass - двумерный массив целых чисел в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    printf("\n------------Array-------------");
    for (int i = 0; i < height; i++)
    {
        printf("\n");
        for (int j = 0; j < width; j++)
            printf(" %d ", mass[i][j]);
    }
    printf("\n------------------------------\n");
}

void printDoubleMassFloat(float **mass, int height, int width)
{
    /* Выводит на экран числа с плавающей точкой двумерного массива.
       :mass - двумерный массив чисел с плавающей точкой в котором все строки будут заполнены;
       :needCountToEnter - количество строк двумерного массива;
    */
    printf("\n---------------------Array---------------------\n");
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            printf("%f", mass[i][j]);
    printf("-----------------------------------------------\n");
}

void reverse(char *mass)
{
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

int set_cur_array(int *b, int k)
{
    /* Ф-ция удаляет из массива повторяющиеся элементы.
    Аналог ф-ции set() из python.
    Возвращает длину мн-ства.
    :b - указатель на массив;
    :k - длина массива;
    */
    for (int i = 0; i < k; i++)
    {
        for (int r = i + 1; r < k; r++)
        {
            if (b[i] == b[r])
            {
                for (int g = r; g < k; g++)
                {
                    b[g] = b[g + 1];
                }
                k--;
                r--;
            }
        }
    }
    return k;
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

char *removeNew(char *mass, char sym)
{
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

int *delitNum(int num, int &len)
{
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

void inputMatrix(int **m, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        m[i] = (int *)malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
        {
            printf("Input matrix element: ");
            scanf("%d", &m[i][j]);
        }
    }
}

int **sumMatrix(int **m1, int **m2, int heightFirstMatrix, int widthFirstMatrix)
{
    int **res = (int **)malloc(heightFirstMatrix * sizeof(int *));
    for (int i = 0; i < heightFirstMatrix; i++)
    {
        res[i] = (int *)malloc(sizeof(int) * widthFirstMatrix);
        for (int j = 0; j < widthFirstMatrix; j++)
            res[i][j] = m1[i][j] + m2[i][j];
    }
    return res;
}
