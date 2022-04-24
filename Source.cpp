#include <iostream>
#include <Windows.h> 
#include <conio.h>
#include <time.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };
void screen_exit();
void inout_screen_exit();
void screen1();
void inout_scren1();
void text();
void input(int &P,int & prover);
void errorr(int error);
void vibor(int& P);
void random(int const SIZE, double A[], double B[], double C[]);
void manually(int const SIZE, double A[], double B[], double C[], double& chislo);
void Hoarasort(double a[], int first, int last);
void Shell(double a[], int const SIZE);
void sum(int const SIZE, double A[], double B[], double C[], int& prover, int &SumA,int & SumB,int & SumC);
void otvet(int& prover, int& SumA, int& SumB, int& SumC);
void vivod(double A[], double B[], double C[], int const SIZE);
int main() {
	srand(time(0));
	int const SIZE = 10;
	int P, prover, SumA = 0, SumB = 0, SumC = 0;
	double chislo;
	double A[SIZE];
	double B[SIZE];
	double C[SIZE];
	bool proverka = true;
	char chose;
	setlocale(LC_ALL, "rus");
	screen1();
	proverka = ((chose = _getch()) == 27) ? 0 : 1;
	//ASCII "Esc" = 27, ASCII "Enter" = 13;
	if (chose == 13) {
		system("cls");
		text();
		input(P,prover);
		if (P == 1) {
			random(SIZE, A, B, C);
		}
		else if (P == 2) {
			manually(SIZE, A, B, C,chislo);
		}
		vibor(P);
		if (P == 1) {
			Hoarasort(A, 0, SIZE - 1);
			Hoarasort(B, 0, SIZE - 1);
			Hoarasort(C, 0, SIZE - 1);
		}
		else if (P == 2) {
			Shell(A, SIZE);
			Shell(B, SIZE);
			Shell(C, SIZE);
		}
		sum(SIZE, A, B, C, prover,SumA, SumB, SumC);
		otvet(prover, SumA, SumB,  SumC);
		vivod(A, B, C, SIZE);
		system("pause");
		screen_exit();
	}
	else if (chose == 27) {
		system("cls");
		screen_exit();
	}
	/*delete[] A;
	delete[] B;
	delete[] C;*/
	return 0;
}
void screen_exit()
{
	system("cls");
	int height = 7;
	int weight = 40;
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < height - 1; i++) {
		bool i_is_not_a_second_third_fourth_and_fifth = (i == 2 || i == 3 || i == 4 || i == 5) ? 0 : 1;
		for (int j = 0; j <= weight; j++) {
			if ((j == 0 || j == weight) && i_is_not_a_second_third_fourth_and_fifth) {
				cout << "|";
			}
			else if (i == 2) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else if (i == 3) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else if (i == 4) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else if (i == 5) {
				if (j == 0) cout << "|";
				else if (j == weight) cout << "|";
				else cout << " ";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight - 0)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++)
		cout << "-";
	cout << "\n";
	inout_screen_exit();
	bool proverka = true;
	char chose;
	proverka = ((chose = _getch()) == 27) ? 0 : 1;
	//ASCII "Esc" = 27, ASCII "Enter" = 13;
	if (chose == 13) {
		system("cls");
		main();
	}
	else if (chose == 27) {
		system("cls");
		exit(0);
	}
}
void inout_screen_exit()
{
	position = { 2, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Program recursion completed it's work";
	position = { 14, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Program recursion";
	position = { 17, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Group 1092";
	position = { 16, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Fedenko Efim";
	position = { 7, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Escape-exit";
	position = { 25, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter-continue";
}
void screen1()
{
	int height = 7;
	int weight = 45;
	for (int i = 0; i < weight + 1; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < height - 1; i++) {
		bool i_is_not_a_second_third_fourth_and_fifth = (i == 2 || i == 3 || i == 4 || i == 5) ? 0 : 1;
		for (int j = 0; j <= weight; j++) {
			if ((j == 0 || j == weight) && i_is_not_a_second_third_fourth_and_fifth) {
				cout << "|";
			}
			else if (i == 2) {
				if (j == 0) cout << "|";
				else if (j == weight -0) cout << "|";
				else cout << " ";
			}
			else if (i == 3) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else if (i == 4) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else if (i == 5) {
				if (j == 0) cout << "|";
				else if (j == weight - 0) cout << "|";
				else cout << " ";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++) {
		cout << "-";
	}
	cout << "\n";
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j <= weight; j++) {
			if (j == 0 || j == weight - 0)
				cout << "|";
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < weight + 1; i++)
		cout << "-";
	cout << "\n";
	inout_scren1();
}
void inout_scren1() {
	position = { 14, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Program recursion";
	position = { 17, 4 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Group 1092";
	position = { 16, 5 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Fedenko Efim";
	position = { 7, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Escape-exit";
	position = { 25, 8 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "Enter-continue";
}
void text() {
	position = { 0, 0 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "1)rand?";
	position = { 0, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "2)manually?";
	position = { 0, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "P=";
}
void input(int &P, int& prover) {
	int error = 0;
	errorr(error);
	do {
		errorr(error);
		position = { 0, 2 };
		SetConsoleCursorPosition(hConsole, position);
		cin >> P;
		error++;
	} while (P > 2);
	error = 0;
	errorr(error);
	do {
		errorr(error);
		position = { 2, 3 };
		SetConsoleCursorPosition(hConsole, position);
		cin >> prover;
		error++;
	} while (prover < 0);
}
void errorr(int error) {
	if (error > 0) {
		position = { 22, 8 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Error";
	}
	else {
		position = { 22, 8 };
		SetConsoleCursorPosition(hConsole, position);
		cout << "Good!";
	}
}
void random(int const SIZE, double A[], double B[], double C[]) {
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand()%100;
	}
	for (int i = 0; i < SIZE; i++) {
		B[i] = rand() % 100;
	}
	for (int i = 0; i < SIZE; i++) {
		C[i] = rand() % 100;
	}
}
void manually(int const SIZE, double A[], double B[], double C[], double& chislo) {
	position = { 0, 1 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "A=";
	for (int i = 0; i < SIZE; i++) {
		cin >> chislo;
		A[i] = chislo;
	}
	position = { 0, 2 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "B=";
	for (int i = 0; i < SIZE; i++) {
		cin >> chislo;
		B[i] = chislo;
	}
	position = { 0, 3 };
	SetConsoleCursorPosition(hConsole, position);
	cout << "C=";
	for (int i = 0; i < SIZE; i++) {
		cin >> chislo;
		C[i] = chislo;
	}
}
void vibor(int& P) {
	cout << "Sort?" << "\n" << "1)Hoar" << '\n' << "2)Shell" << endl;;
	cin >> P;
}
void Hoarasort(double a[], int first, int last)
{
	int i = first, j = last;
	double tmp, x = a[(first + last) / 2];
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		Hoarasort(a, i, last);
	if (first < j)
		Hoarasort(a, first, j);
}
void Shell(double a [], int const SIZE) //сортировка Шелла
{
	int d = SIZE, j;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < SIZE - d; i++)
		{
			j = i;
			while (j >= 0 && a[j] > a[j + d])
			{
				int count = a[j];
				a[j] = a[j + d];
				a[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}
void sum(int const SIZE, double A[], double B[], double C[], int& prover, int& SumA, int& SumB, int& SumC)
{
	for (int i = 0; i < SIZE; i++) {
		SumA=SumA+A[i];
	}
	for (int i = 0; i < SIZE; i++) {
		SumB = SumB + B[i];
	}
	for (int i = 0; i < SIZE; i++) {
		SumC= SumC + C[i];
	}
	cout <<"SumA:"<<SumA << endl <<"SumB:" << SumB << endl <<"SumC:" << SumC << endl;
}
void otvet(int& prover, int& SumA, int& SumB, int& SumC) 
{
	if (prover <SumA)
		cout << "arrA>P";
	else if (prover < SumB)
		cout << "arrB>P";
	else if (prover < SumC)
		cout << "arrC>P";
	else
		cout << "P>arrA,arrB>arrC";
	cout << endl;
}
void vivod(double A[], double B[], double C[], int const SIZE) {
	for (int i = 0; i < SIZE;i++) {
		cout << A[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < SIZE; i++) {
		cout << B[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < SIZE; i++) {
		cout << C[i] << " ";
	}
}


