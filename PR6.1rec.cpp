#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE = 25;
const int Low = -20;
const int High = 30;

// ���������� ������� ��� ��������� ������ � ����������� ����������
void Create(int a[], int size, int i = 0) {
    if (i == size) return; // ������� �������: ���� ������ ����� ������ ������
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, i + 1); // ����������� ������ ��� ���������� �������
}

// ���������� ������� ��� ��������� ������
void output(const int a[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    output(a, size, i + 1); // ����������� ������ ��� ���������� �������
}

// ���������� ������� ��� ��������� ������� �������� ������ ��������
int count(const int a[], int size, int i = 0) {
    if (i == size) return 0; // ������� �������
    int countCurrent;
    if (a[i] > 0 && a[i] % 2 == 0) {
        countCurrent = 1;
    }
    else {
        countCurrent = 0;
    }

    return countCurrent + count(a, size, i + 1); // ������� ��� ���������� ��������
}

// ���������� ������� ��� ���������� ���� �������� ������ ��������
int sum(const int a[], int size, int i = 0) {
    if (i == size) return 0; // ������� �������
    int sumCurrent;
    if (a[i] > 0 && a[i] % 2 == 0) {
        sumCurrent = a[i];
    }
    else {
        sumCurrent = 0;
    }
    return sumCurrent + sum(a, size, i + 1); // ������� ��� ���������� ��������
}

// ���������� ������� ��� ����� �������� ������ �������� �� ���
void replaceZero(int a[], int size, int i = 0) {
    if (i == size) return; // ������� �������
    if (a[i] > 0 && a[i] % 2 == 0) {
        a[i] = 0;
    }
    replaceZero(a, size, i + 1); // ������� ��� ���������� ��������
}

int main() {
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    int array[SIZE];
    Create(array, SIZE);// ��������� ������

    cout << "Original Array:\n";// ��������� ����������� ������
    output(array, SIZE);

    int COUNT = count(array, SIZE);// ϳ�������� ������� �� ���� �������� ������ ��������
    int SUM = sum(array, SIZE);
    
    cout << "\nCount of positive even elements: " << COUNT << endl;// ��������� ����������
    cout << "Sum of positive even elements: " << SUM << endl;
    
    replaceZero(array, SIZE);// ����� �������� ������ �������� �� ���
    
    cout << "\nModified Array:\n";// ��������� �������������� ������
    output(array, SIZE);

    return 0;
}
