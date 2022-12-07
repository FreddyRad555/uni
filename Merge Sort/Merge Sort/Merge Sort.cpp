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

void merge(int array[], int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m - l + 1; nr = r - m;
    int larr[nl], rarr[nr];

    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];

    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];

    i = 0; j = 0; k = l;

    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {
        array[k] = rarr[j];
        j++; k++;
    }
}

void mergeSort(int* array, int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
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
    mergeSort(arr, N);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << search_time << " ms ";
    return 0;
}
