/* Fonction principale main */
#include "monfichier2.h"
/*int main(void) {
	char choix;
	int nvolume = 0; //nombre de fois que la fonction volume a été lancee
	int nsurface = 0; //nombre de fois que la fonction surface a été lancee
	double rayon, hauteur;
	while (1)
	{
		choix = menu();
		switch (choix)
		{
		case '1': cout << endl << "Calcul de la surface :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			nsurface = surface(rayon);
			break;
		case '2': cout << endl << "Calcul du volume :" << endl;
			cout << "Donnez le rayon: ";
			cin >> rayon;
			cout << "Donnez la hauteur: ";
			cin >> hauteur;
			nvolume = volume(rayon, hauteur);
			break;
		case '3':cout << endl << "Sortie du programme" << endl;
			cout << "La fonction volume a ete lancee " << nvolume << " fois" << endl;
			cout << "La fonction surface a ete lancee " << nsurface << " fois" << endl;
			exit(0);
		default: break;
		}
	}
}*/

/* Fonction permettant le calcul de la surface d'un disque
   But: Cette fonction calcule la surface d'un disque
   Parametre: le rayon du disque 
   Retour: le nombre de fois l'operation surface avait été appelée */

int surface(double const& ray) {
	static int nbreSurface { 0 }; // trace le nombre de fois cette fonction avait ete appelée, la variable est statique donc sa durée de vie est celle du programme entier
	double result { ray * ray * Pi }; // formule mathématique
	std::cout << "la surface est: " << result;
	return ++nbreSurface;
}

/* Fonction permettant le calcul du volume du cylindre
*  But: Cette fonction calcule le volume d'un cylindre.
*  Parametre: Le rayon de la base du cylindre et son hauteur
*  Retour: Le nombre de fois la fonction volume avait été appelée
*/

int volume(double const& ray, double const& haut) {
	static int nbreVolume{ 0 };
	double result { ray * ray * Pi * haut };
	std::cout << "le volume est: " << result;
	return ++nbreVolume;
}

/*Fonction menu() : Fonction qui affiche un menu d'option et retourne l'option choisie */

char menu(void) {
	char choix;
	cout << endl;
	cout << "Que souhaitez-vous faire ?:" << endl;
	cout << "\t-Calculer la surface du disque de rayon (Tapez 1)" << endl;
	cout << "\t-Calculer le volume du cylindre de rayon et hauteur (Tapez 2)" << endl;
	cout << "\t-Quittez le programme (Tapez 3)" << endl;
	cout << "Votre choix: ";
	cin >> choix;
	return(choix);
}
