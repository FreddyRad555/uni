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

int shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
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
    shellSort(arr, N);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << search_time << " ms ";
    return 0;
}