#include <iostream>
#include <string>
#include <vector>
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

void rekursiff() {
    char ulang;
    cout << "Apakah anda ingin mengulang? (y/n): ";
    cin >> ulang;
    if (ulang == 'y' || ulang == 'Y') {
        main(); 
    }
}

int main() {
    if (!performLogin()) {
        cout << "Gagal login, program berhenti." << endl;
        return 1;
    }

    int menu;
    vector<Smartphone> dataSmartphone;

    do {
        cout << "============ M E N U ============\n"
             << "1. Tambah Data\n"
             << "2. Lihat Data\n"
             << "3. Ubah Data\n"
             << "4. Delete Data\n"
             << "5. Keluar\n";

        cout << "Masukkan pilihan anda : ";
        cin >> menu;

        if (menu == 1) {
            cout << "Tambah data\n";
            Smartphone phone;

            cout << "Masukkan Nama Handphone: ";
            cin >> phone.namaHandphone;

            cout << "Masukkan Jumlah Ram: ";
            cin >> phone.ram;

            cout << "Masukkan Processor: ";
            cin >> phone.processor;

            cout << "Masukkan Jumlah Memori: ";
            cin >> phone.jumlahMemori;

            dataSmartphone.push_back(phone);

            cout << "Data berhasil ditambahkan.\n";
        } else if (menu == 2) {
            cout << "Lihat data\n";

            for (size_t i = 0; i < dataSmartphone.size(); ++i) {
                cout << "Index " << i << "\n"
                     << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                     << "Jumlah Ram: " << dataSmartphone[i].ram << "\n"
                     << "Processor: " << dataSmartphone[i].processor << "\n"
                     << "Jumlah Memori: " << dataSmartphone[i].jumlahMemori << "\n"
                     << "==============================\n";
            }
        } else if (menu == 3) {
            cout << "Ubah data\n";

            for (size_t i = 0; i < dataSmartphone.size(); ++i) {
                cout << "Index " << i << "\n"
                     << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                     << "==============================\n";
            }

            int Update;
            cout << "Masukkan index data yang ingin diubah: ";
            cin >> Update;

            if (Update >= 0 && Update < static_cast<int>(dataSmartphone.size())) {
                cout << "Masukkan data baru:\n";

                cout << "Masukkan Nama Handphone: ";
                cin >> dataSmartphone[Update].namaHandphone;

                cout << "Masukkan Jumlah Ram: ";
                cin >> dataSmartphone[Update].ram;

                cout << "Masukkan Processor: ";
                cin >> dataSmartphone[Update].processor;

                cout << "Masukkan Jumlah Memori: ";
                cin >> dataSmartphone[Update].jumlahMemori;

                cout << "Data berhasil diubah.\n";
            } else {
                cout << "Index tidak valid.\n";
            }
        } else if (menu == 4) {
            cout << "Hapus data\n";

            for (size_t i = 0; i < dataSmartphone.size(); ++i) {
                cout << "Index " << i << "\n"
                     << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                     << "==============================\n";
            }

            int Delete;
            cout << "Masukkan index data yang ingin dihapus: ";
            cin >> Delete;

            if (Delete >= 0 && Delete < static_cast<int>(dataSmartphone.size())) {
                dataSmartphone.erase(dataSmartphone.begin() + Delete);

                cout << "Data berhasil dihapus.\n";
            } else {
                cout << "Index tidak valid.\n";
            }
        } else if (menu == 5) {
            cout << "Keluar\n";
            break; 
        } else {
            cout << "Pilihan tidak valid\n";
        }

        rekursiff(); 

    } while (true); 

    return 0;
}
