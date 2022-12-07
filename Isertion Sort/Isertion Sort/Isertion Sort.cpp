#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include <ctime>
#include <cstdlib>
#include <cmath>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    std::cout << "Windows 10 x64" << std::endl;
    std::cout << "CPU: Intel(R) Core(TM) i7-4790S CPU @ 3.20GHz" << std::endl;
    std::cout << "***********************************************" << std::endl;
    std::cout << " " << std::endl;

    int N = 10;
    std::cout << "N = ";
    std::cin >> N;
    int* arr = new int[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 21;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    unsigned int start_time = clock();
    insertionSort(arr, N);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << search_time << " ms ";
    return 0;
}
