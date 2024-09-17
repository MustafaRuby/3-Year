#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>

void Regole()
{
	cout << "REGOLE: \n";
	cout << "1. ci sono navi da 2x2 e navi 1x1\n";
	cout << "2. il punteggio sarà il numero di colpi usati per affondare tutte le navi\n";
	cout << "3. Il campo è 10 x 10 dove la riga della griglia è rappresentata da lettere e la colonna da numeri\n";
	cout << "4. Non usare assolutamente altre lettere fuori dalla griglia oppure numeri al posto di lettere e viceversa\n";
	cout << "5. Le navi sono adiacenti al bordo ma non tra loro\n";
	cout << "6. le lettere devono essere inserite in minuscolo senno' vi sara' un errore e non riuscirete a continuare il gioco\n";
	cout << "7. i colpi gia' effettuati non contano come tentativo\n";
	cout << "8. Le lettere ed i numeri vengono inseriti separatamente\n";
	cout << "9. Il simbolo 'X' sono le celle colpite; ']' sono le celle vuote; 'O' sono le navi affondate; '#' sono le navi 2x2\n\n";
}


void lettere_to_Array(char lettereArray[20])
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
	lettereArray[10] = 'm';
	lettereArray[11] = 'n';
	lettereArray[12] = 'o';
	lettereArray[13] = 'p';
	lettereArray[14] = 'q';
	lettereArray[15] = 'r';
	lettereArray[16] = 's';
	lettereArray[17] = 't';
	lettereArray[18] = 'u';
	lettereArray[19] = 'v';
}



void generaNavi(char matrix[20][20])
{
	srand(time(NULL));
	int lettere = 0;
	int numeri = 0;
	bool condizioneAdiacenza;
	int navi = 10;
	int i = 0;
	bool condSize;
	while (i < navi)
	{
		//generazione di navi non adiacenti, dove il simbolo @ sono le parti dove non ci sono navi ma in cui non si possono gnerare della navi, mentre # sono le navi
		condizioneAdiacenza = false;
		
		
		while (condizioneAdiacenza == false)
		{

			lettere = rand() % 10;
			numeri = rand() % 10;

			
			
			if (matrix[lettere][numeri] == '@' || matrix[lettere][numeri] == '#' || matrix[lettere][numeri] == '(')
			{
				condizioneAdiacenza = false;
			}
			else
			{
				condizioneAdiacenza = true;
			}

		}
		condSize = rand() % 2;

		if (condSize == 0 && lettere != 2 && lettere!= 1)
		{
			condSize = false;
			

		}
		else if (condSize == 1 || lettere == 2 || lettere == 1)
		{
			condSize = true;
			
		}

		// navi nella colonna a
		if (lettere == 0 && numeri > 0 && numeri < 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri + 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri + 1] = '(';

			matrix[lettere][numeri - 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
			matrix[lettere + 2][numeri - 1] = '@';


			matrix[lettere + 2][numeri] = '@';
			matrix[lettere + 2][numeri + 1] = '@';
			matrix[lettere + 2][numeri + 2] = '@';

			matrix[lettere][numeri + 2] = '@';
			matrix[lettere + 1][numeri + 2] = '@';
		}
		else if (lettere == 0 && numeri == 0 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri - 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri - 1] = '(';

			matrix[lettere][numeri - 2] = '@';
			matrix[lettere + 1][numeri - 2] = '@';
			matrix[lettere + 2][numeri - 2] = '@';


			matrix[lettere + 2][numeri - 1] = '@';
			matrix[lettere + 2][numeri] = '@';
		}
		else if (lettere == 0 && numeri == 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri + 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri + 1] = '(';

			matrix[lettere + 2][numeri] = '@';
			matrix[lettere + 2][numeri + 1] = '@';

			matrix[lettere][numeri + 2] = '@';
			matrix[lettere + 1][numeri + 2] = '@';
			matrix[lettere + 2][numeri + 2] = '@';

			matrix[lettere + 1][numeri + 2] = '@';
			matrix[lettere][numeri + 2] = '@';
		}
		else if (lettere == 0 && numeri > 0 && numeri < 19 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
		}
		else if (lettere == 0 && numeri == 0 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';
		}
		else if (lettere == 0 && numeri == 19 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
		}

		// navi nelle colonne tra a e v
		if (lettere > 0 && lettere < 19 && numeri > 0 && numeri < 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri + 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri + 1] = '(';

			matrix[lettere][numeri - 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
			matrix[lettere + 2][numeri - 1] = '@';


			matrix[lettere + 2][numeri] = '@';
			matrix[lettere + 2][numeri + 1] = '@';
			matrix[lettere + 2][numeri + 2] = '@';

			matrix[lettere + 1][numeri + 2] = '@';
			matrix[lettere][numeri + 2] = '@';
			matrix[lettere - 1][numeri + 2] = '@';

			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere > 0 && lettere < 19 && numeri == 0 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri + 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri + 1] = '(';

			matrix[lettere][numeri - 1] = '@';
			matrix[lettere + 1][numeri - 1] = '@';
			matrix[lettere + 2][numeri - 1] = '@';


			matrix[lettere + 2][numeri] = '@';
			matrix[lettere + 2][numeri + 1] = '@';
			matrix[lettere + 2][numeri + 2] = '@';

			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}
		else if (lettere > 0 && lettere < 19 && numeri == 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri + 1] = '(';
			matrix[lettere + 1][numeri] = '(';
			matrix[lettere + 1][numeri + 1] = '(';

			matrix[lettere + 2][numeri] = '@';
			matrix[lettere + 2][numeri + 1] = '@';
			matrix[lettere + 2][numeri + 2] = '@';

			matrix[lettere + 1][numeri + 2] = '@';
			matrix[lettere][numeri + 2] = '@';
			matrix[lettere - 1][numeri + 2] = '@';

			matrix[lettere - 1][numeri + 1] = '@';
			matrix[lettere - 1][numeri] = '@';
		}
		else if (lettere > 0 && lettere < 19 && numeri > 0 && numeri < 19 && condSize == true)
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
		else if (lettere > 0 && lettere < 19 && numeri == 0 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere > 0 && lettere < 19 && numeri == 19 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		

		// navi nella colonna V
		if (lettere == 19 && numeri > 0 && numeri < 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere - 1][numeri] = '(';
			matrix[lettere - 1][numeri + 1] = '(';
			matrix[lettere][numeri + 1] = '(';

			matrix[lettere][numeri - 1] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
			matrix[lettere - 2][numeri - 1] = '@';
			matrix[lettere - 2][numeri - 1] = '@';


			matrix[lettere - 2][numeri] = '@';
			matrix[lettere - 2][numeri + 1] = '@';
			matrix[lettere - 2][numeri + 2] = '@';

			matrix[lettere - 1][numeri + 2] = '@';
			matrix[lettere][numeri + 2] = '@';
		}
		else if (lettere == 19 && numeri == 0 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere][numeri - 1] = '(';
			matrix[lettere - 1][numeri - 1] = '(';
			matrix[lettere - 1][numeri] = '(';

			matrix[lettere][numeri - 2] = '@';
			matrix[lettere - 1][numeri - 2] = '@';
			matrix[lettere - 2][numeri - 2] = '@';

			matrix[lettere - 2][numeri - 1] = '@';
			matrix[lettere - 2][numeri] = '@';
		}
		else if (lettere == 19 && numeri == 19 && condSize == false)
		{

			matrix[lettere][numeri] = '(';
			matrix[lettere - 1][numeri] = '(';
			matrix[lettere - 1][numeri + 1] = '(';
			matrix[lettere][numeri + 1] = '(';

			matrix[lettere - 2][numeri] = '@';
			matrix[lettere - 2][numeri + 1] = '@';
			matrix[lettere - 2][numeri + 2] = '@';

			matrix[lettere - 1][numeri + 2] = '@';
			matrix[lettere][numeri + 2] = '@';
		}
		else if (lettere == 19 && numeri > 0 && numeri < 19 && condSize == true)
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
		else if (lettere == 19 && numeri == 0 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri + 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri + 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri + 1] = '@';

		}
		else if (lettere == 19 && numeri == 19 && condSize == true)
		{

			matrix[lettere][numeri] = '#';
			matrix[lettere][numeri - 1] = '@';

			matrix[lettere + 1][numeri] = '@';
			matrix[lettere + 1][numeri - 1] = '@';

			matrix[lettere - 1][numeri] = '@';
			matrix[lettere - 1][numeri - 1] = '@';
		}

		i++;
	}

}


int L_to_N(char lettere)
{
	char lettereArray[20];
	int i = 0;
	int translation = 0;
	bool condizione = false;
	lettere_to_Array(lettereArray);

	while (i < 20 && condizione == false)
	{
		
		if (lettereArray[i] == lettere)
		{
			condizione = true;
			translation = i;
		}
		else if(lettereArray[i] != lettere)
		{
			i++;
			condizione = false;
		}




	}
	if (condizione == false)
	{
		translation = 69;
	}
	return translation;
}

bool affondo2X2(char matrix[20][20], int lettere, int numeri)
{
	bool condAffondo = true;
	int i = 0;
	if (lettere == 0)
	{
		if (numeri == 0)
		{
			if (matrix[lettere][numeri - 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere + 1][numeri - 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
		}
		else if (numeri > 0 && numeri < 19)
		{
			if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere + 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}

		}
		else if (numeri == 19)
		{
			if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere + 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}
		}



	}
	else if (lettere > 0 && lettere < 19)
	{
		if (numeri == 0)
		{
			if (matrix[lettere][numeri - 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere + 1][numeri - 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
		}
		else if (numeri > 0 && numeri < 19)
		{
			if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere + 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}

		}
		else if (numeri == 19)
		{
			if (matrix[lettere + 1][numeri] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere + 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}
		}



	}
	else if (lettere == 19)
	{
		if (numeri == 0)
		{
			if (matrix[lettere][numeri - 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere - 1][numeri - 1] = '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere - 1][numeri] = '(')
			{
				condAffondo = false;
			}

		}
		else if (numeri > 0 && numeri < 19)
		{
			if (matrix[lettere - 1][numeri] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere - 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}


		}
		else if (numeri == 19)
		{
			if (matrix[lettere - 1][numeri] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere - 1][numeri + 1] == '(')
			{
				condAffondo = false;
			}
			else if (matrix[lettere][numeri + 1] == '(')
			{
				condAffondo = false;
			}


		}





	}
	return condAffondo;



}




int main() {
	// area delle variabili
	char campo[20][20];
	char campoGrafico[20][20];
	char LettereArray[20];
	char lettereTentativo = 0;
	int lettere;
	int numeri = 0;
	int naviAffondate = 0;
	int naviRimanenti = 10;
	int punteggio = 0;
	bool checkA2x2;

	for (int x = 0; x < 20; x++)
	{
		for (int i = 0; i < 20; i++)
		{
			campoGrafico[i][x] = ']';
		}
	}

	lettere_to_Array(LettereArray);



	Regole();
	cout << "\n------------------------------------------------\n";
	//genera le regole

	//genera le navi casuali nel campo
	generaNavi(campo);
	int z = 1;

	for (int x = 0; x < 20; x++)
	{
		if (z < 10)
		{
			cout << " " << z << ": ";
		}
		else if (z >= 10)
		{
			cout << z << ": ";
		}
		for (int i = 0; i < 20; i++)
		{
			cout << campoGrafico[i][x];
			cout << " ";
		}
		cout << "\n";
		z++;
	}
	cout << "_____________________________________________\n";
	cout << "    A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "L " << "M " << "N " << "O " << "P " << "Q " << "R " << "S " << "T " << "U " << "V ";
	z = 0;
	cout << "\n\n----------------------------------------\n\n";

	while (naviAffondate < 10)
	{
		checkA2x2 = false;
		lettereTentativo = 0;
		lettere = 0;
		numeri = 0;
		//inserizione delle lettere

		cout << "inserire la lettera del file della nave: \n";
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

		while (numeri < 1 && numeri > 20)
		{
			cout << "Error! Unauthorized number!\n";
			cout << "Reinserire la riga nel file della nave\n";
			cin >> numeri;
		}

		numeri = numeri - 1;
		z = 1;

		//condizione del campo
		if (campo[lettere][numeri] == 'X' || campo[lettere][numeri] == 'O' || campoGrafico[lettere][numeri] == '#')
		{
			cout << "Colpo gia' effettuato!\n";
			campoGrafico[lettere][numeri] = 'X';

		}
		else if (campo[lettere][numeri] == '#')
		{
			campo[lettere][numeri] = 'O';
			campoGrafico[lettere][numeri] = 'O';
			naviAffondate++;

			cout << "Nave affondata!\n";
			punteggio++;
		}
		else if (campo[lettere][numeri] == '(')
		{
			campo[lettere][numeri] = 'O';
			campoGrafico[lettere][numeri] = '#';

			checkA2x2 = affondo2X2(campo, lettere, numeri);

			if (checkA2x2 == true)
			{
				naviAffondate++;
				cout << "nave affondata!\n";
			}
			else if (checkA2x2 == false)
			{
				cout << "parte della nave colpita\n";
			}
			punteggio++;
		}
		else if (campo[lettere][numeri] == '@' || campoGrafico[lettere][numeri] == ']')
		{
			cout << "La cella " << lettereTentativo << numeri + 1 << " non ha navi\n\n";
			campo[lettere][numeri] = 'X';
			punteggio++;
			campoGrafico[lettere][numeri] = 'X';
		}
		else if (campo[lettere][numeri] != '@' && campo[lettere][numeri] != '#' && campo[lettere][numeri] != 'X' && campo[lettere][numeri] != 'O' && campo[lettere][numeri] != '(' && campo[lettere][numeri] == '#')
		{
			cout << "La cella " << lettereTentativo << numeri + 1 << " non ha navi\n\n";
			campo[lettere][numeri] = 'X';
			punteggio++;
			campoGrafico[lettere][numeri] = 'X';
		}

		for (int x = 0; x < 20; x++)
		{
			if (z < 10)
			{
				cout << " " << z << ": ";
			}
			else if (z >= 10)
			{
				cout << z << ": ";
			}
			for (int i = 0; i < 20; i++)
			{
				cout << campoGrafico[i][x];
				cout << " ";
			}
			cout << "\n";
			z++;
		}
		cout << "_____________________________________________\n";
		cout << "    A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "L " << "M " << "N " << "O " << "P " << "Q " << "R " << "S " << "T " << "U " << "V ";
		z = 0;
		cout << "\n\n----------------------------------------\n\n";






	}

	//declarazione del punteggio
	cout << "\n\nCONGRATULAZIONI!!!! Hai affondato tutte le navi!\n";
	cout << "Punteggio: " << punteggio << "\n\n";


}