# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Egi Rizkiyansyah</p>

## Dasar Teori
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang ditempatkan di tumpukan adalah yang terakhir digunakan.

Definisi: Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).
Sebuah tumpukan adalah struktur data terurut yang mengikuti prinsip "Last In, First Out" (LIFO), yang berarti elemen terakhir yang dimasukkan ke dalam tumpukan adalah yang pertama kali dihapus. Operasi penyisipan dan penghapusan elemen dilakukan hanya pada satu ujung dari tumpukan, yang disebut atas.

Contoh: Salah satu contoh yang sering digunakan untuk menjelaskan konsep tumpukan adalah tumpukan piring di sebuah kafetaria. Ketika piring-piring dibersihkan, mereka ditempatkan di atas tumpukan. Pada saat piring dibutuhkan, piring yang terletak di bagian atas tumpukan yang diambil. Ini mengikuti prinsip LIFO; piring yang terakhir ditempatkan di tumpukan adalah yang pertama diambil.

## Guided 

### 1. [Program Input Array Tentang Sourcecode]

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}

```
#### Full code Screenshot:
![Screenshot 2024-05-06 003906](https://github.com/egirizkiyan/egi-/assets/162097461/b797ea34-3993-4c16-8072-fbf6e7f5379a)

#### Output:
![Screenshot 2024-05-06 004110](https://github.com/egirizkiyan/egi-/assets/162097461/bc541a24-27c8-4b40-b45b-0d4e8eb7f2e4)


Kesimpulan dari kode tersebut adalah:

1. Struktur Data Tumpukan (Stack): Program ini menggunakan array sebagai struktur data untuk merepresentasikan tumpukan buku. Tumpukan ini memiliki batasan maksimal (dalam contoh ini, maksimal adalah 5 buku) dan menggunakan variabel top untuk menunjukkan posisi atas dari tumpukan.
2. Fungsi-fungsi Dasar:
   - isFull(): Memeriksa apakah tumpukan penuh.
   - isEmpty(): Memeriksa apakah tumpukan kosong.
   - pushArrayBuku(): Menambahkan buku ke dalam tumpukan.
   - popArrayBuku(): Menghapus buku dari tumpukan.
   - peekArrayBuku(): Melihat buku pada posisi tertentu dalam tumpukan.
   - countStack(): Menghitung jumlah buku dalam tumpukan.
   - changeArrayBuku(): Mengubah buku pada posisi tertentu dalam tumpukan.
   - destroyArraybuku(): Mengosongkan seluruh tumpukan.
   - cetakArrayBuku(): Mencetak isi tumpukan.
3. Implementasi: Program ini mengimplementasikan fungsi-fungsi dasar dari tumpukan menggunakan array dan berbagai operasi seperti push, pop, peek, serta fungsi-fungsi lainnya untuk memanipulasi data dalam tumpukan.
4. Penggunaan: Program ini mencakup contoh penggunaan dari tumpukan buku, mulai dari menambahkan buku, melihat jumlah buku, mengubah buku, hingga menghapus dan mencetak isi tumpukan. Hal ini memberikan gambaran tentang bagaimana tumpukan dapat digunakan dalam konteks aplikasi nyata, dalam hal ini pengelolaan buku.

## Unguided 
### 1. [Soal]

```C++

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

```
#### Output:
![Screenshot 2024-05-06 010928](https://github.com/egirizkiyan/egi-/assets/162097461/13b9fc63-5120-4a92-927e-ca963140555a)


#### Full code Screenshot:
![Screenshot 2024-05-06 010809](https://github.com/egirizkiyan/egi-/assets/162097461/c731ed70-e1ff-4a77-b6b8-e4b8d903b90a)


Kesimpulan dari program ini adalah sebagai berikut:

1. Pengecekan Palindrome: Program ini bertujuan untuk menentukan apakah sebuah kalimat merupakan palindrom atau tidak. Palindrom adalah suatu kata, frasa, angka, atau susunan lain yang dapat dibaca sama baik dari depan maupun dari belakang. Contohnya adalah "kodok", "radar", dan "12321".
2. Implementasi Stack: Program ini menggunakan struktur data stack untuk membalikkan kalimat. Karakter-karakter dari kalimat yang bersih (tanpa karakter non-alfanumerik dan dalam huruf kecil) dimasukkan ke dalam stack. Kemudian, karakter-karakter tersebut diambil dari stack satu per satu untuk membentuk kalimat yang terbalik.
3. Fungsi isPalindrome(): Fungsi ini menerima input sebuah kalimat, membersihkan kalimat tersebut dari karakter non-alfanumerik, dan kemudian memeriksa apakah kalimat yang telah dibersihkan sama dengan kalimat yang telah dibalik. Jika kedua kalimat tersebut sama, maka kalimat tersebut adalah palindrom.
4. Output: Program mencetak hasil pengecekan palindrom untuk dua kalimat yang berbeda. Setiap kalimat diuji dengan fungsi isPalindrome(), dan outputnya adalah apakah kalimat tersebut merupakan palindrom atau tidak.
5. Kesimpulan: Program ini memberikan contoh sederhana penggunaan struktur data stack dalam menentukan apakah sebuah kalimat merupakan palindrom atau tidak. Dengan mengimplementasikan algoritma yang sederhana, kita dapat dengan mudah mengecek sifat palindrom dari suatu kalimat.

### 2. [Soal]

```C++

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


```
#### Output:
![Screenshot 2024-05-06 011522](https://github.com/egirizkiyan/egi-/assets/162097461/a73ec9ca-4110-409e-a58b-c07e739248b6)


#### Full code Screenshot:
![Screenshot 2024-05-06 011404](https://github.com/egirizkiyan/egi-/assets/162097461/fc561c46-8b6a-4893-ac4a-ec198036eec1)


Program ini adalah contoh sederhana dari pembalikan kalimat menggunakan struktur data stack. Berikut adalah kesimpulan dari program ini:

1. Struktur Data Stack: Program ini menggunakan struktur data stack dari C++ STL (std::stack) untuk membalikkan kalimat. Setiap kata dalam kalimat dipisahkan dan dimasukkan ke dalam stack. Kemudian, kata-kata tersebut diambil dari stack satu per satu untuk membentuk kalimat yang terbalik.
2. Fungsi reverseSentence(): Fungsi ini menerima input sebuah kalimat, memisahkan kata-kata dalam kalimat tersebut, dan menggunakan stack untuk membalikkan urutan kata-kata. Hasil pembalikan kalimat tersebut kemudian dikembalikan sebagai string.
3. Output: Program mencetak kalimat asli, kalimat setelah dibalik, dan hasil pembalikan yang ditambahkan ke dalam kalimat asli. Ini memberikan gambaran tentang bagaimana hasil pembalikan dapat dimanfaatkan dalam konteks yang lebih luas.
4. Kesimpulan: Program ini menunjukkan cara sederhana menggunakan stack untuk membalikkan kalimat dalam bahasa pemrograman C++. Dengan menggunakan struktur data stack, kita dapat dengan mudah memanipulasi urutan kata-kata dalam sebuah kalimat.

## Kesimpulan
Dari kode sebelumnya, kita bisa menyimpulkan beberapa hal:

1. Struktur Data Stack: Kode menggunakan struktur data stack dari C++ STL (std::stack) untuk memproses kata-kata dalam sebuah kalimat.
2. Manipulasi Kalimat: Kalimat diproses dalam dua tahap. Pertama, kata-kata dipisahkan dari kalimat dan dimasukkan ke dalam stack. Kedua, kata-kata tersebut diambil dari stack satu per satu untuk membentuk kalimat yang terbalik.
4. Fungsi reverseSentence(): Fungsi ini bertanggung jawab untuk membalikkan urutan kata-kata dalam kalimat menggunakan stack. Inputnya adalah sebuah kalimat, dan outputnya adalah kalimat yang telah dibalik.
5. Output: Setelah kalimat dibalik, hasil pembalikan ditambahkan ke dalam kalimat asli, dan kemudian keseluruhan kalimat tersebut dicetak.
6. Kesimpulan: Kode ini memberikan contoh sederhana tentang bagaimana menggunakan stack untuk membalikkan kalimat. Dengan struktur data stack, proses pembalikan kalimat dapat dilakukan dengan mudah dan efisien. Ini mengilustrasikan penggunaan stack dalam konteks pemrosesan string dalam bahasa pemrograman C++.

## Referensi
[1] Novi Anisa. (2021). Penggunaan variabel array dalam pengolahan data. Digilib Unila. [PDF] penggunaan variabel array dalam pengolahan data - Digilib Unila
[2] Khotibul Umam. (2023). ALGORITMA DAN PEMROGRAMAN KOMPUTER DENGAN PYTHON. Tujuan dan Capaian Pembelajaran. Setelah mempelajari materi dalam bab ini, mahasiswa diharapkan mampu menjelaskan dan mengimplementasikan tipe data array. b.
[3] Novi Anisa(2020, September 18). Belajar Python: Mengenal Array pada Bahasa Pemrograman Python. DQLab.