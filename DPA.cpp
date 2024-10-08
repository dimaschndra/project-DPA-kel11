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
