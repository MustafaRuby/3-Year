#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>

void Regole() 
{
	cout << "REGOLE: \n";
	cout << "1. ci sono 4 navi da 2x2, 6 navi 1x1\n";
	cout << "2. il punteggio sarà il numero di colpi usati per affondare tutte le navi\n";
	cout << "3. Il campo è 10 x 10 dove la riga della griglia è rappresentata da lettere e la colonna da numeri\n";
	cout << "4. Non usare assolutamente altre lettere fuori dalla griglia oppure numeri al posto di lettere e viceversa\n";
	cout << "5. Le navi sono adiacenti al bordo ma non tra loro\n";
	cout << "6. le lettere devono essere inserite in minuscolo senno' vi sara' un errore e non riuscirete a continuare il gioco\n";
	cout << "7. i colpi gia' effettuati non contano come tentativo\n";
}


void lettere_to_Array(char lettereArray[10])
{
	lettereArray[0] = 'a';
	lettereArray[1] = 'b';
	lettereArray[2] = 'c';
	lettereArray[3] = 'd';
	lettereArray[4] = 'e';
	lettereArray[5] = 'f';
	lettereArray[6] = 'g';
	lettereArray[7] = 'h';
	lettereArray[8] = 'i';
	lettereArray[9] = 'l';
}



void generaNavi(char matrix [10][10])
{
	srand(time(NULL));
	int lettere = 0;
	int numeri = 0;
	bool condizioneAdiacenza;
	int navi = 10;
	int i = 0;
	while (i < navi)
	{
		//generazione di navi non adiacenti, dove il simbolo @ sono le parti dove non ci sono navi ma in cui non si possono gnerare della navi, mentre # sono le navi
		condizioneAdiacenza = false;

		while (condizioneAdiacenza == false)
		{

			lettere = rand () % 10;
			numeri = rand() % 10;
			if (matrix[lettere][numeri] == '@' || matrix[lettere][numeri] == '#')
			{
				condizioneAdiacenza = false;
			}
			else 
			{
				condizioneAdiacenza = true;
			}

		}
		cout << "Lettere: " << lettere << "; numeri: " << numeri << "\n";

		

		// navi nella colonna a
		if (lettere == 0 && numeri > 0 && numeri < 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
		}
		else if (lettere == 0 && numeri == 0)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
		}
		else if (lettere == 0 && numeri == 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
		}

		// navi nella colonna b
		if (lettere == 1 && numeri > 0 && numeri < 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 1 && numeri == 0)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			
		}
		else if (lettere == 1 && numeri == 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		// navi nella colonna c
		if (lettere == 2 && numeri > 0 && numeri < 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';
			 
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 2 && numeri == 0)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 2 && numeri == 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		// navi nella colonna d
		if (lettere == 3 && numeri > 0 && numeri < 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';
			 
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
			
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 3 && numeri == 0)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 3 && numeri == 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			
			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}


		// navi nella colonna e
		if (lettere == 4 && numeri > 0 && numeri < 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 4 && numeri == 0)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 4 && numeri == 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		

		// navi nella colonna f
		if (lettere == 5 && numeri > 0 && numeri < 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 5 && numeri == 0)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 5 && numeri == 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}


		// navi nella colonna g
		if (lettere == 6 && numeri > 0 && numeri < 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 6 && numeri == 0)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 6 && numeri == 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		// navi nella colonna h
		if (lettere == 7 && numeri > 0 && numeri < 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 7 && numeri == 0)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 7 && numeri == 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}


		// navi nella colonna i
		if (lettere == 8 && numeri > 0 && numeri < 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 8 && numeri == 0)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 8 && numeri == 9)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		// navi nella colonna L
		if (lettere == 9 && numeri > 0 && numeri < 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';
			 
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere == 9 && numeri == 0)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';
			 
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';
		}
		else if (lettere == 9 && numeri == 9)
		{
			
			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		i++;
	}

}


int L_to_N(char lettere)
{
	char lettereArray[10];
	int i = 0;
	int translation = 0;
	bool condizione = false;

	while (i < 10 && condizione == false)
	{
		lettere_to_Array(lettereArray);
		if (lettereArray[i] == lettere)
		{
			condizione = true;
			translation = i;
		}
		else
		{
			i++;
		}




	}
	if (condizione == false)
	{
		translation = 69;
	}
	return translation;
}






int main() {
	// area delle variabili
	char campo [10][10];
	char LettereArray[10];
	char lettereTentativo = 0;
	int lettere;
	int numeri = 0;
	int naviAffondate = 0;
	int naviRimanenti = 10;
	int punteggio = 0;
	

	
	lettere_to_Array(LettereArray);

	

	Regole();
	cout << "\n------------------------------------------------\n";
	//genera le regole

	//genera le navi casuali nel campo
	generaNavi(campo);
	cout << "\n------------------------------------------------\n";

	while (naviAffondate != 10)
	{
		lettereTentativo = 0;
		lettere = 0;
		numeri = 0;
		//inserizione delle lettere

		cout << "inserire le coordinate della nave: \n";
		cin >> lettereTentativo;

		lettere = L_to_N(lettereTentativo);
		while (lettere == 69)
		{
			cout << "Error! Unauthorized character!\n\n";
			cout << "reinserire la lettera\n";
			cin >> lettereTentativo;
			lettere = L_to_N(lettereTentativo);
		}

		

		
		//inserizione del numero

		cout << "Inserire il numero del file della nave:\n";

		cin >> numeri;

		while (numeri < 1 && numeri > 10)
		{
			cout << "Error! Unauthorized number!\n";
			cout << "Reinserire la riga nel file della nave\n";
			cin >> numeri;
		}

		numeri = numeri - 1;


		//condizione del campo
		if (campo[lettere][numeri] == 'X')
		{
			cout << "Colpo gia' effettuato!\n";
		}
		else if (campo[lettere][numeri] == '#')
		{
			campo[lettere][numeri] = 'X';
			naviAffondate++;
			naviRimanenti--;
			cout << naviAffondate << " navi affondate, " << naviRimanenti << " navi rimanenti\n\n";
			punteggio++;
		}
		else if (campo[lettere][numeri] == '@')
		{
			cout << "La cella " << lettereTentativo << numeri + 1 << " non aveva navi\n\n";
			campo[lettere][numeri] = 'X';
			punteggio++;
		}
		else if (campo[lettere][numeri] != '@' && campo[lettere][numeri] != '#' && campo[lettere][numeri] != 'X')
		{
			cout << "La cella " << lettereTentativo << numeri + 1 << " non aveva navi\n\n";
			campo[lettere][numeri] = 'X';
			punteggio++;
		}









	}
	
	//declarazione del punteggio
	cout << "\n\nCONGRATULAZIONI!!!! Hai affondato tutte le navi!\n";
	cout << "Punteggio: " << punteggio << "\n\n";










}