#include <iostream>
#include <ctime>
#include <malloc.h>
#include <conio.h>

using namespace std;

int* vis = NULL, n, ** p = NULL;

void DFS(int num) {
	cout << num+1 << " ";
	vis[num] = 1;
	for (int i = 0; i < n; i++) {
		if (p[num][i] == 0 && vis[i] == 0) {
			DFS(i);
		}
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0)); //��-���������� ��������� ��������� �������
	int z;
	cout << "������� ������ �������: ";
	cin >> n;
	cout << "������� ����� ��������� �������: ";
	cin >> z;
	cout << "������: \n";
	vis = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	p = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) 
	{
		p[i] = (int*)calloc(n, sizeof(int));
	}
	cout.precision(3 * n);
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			p[i][m] = 0 + rand() % 2;
			p[i][i] = 0;
			cout << p[i][m] << " ";
		}
		cout << endl;
	}
	cout << endl<< "�����: ";
	DFS(z-1);
	return 0;

}

