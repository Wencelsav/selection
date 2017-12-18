#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

bool read(int * a, int n) {
	string mas;
	int array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (int i = 0; i < n; i++)
	{
		if (stream >> a[i])
		{
			array_count++;
		}
	}
	if (array_count == n && stream.eof()) return true;
	else return false;
}
void heapSort(int *a, int n) {

	int sh = 0;
	bool b;
	do {
		b = false;
		for (int i = 0; i < n; ++i) {
			if (i * 2 + 2 + sh < n) {
				if ((a[i + sh] >  a[i * 2 + 1 + sh]) || (a[i + sh] >  a[i * 2 + 2 + sh])) {
					if (a[i * 2 + 1 + sh] < a[i * 2 + 2 + sh]) {
						swap(a[i + sh], a[i * 2 + 1 + sh]);
						b = true;
					}
					else if (a[i * 2 + 1 + sh] > a[i * 2 + 2 + sh]) {
						swap(a[i + sh], a[i * 2 + 2 + sh]);
						b = true;
					}
				}
				if (a[i * 2 + 2 + sh] < a[i * 2 + 1 + sh]) {
					swap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
					b = true;
				}
			}
			else if (i * 2 + 1 + sh < n) {
				if (a[i + sh] >  a[i * 2 + 1 + sh]) {
					swap(a[i + sh], a[i * 2 + 1 + sh]);
					b = true;
				}
			}
		}
		if (!b)
			++sh;
	} while (sh + 2 < n);
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
			heapSort(a, size);
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
