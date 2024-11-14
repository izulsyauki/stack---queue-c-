#include <iostream>
#include <limits>

using namespace std;

// Struktur untuk data barang
struct Data
{
    char nama_pasien[30];
    char alamat[30];
    int sex;
    char diagnosa[30];
};

// Deklarasi fungsi-fungsi
void push();
void pop();
void specialPush();
void specialPop();
void enqueue();
void dequeue();
void specialEnqueue();
void specialDequeue();
void display();

// Konstanta dan variabel global
const int n = 5; // Jumlah maksimal data
int top = 0;     // Jumlah data pasien yang ada  dan indeks depan
Data pasien[n];  // Data pasien yang diinput

int main()
{
    int pilihan = 0; // Inputan user

    do
    {
        // Tampilkan menu pilihan
        cout << "\n===== Menu Pilihan =====" << endl;
        cout << "1. PUSH (Menambah data di akhir)" << endl;
        cout << "2. POP (Mengambil data di akhir)" << endl;
        cout << "3. ENQUEUE (Menambah data di akhir)" << endl;
        cout << "4. DEQUEUE (Mengambil data di awal)" << endl;
        cout << "5. SPECIAL PUSH (Menambah data ke tengah)" << endl;
        cout << "6. SPECIAL POP (Mengambil data dari tengah)" << endl;
        cout << "7. SPECIAL ENQUEUE (Menambah data ke tengah)" << endl;
        cout << "8. SPECIAL DEQUEUE (Mengambil data dari tengah)" << endl;
        cout << "9. DISPLAY (Menampilkan isi data)" << endl;
        cout << "10. EXIT (Keluar dari program)" << endl;

        cout << "\nSilahkan pilih nomor yang diinginkan: ";
        cin >> pilihan;

        // Validasi input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = 0; // Set pilihan ke 0 jika input tidak valid
        }

        // Proses pilihan user
        switch (pilihan)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            enqueue();
            break;
        case 4:
            dequeue();
            break;
        case 5:
            specialPush();
            break;
        case 6:
            specialPop();
            break;
        case 7:
            specialEnqueue();
            break;
        case 8:
            specialDequeue();
            break;
        case 9:
            display();
            break;
        case 10:
            cout << "Keluar dari program, see you next time!" << endl;
            break;
        default:
            cout << "\nPilihan tidak valid, silahkan pilih angka 1 - 10.\n";
            break;
        }
    } while (pilihan != 10);

    return 0;
}

// Fungsi menambahkan data pasien di akhir
void push()
{
    if (top < n)
    {
        cout << "Masukkan nama pasien: ";
        cin >> pasien[top].nama_pasien;
        cout << "Masukkan alamat pasien: ";
        cin >> pasien[top].alamat;
        cout << "Pilih jenis kelamin pasien: " << endl;
        cout << "1. Laki-laki" << endl;
        cout << "2. Perempuan" << endl;
        cout << "Pilih nomor: ";
        cin >> pasien[top].sex;
        if (pasien[top].sex != 1 && pasien[top].sex != 2)
        {
            cout << "Jenis kelamin tidak valid, silahkan pilih 1 atau 2.\n";
            return;
        }
        cout << "Masukkan diagnosa pasien: ";
        cin >> pasien[top].diagnosa;

        top++;
        display();
    }
    else
    {
        cout << "Data sudah penuh, tidak bisa menambah data lagi.\n";
    }
}

// Fungsi untuk mengambil data terakhir pasien
void pop()
{
    if (top > 0)
    {
        cout << "Data pasien yang diambil:" << endl;
        cout << "Nama pasien: " << pasien[top - 1].nama_pasien << endl;
        cout << "Alamat pasien: " << pasien[top - 1].alamat << endl;
        if (pasien[top - 1].sex == 1)
        {
            cout << "Jenis kelamin pasien: Laki-laki" << endl;
        }
        else
        {
            cout << "Jenis kelamin pasien: Perempuan" << endl;
        }
        cout << "Diagnosa pasien: " << pasien[top - 1].diagnosa << endl;
        top--;
    }
    else
    {
        cout << "Data kosong, tidak ada yang bisa diambil.\n";
    }
}

// Fungsi menambahkan data pasien di awal
void enqueue()
{
    if (top < n)
    {
        cout << "Masukkan nama pasien: ";
        cin >> pasien[top].nama_pasien;
        cout << "Masukkan alamat pasien: ";
        cin >> pasien[top].alamat;
        cout << "Pilih jenis kelamin pasien: " << endl;
        cout << "1. Laki-laki" << endl;
        cout << "2. Perempuan" << endl;
        cout << "Pilih nomor: ";
        cin >> pasien[top].sex;
        if (pasien[top].sex != 1 && pasien[top].sex != 2)
        {
            cout << "Jenis kelamin tidak valid, silahkan pilih 1 atau 2.\n";
            return;
        }
        cout << "Masukkan diagnosa pasien: ";
        cin >> pasien[top].diagnosa;
        top++;
        display();
    }
    else
    {
        cout << "Data sudah penuh, tidak bisa menambah data lagi.\n";
    }
}

// Fungsi untuk mengambil data pasien di awal
void dequeue()
{
    if (top > 0)
    {
        cout << "Data pasien yang diambil:" << endl;
        cout << "Nama pasien: " << pasien[0].nama_pasien << endl;
        cout << "Alamat pasien: " << pasien[0].alamat << endl;
        if (pasien[0].sex == 1)
        {
            cout << "Jenis kelamin pasien: Laki-laki" << endl;
        }
        else
        {
            cout << "Jenis kelamin pasien: Perempuan" << endl;
        }
        cout << "Diagnosa pasien: " << pasien[0].diagnosa << endl;

        // Menggeser semua elemen ke depan
        for (int i = 0; i < top - 1; i++)
        {
            pasien[i] = pasien[i + 1];
        }
        top--;
    }
    else
    {
        cout << "Data kosong, tidak ada data yang bisa diambil.\n";
    }
}

// Fungsi specialPush untuk meletakkan data di posisi yang ditentukan
void specialPush()
{
    if (top == 0)
    {
        cout << "Data kosong, mengalihkan ke PUSH biasa.\n";
        push();
    }
    else if (top >= n)
    {
        cout << "Tidak bisa melakukan Special PUSH. Data sudah penuh.\n";
    }
    else
    {
        int posisi;
        cout << "Masukkan posisi tumpukan ke berapa? (2 hingga " << top << "): ";
        cin >> posisi;
        posisi--; // Karena array mulai dari 0, kurangi 1 dari input pengguna

        if (posisi <= 0 || posisi >= top)
        {
            cout << "Tidak bisa melakukan Special PUSH di posisi paling atas atau di atasnya.\n";
        }
        else if (posisi >= 0 && posisi <= top)
        {
            Data temp; // Variabel sementara untuk menyimpan data baru
            cout << "Nama pasien yang akan di PUSH: ";
            cin >> temp.nama_pasien;
            cout << "Alamat pasien yang akan di PUSH: ";
            cin >> temp.alamat;
            cout << "Pilih jenis kelamin pasien: " << endl;
            cout << "1. Laki-laki" << endl;
            cout << "2. Perempuan" << endl;
            cout << "Pilih nomor: ";
            cin >> temp.sex;
            if (temp.sex != 1 && temp.sex != 2)
            {
                cout << "Jenis kelamin tidak valid, silahkan pilih 1 atau 2.\n";
                return;
            }
            cout << "Masukkan diagnosa pasien yang akan di PUSH: ";
            cin >> temp.diagnosa;

            // Menggeser elemen dari belakang ke depan untuk memberi ruang
            for (int i = top; i > posisi; i--)
            {
                pasien[i] = pasien[i - 1];
            }

            // Menyisipkan data baru di posisi yang diinginkan
            pasien[posisi] = temp;
            top++; // Menambah jumlah elemen

            cout << "Data berhasil ditambahkan di posisi " << posisi + 1 << ".\n";
            display();
        }
        else
        {
            cout << "Posisi tidak valid.\n";
        }
    }
}

// Fungsi specialPop untuk mengambil data dari posisi yang ditentukan
void specialPop()
{
    if (top == 0)
    {
        cout << "Stack kosong, tidak bisa melakukan Special POP.\n";
    }
    else if (top == 1)
    {
        cout << "Hanya ada satu data, mengalihkan ke POP biasa.\n";
        pop();
    }
    else
    {
        int posisi;
        cout << "Masukkan posisi barang yang ingin diambil (dari 2 hingga " << top << " ): ";
        cin >> posisi;
        posisi--; // Karena array mulai dari 0, kurangi 1 dari input pengguna

        if (posisi <= 0 || posisi >= top - 1)
        {
            cout << "Tidak bisa melakukan Special POP di posisi paling atas.\n";
        }
        else if (posisi >= 0 && posisi < top)
        {
            // Menampilkan barang yang diambil
            cout << "Hasil Special POP adalah: " << pasien[posisi].nama_pasien << " - " << pasien[posisi].alamat << " - ";
            if (pasien[posisi].sex == 1)
            {
                cout << "Laki-laki";
            }
            else
            {
                cout << "Perempuan";
            }
            cout << " - " << pasien[posisi].diagnosa << endl;

            // Menggeser elemen dari posisi yang di-pop
            for (int i = posisi; i < top - 1; i++)
            {
                pasien[i] = pasien[i + 1];
            }
            top--; // Mengurangi jumlah elemen
        }
        else
        {
            cout << "Posisi tidak valid.\n";
        }
    }
}

// Fungsi specialEnqueue untuk menyisipkan data di posisi tertentu
void specialEnqueue()
{
    if (top == 0)
    {
        cout << "data masih kosong, mengalihkan ke ENQUEUE biasa.\n";
        enqueue();
    }
    else if (top >= n)
    {
        cout << "Tidak bisa melakukan Special ENQUEUE. data sudah penuh.\n";
    }
    else
    {
        int posisi;
        cout << "Masukkan posisi antrian ke berapa? (2 hingga " << top << "): ";
        cin >> posisi;
        posisi--; // Karena array mulai dari 0

        if (posisi <= 0 || posisi > top)
        {
            cout << "Posisi tidak valid.\n";
        }
        else
        {
            Data temp;
            cout << "Nama pasien yang akan di ENQUEUE: ";
            cin >> temp.nama_pasien;
            cout << "Alamat pasien yang akan di ENQUEUE: ";
            cin >> temp.alamat;
            cout << "Pilih jenis kelamin pasien: " << endl;
            cout << "1. Laki-laki" << endl;
            cout << "2. Perempuan" << endl;
            cout << "Pilih nomor: ";
            cin >> temp.sex;
            if (temp.sex != 1 && temp.sex != 2)
            {
                cout << "Jenis kelamin tidak valid, silahkan pilih 1 atau 2.\n";
                return;
            }
            cout << "Masukkan diagnosa pasien yang akan di ENQUEUE: ";
            cin >> temp.diagnosa;

            // Menggeser elemen dari belakang ke depan untuk memberi ruang
            for (int i = top; i > posisi; i--)
            {
                pasien[i] = pasien[i - 1];
            }

            pasien[posisi] = temp;
            top++;
            cout << "Data berhasil ditambahkan di posisi " << posisi + 1 << ".\n";
            display();
        }
    }
}

// Fungsi specialDequeue untuk mengambil data dari posisi tertentu
void specialDequeue()
{
    if (top == 0)
    {
        cout << "Data kosong, tidak bisa melakukan Special DEQUEUE.\n";
    }
    else if (top == 1)
    {
        cout << "Hanya ada satu data, mengalihkan ke DEQUEUE biasa.\n";
        dequeue();
    }
    else
    {
        int posisi;
        cout << "Masukkan posisi data pasien yang ingin diambil (dari 2 hingga " << top << "): ";
        cin >> posisi;
        posisi--; // Karena array mulai dari 0

        if (posisi <= 0 || posisi >= top)
        {
            cout << "Posisi tidak valid.\n";
        }
        else
        {
            cout << "Hasil Special DEQUEUE adalah: " << pasien[posisi].nama_pasien << " - " << pasien[posisi].alamat << " - ";
            if (pasien[posisi].sex == 1)
            {
                cout << "Laki-laki";
            }
            else
            {
                cout << "Perempuan";
            }
            cout << " - " << pasien[posisi].diagnosa << endl;

            // Menggeser elemen setelah posisi yang dihapus
            for (int i = posisi; i < top - 1; i++)
            {
                pasien[i] = pasien[i + 1];
            }
            top--;
        }
    }
}

// Fungsi menampilkan data di dalam stack
void display()
{
    if (top > 0)
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << "\nNama pasien: " << pasien[i].nama_pasien << endl;
            cout << "Alamat pasien: " << pasien[i].alamat << endl;
            if (pasien[i].sex == 1)
            {
                cout << "Jenis kelamin pasien: Laki-laki" << endl;
            }
            else
            {
                cout << "Jenis kelamin pasien: Perempuan" << endl;
            }
            cout << "Diagnosa pasien: " << pasien[i].diagnosa << endl;
            cout << "===================================" << endl;
        }
    }
    else
    {
        cout << "Data kosong, tidak ada data yang bisa ditampilkan.\n";
    }
}
