#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int count = 0;
    while (A > 1 || B > 1 || C > 1){
        // Sort A, B, and C in descending order
        if (A < B) swap(A, B);
        if (A < C) swap(A, C);
        if (B < C) swap(B, C);

        // Divide the longest side by 2 and throw away one part
        if (A % 2 == 0){
            A /= 2; count++;
        } else {
            A = (A - 1) / 2;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

