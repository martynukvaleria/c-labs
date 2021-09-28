#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int MaxSize = 100;
    int n, print;
    cout << "Enter the size of an array:";
    while (true) {
        cin >> n;
        if (n < 1 || n > MaxSize) {
            cout << "Error!the size of an array must be greater than 1 and less than 100 .Enter size:";
            cin >> n;
        } else {
            break;
        }
    }

    double *arr = new double[n];
    cout << "How do you want to enter array?" << endl << "1. From keyboard" << endl << "2. Random numbers" << endl;
    cin >> print;
    switch (print) {
        case 1: {
            cout << "Enter members of array:";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;
            default:
                return 1;
        }
        case 2: {
            cout << "Enter the lower bound and upper bound of random numbers:";
            int lower_bound, upper_bound;
            cin >> lower_bound >> upper_bound;
            if (upper_bound < lower_bound) {
                cout << "Error!";
                return 1;
            }
            srand(time(0));//беру за базу системные часы
            for (int i = 0; i < n; i++) {
                arr[i] = (rand() % (upper_bound - lower_bound + 1) + lower_bound);
            }
            break;
        }
    }
    cout<<"Source array:\n";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i] << " ";
    }
    int max_element=0, min_element=0, last_min_element;
    for(int i=1 ;i<n; i++){
        if (fabs(arr[i])>fabs(arr[max_element]))
            max_element=i;
        if (fabs(arr[i])<fabs(arr[min_element]))
                min_element=i;
    }
    for (int i = 0; i < n; ++i) {
        if (fabs(arr[i])==fabs(arr[min_element])){
            last_min_element=i;
        }
    }
    swap(arr[max_element],arr[min_element]);
    cout<<"\nArray after swapping:\n";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i] << " ";
    }
    double Sum=0;
    for(int i =last_min_element + 1; i < n; i++){
        Sum=Sum+arr[i];
    }
    cout<<"\nThe sum of array elements located after the last minimum element in absolute value:\n"<<Sum<<endl;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            arr[i] = arr[i] * arr[i];
        }
    }
    cout<<"Array before sorting:\n";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i] << " ";
    }
    sort(arr,arr+n);
    cout<<"\nArray after sorting:\n";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i] << " ";
    }
    delete[]arr;
}
