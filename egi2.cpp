#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseSentence(string sentence) {
    stack<string> wordStack;
    string word, reversedSentence;

    // Memisahkan kata-kata dalam kalimat
    for (int i = 0; i < sentence.length(); ++i) {
        if (sentence[i] == ' ') {
            // Memasukkan kata ke dalam stack
            wordStack.push(word);
            word = "";
        } else {
            word += sentence[i];
        }
    }
    // Memasukkan kata terakhir ke dalam stack
    wordStack.push(word);

    // Membentuk kalimat terbalik dari kata-kata dalam stack
    while (!wordStack.empty()) {
        reversedSentence += wordStack.top() + " ";
        wordStack.pop();
    }

    return reversedSentence;
}

int main() {
    string sentence = "Telkom Purwokerto";
    cout << "Kalimat awal: " << sentence << endl;

    string reversed = reverseSentence(sentence);
    cout << "Kalimat setelah dibalik: " << reversed << endl;

    // Menambahkan hasil ke dalam kalimat asli
    sentence = "Hasil pembalikan: " + reversed;
    cout << sentence << endl;

    return 0;
}
