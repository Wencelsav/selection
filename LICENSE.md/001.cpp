#include "stdafx.h"

#include <iostream>

#include <iomanip>

using namespace std;

 

void insertionSort(int *, int);

 

int main(int argc, char* argv[])

{

    setlocale(LC_ALL, "rus");

    cout << "Введите размер массива: ";

    int size_array; 

    cin >> size_array;

 

    int *sorted_array = new int [size_array]; 

    for (int counter = 0; counter < size_array; counter++)

    {

        sorted_array[counter] = rand() % 100; 

        cout << setw(2) << sorted_array[counter] << "  "; 

    }

    cout << "n";

 

    insertionSort(sorted_array, size_array); 

 

    for (int counter = 0; counter < size_array; counter++)

    {

        cout << setw(2) << sorted_array[counter] << "  "; 

    }

    cout << "n";

    delete [] sorted_array; 
    
    system("pause");

    return 0;

}

 

void insertionSort(int *arrayPtr, int length) 

{

    int temp, 

        item; 

    for (int counter = 1; counter < length; counter++)

    {

        temp = arrayPtr[counter]; 

        item = counter-1; 

        while(item >= 0 && arrayPtr[item] > temp)



        {

            arrayPtr[item + 1] = arrayPtr[item]; 

            arrayPtr[item] = temp;

            item--;

        }

    }

}
