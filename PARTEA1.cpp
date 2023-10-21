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

	static int aflaCodProdus()
	{
		return codProdus;
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
				cout << culori[i] << " ";
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
		nrPixuri++
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
				cout << culori[i] << " ";
			}
		}
		else
		{
			cout << "indisponibile momentan";
		}

		cout << endl;

		cout << " accesibile prin codul " << codProdus;
	}
};

int Pix::nrPixuri = 2;

void main()
{
	Palarie palarie1(47.9);
	palarie1.afisareStaticaPalarii();
	palarie1.afisarePalarii();
	cout << palarie1.aflaCodProdus();

	Palarie palarie2("Maddame Paris", 34.7);
	palarie2.afisareStaticaPalarii();
	palarie2.afisarePalarii();

	Palarie palarie3("Milan", 34.5, 3, culori);
	palarie3.afisareStaticaPalarii();
	palarie3.afisarePalarii();
	culori = new string[3];
	culori[0] = "rosu";
	culori[1] = "albastru";
	culori[2] = "verde";

	culori = new string[5];
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
	
}