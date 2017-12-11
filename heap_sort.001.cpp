#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

bool read(int * a, unsigned int size) {
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for (unsigned int i = 0; i < size; ++i) {
        if (!(stream >> a[i])) {
            return false;
        }
    }
    return true;
}
void siftDown(int *numbers, int root, int bottom)
{
    int maxChild;
    int done = 0; 
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    
            maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; 
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else 
            done = 1;
    }
}
void heapSort(int *numbers, int array_size)
{
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        siftDown(numbers, i, array_size);
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}
int main()
{

    int size = 0;
    if ((cin >> size) && (size>1)) {
        string s;
        getline(cin, s);
        istringstream stream(s);
        int * a = new int[size];
        if (read(a, size)) {
            heapSort(a, size);;
            for (int i = 0; i < size; ++i) {
                cout << a[i] << " ";
            }
        }
        else cout << "An error has occured while reading input data." << endl;
        delete[] a;
    }
    else cout << "An error has occured while reading input data." << endl;
    return 0;
}
