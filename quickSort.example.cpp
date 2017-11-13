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
void qs(int *s_arr, int first, int last) {
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
int main() {
    int size=0;
    if ((cin>>size) && (size>1)){
        string s;   
    getline(cin, s);
        istringstream stream(s);

        int * a = new int[size];
        if (read(a, size)) {
            qs(a,0,size);
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
