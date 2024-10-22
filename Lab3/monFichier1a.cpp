/*Ex1a - Devoir 3 CSI2772A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	Color color;
	Face face;
};

int main() {
	Card game[32];
	//VOTRE CODE VIENT ICI
	int i{ 0 };
	for (int face{ 0 }; face < 8; face++) {
		for (int color{ 0 }; color < 4; color++) {
			game[i] = {static_cast<Color>(color),static_cast<Face>(face) };// prendre en compte toutes les combinaisons possibles
			i++;
		}
	}

	char color[9];
	char face [7];

	// affichage des cartes
	for (Card card : game) {
		switch (card.face) {
			case 0:
				strcpy_s(face, "seven");
				break;
			case 1:
				strcpy_s(face, "eight");
				break;
			case 2:
				strcpy_s(face, "nine");
				break;
			case 3:
				strcpy_s(face, "ten");
				break;
			case 4: 
				strcpy_s(face, "jack");
				break;
			case 5:
				strcpy_s(face, "queen");
				break;
			case 6:
				strcpy_s(face, "king");
				break;
			case 7:
				strcpy_s(face, "ace");
				break;
			default:
				break;
		}

		switch (card.color) {
			case 0:
				strcpy_s(color, "club");
				break;
			case 1:
				strcpy_s(color, "diamond");
				break;
			case 2:
				strcpy_s(color, "spades");
				break;
			case 3:
				strcpy_s(color, "heart");
				break;
			default:
				break;
		}
		cout << "color: " << color << "\t" << "face: " << face << "\n";
	}

	cout << "we have: " << size(game) << " cards";

}


