#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// 1. Sýnýf Kavramý: Her bir öðrencinin verisini ve davranýþýný tutar.
class Ogrenci {
private:
    string isim;
    int okulNo;
    double vizeNotu;
    double finalNotu;

public:
    // Yapýcý Metot (Constructor): Öðrenci oluþturulduðu an çalýþan fonksiyon
    Ogrenci(string _isim, int _no, double _vize, double _final) {
        isim = _isim;
        okulNo = _no;
        vizeNotu = _vize;
        finalNotu = _final;
    }

    // Ortalama hesaplayan fonksiyon (%40 Vize + %60 Final)
    double ortalamaHesapla() const {
        return (vizeNotu * 0.4) + (finalNotu * 0.6);
    }

    // Ortalamaya göre Harf Notu döndüren fonksiyon
    string harfNotuBul() const {
        double ort = ortalamaHesapla();
        if (ort >= 90) return "AA";
        if (ort >= 80) return "BA";
        if (ort >= 70) return "BB";
        if (ort >= 60) return "CB";
        if (ort >= 50) return "CC";
        return "FF";
    }

    // Bilgileri ekrana yazdýran fonksiyon
    void bilgileriYazdir() const {
        cout << "No: " << okulNo << " | Isim: " << isim 
             << " | Ortalama: " << ortalamaHesapla() 
             << " | Harf Notu: " << harfNotuBul() << endl;
    }
};

int main() {
    // 2. Sýnýf Kavramý: Dinamik geniþleyen dizi (Vector) kullanýmý
    vector<Ogrenci> ogrenciler;
    
    cout << "=== OGRENCI NOT KAYIT SISTEMINE HOS GELDINIZ ===" << endl;
    
    // Test verileri ekliyoruz
    ogrenciler.push_back(Ogrenci("Ahmet Yilmaz", 101, 75, 85));
    ogrenciler.push_back(Ogrenci("Ayse Demir", 102, 90, 95));
    ogrenciler.push_back(Ogrenci("Mehmet Kaya", 103, 40, 50));

    int secim;
    do {
        cout << "\n1. Yeni Ogrenci Ekle\n2. Ogrencileri Listele\n3. Sinif Istatistikleri\n4. Cikis\nSeciminiz: ";
        cin >> secim;

        if (secim == 1) {
            string isim;
            int no;
            double vize, finalNot;
            
            cout << "Ogrenci Ismi (Bosluksuz): "; cin >> isim;
            cout << "Okul No: "; cin >> no;
            cout << "Vize Notu: "; cin >> vize;
            cout << "Final Notu: "; cin >> finalNot;
            
            ogrenciler.push_back(Ogrenci(isim, no, vize, finalNot));
            cout << "Ogrenci basariyla eklendi!" << endl;
            
        } else if (secim == 2) {
            cout << "\n--- OGRENCI LISTESI ---" << endl;
            for (const auto& ogr : ogrenciler) {
                ogr.bilgileriYazdir();
            }
        } else if (secim == 3) {
            if (ogrenciler.empty()) {
                cout << "Sinifta henuz ogrenci yok." << endl;
                continue;
            }
            double toplamOrt = 0;
            for (const auto& ogr : ogrenciler) {
                toplamOrt += ogr.ortalamaHesapla();
            }
            cout << "\n--- SINIF ISTATISTIKLERI ---" << endl;
            cout << "Toplam Ogrenci Sayisi: " << ogrenciler.size() << endl;
            cout << "Sinif Ortalamasi: " << (toplamOrt / ogrenciler.size()) << endl;
        }
    } while (secim != 4);

    cout << "Programdan cikiliyor... Kodunuza yildiz vermeyi unutmayin!" << endl;
    return 0;
}
