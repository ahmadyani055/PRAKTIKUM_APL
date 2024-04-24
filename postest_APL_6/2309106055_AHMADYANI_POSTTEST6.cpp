#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <unordered_map>
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

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ubahData(vector<Smartphone>& dataSmartphone) {
    int Update;
    cout << "Masukkan index data yang ingin diubah: ";
    if (!(cin >> Update) || Update < 0 || Update >= dataSmartphone.size()) {
        cout << "Index tidak valid.\n";
        clearInputBuffer();
        return;
    }

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
}

bool compareNamaHandphoneAsc(const Smartphone& a, const Smartphone& b) {
    return a.namaHandphone < b.namaHandphone;
}

bool compareNamaHandphoneDesc(const Smartphone& a, const Smartphone& b) {
    return a.namaHandphone > b.namaHandphone;
}

int binarySearchAsc(const vector<Smartphone>& arr, const string& x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].namaHandphone == x)
            return mid;
        if (arr[mid].namaHandphone < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchDesc(const vector<Smartphone>& arr, const string& x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].namaHandphone == x)
            return mid;
        if (arr[mid].namaHandphone > x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    if (!performLogin()) {
        cout << "Gagal login, program berhenti." << endl;
        return 1;
    }

    unordered_map<string, Smartphone> smartphoneMap;
    smartphoneMap["Vivo"] = {"Vivo", "8GB", "Snapdragon 888", "256GB"};
    smartphoneMap["Oppo"] = {"Oppo", "6GB", "Snapdragon 750G", "128GB"};
    smartphoneMap["Samsung"] = {"Samsung", "12GB", "Exynos 2100", "512GB"};
    smartphoneMap["iPhone"] = {"iPhone", "6GB", "Apple A14 Bionic", "256GB"};
    smartphoneMap["Asus"] = {"Asus", "8GB", "Snapdragon 865", "256GB"};
    smartphoneMap["Acer"] = {"Acer", "4GB", "MediaTek Helio P35", "128GB"};
    smartphoneMap["Axioo"] = {"Axioo", "6GB", "Snapdragon 662", "128GB"};
    smartphoneMap["Redmi"] = {"Redmi", "8GB", "Snapdragon 870", "256GB"};
    smartphoneMap["Realme"] = {"Realme", "8GB", "Dimensity 1200", "256GB"};

    vector<Smartphone> dataSmartphone;
    for (const auto& entry : smartphoneMap) {
        dataSmartphone.push_back(entry.second);
    }

    int menu;
    char ulang;

    do {
        cout << "============ M E N U ============\n"
             << "1. Tambah Data\n"
             << "2. Lihat Data\n"
             << "3. Ubah Data\n"
             << "4. Delete Data\n"
             << "5. Keluar\n"
             << "6. Sort Nama Handphone Ascending\n"
             << "7. Sort Nama Handphone Descending\n"
             << "8. Cari Nama Handphone Ascending (Binary Search)\n"
             << "9. Cari Nama Handphone Descending (Binary Search)\n";

        cout << "Masukkan pilihan anda : ";
        if (!(cin >> menu)) {
            cout << "Input tidak valid. Harap masukkan nomor.\n";
            clearInputBuffer();
            continue;
        }

        switch (menu) {
            case 1: {
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
                break;
            }

            case 2: {
                cout << "Lihat data\n";
                if (dataSmartphone.empty()) {
                    cout << "Tidak ada data untuk ditampilkan.\n";
                } else {
                    for (size_t i = 0; i < dataSmartphone.size(); ++i) {
                        cout << "Index " << i << "\n"
                             << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                             << "Jumlah Ram: " << dataSmartphone[i].ram << "\n"
                             << "Processor: " << dataSmartphone[i].processor << "\n"
                             << "Jumlah Memori: " << dataSmartphone[i].jumlahMemori << "\n"
                             << "==============================\n";
                    }
                }
                break;
            }

            case 3: {
                cout << "Ubah data\n";
                if (dataSmartphone.empty()) {
                    cout << "Tidak ada data yang dapat diubah.\n";
                } else {
                    for (size_t i = 0; i < dataSmartphone.size(); ++i) {
                        cout << "Index " << i << "\n"
                             << "Nama Handphone: " << dataSmartphone[i].namaHandphone << "\n"
                             << "==============================\n";
                    }

                    ubahData(dataSmartphone);
                }
                break;
            }

            case 4:
                // Implementasi hapus data
                break;

            case 5:
                cout << "Keluar\n";
                break;

            case 6:
                cout << "Sort Nama Handphone Ascending\n";
                sort(dataSmartphone.begin(), dataSmartphone.end(), compareNamaHandphoneAsc);
                break;

            case 7:
                cout << "Sort Nama Handphone Descending\n";
                sort(dataSmartphone.begin(), dataSmartphone.end(), compareNamaHandphoneDesc);
                break;

            case 8: {
                cout << "Cari Nama Handphone Ascending (Binary Search)\n";
                string target;
                cout << "Masukkan nama handphone yang ingin dicari: ";
                cin >> target;
                int resultAsc = binarySearchAsc(dataSmartphone, target);
                if (resultAsc != -1) {
                    cout << "Data ditemukan pada index " << resultAsc << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }

            case 9: {
                cout << "Cari Nama Handphone Descending (Binary Search)\n";
                string target;
                cout << "Masukkan nama handphone yang ingin dicari: ";
                cin >> target;
                int resultDesc = binarySearchDesc(dataSmartphone, target);
                if (resultDesc != -1) {
                    cout << "Data ditemukan pada index " << resultDesc << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }

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
