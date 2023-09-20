#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <algorithm>

using namespace std;

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}


void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* ����� ���������� */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setlocale(LC_ALL, "Rus");


    int* masshell, * masqs, * masbibl;
    clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
    for (int razmmas = 1000; razmmas <= 100000; razmmas *= 5) {

        masshell = new int[razmmas];
        masqs = new int[razmmas];
        masbibl = new int[razmmas];



        srand(time(NULL)); // �������������� ��������� ���������� ��������� ����� 

        for (int i = 0; i < razmmas;i++) {
            masshell[i] = rand() % 10000 - 5001; // ��������� ������ ���������� �������
            masqs[i] = masshell[i];
            masbibl[i] = masshell[i];

        }
        start = clock();
        shell(masshell, razmmas);
        end = clock();
        double timee = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "����� ���������� Shell �������� ������������ ������� �������  " << razmmas << " = " << timee << "\n";


        start = clock();
        qs(masqs, 0, razmmas - 1);
        end = clock();
        timee = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "����� ���������� qs �������� ������������ ������� �������  " << razmmas << " = " << timee << "\n";


        start = clock();
        sort(masbibl, masbibl + razmmas);
        end = clock();
        timee = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "����� ���������� bibl �������� ������������ ������� �������  " << razmmas << " = " << timee << "\n\n";

        

        free(masshell);
        free(masqs);
        free(masbibl);

    }
}
