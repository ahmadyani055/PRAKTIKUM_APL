#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Smartphone {
    string namaHandphone;
    string ram;
    string processor;
    string jumlahMemori;
};

bool performLogin() {
    string user, pass;
    for (int i = 1; i <= 3; i++) {
        cout << "Masukan username : ";
        cin >> user;
        cout << "Masukan password : ";
        cin >> pass;

        if (user == "amat" && pass == "123") {
            cout << "Anda berhasil login" << endl;
            return true;
        } else {
            cout << "Username atau password anda salah" << endl;
        }

        if (i < 3) {
            cout << "Percobaan login anda habis. Coba lagi nanti." << endl;
        }
    }
    return false;
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ubahData(Smartphone* dataSmartphone, int jumlahSmartphone) {
    int Update;
    cout << "Masukkan index data yang ingin diubah: ";
    if (!(cin >> Update) || Update < 0 || Update >= jumlahSmartphone) {
        cout << "Index tidak valid.\n";
        clearInputBuffer();
        return;
    }

    Smartphone* smartphone = &dataSmartphone[Update];

    cout << "Masukkan data baru:\n";
    cout << "Masukkan Nama Handphone: ";
    cin >> smartphone->namaHandphone;

    cout << "Masukkan Jumlah Ram: ";
    cin >> smartphone->ram;

    cout << "Masukkan Processor: ";
    cin >> smartphone->processor;

    cout << "Masukkan Jumlah Memori: ";
    cin >> smartphone->jumlahMemori;

    cout << "Data berhasil diubah.\n";
}

int main() {
    if (!performLogin()) {
        cout << "Gagal login, program berhenti." << endl;
        return 1;
    }

    const int MAX_SMARTPHONES = 100;
    Smartphone dataSmartphone[MAX_SMARTPHONES];
    int jumlahSmartphone = 0;

    int menu;
    char ulang;

    do {
        cout << "============ M E N U ============\n"
             << "1. Tambah Data\n"
             << "2. Lihat Data\n"
             << "3. Ubah Data\n"
             << "4. Delete Data\n"
             << "5. Keluar\n";

        cout << "Masukkan pilihan anda : ";
        if (!(cin >> menu)) {
            cout << "Input tidak valid. Harap masukkan nomor.\n";
            clearInputBuffer();
            continue;
        }

        switch (menu) {
            case 1:
                cout << "Tambah data\n";
                if (jumlahSmartphone < MAX_SMARTPHONES) {
                    Smartphone phone;
                    cout << "Masukkan Nama Handphone: ";
                    cin >> phone.namaHandphone;

                    cout << "Masukkan Jumlah Ram: ";
                    cin >> phone.ram;

                    cout << "Masukkan Processor: ";
                    cin >> phone.processor;

                    cout << "Masukkan Jumlah Memori: ";
                    cin >> phone.jumlahMemori;

                    dataSmartphone[jumlahSmartphone++] = phone;
                    cout << "Data berhasil ditambahkan.\n";
                } else {
                    cout << "Maaf, kapasitas data sudah penuh.\n";
                }
                break;

            case 2:
                cout << "Lihat data\n";
                if (jumlahSmartphone == 0) {
                    cout << "Tidak ada data untuk ditampilkan.\n";
                } else {
                    for (int i = 0; i < jumlahSmartphone; ++i) {
                        cout << "Index " << i << "\n"
                             << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                             << "Jumlah Ram: " << dataSmartphone[i].ram << "\n"
                             << "Processor: " << dataSmartphone[i].processor << "\n"
                             << "Jumlah Memori: " << dataSmartphone[i].jumlahMemori << "\n"
                             << "==============================\n";
                    }
                }
                break;

            case 3:
                cout << "Ubah data\n";
                if (jumlahSmartphone == 0) {
                    cout << "Tidak ada data yang dapat diubah.\n";
                } else {
                    for (int i = 0; i < jumlahSmartphone; ++i) {
                        cout << "Index " << i << "\n"
                             << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                             << "==============================\n";
                    }

                    ubahData(dataSmartphone, jumlahSmartphone);
                }
                break;

            case 4:
                cout << "Hapus data\n";
                break;

            case 5:
                cout << "Keluar\n";
                break;

            default:
                cout << "Pilihan tidak valid\n";
                clearInputBuffer();
                break;
        }

        cout << "Apakah anda ingin mengulang? (y/n): ";
        cin >> ulang;
        clearInputBuffer();
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

