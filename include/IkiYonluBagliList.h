#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class IkiYonluBagliList
{
public:
	struct Node
	{
		string ad;	   // deger
		Node *Sonraki; // sonraki eleman
		Node *onceki;  //önceki eleman

		Node();
	};

	Node *head = NULL; // sürekli ilk elemanı tutar

	void KonumdaEkle(string, int);

	void KonumdaSil(int);

	void Dispaly();
};
