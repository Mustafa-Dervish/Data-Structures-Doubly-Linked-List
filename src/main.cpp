#include <iostream>
#include <string>
#include <fstream>
#include "IkiYonluBagliList.h"
using namespace std;

void Metindenoku()
{
	IkiYonluBagliList list;

	ifstream dosyam("Veri.txt"); // dosyayı açma

	if (dosyam.is_open())
	{
		string hat; // dosyadaki satirlari tutmasi icin
		int konum = 0;

		while (getline(dosyam, hat)) // tek satir okuma ve hat degiskenine atama
		{
			string sinir = "(";
			konum = hat.find(sinir);
			string fonkisyonAdi = hat.substr(0, konum); // boslugua kadar deger, degiskene atama
			hat.erase(0, konum + sinir.length());		// alinan deger, hat'den silme

			if (fonkisyonAdi == "E")
			{
				// found index
				string sinir = "#";
				konum = hat.find(sinir);
				string str_index = hat.substr(0, konum); // boslugua kadar deger, degiskene atama
				int index = stoi(str_index);
				hat.erase(0, konum + sinir.length()); // alinan deger, hat'den silme

				// found the name
				sinir = ")";
				konum = hat.find(sinir);
				string name = hat.substr(0, konum); // boslugua kadar deger, degiskene atama

				list.KonumdaEkle(name, index);
			}
			else if (fonkisyonAdi == "S")
			{

				konum = hat.find(")");
				string str_index = hat.substr(0, konum); // boslugua kadar deger, degiskene atama
				int index = stoi(str_index);

				list.KonumdaSil(index);
			}
		}
		dosyam.close();
	}

	list.Dispaly();
}

int main()
{
	Metindenoku();
	return 0;
}
