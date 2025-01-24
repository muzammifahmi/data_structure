//prefix to postfix
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk memeriksa apakah karakter merupakan operator
bool periksaApakahOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Fungsi untuk mengubah ekspresi prefix menjadi postfix
string ubahPrefixKePostfix(string prefix) {
    stack<string> tumpukan;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (periksaApakahOperator(prefix[i])) {
            // Pastikan ada cukup operand dalam tumpukan
            if (tumpukan.size() < 2) {
                cout << "Ekspresi tidak valid" << endl;
                return "";
            }

            string op1 = tumpukan.top();
            tumpukan.pop();
            string op2 = tumpukan.top();
            tumpukan.pop();

            // Gabungkan operand dan operator dalam bentuk postfix
            string temp = op1 + op2 + prefix[i];
            tumpukan.push(temp);
        } else if (isdigit(prefix[i])) {
            // Masukkan nilai numerik langsung ke dalam tumpukan
            tumpukan.push(string(1, prefix[i]));
        }
    }

    // Jika tumpukan kosong atau memiliki lebih dari satu elemen, ekspresi tersebut tidak valid
    if (tumpukan.empty() || tumpukan.size() > 1) {
        cout << "Ekspresi tidak valid" << endl;
        return "";
    }

    return tumpukan.top();
}
