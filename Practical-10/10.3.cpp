#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = -1;
    }

    int n, id;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int count = 0;
        int index = h1;

        while (table[index] != -1 && count < 10) {
            index = (h1 + count * h2) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Hash table is full!\n";
        } else {
            table[index] = id;
            cout << "Student ID " << id
                 << " stored at slot " << index << endl;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];
        cout << endl;
    }

    return 0;
}

