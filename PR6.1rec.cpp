#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE = 25;
const int Low = -20;
const int High = 30;

// Рекурсивна функція для генерації масиву з випадковими значеннями
void Create(int a[], int size, int i = 0) {
    if (i == size) return; // Базовий випадок: якщо індекс досяг розміру масиву
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, i + 1); // Рекурсивний виклик для наступного індексу
}

// Рекурсивна функція для виведення масиву
void output(const int a[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    output(a, size, i + 1); // Рекурсивний виклик для наступного індексу
}

// Рекурсивна функція для підрахунку кількості додатних парних елементів
int count(const int a[], int size, int i = 0) {
    if (i == size) return 0; // Базовий випадок
    int countCurrent;
    if (a[i] > 0 && a[i] % 2 == 0) {
        countCurrent = 1;
    }
    else {
        countCurrent = 0;
    }

    return countCurrent + count(a, size, i + 1); // Рекурсія для наступного елемента
}

// Рекурсивна функція для обчислення суми додатних парних елементів
int sum(const int a[], int size, int i = 0) {
    if (i == size) return 0; // Базовий випадок
    int sumCurrent;
    if (a[i] > 0 && a[i] % 2 == 0) {
        sumCurrent = a[i];
    }
    else {
        sumCurrent = 0;
    }
    return sumCurrent + sum(a, size, i + 1); // Рекурсія для наступного елемента
}

// Рекурсивна функція для заміни додатних парних елементів на нулі
void replaceZero(int a[], int size, int i = 0) {
    if (i == size) return; // Базовий випадок
    if (a[i] > 0 && a[i] % 2 == 0) {
        a[i] = 0;
    }
    replaceZero(a, size, i + 1); // Рекурсія для наступного елемента
}

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    int array[SIZE];
    Create(array, SIZE);// Генерація масиву

    cout << "Original Array:\n";// Виведення початкового масиву
    output(array, SIZE);

    int COUNT = count(array, SIZE);// Підрахунок кількості та суми додатних парних елементів
    int SUM = sum(array, SIZE);
    
    cout << "\nCount of positive even elements: " << COUNT << endl;// Виведення результатів
    cout << "Sum of positive even elements: " << SUM << endl;
    
    replaceZero(array, SIZE);// Заміна додатних парних елементів на нулі
    
    cout << "\nModified Array:\n";// Виведення модифікованого масиву
    output(array, SIZE);

    return 0;
}
