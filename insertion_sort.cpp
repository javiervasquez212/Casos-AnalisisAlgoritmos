
#include <iostream>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;


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

int *generateArray(int sizeArray){

    int array[sizeArray] = {0};
    srand( time( 0 ) );
    for ( int i = 0; i < sizeArray-i; ++i ){
        array[ i ] = 0;
    }
    return array;
}

void executionTime(int pArray[]){
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(pArray, 0);
    sleep(1);
    auto end = std::chrono::high_resolution_clock::now();

    cout << "Elapsed time in nanoseconds: "
            << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
            << " ns" << endl;

}
 
int main()
{
    int *arrA;
    int *arrB;
    int *arrC;

    int *arrD;
    int *arrE;
    int *arrF;


    arrA = generateArray(2000);
    arrB = generateArray(4000);
    arrC = generateArray(6000);
    arrD = generateArray(8000);
    arrE = generateArray(10000);
    arrF = generateArray(12000);

    executionTime(arrA);
    executionTime(arrC);
    executionTime(arrB);
    executionTime(arrD);
    executionTime(arrE);
    executionTime(arrF);

    return 0;
}
 