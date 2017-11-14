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
void merge(int *a, int low, int mid, int high)
{
	 
	int *b = new int[high + 1 - low];
	int h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;
	
	while ((h <= mid) && (j <= high))
	{
		if (a[h] <= a[j])
		{
			b[i] = a[h];
			h++;
		}
		else
		{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	
	if (h>mid)
	{
		for (k = j; k <= high; k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	
	for (k = 0; k <= high - low; k++)
	{
		a[k + low] = b[k];
	}
	delete[] b;
}
void merge_sort(int *a, int low, int high)
{
	int mid;
	if (low<high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
int main() {
	int size = 0;
	if ((cin >> size) && (size>1)) {
		string s;
		getline(cin, s);
		istringstream stream(s);
		int * a = new int[size];
		if (read(a, size)) {
			merge_sort(a, 0, size-1);
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

