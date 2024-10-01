//#include "monfichier1.h"
//
//
//int main()
//{
//	std::cout << "Taille en octets d'un caractere:\t" << sizeof(char) << "\n";
//	std::cout << "Taille en octets d'un entier:\t" << sizeof(int) << "\n";
//	std::cout << "Taille en octets d'un reel:\t" << sizeof(float) << "\n";
//	std::cout << "Taille en octets d'un double:\t" << sizeof(double) << "\n";
//	std::cout << "Taille en octets d'un entier court:\t" << sizeof(short int) << "\n";
//	std::cout << "Taille en octets d'un entier non signe:\t" << sizeof(unsigned int) << "\n";
//
//	int numberInt{};
//	float numberFloat{};
//	char inputChar;
//
//	std::cout << "Saisissez un entier: \t";
//	std::cin >> numberInt;
//	std::cout << "En utilisant la premiere maniere d'affichage, en utilisant les outputs manipulators dec,oct et hex \n";
//	std::cout << std::dec << "Nombre en decimal: " << numberInt << "\n";
//	std::cout << std::oct << "Nombre en octal: " << numberInt << "\n";
//	std::cout << std::hex << "Nombre en hexa: " << numberInt << "\n";
//	std::cout << "En utilisant la deuxieme maniere d'affichage, en utilisant les outputs manipulators setbase(int i) \n";
//	std::cout << std::setbase(10) << "Nombre en decimal: " << numberInt << "\n";
//	std::cout << std::setbase(8) << "Nombre en octal: " << numberInt << "\n";
//	std::cout << std::setbase(16) << "Nombre en hexa: " << numberInt << "\n";
//	std::cout << "Saisissez un reel: \t";
//	std::cin >> numberFloat;
//	//std::cout << std::setprecision(5) << numberFloat << "\n";
//	//std::cout << std::fixed << std::setprecision(3) << numberFloat << "\n";
//	std::cout << std::setprecision(3) << std::setiosflags(std::ios::left | std::ios::fixed) << numberFloat << "\n";
//	std::cout << std::setw(10) << std::hexfloat << numberFloat << "\n";
//	std::cout << "Saisissez un caractere: \t";
//	std::cin >> inputChar;
//	std::cout << inputChar << "\n";
//	std::cout << static_cast<int>(inputChar);
//}
//
//
//// Exercice 2:
//
//// a) ce que fait la fonction main donnee en A2
//
//// La fonction main fait constemment appel a une fonction menu() qui donne le choix 
//// de l utilisateur. Dependemment de ce choix, la fonction calcule soit 
//// la surface, soit le volume, soit donne un resume de nombre d operations de calcul de 
//// volume ou de surface faites. Si l'utilisateur choisit ce dernier cas, le programme termine.
//
