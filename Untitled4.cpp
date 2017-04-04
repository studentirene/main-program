#include <iostream>
#include <ctime>                                //для роботи srand()
#include <cstdlib>                              //для роботи rand()
#include <iomanip>
#include <Windows.h>                            // для очистки вікна консолі

//инициализация перемнных и указателей
int p,n,q,i,j,count=0, aa,ii,jj;                              // розміри матриці та змінні
bool f_exit=true;                               // вихід з програми
int **A, *csrA, *csrJ, *csrI;		                  // вказівник на матрицю

// прототипы функций
void inputSizeMatrix();                         // Ввід розмірності матриці
bool exitProg();                                // Запит на продовження роботи програми

void fillMatrix(int **Matrix,int ,int );        // Заповнення матриці
void printMatrix (int **Matrix,int ,int );      // Вивід матриці

int countElOfMatrix (int **Matrix, int ,int);
void kooMatrix (int **Matrix, int ,int);					//вивід в координатному форматі
void csrMatrix (int **Matrix, int ,int);					//вивід в розрідженому рядковому форматі

using namespace std;

int main() {
	setlocale(0,"");
	srand(time(NULL));
repeat:
	inputSizeMatrix();

// Виділення пам'яті на матрицю та її вказівник
	A=new int *[p];
	for (i=0; i<p; i++) A[i]=new int [n];

	fillMatrix (A,p,n);     // заповнюємо матрицю A
	cout    << "\n Матриця А("<<p<<" x "<<n<<"):";
	printMatrix (A,p,n);

	countElOfMatrix (A,p,n);
	csrA=new int *[n*p];
	csrJ=new int *[p];
	csrI=new int *[n+1];

	kooMatrix (A,p,n);


	// чистимо пам'ять
	for (i=0; i<p; i++) {
		delete []A[i];
	}
	delete []A;

	if(exitProg()==true)goto repeat;
	return 0;
}

void inputSizeMatrix() {
	// Функція вводу розмірностей матриці
refresh:
	cout    << "Введите размерность матриц А:\n\n";
	cout    << "\nКоличество строк в матрице А=\t\t";
	cin  >> n;
	cout    << "\nКоличество столбцов в матрице А=\t";
	cin  >> p;
	cout    << "\n------------------------------------------\n";
}

void fillMatrix(int **Matrix,int col,int row) {
	// Заповнення матриці випадковими розрідженими значеннями
	for (int i=0; i<col; i++)
		for (int j=0; j<row; j++)
			Matrix[i][j]=(1+rand()%(100))*(rand()%2); //генеруєм випадкові числа від 0 до 100
}
void printMatrix (int **Matrix,int col,int row) {
	// Вивід на консоль матриці розмірності col x row
	cout    << endl;
	for (i=0; i<col; i++) {
		cout    << endl;
		for (j=0; j<row; j++)
			cout    <<setw(7) << Matrix[i][j];
	}
	cout    << endl;
}

bool exitProg() {
	//Чи завершуємо роботу?
	cout    << "\n------------------------------------------";
	cout    << "\n------------------------------------------\n";
	cout    << "\nЖелаете продолжить работу ? 0-нет/1-да\t";
	cin     >> x;
	if (x==1) system("cls");
	return x;
}

void kooMatrix (int **Matrix, int col,int row )
//вивід матриці в координатному форматі
{
	cout << endl;
	cout << "Координатний формат матриці" << endl;
	cout << " A:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << Matrix[i][j];
	cout << endl;
	cout << " Li:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << i+1;
	cout << endl;
	cout << " Lj:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << j+1;
}

int countElOfMatrix (int **Matrix, int col,int row ) {
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				count++;
	return count;
}


void csrMatrix (int **Matrix, int col,int row, int *csrA, int *csrJ, int *csrI)
//вивід матриці в розрідженому рядковому форматі
{
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				Matrix[i][j]=crsA[aa];



	cout << endl;
	cout << "Розріджений рядковий формат матриці" << endl;
	cout << " A:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << Matrix[i][j];
	cout << endl;
	cout << " Lj:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << j+1;
	cout << endl;
	cout << " Lj:"  << endl;
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				cout <<setw(4) << j+1;
}
