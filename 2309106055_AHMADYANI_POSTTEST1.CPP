#include <iostream>
using namespace std;

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
    }

    cout << "Percobaan login anda habis. Coba lagi nanti." << endl;
    return false;
}

void convertKmPerHour(double kmPerHour) {
    cout << "Hasil Konversi:" << endl;
    cout << kmPerHour << " Kilometer/jam = " << kmPerHour * 100000 << " Centimeter/detik" << endl;
    cout << kmPerHour << " Kilometer/jam = " << kmPerHour * 1000 << " Meter/detik" << endl;
    cout << kmPerHour << " Kilometer/jam = " << kmPerHour * 0.621371 << " Mil/jam" << endl;
}

void convertCmPerSecond(double cmPerSecond) {
    cout << "Hasil Konversi:" << endl;
    cout << cmPerSecond << " Centimeter/detik = " << cmPerSecond / 100000 << " Kilometer/jam" << endl;
    cout << cmPerSecond << " Centimeter/detik = " << cmPerSecond / 100 << " Meter/detik" << endl;
    cout << cmPerSecond << " Centimeter/detik = " << cmPerSecond * 0.00000621371 << " Mil/jam" << endl;
}

void convertMPerSecond(double mPerSecond) {
    cout << "Hasil Konversi:" << endl;
    cout << mPerSecond << " Meter/detik = " << mPerSecond * 3.6 << " Kilometer/jam" << endl;
    cout << mPerSecond << " Meter/detik = " << mPerSecond * 100 << " Centimeter/detik" << endl;
    cout << mPerSecond << " Meter/detik = " << mPerSecond * 0.000621371 << " Mil/jam" << endl;
}

void convertMilesPerHour(double milesPerHour) {
    cout << "Hasil Konversi:" << endl;
    cout << milesPerHour << " Mil/jam = " << milesPerHour * 1.60934 << " Kilometer/jam" << endl;
    cout << milesPerHour << " Mil/jam = " << milesPerHour * 160934 << " Centimeter/detik" << endl;
    cout << milesPerHour << " Mil/jam = " << milesPerHour * 26.8224 << " Meter/detik" << endl;
}

int main() {
    char ulang;

    do {
        int choice;
        double speed;

        cout << "===== Menu Konversi Kecepatan =====" << endl;
        cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
        cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
        cout << "3. Konversi Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)" << endl;
        cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan kecepatan dalam Kilometer/jam: ";
                cin >> speed;
                convertKmPerHour(speed);
                break;
            case 2:
                cout << "Masukkan kecepatan dalam Centimeter/detik: ";
                cin >> speed;
                convertCmPerSecond(speed);
                break;
            case 3:
                cout << "Masukkan kecepatan dalam Meter/detik: ";
                cin >> speed;
                convertMPerSecond(speed);
                break;
            case 4:
                cout << "Masukkan kecepatan dalam Mil/jam: ";
                cin >> speed;
                convertMilesPerHour(speed);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Ingin kembali ke menu konversi? (y/t): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
