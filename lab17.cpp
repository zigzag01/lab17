#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для заполнения массива случайными числами от 1 до 10
void fill_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1;
    }
}

// Функция для вывода массива на экран
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shell_sort(int *arr, int N) {
    int h, i, t;
    int k; // признак перестановки

    h = N / 2; // начальное значение интервала
    while (h > 0) {
        k = 1;
        while (k) {
            k = 0;
            for (i = 0; i < N - h; i++) {
                if (arr[i] > arr[i + h]) {
                    // меняем местами
                    t = arr[i];
                    arr[i] = arr[i + h];
                    arr[i + h] = t;
                    // признак перестановки
                    k = 1; 
                }
            }
            
        }
        h /= 2; // уменьшение интервала
    }
}

void insert_sort(int* arr, int N) {
    int x;
    long i, j;
    for (i = 0; i < N; i++) {
        x = arr[i]; // где i - номер прохода
        for (j = i; j >= 0 && arr[j] > x; j--) { // поиск эл-та в готовой последовательности
            arr[j + 1] = arr[j]; // сдвигаем элемент
            arr[j + 1] = x; // вставка элемента
        }
    }
}

int main() {

    setlocale(LC_ALL, "rus");
    
    const int N = 100; // задаем размер массива
    int arr[N]; // создаем массив
    
    fill_array(arr, N); // заполняем массив случайными числами
    
    cout << "Mассив до сортировки: " << endl;
    print_array(arr, N);

    time_t start1, finish1, start2, finish2;

    time(&start1);
    shell_sort(arr, N);
    cout << "Массив после сортировки методом Шелла: " << endl;
    print_array(arr, N);
    time(&finish1);

    time(&start2); 
    insert_sort(arr, N);
    cout << "Массив после сортировки методом вставок: " << endl;
    print_array(arr, N);
    time(&finish2);
    
    cout << "Время, затраченное на сортировку методом Шелла: " << difftime(finish1, start1) << endl;
    cout << "Время, затраченное на сортировку методом вставок: " << difftime(finish2, start2) << endl;
}