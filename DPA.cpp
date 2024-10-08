#include <iostream>
#include <cmath>

using namespace std;

    double HitungJarakTempuh(double X1, double Y1, double X2, double Y2) {
    return sqrt(pow(X2 - X1, 2) + pow(Y1 - Y2, 2));
}

int main(){
    int JumlahLokasi;
    cout << "Masukan Jumlah lokasi yang dicari : ";
    cin >> JumlahLokasi;

   double X[JumlahLokasi], Y[JumlahLokasi];
   for (int i = 0; i < JumlahLokasi; i++) {
   cout << "Masukan kordinat lokasi : " << i + 1 << " (X Y) ";
   cin >> X[i] >> Y[i];
}
int Urutan[JumlahLokasi];
bool SudahDiKunjungi[JumlahLokasi] = {false};


 Urutan[0] = 0;
 SudahDiKunjungi[0] = true;

   double TotalJarak = 0.0;
    for (int i = 1; i < JumlahLokasi; ++i) { 
        int LokasiSebelumnya = Urutan[i - 1];
        double JarakTerdekat = INFINITY;
        int LokasiBerikutnya = -1;

        for (int j = 0; j < JumlahLokasi; ++j) {
            if (!SudahDiKunjungi[j]) {
                double jarak = HitungJarakTempuh(X[LokasiSebelumnya], Y[LokasiSebelumnya], X[j], Y[j]);
                if (jarak < JarakTerdekat) {
                    JarakTerdekat = jarak;
                    LokasiBerikutnya = j;
                }
            }
        }

        Urutan[i] = LokasiBerikutnya;
        SudahDiKunjungi[LokasiBerikutnya] = true;
        TotalJarak += JarakTerdekat;
    }
    
TotalJarak += HitungJarakTempuh(X[Urutan[JumlahLokasi - 1]], Y[Urutan[JumlahLokasi - 1]], X[0], Y[0]);

    char pilihan;
    cout << "Pilih satuan jarak (m untuk meter, km untuk kilometer): ";
    cin >> pilihan;

    if (pilihan == 'k' || pilihan == 'K') {
        TotalJarak /= 1000.0;
    }

    cout << " Urutan kunjungan lokasi: ";
    for (int i = 0; i < JumlahLokasi; ++i) {
        cout << Urutan[i] + 1 << " ";
    }
    cout << "\nTotal jarak yang ditempuh: " << TotalJarak << " " 
         << (pilihan == 'k' || pilihan == 'K' ? "km" : "meter") << endl;

    return 0;
}
