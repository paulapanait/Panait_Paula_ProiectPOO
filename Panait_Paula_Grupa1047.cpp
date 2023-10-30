#include <iostream>
#include <string>
using namespace std;

#define BLUE "\033[34m"
#define GREEN   "\033[32m"
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

void prelucrareAstronomica3(const Galaxie& galaxie)
{
    cout << GREEN << "Prelucrare 3 cu galaxia " << galaxie.nume << RESET << endl;
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
    nebuloaseNoi[0] = "Nebuloasa Veil";
    nebuloaseNoi[1] = "Nebuloasa North America";
    constelatie1.setNebuloase(2, nebuloaseNoi);

    cout << "Nume constelatie dupa modificare: " << constelatie1.getNume() << endl;
    cout << "Numar stele dupa modificare: " << constelatie1.getNrStele() << endl;
    cout << "Numar nebuloase dupa modificare: " << constelatie1.getNrNebuloase() << endl;
    cout << " " << endl;

    prelucrareAstronomica3(g3);

    Galaxie galaxie1("Calea Lactee");
    cout << "Nume galaxie: " << galaxie1.getNume() << endl;
    cout << "Numar obiecte: " << galaxie1.getNrObiecte() << endl;
    cout << "Lungime: " << galaxie1.getLungime() << endl;
    cout << "Numar brate: " << galaxie1.getNrBrate() << endl;
    cout << " " << endl;

    galaxie1.setNume();
    galaxie1.setNrObiecte(40000);
    galaxie1.setLungime(15000);
    galaxie1.setNrBrate(3);
    string* brateNoi = new string[3];
    brateNoi[0] = "Brat1";
    brateNoi[1] = "Brat2";
    brateNoi[2] = "Brat3";
    galaxie1.setBrate(3, brateNoi);

    cout << "Nume galaxie dupa modificare: " << galaxie1.getNume() << endl;
    cout << "Numar obiecte dupa modificare: " << galaxie1.getNrObiecte() << endl;
    cout << "Lungime dupa modificare: " << galaxie1.getLungime() << endl;
    cout << "Numar brate dupa modificare: " << galaxie1.getNrBrate() << endl;
    cout << " " << endl;
}
