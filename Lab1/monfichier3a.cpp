/*monfichier3a.cpp : ex3a devoir1 csi2772a*/

#include <iostream>
# include <vector>

using namespace std;

/* fonction de selection rechercheindex qui renvoie l'indice de la valeur max d'un tableau
**
*/
int rechercheindex(vector<int> t, int imax) {
	if (t.size() < imax - 1) {
		cout << "erreur ! tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	for (int i = 1; i <= imax; i++)
		if (t[i] > t[res]) res = i;
	return res;
}


/* fonction saisietab pour saisir les valeurs de votre tableau
**
*/
vector<int> saisietab() {
	int taille;
	cout << " entrer la taille de votre tableau: ";
	cin >> taille;
	vector<int> res(taille, 0);
	cout << " saisir les valeurs de votre tableau: \n";
	for (int i = 0; i < taille; i++) {
		cout << " val[ " << i << "] =";
		cin >> res[i];
	}
	cout << "\n";
	return res;
}


/* fonction trier avec passage par valeur
** but: cette fonction trie un tableau
   parametre: le tableau transferee par valeur
   retour: le meme tableau*/ 
vector<int> trier(vector<int> t) {
	//votre code vient ici
	int size   { static_cast<int>(t.size()) }; // taille du tableau
	int indfin { size - 1 }; // [0,indfin] represente la portion de la liste ou on doit trouver l'element max ("portion non triee")
	int indmax { 0 };
	while (indfin >= 1) {
		indmax = rechercheindex(t, indfin); // represente l'indice de l'element max
		// echange entre l'element max et le dernier element correspondant
		int elementfin { t[indfin] };
		t[indfin] = t[indmax];
		t[indmax] = elementfin;
		indfin--;
	}
	return t;
}

/* fonction principale main
**
*/
int main() {
	vector<int> tab;
	vector<int> tabtrie;
	tab = saisietab();
	cout << "les valeurs de mon tableau sont : ";
	for (int i = 0; i < tab.size(); i++) {
		cout << "\n" << tab[i];
	}
	cout << "\n";

	tabtrie = trier(tab);
	cout << "\nles valeurs de mon tableau trie sont : ";
	for (int i = 0; i < tabtrie.size(); i++) {
		cout << "\n" << tabtrie[i];

	}

}



