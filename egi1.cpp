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
            charStack.push(tolower(c)); // Memasukkan karakter ke dalam stack saat membersihkan
        }
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
    string kalimat1 = "ini";
    string kalimat2 = "telkom";

    if (isPalindrome(kalimat1)) {
        cout << "Kalimat :" << kalimat1 << 
        " kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat :" << kalimat1 << 
        " kalimat tersebut adalah bukan palindrom." << endl;
    }

    if (isPalindrome(kalimat2)) {
        cout << "Kalimat :" << kalimat2 << 
        " kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat :" << kalimat2 << 
        " kalimat tersebut adalah bukan palindrom." << endl;
    }

    return 0;
}
