#include <iostream>
#include <ctime>
using namespace std;

void fillArray(int n, int* numbers) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100;
        cout << numbers[i] << endl;
    }
}

int  findMaxEl() 
{

} 

int main()
{

    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    int* numbers{ new int[n] {} };
    fillArray(n, numbers);
}

