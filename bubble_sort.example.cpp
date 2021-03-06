#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;




void bubbleSort(int* a, int n)
{
	int temp = 0;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (n - 1); int_counter++)

			if (a[int_counter] > a[int_counter + 1])
			{

				temp = a[int_counter];
				a[int_counter] = a[int_counter + 1];
				a[int_counter + 1] = temp;
				exit = false;
			}
	}
}
bool read_numbers(int *a, int n)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) 
	{
		if (!(stream >> a[i])) 
		{
			success = false;
			break;
		}
	}

	return success;
}

int main() {
	int n;
	int *a;
	cin >> n;
	cin.get();
	a = new int[n];
	if (read_numbers(a, n))
	{
		bubbleSort(a, n);
		for (int i = 0; i < n; i++) 
		{
			cout << a[i] << " ";
		}
	}
	else {
		cout << "An error has occured while reading input data.";
	}
	delete[] a;
	return 0;
}
