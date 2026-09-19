#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    // Input jumlah astronot dan nilai K awal
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    // Inisialisasi daftar astronot [1, 2, ..., N]
    vector<int> astronot;
    for (int i = 1; i <= N; ++i) {
        astronot.push_back(i);
    }

    vector<int> urutanEliminasi;
    int posisi = 0; // Indeks penunjuk awal hitungan (berbasis 0)

    // Proses simulasi eliminasi
    while (astronot.size() > 1) {
        // Hitung posisi astronot yang akan gugur
        posisi = (posisi + K - 1) % astronot.size();
        
        int tereliminasi = astronot[posisi];
        urutanEliminasi.push_back(tereliminasi);

        // Hapus astronot dari lingkaran
        astronot.erase(astronot.begin() + posisi);

        // Perbarui nilai K berdasarkan sifat nomor astronot
        if (tereliminasi % 2 == 0) {
            K += 2; // Genap: K bertambah 2
        } else {
            K -= 1; // Ganjil: K berkurang 1
        }

        // Aturan khusus: K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }
    }

    // Menampilkan hasil
    cout << "\n================ HASIL SIMULASI ================" << endl;
    cout << "Urutan astronot yang tereliminasi: ";
    for (size_t i = 0; i < urutanEliminasi.size(); ++i) {
        cout << urutanEliminasi[i] << (i == urutanEliminasi.size() - 1 ? "" : ", ");
    }
    cout << endl;

    cout << "Astronot terakhir yang bertahan : " << astronot[0] << endl;
    cout << "================================================" << endl;

    return 0;
}