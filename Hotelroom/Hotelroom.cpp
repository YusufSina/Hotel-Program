/****************************************************************************
**                        SAKARYA ÜNİVERSİTESİ
**              BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ 
**                     PROGRAMLAMAYA GİRİŞ DERSİ 
**                       2017-2018 GÜZ DÖNEMİ 
**  
**                      ÖDEV NUMARASI..........:PROJE
**                      ÖĞRENCİ ADI............: YUSUF SİNA YILDIZ
**                      ÖĞRENCİ NUMARASI.......: B171210004
**                      DERSİN ALINDIĞI GRUP...: C GRUBU
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Oda {
	int numara;
	int ucreti;
	
};
struct Musteri {
	string isim;
	string soyisim;
	int numara;
	string kimliknumara;
	
};
class Otel {
private:
public:
	// Müşteri işlem menüsü
	void musteriislem() {
		int secim;
		do { system("cls");
		cout << "..:Müşteri İşlemleri:.." << endl;
		cout << "1-Müşteri Ekle" << endl << "2-Müşteri Sil" << endl << "3-Müşteri Listele" << endl << "99-Üst Menü" << endl;
		cout << "Seçiminiz : "; cin >> secim;
		switch (secim) {
		case 1:musteriEkle();
			break;
		case 2:musteriSil();
			break;
		case 3:musteriListele();
			system("pause");
			break;
		case 99:
			break;
		default:system("cls");
			cout << "Hatalı seçim" << endl;
			system("pause");
			break;
		}
		} while (secim != 99);
	}

	// Oda İşlem menüsü
	void odaislem() {
		int secim;
		do {
			system("cls");
			cout << "...:Oda İşlemleri:.." << endl;
			cout << "1-Oda Ekle" << endl << "2-Oda Sil" << endl << "3-Oda Listele" << endl << "99-Üst Menü" << endl;
			cout << "Seçiminiz : "; cin >> secim;
			switch (secim) {
			case 1:odaEkle();
				break;
			case 2:odaSil();
				break;
			case 3:odaListele();
				system("pause");
				break;
			case 99:
				break;
			default:system("cls");
				cout << "Hatalı seçim" << endl;
				system("pause");
				break;
			}
		} while (secim != 99);
	}
	
	//Oda Kayıt menüsü

	void odakayitislem() {
		int secim;
		do {
			system("cls");
			cout << "...:Oda Kayıt İşlemleri:..." << endl;
			cout << "1- Oda-Kayıt Ekle" << endl;
			cout << "2- Oda-Kayıt Sil" << endl;
			cout << "3- Oda-Kayıt Listele" << endl;
			cout << "99-Üst Menü" << endl;
			cout << "Seçiminiz : "; cin >> secim;
			switch (secim) {
			case 1:odakayitekle();
				break;
			case 2:odakayitsil();
				break;
			case 3:odakayitlistele();
				break;
			case 99:
				break;
			default:
				system("cls");
				cout << "Hatalı seçim" << endl;
				system("pause");
				break;
			}
		} while (secim != 99);

	}
	// Oda İşlemleri
	void odaEkle() {
		Oda oda;
		ofstream dosyaYaz;
		dosyaYaz.open("odalar.txt", ios::app);
		cout << "Oda numarasını girin : "; cin >> oda.numara;
		cout << "Oda ücretini girin : "; cin >> oda.ucreti;
		dosyaYaz <<" "<< oda.numara << " " << oda.ucreti;
		dosyaYaz.close();
	}

	void odaSil() {
		int numarasilme;
		Oda oda;
		ifstream dosyaOku;
		dosyaOku.open("odalar.txt", ios::in);
		ofstream dosyaYaz;
		dosyaYaz.open("odalaryedek.txt", ios::app);
		cout << "Silinecek odanın numarasını girin : "; cin >> numarasilme;
		while (!dosyaOku.eof()) {
			dosyaOku >> oda.numara >> oda.ucreti;
			if (oda.numara == numarasilme) {
				cout << oda.numara <<" numaralı "<< oda.ucreti<<" tl ücretli odayı sildiniz"<<endl;
				system("pause");
			}
			else {
				dosyaYaz <<" "<< oda.numara << " " << oda.ucreti;
			}
		}
		dosyaYaz.close();
		dosyaOku.close();
		
		remove("odalar.txt");
		rename("odalaryedek.txt", "odalar.txt");
	}

	void odaListele() {
		Oda oda;
		ifstream dosyaOku;
		dosyaOku.open("odalar.txt", ios::in);
		while (!dosyaOku.eof()) {
			dosyaOku >> oda.numara >> oda.ucreti;
			cout << setw(4) << oda.numara << " numaralı oda " << setw(4) << oda.ucreti << " tl" << endl;
		}
		dosyaOku.close();
	}
	//Müşteri İşlemleri
	void musteriEkle() {
		Musteri musteri;
		ofstream dosyaYaz;
		dosyaYaz.open("musteriler.txt", ios::app);
		cout << "Müşteri adını girin : "; cin >> musteri.isim;
		cout << "Müşteri soyadını girin : "; cin >> musteri.soyisim;
		cout << "Müşteri numarasını girin : "; cin >> musteri.numara;
		cout << "Müşteri kimlik numarasını girin : "; cin >> musteri.kimliknumara;
		dosyaYaz <<" "<< musteri.numara << " " << musteri.isim << " " << musteri.soyisim << " " << musteri.kimliknumara;
		dosyaYaz.close();
	}

	void musteriSil() {
		Musteri musteri;
		ifstream dosyaOku;
		dosyaOku.open("musteriler.txt", ios::in);
		ofstream dosyaYaz;
		dosyaYaz.open("musterileryedek.txt", ios::app);
		int musterino;
		cout << "Silinecek müşteri numarasını girin : "; cin >> musterino;
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.numara>>musteri.isim>>musteri.soyisim>>musteri.kimliknumara;
			if (musterino == musteri.numara) {
				cout << musterino << " numaralı müşteriyi sildiniz." << endl;
				system("pause");
			}
			else {
				dosyaYaz <<" "<< musteri.numara << " " << musteri.isim << " " << musteri.soyisim << " " << musteri.kimliknumara;
			}
		}
		dosyaYaz.close();
		dosyaOku.close();
		remove("musteriler.txt");
		rename("musterileryedek.txt", "musteriler.txt");
	}

	void musteriListele() {
		Musteri musteri;
		ifstream dosyaOku;
		dosyaOku.open("musteriler.txt", ios::in);
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.numara >> musteri.isim >> musteri.soyisim >> musteri.kimliknumara;
			cout << setw(2) << musteri.numara << setw(10) << musteri.isim << " " << musteri.soyisim << setw(13) << musteri.kimliknumara<<endl;
		}
		dosyaOku.close();
	}

	// Oda-Kayıt İşlemleri

	void odakayitekle() {
		Musteri musteri;
		Oda oda;
		ifstream dosyaOku;
		ifstream DosyaOku;
		dosyaOku.open("musteriler.txt", ios::in);
		DosyaOku.open("odalar.txt", ios::in);
		ofstream dosyaYaz;
		dosyaYaz.open("odakayit.txt", ios::app);
		int odano, musterino;
		cout << "Kayıt edilecek oda numarasını giriniz : "; cin >> odano;
		cout << "Kayıt edilecek müşteri numarasını giriniz : "; cin >> musterino;
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.numara >> musteri.isim >> musteri.soyisim >> musteri.kimliknumara;
			if (musterino == musteri.numara) {
				dosyaYaz << " " << musteri.numara;
				break;
			}
		}
		while (!DosyaOku.eof()) {
			DosyaOku >> oda.numara >> oda.ucreti;
			if (oda.numara==odano) {
				dosyaYaz << " " << oda.numara;
				break;
			}	
		}
		cout << musteri.isim<<" "<<musteri.soyisim << " bey/hanım " << oda.numara << " numaralı odaya yerleşti."<<endl;
		system("pause");
		dosyaOku.close();
		DosyaOku.close();
		dosyaYaz.close();
	}
	void odakayitsil() {
		Musteri musteri;
		Oda oda;
		ifstream dosyaOku;
		dosyaOku.open("odakayit.txt", ios::in);
		ofstream dosyaYaz("odakayityedek.txt", ios::app);
		int musterino;
		cout << "Kayıtı silenecek müşteri numarasını girin : "; cin >> musterino;
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.numara >> oda.numara;
			if (musteri.numara == musterino) {
				cout << musteri.numara << " numaralı müşterinin kayıtını sildiniz." << endl;
				system("pause");
			}
			else {
				dosyaYaz << " " << musteri.numara << " " << oda.numara;
			}
		}
		dosyaYaz.close();
		dosyaOku.close();
		remove("odakayit.txt");
		rename("odakayityedek.txt", "odakayit.txt");
	}
	void odakayitlistele() {
		Musteri musteri;
		Oda oda;
		ifstream dosyaOku;
		dosyaOku.open("odakayit.txt", ios::in);
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.numara >> oda.numara;
			cout << musteri.numara << " numaralı müşteri " << oda.numara << " numaralı odada kalıyor." << endl;
		}
		system("pause");
		dosyaOku.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	Otel otel;
	do {
		system("cls");
		cout << "...:Otel İşlemleri:..." << endl;
		cout << "1-Oda İşlemleri" << endl << "2-Müşteri İşlemleri" << endl << "3-Oda-Kayıt İşlemleri" <<endl<< "99-Çıkış" << endl;
		cout << "Seçiminiz : "; cin >> secim;
		switch (secim) {
		case 1:otel.odaislem();
			break;
		case 2:otel.musteriislem();
			break;
		case 3:otel.odakayitislem();
			break;
		case 99:system("cls");
			cout << "Çıkış yaptınız" << endl;
			break;
		default:system("cls");
			cout << "Hatalı seçim" << endl;
			system("pause");
			break;
		}
		
	} while (secim != 99);
	system("pause");
    return 0;
}

