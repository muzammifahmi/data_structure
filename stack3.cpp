//postfix to invix
#include <iostream>
#include <stack>
using namespace std;

// Fungsi untuk mengecek apakah karakter adalah operand
bool apakahOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Fungsi untuk mengubah ekspresi postfix menjadi ekspresi infix
string postfixKeInfix(string postfix) {
    stack<string> tumpukan;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        // Jika karakter adalah operand, masukkan ke dalam tumpukan
        if (apakahOperand(postfix[i])) {
            tumpukan.push(string(1, postfix[i]));
        } else {
            // Dengan asumsi ekspresi postfix yang valid, sebuah operator akan muncul di sini
            string operand1 = tumpukan.top(); tumpukan.pop();
            string operand2 = tumpukan.top(); tumpukan.pop();

            // Membentuk ekspresi infix dengan menambahkan tanda kurung
            tumpukan.push("(" + operand2 + postfix[i] + operand1 + ")");
        }
    }

    // Di akhir, hanya satu elemen yang tersisa dalam tumpukan, yaitu ekspresi infix yang diinginkan
    return tumpukan.top();
}

int main() {
    string ekspresiPostfix;
    cout << "Masukkan ekspresi postfix: ";
    cin >> ekspresiPostfix;

    string ekspresiInfix = postfixKeInfix(ekspresiPostfix);
    cout << "Infix: " << ekspresiInfix << endl;
    return 0;
}
