#include <iostream>
#include <limits>
using namespace std;

int main() {
    int arr[20];        // smallest possible array for worst case
    int uniqueCount = 0;
    int num;

    cout << "Enter 20 numbers between 10 and 100:\n";

    for(int i = 0; i < 20; ) {
        cin >> num;

        // ---- Input failure handling ----
        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();  // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            continue;
        }

        // ---- Range validation ----
        if (num < 10 || num > 100) {
            cout << "Number out of range. Enter between 10 and 100.\n";
            continue;yghyiibyuiobytib
        }

        // ---- Duplicate check ----
        bool isDuplicate = false;
        for(int j = 0; j < uniqueCount; j++) {
            if(arr[j] == num) {
                isDuplicate = true;
                break;
            }
        }

        // ---- Store only if unique ----
        if(!isDuplicate) {
            arr[uniqueCount] = num;
            uniqueCount++;
            i++;   // count only valid attempts
        } else {
            cout << "Duplicate number ignored.\n";
        }
    }

    // ---- Display unique values ----
    cout << "\nUnique numbers entered:\n";
    for(int i = 0; i < uniqueCount; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
