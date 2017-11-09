#include <iostream>
#include <iomanip>
using namespace std;
 

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}
    bool read_numbers(int *a, int n)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> a[i])) {
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
	if (read_numbers(a, n)) {
		qs(a,0,n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	else {
		cout << "An error has occured while reading input data.";
	}
	
	return 0;
}
