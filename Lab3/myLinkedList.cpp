/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"

int main()
{
	Evaluation* first = NULL;	//Pointer on the first element of the list
	//the list is empty, so initialization to NULL
	int number = 0;			//number of elements in the linked  list 
	int choice;			//choice for the menu

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
		break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}

/*
*add() Function*
* Cette fonction ajoute un nouveau element a la liste a la position specifiee par l'utilisateur
* parametres: 
		p: pointeur vers la tete de la liste
		number: nombre d'elements actuel dans la liste
  Retour: 
		un pointeur vers la tete de la liste
**/
Evaluation* add(Evaluation* p, int& number)
{
	char student[capacity];// enregistre le nom de l'etudiant a entrer
	cout << "After which element you want to insert ? (0 for start): ";
	int position{};
	cin >> position;
	while (position < 0 || position > number || cin.fail()) {
		if (cin.fail()) {// si l'entree est un non nombre, on le traite ici
			cout << "The position is a number\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else if (position < 0) {
			cout << "The position cannot be negative\n";
		}
		else if (position > number) {
			cout << "The position is too big. There are only " << number << " elements in the list now\n";
		}
		cout << "Try again: ";
		cin >> position;
	}
	
	cout << "\nEntering the item from the chained list.\n";
	cout << "Enter the student (followed by a tab): ";
	cin.getline(student, capacity, '\t');
	if (student[0] == 10) {
		memmove(student, student + 1, strlen(student));// enlever le retour de ligne au debut du nom de la variable
	}
	cout << "Enter the grade: ";
	int grade{};
	cin >> grade;

	if (position == 0) {
		Evaluation* rest{};
		if (p != NULL) {
			rest = p;
		}
		// premier cas, ajouter au debut de la liste
		p = new Evaluation;
		strcpy_s(p->student, student);//copie des char*
		p->grade = grade;
		(p != NULL)? p->next = rest : p->next = NULL;
	} else {
		// L"insertion n'est pas au debut
		int counter { 1 };
		Evaluation* index{ p };
		// Trouvons l'element precedent celui que l'on doit ajouter
		while (counter != position) {
			index = index->next;
			counter++;
		}
		// index pointe vers l'element precedent celui que l'on doit ajouter
		if (index->next != NULL) {
			Evaluation* tmp{ index->next };// le reste de la liste est enregistree a tmp
			index->next = new Evaluation;
			strcpy_s(index->next->student, student);
			index->next->grade = grade;
			index->next->next = tmp;// relier l'element nouvellement ajoutee au reste de la liste
		}
		else {
			// le cas que l'on va ajouter a la fin
			index->next = new Evaluation;
			strcpy_s(index->next->student, student);
			index->next->grade = grade;
			index->next->next = NULL;
		}
	}

	number++;
	return p;
}


/*
remove() function
	Cette fonction supprime l'element trouvee dans une position specifiee par l'utilisateur
	parametres:
		p: pointeur vers la tete de la liste
		number: nombre d'elements total dans la liste
	retour: 
		Un pointeur vers la tete de la liste
*/

Evaluation* remove(Evaluation* p, int& number)
{
	//VOTRE CODE VIENT ICI
	cout << "What is the number of the element to delete?: ";
	int position{};
	cin >> position;
	while (position <= 0 || position > number || cin.fail()) { // si l'entree est un non nombre, on le traite ici
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else if (position <= 0) {
			cout << "The position cannot be negative or null\n";
		}
		else {
			cout << "The position is too big\n";
		}
		cout << "Try again: ";
		cin >> position;
	}

	if (position == 1) {
		// l'element a supprimer est dans le debut de la liste
		if (p->next != NULL) {
			Evaluation* tmp{ p->next };// le reste de la liste
			delete p;
			p = tmp;
		}
		else {
			// il y a un seul element que l'on cherche a supprimer
			delete p;
			p = NULL;
		}
	}
	else if (position < number) {
		Evaluation* index{ p };
		Evaluation* previous{ p };
		int counter{ 1 };
		while (counter != position) {

			if (counter == (position - 1)) {// le predecesseur detecte, enregistre dans previous
				index = index->next;
			}
			else {
				index = index->next;
				previous = previous->next;
			}
			counter++;
		}
		//index pointe a ce que l'on doit supprimer maintenant, previous pointe au predecesseur
		Evaluation* successor = index->next;// pointer au successeur
		delete previous->next;
		previous->next = successor;
	}
	else {
		// dernier element de la liste
		int counter { 1 };
		Evaluation* start{ p };
		while (counter != (position-1)) {
			start = start->next;
			counter++;
		}

		// start maintenant pointe a l'element avant celui qui doit etre supprimee
		delete start->next;
		start->next = NULL;
	}
	number--;
	return p;
}



/**
*display() Function
* Cette fonction imprime les elements d'une liste
* 
*	parametres: p: pointeur vers la tete de la liste
*	Retour: rien
**/
void display(Evaluation* p)
{
	//VOTRE CODE VIENT ICI
	Evaluation* start{ p };
	while (start != NULL) {
		cout << "Student: " << start->student;
		cout << "\nThe grade is: " << start->grade;
		cout << "\n\n";
		start = start->next;
	}
}



/**
*average() Function *
* Cette fonction calcule la moyenne de la classe
* Parametres:   p: pointeur vers la tete de la liste
*				nbre: Nombre total d'elements dans la liste
* Retour: 0: probleme survenu
*		  1: pas de probleme survenu
***/
int average(Evaluation* p, int const& nbre)
{
	//VOTRE CODE VIENT ICI
	if (nbre <= 0) {
		return 0;
	}
	int average{};
	Evaluation* index{ p };
	while (index != NULL) {
		average += index->grade;
		index = index->next;
	}
	average = average / nbre;
	cout << "The average of the class is: " << average;
	return 1;
}






