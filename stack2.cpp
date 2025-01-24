// infix to previx
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk mengecek apakah karakter adalah operator
bool apakahOperator(char karakter) {
    return karakter == '+' || karakter == '-' || karakter == '*' || karakter == '/';
}

// Fungsi untuk mengonversi ekspresi prefix ke postfix
string konversiPrefixKePostfix(string prefix) {
    stack<string> tumpukan;
    
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (apakahOperator(prefix[i])) {
            // Pastikan ada cukup operand dalam tumpukan
            if (tumpukan.size() < 2) {
                cout << "Ekspresi tidak valid" << endl;
                return "";
            }
            
            string operand1 = tumpukan.top(); tumpukan.pop();
            string operand2 = tumpukan.top(); tumpukan.pop();
            
            // Gabungkan operand dan operator dalam bentuk postfix
            string ekspresi = operand1 + operand2 + prefix[i];
            tumpukan.push(ekspresi);
        } else if (isdigit(prefix[i])) {
            // Masukkan angka langsung ke dalam tumpukan
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
