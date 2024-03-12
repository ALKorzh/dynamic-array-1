#include <iostream>
#include <ctime>
using namespace std;

void fillArray(int n, int* array) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
        cout << array[i] << endl;
    }
}

int  findMaxEl(int n,int* array) 
{
    int maxNum = -1;
    for (int i = 0; i < n; i++) {
        if (maxNum < array[i]) {
            maxNum = array[i];
        }
    }

    return maxNum;
} 

int main()
{

    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    int* numbers{ new int[n] {} };
    fillArray(n, numbers);

    cout << findMaxEl(n, numbers) << endl;



    delete[] numbers;
}

