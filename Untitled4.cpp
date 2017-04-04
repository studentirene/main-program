#include <iostream>
#include <ctime>                                //��� ������ srand()
#include <cstdlib>                              //��� ������ rand()
#include <iomanip>
#include <Windows.h>                            // ��� ������� ���� ������

//������������� ��������� � ����������
int p,n,q,i,j,count=0, aa,ii,jj;                              // ������ ������� �� ����
bool f_exit=true;                               // ����� � ��������
int **A, *csrA, *csrJ, *csrI;		                  // �������� �� �������

// ��������� �������
void inputSizeMatrix();                         // ��� ��������� �������
bool exitProg();                                // ����� �� ����������� ������ ��������

void fillMatrix(int **Matrix,int ,int );        // ���������� �������
void printMatrix (int **Matrix,int ,int );      // ���� �������

int countElOfMatrix (int **Matrix, int ,int);
void kooMatrix (int **Matrix, int ,int);					//���� � ������������� ������
void csrMatrix (int **Matrix, int ,int);					//���� � ����������� ��������� ������

using namespace std;

int main() {
	setlocale(0,"");
	srand(time(NULL));
repeat:
	inputSizeMatrix();

// �������� ���'�� �� ������� �� �� ��������
	A=new int *[p];
	for (i=0; i<p; i++) A[i]=new int [n];

	fillMatrix (A,p,n);     // ���������� ������� A
	cout    << "\n ������� �("<<p<<" x "<<n<<"):";
	printMatrix (A,p,n);

	countElOfMatrix (A,p,n);
	csrA=new int *[n*p];
	csrJ=new int *[p];
	csrI=new int *[n+1];

	kooMatrix (A,p,n);


	// ������� ���'���
	for (i=0; i<p; i++) {
		delete []A[i];
	}
	delete []A;

	if(exitProg()==true)goto repeat;
	return 0;
}

void inputSizeMatrix() {
	// ������� ����� ����������� �������
refresh:
	cout    << "������� ����������� ������ �:\n\n";
	cout    << "\n���������� ����� � ������� �=\t\t";
	cin  >> n;
	cout    << "\n���������� �������� � ������� �=\t";
	cin  >> p;
	cout    << "\n------------------------------------------\n";
}

void fillMatrix(int **Matrix,int col,int row) {
	// ���������� ������� ����������� ����������� ����������
	for (int i=0; i<col; i++)
		for (int j=0; j<row; j++)
			Matrix[i][j]=(1+rand()%(100))*(rand()%2); //������� �������� ����� �� 0 �� 100
}
void printMatrix (int **Matrix,int col,int row) {
	// ���� �� ������� ������� ��������� col x row
	cout    << endl;
	for (i=0; i<col; i++) {
		cout    << endl;
		for (j=0; j<row; j++)
			cout    <<setw(7) << Matrix[i][j];
	}
	cout    << endl;
}

bool exitProg() {
	//�� ��������� ������?
	cout    << "\n------------------------------------------";
	cout    << "\n------------------------------------------\n";
	cout    << "\n������� ���������� ������ ? 0-���/1-��\t";
	cin     >> x;
	if (x==1) system("cls");
	return x;
}

void kooMatrix (int **Matrix, int col,int row )
//���� ������� � ������������� ������
{
	cout << endl;
	cout << "������������ ������ �������" << endl;
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
//���� ������� � ����������� ��������� ������
{
	for (i=0; i<col; i++)
		for (j=0; j<row; j++)
			if (Matrix[i][j] != 0)
				Matrix[i][j]=crsA[aa];



	cout << endl;
	cout << "���������� �������� ������ �������" << endl;
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
