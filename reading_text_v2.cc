#include<bits/stdc++.h> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <stdio.h> /*printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand*/
#include <time.h>

using namespace std;



int main() {
	int ii=0;
	int randNumber;
	int vect_size;
	char iGuess;
	string test2;
	string test1 = "out";
	int contador_geral;
	int contador_ok;
	float value_performance;
//ichar palabra[100][100] = {"hola"};
	vector <string> palabra;
	std::ifstream file("datafile.txt");
	std::string temp;
	std::string P;
	std::string Q;
	string matrix_string[4][2]={"uno","dos","tres","quatro"};

 	while(std::getline(file, temp)) {
		istringstream is(temp); // line to read the columns of each line "row"
		is>>P>>Q; // the column first string column is saved in P and the other in Q variables
//	cout << "primera columna=" << P << " Segunda COlumna=" << Q<< endl;
//	cout << "info del teste==>" << sizeof(matrix_string[1][1])<<endl;
      //Do with temp
		palabra.push_back(P);
		palabra.push_back(Q);
		ii = ii + 1;
//	cout << "El indice es = " << ii << endl;
//	palabra[ii] = char temp;
//	cout << "The char is = " << temp << endl;
 	}
// Obtaining the vector's size in the vaiable vect_size
		vect_size = palabra.size();

// generating a new seed for the random function generator
		srand (time(NULL));
		randNumber = rand() % vect_size+1;

// this line is mandatory to guarantee that randNumber will be always odd 
		if (randNumber % 2 == 0 )
		randNumber--;

// Text to debug
		cout << "the size of the vector is: " << vect_size << endl; 
		cout << "The random number is " << randNumber << endl;
		cout << "la palabra is = " << palabra[randNumber-1] << endl;
		cout << "Traduccion es = " << palabra[randNumber] << endl;
		contador_geral = 0;
		contador_ok=0;
		do {
			contador_geral++;
//			printf("Please, what is the translation of this word in Finnish?: ");
//			std::getline(std::cin, test2);
			srand (time(NULL));
			randNumber = rand() % vect_size+1;

				if (randNumber % 2 == 0)
					randNumber--;
				cout << endl;
				cout << "In case you like to exit, write --> out" << endl;
				cout << "what is the meaning of: #### " << palabra[randNumber] << " ####"<< endl;
				std::getline(std::cin, test2);
				if (palabra[randNumber-1] == test2)
					{
					cout << "your answer was ok!" << endl;
					contador_ok++;
					}
				else
					cout << "you failed, try again..." << endl;
	//if (iGuess == palabra[randNumber]) puts ("Your answer is OK");
	//else puts ("Your answer is wrong!!");
	
			} while (test2 != test1); 
	//contador_ok--;
	contador_geral--;
	//cout << "total de preguntas " << contador_geral << endl;
	//cout << "preguntas respondidas ok " << contador_ok << endl;
	// we should not count the last try
	value_performance = (float)contador_ok  / (float)contador_geral;
	cout << endl;
	cout << "your performances was " << value_performance*100 <<"%" << endl;
	return 0;
}
