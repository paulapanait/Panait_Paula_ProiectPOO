//Deoarece initialele mele sunt PPA, voi face clasele "Palarie", "Pix" si "Autoturisme"

#include <iostream>

using namespace std;

class Palarie
{
public:
	static int nrPalarii;
	const int codProdus;
	string producator;
	float pret;
	int nrCulori;
	string* culori;

	Palarie(float pret) : pret(pret), codProdus(1234)
	{
		nrPalarii++;
		this->producator = "Maddame Paris";
		this->pret = pret;
		this->nrCulori = 0;
		this->culori = NULL;
	}

	Palarie(string producator, float pret) : codProdus(1234)
	{
		nrPalarii++;
		this->producator = producator;
		this->pret = pret;
		this->nrCulori = 0;
		this->culori = NULL;
	}

	Palarie(string producator, float pret, int nrCulori, string* culori) : codProdus(1234)
	{
		nrPalarii++;
		this->producator = producator;
		this->pret = pret;
		this->nrCulori = nrCulori;
		this->culori = new string[nrCulori];
		for (int i = 0; i < nrCulori; i++)
		{
			this->culori[i] = culori[i];
		}
	}

	~Palarie()
	{
		if (this->culori != NULL)
		{
			delete[]this->culori;
		}
	}

	void afisareStaticaPalarii()
	{
		cout << "Magazinul nostru va pune la dispozitie o serie de " << nrPalarii << " palarii," << endl;
	}

	void afisarePalarii()
	{
		cout << "accesibile si pe site-ul nostru prin codul " << codProdus << endl;
		cout << "de la designer-ul " << producator << ", la pretul unic de " << pret << endl;
		cout << "si intr-o varietate de " << nrCulori << " culori: " << endl;

		if (nrCulori != NULL)
		{
			for (int i = 0; i < nrCulori; i++)
			{
				cout << culori[i] << ", ";
			}
		}
		else
		{
			cout << "indisponibile momentan";
		}

		cout << endl;
	}
};

int Palarie::nrPalarii = 14;

class Pix
{
public:
	static int nrPixuri;
	const int codProdus;
	string producator;
	float pret;
	int nrCulori;
	string* culori;

	Pix(float pret) : pret(pret), codProdus(4321)
	{
		nrPixuri++;
		this->producator = "BIC";
		this->pret = pret;
		this->nrCulori = 0;
		this->culori = NULL;
	}

	Pix(string producator, float pret) : Pix(pret)
	{
		nrPixuri++;
		this->producator = producator;
		this->pret = pret;
		this->nrCulori = 0;
		this->culori = NULL;
	}

	Pix(string producator, float pret, int nrCulori, string* culori) : Pix(pret)
	{
		nrPixuri++;
		this->producator = producator;
		this->pret = pret;
		this->nrCulori = nrCulori;
		this->culori = new string[nrCulori];
		for (int i = 0; i < nrCulori; i++)
		{
			this->culori[i] = culori[i];
		}
	}

	~Pix()
	{
		if (this->culori != NULL)
		{
			delete[]this->culori;
		}
	}

	void afisareStaticaPixuri()
	{
		cout << "Magazinul nostru va pune la dispozitie o serie de " << nrPixuri << " pixuri," << endl;
	}

	void afisarePixuri()
	{
		cout << "de la producatorul " << producator << ", la pretul unic de " << pret << endl;
		cout << "si intr-o varietate de " << nrCulori << " culori: " << endl;

		if (nrCulori != NULL)
		{
			for (int i = 0; i < nrCulori; i++)
			{
				cout << culori[i] << ", ";
			}
		}
		else
		{
			cout << "indisponibile momentan";
		}

		cout << endl;

		cout << "accesibile prin codul " << codProdus << endl;
	}
};

int Pix::nrPixuri = 2;

class Autoturism
{
public:
	static int nrMasini;
	const int codMasina;
	string marca;
	int putere;
	float greutate;
	bool automata;
	int nrDetinatori;
	string* detinatori;

	Autoturism(int putere) : codMasina(9007)
	{
		this->nrMasini = 12;
		this->marca = "Bugatti";
		this->putere = putere;
		this->greutate = 2;
		this->automata = true;
		this->nrDetinatori = 0;
		this->detinatori = NULL;
	}

	Autoturism(int nrMasini, int putere, string marca) : Autoturism(nrMasini)
	{
		this->nrMasini = nrMasini;
		this->putere = putere;
		this->marca = marca;
		this->greutate = 4;
		this->automata = false;
		this->nrDetinatori = 0;
		this->detinatori = NULL;
	}

	Autoturism(int nrDetinatori, string* detinatori) : codMasina(9007)
	{
		this->nrMasini = 10;
		this->putere = 120;
		this->marca = "Maseratti";
		this->greutate = 3;
		this->automata = true;
		this->nrDetinatori = nrDetinatori;
		this->detinatori = new string[nrDetinatori];
		for (int i = 0; i < nrDetinatori; i++)
		{
			this->detinatori[i] = detinatori[i];
		}
	}

	~Autoturism()
	{
		if (this->detinatori != NULL)
		{
			delete[]this->detinatori;
		}
	}

	void afisareStaticaAutoturisme()
	{
		cout << "Va punem la dispozitie o gama variata de " << nrMasini << " masini " << endl;
	}

	void afisareAutoturisme()
	{
		cout << "din marca " << marca << " cu puterea de " << putere << " W si o greutate de " << endl;
		cout << greutate << " tone, cu o cutie " << (automata ? "automata" : "manuala") << " si " << endl;
		
		if (nrDetinatori != NULL)
		{
			for (int i = 0; i < nrDetinatori; i++)
			{
				cout << "-detinator anterior: " << detinatori[i] << " " << endl;
			}
		}
		else
		{
			cout << "0 detinatori anteriori" << endl;
		}
	}
};

int Autoturism::nrMasini = 10;

void main()
{
	Palarie palarie1(47.9);
	palarie1.afisareStaticaPalarii();
	palarie1.afisarePalarii();

	Palarie palarie2("Maddame Paris", 34.7);
	palarie2.afisareStaticaPalarii();
	palarie2.afisarePalarii();

	string* culorip = new string[3];
	culorip[0] = "rosu";
	culorip[1] = "albastru";
	culorip[2] = "verde";

	Palarie palarie3("Milan", 34.5, 3, culorip);
	palarie3.afisareStaticaPalarii();
	palarie3.afisarePalarii();

	string* culori = new string[5];
	culori[0] = "rosu";
	culori[1] = "verde";
	culori[2] = "albastru";
	culori[3] = "negru";
	culori[4] = "violet";

	Pix pix1(8.9);
	pix1.afisareStaticaPixuri();
	pix1.afisarePixuri();

	Pix pix2("BIC", 0.8);
	pix2.afisareStaticaPixuri();
	pix2.afisarePixuri();

	Pix pix3("BIC", 2.3, 5, culori);
	pix3.afisareStaticaPixuri();
	pix3.afisarePixuri();

	string* detinatori = new string[2];
	detinatori[0] = "Marian";
	detinatori[1] = "Iulian";

	Autoturism autoturism1(2,detinatori);
	autoturism1.afisareStaticaAutoturisme();
	autoturism1.afisareAutoturisme();

	Autoturism autoturism2(12, 120, "Ferrari");
	autoturism2.afisareStaticaAutoturisme();
	autoturism2.afisareAutoturisme();

	Autoturism autoturism3(130);
	autoturism3.afisareStaticaAutoturisme();
	autoturism3.afisareAutoturisme();


}
