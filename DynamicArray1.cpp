#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void fillArray(int n, int* array) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
        //cout << array[i] << endl;
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

int productBetweenTwoZeroes(int n, int* array) {
    long long int product = 1;
    int zeroIndexies[2];
    int zeroCounter = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            zeroIndexies[zeroCounter] = i;
            zeroCounter++;
        }

        if (zeroCounter == 2) {
            break;
        }
        
    }

    if(zeroCounter == 2){
        for (int j = zeroIndexies[0] + 1; j < zeroIndexies[1]; j++) {
            product *= array[j];
        }
    }

    

    return product;
}

void updateArray(int n, int* array) {
    int evenCounter = 0;
    int size1 = floor(n / 2) + (n % 2);
    int* evenIndexies{ new int[size1] {}};
    

    int oddCounter = 0;
    int size2 = floor(n / 2);
    int* oddIndexies{ new int[size2] {}};

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenIndexies[evenCounter] = array[i];
            evenCounter++;
        }
        if (i % 2 == 1) {
            oddIndexies[oddCounter] = array[i];
            oddCounter++;
        }
    }

    for (int j = 0; j < size1; j++) {
        array[j] = evenIndexies[j];
        //cout << "Even:" << evenIndexies[j] << endl;
    }

    for (int k = 0; k < size2; k++) {
        array[k + size1] = oddIndexies[k];
        //cout << "Odd:" << oddIndexies[k] << endl;
    }

    delete[] oddIndexies;
    delete[] evenIndexies;
}
void showArray(int n, int* array) {
    cout << "[";
    for (int i = 0; i < n; i++) {

        if (i == n - 1) {
            cout << array[i];
        }
        else {
            cout << array[i] << ", ";
        }

    }
    cout << "]" << endl;
}

int main()
{

    int n;
    cout << "Enter length of array:" << endl;
    cin >> n;

    int* numbers{ new int[n] {} };
    fillArray(n, numbers);
    showArray(n, numbers);

    cout <<"Max Element:" << findMaxEl(n, numbers) << endl;
    cout << "Poduct between two zeroes:" << productBetweenTwoZeroes(n, numbers) << endl;

    updateArray(n, numbers);
    showArray(n, numbers);

    delete[] numbers;

}

