/*Ex1b - Devoir 3 CSI2772A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/* testPair() function
Cette methode determine si la main a au moins une paire de cartes
	Parametre: une main de joueur
	Retour: true si au moins une paire existe, false si aucune paire n'existe
*/
bool testPair(const Hand& h)
{
	//VOTRE CODE VIENT ICI
	bool isFound{false};

	for (int i{ 0 }; i<(size(h)-1); i++) {
		for (int j{ i + 1 }; j < size(h); j++) {
			if (h[i].face == h[j].face) {
				isFound = true;// comparer chaque face de carte avec toutes les autres
				break;
			}
		}
		if (isFound == true) {
			break;
		}
	}
	return isFound;
}


/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << "pair" << endl;
	return 0;
}



