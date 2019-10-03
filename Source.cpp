#include <iostream>;
#include <cstdio>
#include <locale.h>
#pragma warning(disable:4996)
const int nmax = 100;
int vvod(FILE* flexity, int x[][nmax], int& m, int& n)
{
	bool fl = true;
	if (fscanf_s(flexity, "%d\n%d", &m, &n) < 2) {
		printf("Problem with reading");
		fl = false;
	}
	else if (((n < 0) | (n > nmax)) | ((m < 0) | (m > nmax))) {
		printf("Incorrect ammount of elements");
		fl = false;
	}
	else if (fl) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				fscanf_s(flexity, "%d", &x[i][j]);
		fclose(flexity);
	}
	return fl;
}

void vyvod(FILE*& flex, int x[][nmax], int m, int n)
{

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			fprintf(flex, "%d ", x[i][j]);
		fprintf(flex, "\n");
	}

	fprintf(flex, "\n");

}
int count(int x[][nmax], int m, int n) //������� ������� ��������� ��� �������� ������� � �������
{
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (x[i][j] == 0)
				s++;
	return s;
}
bool proverka_2(int x[nmax], int n) {//�������� ������� ������������� ���������� � ������ ����� �������� ���� �������
	bool fl = false;
	int j = 0;
	while ((j < n) && (fl == false)) {
		if (x[j] < 0)
			fl = true;
		j++;
	}
	return fl;
}
void vyvod_2(FILE* flex, int x[nmax][nmax], int mx, int nx) {
	for (int i = 0; i < mx; i++)
		fprintf(flex, "%d ", proverka_2(x[i], nx));
	fprintf(flex, "\n");
};

void main(int argc, char* argv[])
{
	bool fl = true;
	int na, ma, nb, mb, sa, sb, mg;
	int a[nmax][nmax];
	int b[nmax][nmax];
	bool* g;
	FILE* file;
	if (argc < 3)
	{
		printf("������������ ����������!\n");
		fl = false;
	}
	if ((file = fopen(argv[1], "r")) == NULL)
		fl = false;
	if (!(vvod(file, a, ma, na)))
		fl = false;
	if ((file = fopen(argv[2], "r")) == NULL)
		fl = false;
	if (!(vvod(file, b, mb, nb)))
		fl = false;
	file = fopen(argv[3], "w");
	if (fl) {
		vyvod(file, a, ma, na);
		vyvod(file, b, mb, nb);
		fprintf(file, "���������� ����� � ������� �\n");
		sa = count(a, ma, na);
		fprintf(file, "%d\n", sa);
		sb = count(b, mb, nb);
		fprintf(file, "���������� ����� � ������� b\n");
		fprintf(file, "%d\n", sb);
		if (sa < sb) {
			fprintf(file, "������� ������������� ��������� � ������� �");
			vyvod_2(file, a, ma, na);
		}
		else if (sa > sb)
		{
			fprintf(file, "������� ������������� ��������� � ������� b");
			vyvod_2(file, b, mb, nb);
		}
		else
		{
			fprintf(file, "������� ������������� ��������� � ������� �\n");
			vyvod_2(file, a, ma, na);
			fprintf(file, "������� ������������� ��������� � ������� b\n");
			vyvod_2(file, b, mb, nb);
		}

	}
	return;

}