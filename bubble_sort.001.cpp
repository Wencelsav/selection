
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;




void bubbleSort(int* a, int n)
{
	
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int i = 0; i < (n - 1); i++)

			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
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

int main() 
{
	int n;
	int *a;
	
	cin.get();
	a = new int[n];
	if (((cin >> n) || (n >= 0))&& read_numbers(a, n)) {
		
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
