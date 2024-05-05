#include <iostream>
#include <stack>
#include <cctype> // Untuk isalnum()

using namespace std;

bool isPalindrome(string sentence) {
    stack<char> charStack;
    string cleanedSentence;

    // Membersihkan kalimat dari karakter non-alfanumerik dan mengonversi ke huruf kecil
    for (char c : sentence) {
        if (isalnum(c)) {
            cleanedSentence += tolower(c);
        }
    }

    // Memasukkan karakter-karakter yang telah dibersihkan ke dalam stack
    for (char c : cleanedSentence) {
        charStack.push(c);
    }

    // Membalikkan kalimat menggunakan stack
    string reversedSentence;
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    // Membandingkan kalimat asli dengan kalimat yang telah dibalik
    return cleanedSentence == reversedSentence;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat:";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << "Kalimat tersebut adalah Telkom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
