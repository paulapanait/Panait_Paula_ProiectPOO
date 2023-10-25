//Domeniul ales este ASTRONOMIE

#include <iostream>
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
using namespace std;

class Planeta
{
public:
	static int locSistem;
	const int nrObservatii;
	string nume;
	float greutate;
	int nrSateliti;
	string* sateliti;

	Planeta(float greutate) : greutate(greutate), nrObservatii(12)
	{
		locSistem++;
		this->nume = "Marte";
		this->greutate = greutate;
		this->nrSateliti = 0;
		this->sateliti = NULL;
	}

	Planeta(string nume, float greutate) : nrObservatii(12)
	{
		locSistem++;
		this->nume = nume;
		this->greutate = greutate;
		this->nrSateliti = 0;
		this->sateliti = NULL;
	}

	Planeta(string nume, float greutate, int nrSateliti, string* sateliti) : nrObservatii(12)
	{
		locSistem++;
		this->nume = nume;
		this->greutate = greutate;
		this->nrSateliti = nrSateliti;
		this->sateliti = new string[nrSateliti];
		for (int i = 0; i < nrSateliti;  i++)
		{
			this->sateliti[i] = sateliti[i];
		}
	}

	~Planeta()
	{
		if (this->sateliti != NULL)
		{
			delete[]this->sateliti;
		}
	}

	void afisareStaticaPlaneta()
	{
		cout << "A " << locSistem << "-a planeta de la Soare," << endl;
	}

	void afisarePlaneta()
	{
		cout << "numita " << nume << " a fost observata anul acesta de " << nrObservatii << endl;
		cout << "ori si are o greutate de " << greutate << " mii de tone " << endl;
		cout << "si un numar de " << nrSateliti << " sateliti, numiti: " << endl;

		if (nrSateliti != NULL)
		{
			for (int i = 0; i < nrSateliti; i++)
			{
				cout << "->" << sateliti[i] << endl;
			}
		}
		else
		{
			cout << "nu au fost identificati sateliti" << endl;
		}

		cout << endl;
	}
};

int Planeta::locSistem= 0;

class Constelatie
{
public:
	static int nrObservatie;
	const int nrObservatii;
	string nume;
	float nrStele;
	int nrNebuloase;
	string* nebuloase;

	Constelatie(string nume) : nrObservatii(4)
	{
		nrObservatie++;
		this->nume = nume;
		this->nrStele = 7;
		this->nrNebuloase = 0;
		this->nebuloase = NULL;
	}

	Constelatie(string nume, float nrStele) : nrObservatii(4)
	{
		nrObservatie++;
		this->nume = nume;
		this->nrStele = nrStele;
		this->nrNebuloase = 0;
		this->nebuloase = NULL;
	}

	Constelatie(string nume, float nrStele, int nrNebuloase, string* nebuloase) : nrObservatii(4)
	{
		nrObservatie++;
		this->nume = nume;
		this->nrStele = nrStele;
		this->nrNebuloase = nrNebuloase;
		this->nebuloase = new string[nrNebuloase];
		for (int i = 0; i < nrNebuloase; i++)
		{
			this->nebuloase[i] = nebuloase[i];
		}
	}

	~Constelatie()
	{
		if (this->nebuloase != NULL)
		{
			delete[]this->nebuloase;
		}
	}

	void afisareStaticaConstelatie()
	{
		cout << "A " << nrObservatie << "-a constelatie observata" << endl;
	}

	void afisareConstelatie()
	{
		cout << "cu denumirea de " << nume << " si un numar de " << nrStele << " stele" << endl; 
		cout << "a fost observata anul acesta de " << nrObservatii << " ori si are un numar de " << endl;
		cout << nrNebuloase << " nebuloase, numite: " << endl;

		if (nrNebuloase != NULL)
		{
			for (int i = 0; i < nrNebuloase; i++)
			{
				cout << "->" << nebuloase[i] << endl;
			}
		}
		else
		{
			cout << "nu am putut identifica nebuloase pentru aceasta constelatie" << endl;
		}

		cout << endl;
	}
};

int Constelatie::nrObservatie = 20;

class Galaxie
{
public:
	static int nrObservatie;
	const int nrObservatii;
	string nume;
	int nrObiecte;
	float lungime;
	bool spirala;
	int nrBrate;
	string* brate;

	Galaxie(string nume) : nrObservatii(3)
	{
		nrObservatie++;
		this->nume = nume;
		this->lungime = 14000;
		this->nrObiecte = 30000;
		this->spirala = true;
		this->nrBrate = 0;
		this->brate = NULL;
	}

	Galaxie(string nume, int lungime, int nrObiecte) : nrObservatii(3)
	{
		nrObservatie++;
		this->nume= nume;
		this->lungime = lungime;
		this->nrObiecte = nrObiecte;
		this->spirala = false;
		this->nrBrate = 0;
		this->brate = NULL;
	}

	Galaxie(string nume, int nrBrate, string* brate) : nrObservatii(3)
	{
		nrObservatie++;
		this->nume = nume;
		this->lungime = 120000;
		this->nrObiecte = 500000;
		this->spirala = true;
		this->nrBrate = nrBrate;
		this->brate = new string[nrBrate];
		for (int i = 0; i < nrBrate; i++)
		{
			this->brate[i] = brate[i];
		}
	}

	~Galaxie()
	{
		if (this->brate != NULL)
		{
			delete[]this->brate;
		}
	}

	void afisareStaticaGalaxie()
	{
		cout << "A " << nrObservatie << "-a galaxie observata anul acesta " << endl;
	}

	void afisareGalaxie()
	{
		cout << "poarta numele de " << nume << ", " << endl;
		cout << "se extinde pe o lungime de " << endl;
		cout << lungime << " ani lumina, continand in total " << nrObiecte << endl;
		cout << "miliarde de obiecte, incapsulate in brate " << endl;
		cout << (spirala ? "sub forma de spirala" : "fara forma de spirala") << ", dintre care principale: " << endl;

		if (nrBrate != NULL)
		{
			for (int i = 0; i < nrBrate; i++)
			{
				cout << "->" << brate[i] << endl;
			}
		}
		else
		{
			cout << "nu am putut identifica bratele cautate" << endl;
		}

		cout << "si a fost observata de " << nrObservatii << " ori " << endl;

		cout << endl;
	}
};

int Galaxie::nrObservatie = 10;

void main()
{

	cout << BLUE << "PREZENTARE OBSERVATII ASTRONOMICE 2023" << RESET << endl;
	cout << " " << endl;
	cout << " " << endl;

	Planeta p1(6000);
	p1.afisareStaticaPlaneta();
	p1.afisarePlaneta();

	Planeta p2("Venus", 34000);
	p2.afisareStaticaPlaneta();
	p2.afisarePlaneta();

	string* satelitip = new string[1];
	satelitip[0] = "Luna";

	Planeta p3("Pamant", 27000, 1, satelitip);
	p3.afisareStaticaPlaneta();
	p3.afisarePlaneta();

	string* nebuloase = new string[1];
	nebuloase[0] = "Nebuloasa Orion";

	Constelatie c1("Carul Mare");
	c1.afisareStaticaConstelatie();
	c1.afisareConstelatie();

	Constelatie c2("Lebada", 93);
	c2.afisareStaticaConstelatie();
	c2.afisareConstelatie ();

	Constelatie c3("Orion", 6, 1, nebuloase);
	c3.afisareStaticaConstelatie();
	c3.afisareConstelatie();

	string* brate = new string[2];
	brate[0] = "Scutul-Crucea";
	brate[1] = "Carena-Sagetator";

	Galaxie g1("Calea Lactee", 2, brate);
	g1.afisareStaticaGalaxie();
	g1.afisareGalaxie();


	Galaxie g2("Andromeda", 12000, 300000);
	g2.afisareStaticaGalaxie();
	g2.afisareGalaxie();

	Galaxie g3("Galaxia Artificiilor");
	g3.afisareStaticaGalaxie();
	g3.afisareGalaxie();


}
