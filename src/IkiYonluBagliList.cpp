#include <fstream>
#include <iostream>
#include <string>
#include "IkiYonluBagliList.h"
IkiYonluBagliList::Node::Node()
{
	ad = "";
	Sonraki = nullptr;
	onceki = nullptr;
}

void IkiYonluBagliList::KonumdaEkle(string val, int pos)
{
	Node *newnode = new Node;
	newnode->onceki = NULL;
	newnode->Sonraki = NULL;

	if (head == NULL)
	{ // ilk eleman ise direk head'a yerleşecek
		newnode->ad = val;
		head = newnode;
		return;
	}

	// istenenNode temp indexi bulma
	Node *istenenNode = head;
	for (int i = 0; i < pos; i++)
	{ // silenecek indexin bir önceki elemanda durmak
		if (istenenNode->Sonraki == NULL)
		{
			// istenenNode indexinin liste disi
			// sonunda yeni temp ekle
			istenenNode->Sonraki = newnode;
			newnode->onceki = istenenNode;
			newnode->ad = val;

			return;
		}

		istenenNode = istenenNode->Sonraki;
	}

	// son indexi bul
	Node *lastNode = head;
	while (lastNode->Sonraki != NULL)
		lastNode = lastNode->Sonraki;

	// yeni Node listenin sonuna ekle
	lastNode->Sonraki = newnode;
	newnode->onceki = lastNode;

	// isimleri one kopyala
	Node *prevNode = newnode;
	while (prevNode->onceki != istenenNode)
	{
		prevNode->ad = prevNode->onceki->ad;
		prevNode = prevNode->onceki;
	}

	prevNode->ad = istenenNode->ad;
	istenenNode->ad = val;
}

void IkiYonluBagliList::KonumdaSil(int pos)
{
	Node *temp = head;

	if (head == NULL)
		return; // list boş ise

	// istenen temp indexi bul;
	Node *istenenNode = head;
	for (int i = 0; i < pos; i++)
	{ // silenecek indexin bir önceki elemanda durmak
		if (istenenNode->Sonraki == NULL)
		{
			break;
		}

		istenenNode = istenenNode->Sonraki;
	}

	// isimleri one kopyala
	Node *nextNode = istenenNode;
	while (nextNode->Sonraki != NULL)
	{
		nextNode->ad = nextNode->Sonraki->ad;
		nextNode = nextNode->Sonraki;
	}

	// silme düğümünün son olup olmadığını kontrol edin
	if (nextNode == head)
		head = NULL;
	else
		nextNode->onceki->Sonraki = NULL;

	delete nextNode;
}
void IkiYonluBagliList::Dispaly()
{ // list elemanlari ekrana yazdırma
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->ad << " ";
		temp = temp->Sonraki;
	}
	cout << endl;
}
