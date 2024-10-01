//*monfichier3b.cpp : Ex3b Devoir1 CSI2772A*/

#include <iostream>
# include <vector>

using namespace std;

/* Fonction de selection rechercheIndex qui renvoie l'indice de la valeur max d'un tableau
**
*/
int rechercheIndex(vector<int> T, int imax) {
	if (T.size() < imax - 1) {
		cout << "Erreur ! Tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	for (int i = 1; i <= imax; i++)
		if (T[i] > T[res]) res = i;
	return res;
}


/* Fonction trier avec passage Par reference
   But: Cette fonction permet d'ordonner un tableau
   Parametre: la reference vers un tableau d'entiers
   Retour: rien */
void trier(vector<int>& T) {
	//VOTRE VIENT ICI
	int size { static_cast<int>(T.size()) };
	int indFin{ size - 1 }; //[0,indFin] est la portion de la liste ou l'on doit trouver l'indice du max ("portion non triee")
	int indMax{ 0 };
	while (indFin >= 1) {
		indMax = rechercheIndex(T, indFin); // represente l'indice de l'element max
		// puis une fois l'element maximal est detectee, il faut l'echanger avec le dernier element correspondant
		int elementFin{ T[indFin] };
		T[indFin] = T[indMax];
		T[indMax] = elementFin;
		indFin--;
	}
}

/* Fonction saisieTab pour saisir les valeurs de votre tableau
**
*/
vector<int> saisieTab() {
	int taille;
	cout << " Entrer la taille de votre tableau: ";
	cin >> taille;
	vector<int> res(taille, 0);
	cout << " Saisir les valeurs de votre tableau: \n";
	for (int i = 0; i < taille; i++) {
		cout << " val[ " << i << "] =";
		cin >> res[i];
	}
	cout << "\n";
	return res;
}

/* Fonction principale main
**
*/
int main() {
	vector<int> tab;
	tab = saisieTab();
	cout << "Les valeurs de mon tableau sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];

	}
	cout << "\n";
	trier(tab);
	cout << "\nLes valeurs de mon tableau trie sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];

	}

}


