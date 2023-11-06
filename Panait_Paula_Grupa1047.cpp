#include <iostream>
#include <string>
using namespace std;

#define BLUE "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET "\033[0m"

class Planeta
{
private:
    static int locSistem;
    float greutate;
    int nrSateliti;
    string* sateliti;

public:
    const int nrObservatii;
    string nume;

    Planeta(float greutate) : greutate(greutate), nrObservatii(12)
    {
        locSistem++;
        this->nume = "Marte";
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
        for (int i = 0; i < nrSateliti; i++)
        {
            this->sateliti[i] = sateliti[i];
        }
    }

    Planeta(const Planeta& nou) : nrObservatii(nou.nrObservatii)
    {
        locSistem++;
        this->nume = nou.nume;
        this->greutate = nou.greutate;
        this->nrSateliti = nou.nrSateliti;
        this->sateliti = new string[nrSateliti];
        for (int i = 0; i < nrSateliti; i++)
        {
            this->sateliti[i] = nou.sateliti[i];
        }
    }

    ~Planeta()
    {
        delete[] this->sateliti;
    }

    string getNume() const
    {
        return nume;
    }

    void setNume(string nume)
    {
        this->nume = nume;
    }

    float getGreutate() const
    {
        return greutate;
    }

    void setGreutate(float greutate)
    {
        this->greutate = greutate;
    }

    int getNrSateliti() const
    {
        return nrSateliti;
    }

    void setNrSateliti(int nrSateliti) 
    {
        this->nrSateliti = nrSateliti;
    }

    string* getSateliti() const
    {
        return sateliti;
    }

    void setSateliti(int nrSateliti, string* sateliti)

    {
        delete[] this->sateliti;
        this->nrSateliti = nrSateliti;
        this->sateliti = new string[nrSateliti];
        for (int i = 0; i < nrSateliti; i++)
        {
            this->sateliti[i] = sateliti[i];
        }
    }

    Planeta operator=(const Planeta& p)
    {
        if (this != &p)
        {
            this->nume = p.nume;
            this->greutate = p.greutate;
            this->nrSateliti = p.nrSateliti;
            this->sateliti = p.sateliti;
            if (this->nrSateliti != NULL)
            {
                delete[]this->sateliti;
            }
            for (int i = 0; i < p.nrSateliti; i++)
            {
                this->sateliti[i] = p.sateliti[i];
            }
        }
        return *this;
    }

    Planeta operator+(const Planeta& p)
        const {
        Planeta aux = *this;
        aux.nume = this->nume + " si " + p.nume;
        aux.greutate = this->greutate + p.greutate;
        aux.nrSateliti = this->nrSateliti + p.nrSateliti;
        if (aux.sateliti != NULL)
        {
            delete[]aux.sateliti;
        }
        aux.sateliti = new string[nrSateliti];
        for (int i = 0; i < nrSateliti; i++)
        {
            aux.sateliti[i] = this->sateliti[i];
        }
        for (int i = this->nrSateliti; i < aux.nrSateliti; i++)
        {
            aux.sateliti[i] = p.sateliti[i - this->nrSateliti];
        }

        return aux;
    }

    Planeta operator*(const Planeta& p)
    {
        Planeta aux = *this;
        aux.nume = this->nume + " si " + p.nume;
        aux.greutate = this->greutate * p.greutate;
        aux.nrSateliti = this->nrSateliti * p.nrSateliti;
        if (aux.sateliti != NULL)
        {
            delete[]aux.sateliti;
        }
        aux.sateliti = new string[nrSateliti];
        for (int i = 0; i < nrSateliti; i++)
        {
            aux.sateliti[i] = this->sateliti[i];
        }
        for (int i = this->nrSateliti; i < aux.nrSateliti; i++)
        {
            aux.sateliti[i] = p.sateliti[i - this->nrSateliti];
        }

        return aux;
    }

    Planeta operator/(const Planeta& p)
    {
        Planeta aux = *this;
        aux.nume = this->nume + " si " + p.nume;
        aux.greutate = this->greutate / p.greutate;
        aux.nrSateliti = this->nrSateliti / p.nrSateliti;
        if (aux.sateliti != NULL)
        {
            delete[]aux.sateliti;
        }
        aux.sateliti = new string[nrSateliti];
        for (int i = 0; i < nrSateliti; i++)
        {
            aux.sateliti[i] = this->sateliti[i];
        }
        for (int i = this->nrSateliti; i < aux.nrSateliti; i++)
        {
            aux.sateliti[i] = p.sateliti[i - this->nrSateliti];
        }

        return aux;
    }

    friend int afisareGreutate(const Planeta& p)
    {
        return p.greutate;
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

        if (nrSateliti != 0)
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

int Planeta::locSistem = 0;

class Constelatie
{
private:
    static int nrObservatie;
    float nrStele;
    int nrNebuloase;
    string* nebuloase;

public:
    const int nrObservatii;
    string nume;

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

    Constelatie(const Constelatie& nou) : nrObservatii(nou.nrObservatii)
    {
        nrObservatie++;
        this->nume = nou.nume;
        this->nrStele = nou.nrStele;
        this->nrNebuloase = nou.nrNebuloase;
        this->nebuloase = new string[nrNebuloase];
        for (int i = 0; i < nrNebuloase; i++)
        {
            this->nebuloase[i] = nou.nebuloase[i];
        }
    }

    ~Constelatie()
    {
        delete[] nebuloase;
    }

    string getNume() const
    {
        return nume;
    }

    void setNume()
    {
        this->nume = nume;
    }

    float getNrStele() const
    {
        return nrStele;
    }
    
    void setNrStele(float nrStele)
    {
        this->nrStele = nrStele;
    }

    int getNrNebuloase() const
    { 
        return nrNebuloase;
    }
    
    void setNrNebuloase(int nrNebuloase)
    {
        this->nrNebuloase = nrNebuloase;
    }

    string* getNebuloase() const
    {
        return nebuloase;
    }

    void setNebuloase(int nrNebuloase, string* nebuloase)
    {
        delete[] this->nebuloase;
        this->nrNebuloase = nrNebuloase;
        this->nebuloase = new string[nrNebuloase];
        for (int i = 0; i < nrNebuloase; i++)
        {
            this->nebuloase[i] = nebuloase[i];
        }
    }

    Constelatie operator=(const Constelatie& c)
    {
        if (this != &c)
        {
            this->nume = c.nume;
            this->nrStele = c.nrStele;
            this->nrNebuloase = c.nrNebuloase;
            this->nebuloase = c.nebuloase;
            if (this->nrNebuloase != NULL)
            {
                delete[]this->nebuloase;
            }
            for (int i = 0; i < c.nrNebuloase; i++)
            {
                this->nebuloase[i] = c.nebuloase[i];
            }
        }
        return *this;
    }

    Constelatie operator-(const Constelatie& c)
    {
        Constelatie aux = *this;
        aux.nume = this->nume + " si " + c.nume;
        aux.nrStele = this->nrStele - c.nrStele;
        aux.nrNebuloase = this->nrNebuloase - c.nrNebuloase;
        if (aux.nebuloase != NULL)
        {
            delete[]aux.nebuloase;
        }
        aux.nebuloase = new string[nrNebuloase];
        for (int i = 0; i < nrNebuloase; i++)
        {
            aux.nebuloase[i] = this->nebuloase[i];
        }
        for (int i = this->nrNebuloase; i < aux.nrNebuloase; i++)
        {
            aux.nebuloase[i] = c.nebuloase[i - this->nrNebuloase];
        }

        return aux;
    }

    bool operator<(Constelatie c)
    {
        return this->nrStele < c.nrStele;
    }

    bool operator!=(Constelatie c)
    {
        return this->nrNebuloase != c.nrNebuloase;
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

        if (nrNebuloase != 0)
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
private:
    static int nrObservatie;
    int nrObiecte;
    float lungime;
    bool spirala;
    int nrBrate;
    string* brate;

public:
    const int nrObservatii;
    string nume;

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
        this->nume = nume;
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

    Galaxie(const Galaxie& nou) : nrObservatii(nou.nrObservatii)
    {
        nrObservatie++;
        this->nume = nou.nume;
        this->lungime = nou.lungime;
        this->nrObiecte = nou.nrObiecte;
        this->spirala = nou.spirala;
        this->nrBrate = nou.nrBrate;
        this->brate = new string[nrBrate];
        for (int i = 0; i < nrBrate; i++)
        {
            this->brate[i] = nou.brate[i];
        }
    }

    ~Galaxie()
    {
        delete[] brate;
    }

    string getNume() const
    {
        return nume;
    }

    void setNume()
    {
        this->nume = nume;
    }

    int getNrObiecte() const
    {
        return nrObiecte; 
    }

    void setNrObiecte(int nrObiecte)
    {
        this->nrObiecte = nrObiecte;
    }

    float getLungime() const
    {
        return lungime;
    }

    void setLungime(float lungime)
    {
        this->lungime = lungime;
    }

    bool getSpirala() const
    {
        return spirala;
    }

    void setSpirala(bool spirala)
    {
        this->spirala = spirala;
    }

    int getNrBrate() const
    {
        return nrBrate;
    }

    void setNrBrate(int nrBrate)
    {
        this->nrBrate = nrBrate;
    }

    string* getBrate() const
    {
        return brate;
    }

    void setBrate(int nrBrate, string* brate)
    {
        delete[] this->brate;
        this->nrBrate = nrBrate;
        this->brate = new string[nrBrate];
        for (int i = 0; i < nrBrate; i++)
        {
            this->brate[i] = brate[i];
        }
    }

    Galaxie operator=(const Galaxie& g)
    {
        if (this != &g)
        {
            this->nume = g.nume;
            this->lungime = g.lungime;
            this->nrObiecte = g.nrObiecte;
            this->spirala = g.spirala;
            this->nrBrate = g.nrBrate;
            if (this->nrBrate != NULL)
            {
                delete[]this->brate;
            }
            this->brate = new string[g.nrBrate];
            for (int i = 0; i < g.nrBrate; i++)
            {
                this->brate[i] = g.brate[i];
            }
        }
        return *this;
    }

    bool operator<=(Galaxie g)
    {
        return this->lungime < g.lungime;
    }
      
    friend ostream& operator<<(ostream& galaxie, const Galaxie& g) {
        galaxie << "Nume: " << g.nume << endl;
        galaxie << "Lungime: " << g.lungime << endl;
        galaxie << "mii de ani lumina" << endl;
        return galaxie;
    }

    friend istream& operator>>(istream& galaxie, Galaxie& g) {
        cout << "Nume: ";
        galaxie >> g.nume;
        cout << "Lungime: ";
        galaxie >> g.lungime;
        cout << "mii de ani lumina " << endl;
        return galaxie;
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

        if (nrBrate != 0)
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

void prelucrareAstronomica1(const Planeta& planeta)
{
    cout << GREEN << "Prelucrare 1 cu planeta " << planeta.nume << RESET << endl;
    cout << " " << endl;
}

void prelucrareAstronomica2(const Constelatie& constelatie)
{
    cout << GREEN << "Prelucrare 2 cu constelatia " << constelatie.nume << RESET << endl;
    cout << " " << endl;
}

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
    c2.afisareConstelatie();

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

    prelucrareAstronomica1(p1);

    Planeta planeta1(6000);
    cout << "Nume planeta: " << planeta1.getNume() << endl;
    cout << "Greutate: " << planeta1.getGreutate() << endl;
    cout << "Numar sateliti: " << planeta1.getNrSateliti() << endl;
    cout << " " << endl;

    planeta1.setNume("Marte");
    planeta1.setGreutate(7000);
    planeta1.setNrSateliti(2);
    string* sateliti = new string[2];
    sateliti[0] = "Phobos";
    sateliti[1] = "Deimos";
    planeta1.setSateliti(2, sateliti);

    cout << "Nume planeta dupa modificare: " << planeta1.getNume() << endl;
    cout << "Greutate dupa modificare: " << planeta1.getGreutate() << endl;
    cout << "Numar sateliti dupa modificare: " << planeta1.getNrSateliti() << endl;
    cout << "Nume sateliti dupa modificare: " << endl;
    string* numeSateliti = planeta1.getSateliti();
    for (int i = 0; i < planeta1.getNrSateliti(); ++i)
    {
        cout << numeSateliti[i] << endl;
    }
    cout << " " << endl;

    prelucrareAstronomica2(c2);

    Constelatie constelatie1("Carul Mare");
    cout << "Nume constelatie: " << constelatie1.getNume() << endl;
    cout << "Numar stele: " << constelatie1.getNrStele() << endl;
    cout << "Numar nebuloase: " << constelatie1.getNrNebuloase() << endl;
    cout << " " << endl;

    constelatie1.setNume();
    constelatie1.setNrStele(100);
    constelatie1.setNrNebuloase(5);
    string* nebuloaseNoi = new string[2];
    nebuloaseNoi[0] = "Nebuloasa 'Veil'";
    nebuloaseNoi[1] = "Nebuloasa 'North America'";
    constelatie1.setNebuloase(2, nebuloaseNoi);

    cout << "Nume constelatie dupa modificare: " << constelatie1.getNume() << endl;
    cout << "Numar stele dupa modificare: " << constelatie1.getNrStele() << endl;
    cout << "Numar nebuloase dupa modificare: " << constelatie1.getNrNebuloase() << endl;
    cout << "Nume nebuloase dupa modificare:  " << endl;
    string* numeNebuloase = constelatie1.getNebuloase();
    for (int i = 0; i < constelatie1.getNrNebuloase(); ++i)
    {
        cout << numeNebuloase[i] << endl;
    }

    cout << " " << endl;

    Planeta p5 = p1;
    cout << "Planeta 5 este o copie a planetei 1: " << endl;
    p5.afisareStaticaPlaneta();
    p5.afisarePlaneta();
    cout << endl;

    cout << GREEN << "OPERATORI: " << RESET << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << YELLOW << "Operatorul '=' pentru clasa 'Planeta': " << RESET << endl;
    cout << " " << endl;
    Planeta p6(8000);
    p6 = p1;
    p6.afisareStaticaPlaneta();
    p6.afisarePlaneta();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '+' pentru clasa 'Planeta': " << RESET << endl;
    Planeta p7 = p1 + p2;
    p7.afisareStaticaPlaneta();
    p7.afisarePlaneta();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '*' pentru clasa 'Planeta': " << RESET << endl;
    Planeta p8 = p1 * p2;
    p8.afisareStaticaPlaneta();
    p8.afisarePlaneta();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '/' pentru clasa 'Planeta': " << RESET << endl;
    Planeta p9 = p2 / p3;
    p9.afisareStaticaPlaneta();
    p9.afisarePlaneta();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '=' pentru clasa 'Constelatie': " << RESET << endl;
    cout << " " << endl;
    Constelatie c6("Scorpio");
    c6 = c1;
    c6.afisareStaticaConstelatie();
    c6.afisareConstelatie();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '-' pentru clasa 'Constelatie': " << RESET << endl;
    cout << " " << endl;
    Constelatie c7=c1-c2;
    c7.afisareStaticaConstelatie();
    c7.afisareConstelatie();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '<' pentru clasa 'Constelatie': " << RESET << endl;
    cout << " " << endl;
    bool c8 = c1 < c2;
    cout << (c8 ? "Constelatia 1 are un numar mai mare de stele decat constelatia 2" : "Constelatia 1 are un numar mai mic de stele decat constelatia 2") << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << YELLOW << "Operatorul '!=' pentru clasa 'Constelatie': " << RESET << endl;
    cout << " " << endl;
    bool c9 = c1 != c2;
    cout << (c9 ? "Constelatia 1 are un numar diferit de nebuloase fata de constelatia 2" : "Constelatia 1 are acelasi numar de nebuloase precum constelatia 2") << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << YELLOW << "Operatorul '=' pentru clasa 'Galaxie': " << RESET << endl;
    cout << " " << endl;
    Galaxie g6("Compasul");
    g6 = g1;
    g6.afisareStaticaGalaxie();
    g6.afisareGalaxie();
    cout << " " << endl;
    cout << YELLOW << "Operatorul '<=' pentru clasa 'Galaxie': " << RESET << endl;
    cout << " " << endl;
    bool g7 = g1 <= g2;
    cout << (g7 ? "Galaxia 1 are o lungime mai mica sau egala cu lungimea galaxiei 2." : "Galaxia 1 are o lungime mai mare strict decat lungimea galaxiei 2.");
    cout << " " << endl;
    cout << " " << endl;
    cout << YELLOW << "Operatorul '<<' pentru clasa 'Galaxie': " << RESET << endl;
    cout << " " << endl;
    Galaxie g8("Fluturelui");
    cout << g8;
    cout << " " << endl;
    cout << YELLOW << "Operatorul '>>' pentru clasa 'Galaxie': " << RESET << endl;
    cout << " " << endl;
    Galaxie g9("Fluturelui");
    cin >> g9;
    cout << " " << endl;
    cout << GREEN << "Functia friend: " << RESET << endl;
    cout << "Afisare greutate p1: ";
    cout << afisareGreutate(p1);
    cout << " " << endl;
}
