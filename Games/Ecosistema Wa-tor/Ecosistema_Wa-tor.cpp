#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

//1 cronono = 2000 ms
//0 = acqua
//1 = pesce
//2 = squalo

#define xDim 40 //x delle matrici
#define yDim 60 //y delle matrici
#define initialSharks 5 //quantità iniziativa dei squali
#define initialFishs 1000 //quantità iniziativa dei pesci
#define riproSharks 12 //eta di riproduzione di squali in crononi
#define riproFishs 5 //eta riproduzione di pesci in crononi

struct IDfish {
	int eta = 0; //da quando è vivo in crononi
	int etaRiproduzione = 0; //quando deve raggiungere l'età di riproduzione (casuale tra 2 e 4 crononi)
	bool maturo = false; //se ha raggiunto l'età di riproduzione
};

struct IDshark {
	int eta = 0; //da quando è vivo in crononi
	int etaRiproduzione = 0; //quando deve raggiungere l'età di riproduzione (casuale tra 1 e 7 crononi)
	bool maturo = false; //se ha raggiunto l'età di riproduzione
	int tempoPasto = 0; //da quanto non ha mangiato in crononi
};

void bigBang(int world[xDim][yDim])
{
	for (int x = 0; x < xDim; x++)
	{
		for (int y = 0; y < yDim; y++)
		{
			world[x][y] = 0;
		}
	}
}

void worldGeneration(int world[xDim][yDim], IDfish pesci[xDim][yDim], IDshark squali[xDim][yDim], int& numFish, int& numSharks)
{
	int casualFishx;
	int casualFishy;

	int casualSharkx;
	int casualSharky;

	bool blank = false;
	for (int x = 0; x < initialFishs; x++)
	{
		casualFishx = rand() % xDim;
		casualFishy = rand() % yDim;
		world[casualFishx][casualFishy] = 1;
		pesci[casualFishx][casualFishy].eta = 0;
		pesci[casualFishx][casualFishy].etaRiproduzione = rand() % 3 + 2; //genera un numero casuale da 2 a 4
		pesci[casualFishx][casualFishy].maturo = false;
		numFish++;
	}

	for (int y = 0; y < initialSharks; y++)
	{
		while (blank == false)
		{
			casualSharkx = rand() % xDim;
			casualSharky = rand() % yDim;

			if (world[casualSharkx][casualSharky] == 0)
			{
				blank = true;
			}
		}

		world[casualSharkx][casualSharky] = 2;
		squali[casualSharkx][casualSharky].eta = 0;
		squali[casualSharkx][casualSharky].etaRiproduzione = rand() % 4 + 1;
		squali[casualSharkx][casualSharky].maturo = false;

		numSharks++;

		blank = false;
	}


}

bool fishMotionFunction(int world[xDim][yDim], int xCoor, int yCoor, int& newxCoor, int& newyCoor)
{
	bool blank = false;
	int XMIN, XMAX, YMIN, YMAX;
	XMIN = xCoor - 1;
	XMAX = xCoor + 1;
	YMIN = yCoor - 1;
	YMAX = yCoor + 1;

	if (xCoor == 0) XMIN = xCoor;
	if (xCoor == xDim - 1) XMAX = xCoor;
	if (yCoor == 0) YMIN = yCoor;
	if (yCoor == yDim - 1) YMAX = yCoor;

	for (int i = XMIN; i <= XMAX && blank == false; i++)
	{
		for (int J = YMIN; J <= YMAX && blank == false; J++)
		{
			if (world[i][J] == 0)
			{
				newxCoor = i;
				newyCoor = J;
				blank = true; //si sposta in questa coordinata

			}


		}



	}


	return blank; //se è true, si sposta in questa specifica coordinata, se è false, non ci sono celle libere da spostarci in cui


}

int sharkMotionFunction(int world[xDim][yDim], int xCoor, int yCoor, int& newxCoor, int& newyCoor)
{
	bool blank = false;
	int status = 0;
	int XMIN, XMAX, YMIN, YMAX;
	XMIN = xCoor - 1;
	XMAX = xCoor + 1;
	YMIN = yCoor - 1;
	YMAX = yCoor + 1;

	if (xCoor == 0) XMIN = xCoor;
	if (xCoor == xDim - 1) XMAX = xCoor;
	if (yCoor == 0) YMIN = yCoor;
	if (yCoor == yDim - 1) YMAX = yCoor;

	for (int i = XMIN; i <= XMAX && blank == false; i++)
	{
		for (int J = YMIN; J <= YMAX && blank == false; J++)
		{
			if (world[i][J] == 0)
			{
				newxCoor = i;
				newyCoor = J;
				blank = true;
				status = 1; //non mangia niente
			}
			else if (world[i][J] == 1)
			{
				newxCoor = i;
				newyCoor = J;
				blank = true;
				status = 2; //mangia un pesce
			}


		}



	}


	if (blank == false)
	{
		status = 0; //significa che non ci sono posti liberi da posizionarsi in cui 
	}

	return status;

}


void generalMotion(int world[xDim][yDim], int xCoor, int yCoor, int newxCoor, int newyCoor)
{
	if (world[xCoor][yCoor] == 1)
	{
		world[newxCoor][newyCoor] = 1;
		world[xCoor][yCoor] = 0;
	}
	if (world[xCoor][yCoor] == 2)
	{
		world[newxCoor][newyCoor] = 2;
		world[xCoor][yCoor] = 0;
	}
}


void fishReproduction(int world[xDim][yDim], IDfish pesci[xDim][yDim], int &numFish, int fishMaturi)
{
	int casualFishx;
	int casualFishy;

	int quantity = fishMaturi / 2;
	bool blank = false;
	for (int x = 0; x < quantity; x++)
	{
		while (blank == false)
		{

			casualFishx = rand() % xDim;
			casualFishy = rand() % yDim;

			if (world[casualFishx][casualFishy] == 0)
			{
				blank = true;
			}
		}

		world[casualFishx][casualFishy] = 1;
		pesci[casualFishx][casualFishy].eta = 0;
		pesci[casualFishx][casualFishy].etaRiproduzione = rand() % 3 + 2; //genera un numero casuale da 2 a 4
		pesci[casualFishx][casualFishy].maturo = false;
		numFish++;

		blank = false;
	}




}

void sharkReproduction(int world[xDim][yDim], IDshark squali[xDim][yDim], int &numSharks, int sharkMaturi)
{
	

	int casualSharkx;
	int casualSharky;
	int quantity = sharkMaturi / 2;

	bool blank = false;
	

	for (int y = 0; y < quantity; y++)
	{
		while (blank == false)
		{
			casualSharkx = rand() % xDim;
			casualSharky = rand() % yDim;

			if (world[casualSharkx][casualSharky] == 0)
			{
				blank = true;
			}
		}

		world[casualSharkx][casualSharky] = 2;
		squali[casualSharkx][casualSharky].eta = 0;
		squali[casualSharkx][casualSharky].etaRiproduzione = rand() % 4 + 1;
		squali[casualSharkx][casualSharky].maturo = false;

		numSharks++;

		blank = false;
	}




}


int main() {
	int fishReproductionPeriod = 0;
	int sharkRiproductionPeriod = 0;

	int newFishxCoor = 0;
	int newFishyCoor = 0;

	int fishMaturi = 0;
	int sharkMaturi = 0;

	int newSharkxCoor = 0;
	int newSharkyCoor = 0;

	bool fishCondition = false;
	int sharkCondition = 0;

	int numFish = 0;
	int numSharks = 0;

	int crononiCorrenti = 0;

	int world[xDim][yDim];

	IDfish pesci[xDim][yDim];

	IDshark squali[xDim][yDim];

	bigBang(world);

	worldGeneration(world, pesci, squali, numFish, numSharks);

	//ciclo di vita del mondo

	std::cout << "Numero di pesci: " << numFish << "\n";
	std::cout << "Numero di squali: " << numSharks << "\n";
	std::cout << "Crononi passati: " << crononiCorrenti << "\n";
	std::cout << "Pesci all'eta' di riproduzione: " << fishMaturi << "\n";
	std::cout << "Squali all'eta' di riproduzione: " << sharkMaturi << "\n";
	std::cout << "\n";

	while (numSharks != 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		crononiCorrenti = crononiCorrenti + 1;
		fishReproductionPeriod = fishReproductionPeriod + 1;
		sharkRiproductionPeriod = sharkRiproductionPeriod + 1;

		for (int x = 0; x < xDim; x++)
		{
			for (int y = 0; y < yDim; y++)
			{
				if (world[x][y] == 1)//azione dei pesci quando passa un cronono
				{

					fishCondition = fishMotionFunction(world, x, y, newFishxCoor, newFishyCoor);
					if (fishCondition == false)
					{
						pesci[x][y].eta = pesci[x][y].eta + 1;
						if (pesci[x][y].eta == pesci[x][y].etaRiproduzione)
						{
							pesci[x][y].maturo = true;
							fishMaturi = fishMaturi + 1;
							
						}
					}
					else if (fishCondition == true)
					{
						pesci[x][y].eta = pesci[x][y].eta + 1;
						if (pesci[x][y].eta == pesci[x][y].etaRiproduzione)
						{
							pesci[x][y].maturo = true;
							fishMaturi = fishMaturi + 1;


						}
						pesci[newFishxCoor][newFishyCoor].eta = pesci[x][y].eta;
						pesci[newFishxCoor][newFishyCoor].etaRiproduzione = pesci[x][y].etaRiproduzione;
						pesci[newFishxCoor][newFishyCoor].maturo = pesci[x][y].maturo;




						generalMotion(world, x, y, newFishxCoor, newFishyCoor);



					}

				}
				else if (world[x][y] == 2)
				{
					sharkCondition = sharkMotionFunction(world, x, y, newSharkxCoor, newSharkyCoor);
					if (squali[x][y].tempoPasto == 5)
					{
						world[x][y] = 0;
						squali[x][y].eta = 0;
						squali[x][y].etaRiproduzione = 0;
						squali[x][y].tempoPasto = 0;
						squali[x][y].maturo = false;
					}
					else if (sharkCondition == 0)
					{
						squali[x][y].eta++;
						squali[x][y].tempoPasto++;
						if (squali[x][y].eta == squali[x][y].etaRiproduzione)
						{
							squali[x][y].maturo = true;
							sharkMaturi++;
						}
					}
					else if (sharkCondition == 1)
					{
						
						squali[x][y].eta++;
						squali[x][y].tempoPasto++;
						if (squali[x][y].eta == squali[x][y].etaRiproduzione)
						{
							squali[x][y].maturo = true;
							sharkMaturi++;
						}

						squali[newSharkxCoor][newSharkyCoor].eta = squali[x][y].eta;
						squali[newSharkxCoor][newSharkyCoor].etaRiproduzione = squali[x][y].etaRiproduzione;
						squali[newSharkxCoor][newSharkyCoor].tempoPasto = squali[x][y].tempoPasto;
						squali[newSharkxCoor][newSharkyCoor].maturo = squali[x][y].maturo;
						generalMotion(world, x, y, newSharkxCoor, newSharkyCoor);
					}
					else if (sharkCondition == 2)
					{

						squali[x][y].eta++;
						squali[x][y].tempoPasto = 0;
						if (squali[x][y].eta == squali[x][y].etaRiproduzione)
						{
							squali[x][y].maturo = true;
							sharkMaturi++;
							
						}

						squali[newSharkxCoor][newSharkyCoor].eta = squali[x][y].eta;
						squali[newSharkxCoor][newSharkyCoor].etaRiproduzione = squali[x][y].etaRiproduzione;
						squali[newSharkxCoor][newSharkyCoor].tempoPasto = squali[x][y].tempoPasto;
						squali[newSharkxCoor][newSharkyCoor].maturo = squali[x][y].maturo;
						numFish--;
						generalMotion(world, x, y, newSharkxCoor, newSharkyCoor);
					}

				}
			}
		}
		
		if (fishReproductionPeriod == riproFishs)
		{
			if (fishMaturi % 2 == 0 && fishMaturi > 1)
			{
				fishReproduction(world, pesci, numFish, fishMaturi);
			}
			else if (fishMaturi % 2 != 0 && fishMaturi > 1)
			{
				fishReproduction(world, pesci, numFish, fishMaturi - 1);
			}
			fishReproductionPeriod = 0;
		}

		if (sharkRiproductionPeriod == riproSharks)
		{
			if(sharkMaturi % 2 == 0 && sharkMaturi >1)
			{
				sharkReproduction(world, squali, numSharks, sharkMaturi);
			}
			if (sharkMaturi % 2 != 0 && sharkMaturi > 1)
			{
				sharkReproduction(world, squali, numSharks, sharkMaturi - 1);
			}
		}

		std::cout << "Numero di pesci: " << numFish << "\n";
		std::cout << "Numero di squali: " << numSharks << "\n";
		std::cout << "Crononi passati: " << crononiCorrenti << "\n";
		std::cout << "Pesci all'eta' di riproduzione: " << fishMaturi << "\n";
		std::cout << "Squali all'eta' di riproduzione: " << sharkMaturi << "\n";
		std::cout << "\n";




	}

	std::cout << "ecosystem collapse!";


}
