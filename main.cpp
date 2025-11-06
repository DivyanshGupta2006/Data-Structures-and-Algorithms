#include <iostream>
using namespace std;
typedef long long int ll;

ll fact(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int sumOfDigits(ll n) {
    int sum = 0;
    for (ll i = n; i > 0; i /= 10) {
        sum += i % 10;
    }
    return sum;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The array before sorting is: " << endl;
    printArray(arr, n);

    int numSwaps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1) {
                if (arr[j] > arr[j + 1] && j != i) {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    numSwaps ++ ;
                    printArray(arr, n);
                }
            }
        }
    }

    cout << "The array after sorting is: " << endl;
    printArray(arr, n);

    cout << "The number of swaps is: " << numSwaps << endl;

    cout << "The sum of digits of factorial of number of swaps in bubble sort is: " << sumOfDigits(fact(numSwaps)) << endl;

    return 0;
}