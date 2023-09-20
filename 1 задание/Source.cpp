#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;


int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int razmmas = 100;
	int elem_c, poryadok = 600;
	int** a,** b,** c;
	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
	for (int progon = 0; progon < 8; progon++) { // ���� ��� ��������������� �������� ������ �������
	
		a = new int* [razmmas]; // ������ ��������� ������
		b = new int* [razmmas];
		c = new int* [razmmas];
		for (int p = 0; p < razmmas; p++) {
			a[p] = new int[razmmas];
			b[p] = new int[razmmas];
			c[p] = new int[razmmas];
		}

		int i = 0, j = 0, r;
		elem_c = 0;

		srand(time(NULL)); // �������������� ��������� ���������� ��������� ����� 
		while (i < razmmas)
		{
			while (j < razmmas)
			{
				a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
				j++;
			}
			i++;
		}
		srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
		i = 0; j = 0;
		while (i < razmmas)
		{
			while (j < razmmas)
			{
				b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
				j++;
			}
			i++;
		}

		start = clock(); // ��������� ����� �� ������ ��������� �����
		for (i = 0;i < razmmas;i++)
		{
			for (j = 0;j < razmmas;j++)
			{
				elem_c = 0;
				for (r = 0;r < razmmas;r++)
				{
					elem_c = elem_c + a[i][r] * b[r][j];
					c[i][j] = elem_c;
				}
			}
		}
		end = clock();// ��������� ����� � ����� ��������� �����
		double timee = (double)(end - start) / CLOCKS_PER_SEC;// ������� � ������� 
		cout << "Time pri " << razmmas << " elementax: " << timee << "\n";

		if (razmmas == 400 || razmmas == 4000) {
			razmmas += poryadok;
			poryadok *= 10;
		}
		else { razmmas *= 2; }
	}


	return(0);
}

