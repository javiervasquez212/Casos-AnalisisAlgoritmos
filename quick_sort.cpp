
#include <iostream>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;
using std::cout;
using std::endl;


 
void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

int *generateArray(int sizeArray){

    int array[sizeArray] = {0};
    srand( time( 0 ) );
    for ( int i = 0; i < sizeArray; ++i ){
        array[ i ] = 0;

    }
    return array;
}

void executionTime(int pArray[], int pPivote){

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(pArray, 0,0);
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

    //Pivote aleatorio 

    cout << "Tiempos pivote aleatorio: " << endl;

    executionTime(arrA,rand() % 2000);
    executionTime(arrC,rand() % 4000);
    executionTime(arrB,rand() % 6000);
    executionTime(arrD,rand() % 8000);
    executionTime(arrE,rand() % 10000);
    executionTime(arrF,rand() % 12000);

    cout << "Tiempos pivote fijo: " << endl;

    //Pivote fijo arrayLenght/2

    executionTime(arrA,1000);
    executionTime(arrC,2000);
    executionTime(arrB,3000);
    executionTime(arrD,4000);
    executionTime(arrE,5000);
    executionTime(arrF,6000);

    return 0;
}

