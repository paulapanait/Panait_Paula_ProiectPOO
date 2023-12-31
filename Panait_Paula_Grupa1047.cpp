#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

#define BLUE "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET "\033[0m"

class CorpCeresc
{
    string nume;
    int nrCC;
    string* cc;
public:
    virtual void descrieObiect() = 0;

    CorpCeresc()
    {
        this->nume = "Nume corp ceresc";
    }

    void setNume(string nume)
    {
        this->nume = nume;
    }

    string getNume()
    {
        return this->nume;
    }
};

class Planeta: public CorpCeresc
{
private:
    static int locSistem;
    float greutate;
    int nrSateliti;
    string* sateliti;

public:
    const int nrObservatii;
    string nume;

    void descrieObiect()
    {
        cout << "Planeta " << this->nume << " are o greutate de " << this->greutate << endl;
    }

    Planeta() : CorpCeresc(), nume(" "), nrSateliti(0), sateliti(NULL), nrObservatii(12)
    {
        locSistem++;
        this->nume = nume;
        this->greutate = greutate;
        this->nrSateliti = nrSateliti;
        this->sateliti = sateliti;
    }

    Planeta(float greutate) : CorpCeresc(), greutate(greutate), nrObservatii(12)
    {
        locSistem++;
        this->nume = "Marte";
        this->nrSateliti = 0;
        this->sateliti = NULL;
    }

    Planeta(string nume, float greutate) : CorpCeresc(), nrObservatii(12)
    {
        locSistem++;
        this->nume = nume;
        this->greutate = greutate;
        this->nrSateliti = 0;
        this->sateliti = NULL;
    }

    Planeta(string nume, float greutate, int nrSateliti, string* sateliti) : CorpCeresc(), nrObservatii(12)
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

    Planeta(const Planeta& nou) :CorpCeresc(nou), nrObservatii(nou.nrObservatii)
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
            CorpCeresc::operator=(p);
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

    friend ostream& operator<<(ostream& planeta, const Planeta& p)
    {
        planeta << "Nume: " << p.nume << endl;
        planeta << "Greutate: " << p.greutate << endl;
        planeta << "Numar sateliti: " << p.nrSateliti << endl;
        string sateliti = " ";
        planeta << "Nume sateliti: ";
        for (int i = 0; i < p.nrSateliti; i++)
        {
            planeta << p.sateliti[i] << " ";
        }
        cout << endl;
        return planeta;
    }

    friend istream& operator>>(istream& planeta, Planeta& p)
    {
        cout << "Nume: ";
        planeta >> p.nume;
        cout << endl;
        cout << "Greutate: ";
        planeta >> p.greutate;
        cout << endl;
        cout << "Numar sateliti: ";
        planeta >> p.nrSateliti;
        cout << endl;
        p.sateliti = new string[p.nrSateliti];
        cout << "Nume satelit: " << endl;
        for (int i = 0; i < p.nrSateliti; i++)
        {
            cout << "Satelitul " << i + 1 << ": " << endl;
            planeta >> p.sateliti[i];
            cout << endl;
        }
        cout << endl;
        return planeta;
    }

    const string& operator[](int index)
    {
        if (index <= 0 && index > nrSateliti)
        {
            throw out_of_range("Index invalid pentru sateliti");
        }
        return sateliti[index];
    }


    friend int afisareGreutate(const Planeta& p)
    {
        return p.greutate;
    }

    friend ofstream& operator<<(ofstream& out, const Planeta& planeta)
    {
        out << planeta.nume << endl;
        out << planeta.nrSateliti << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& is, Planeta& planeta)
    {
        is >> planeta.nume;
        cout << endl;
        is >> planeta.nrSateliti;
        cout << endl;
        return is;
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

class PlanetaTelurica : public Planeta
{
private:
    string tipuriRoci;
    string culori;
    string tipuriInvelisuri;
    string nume;

public:
    PlanetaTelurica() : Planeta("Pamant", 140000)
    {
        this->tipuriRoci = "vulcanice, sedimentare, carbonatice, metamorfice";
        this->culori = "albastru, verde, maro, alb";
        this->tipuriInvelisuri = "scoarta terestra, mantaua externa, mantaua interna, stratul nucleului extern, stratul nucleului intern";
    }

    PlanetaTelurica(string nume, string tipuriRoci, string culori, string tipuriInvelisuri) : Planeta()
    {
        this->nume = nume;
        this->tipuriRoci = tipuriRoci;
        this->culori = culori;
        this->tipuriInvelisuri = tipuriInvelisuri;
    }

    PlanetaTelurica(const PlanetaTelurica& pt) : Planeta()
    {
        this->nume = pt.nume;
        this->tipuriRoci = pt.tipuriRoci;
        this->culori = pt.culori;
        this->tipuriInvelisuri = pt.tipuriInvelisuri;
    }


    PlanetaTelurica operator=(const PlanetaTelurica& pt)
    {
        if (this != &pt)
        {
            Planeta ::operator=(pt);
            this->nume = pt.nume;
            this->tipuriRoci = pt.tipuriRoci;
            this->culori = pt.culori;
            this->tipuriInvelisuri = pt.tipuriInvelisuri;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& ecran, const PlanetaTelurica& pt)
    {
        ecran << (Planeta)pt << endl;
        ecran << "Nume: " << pt.nume << endl;
        ecran << "Tipuri roci: " << pt.tipuriRoci << endl;
        ecran << "Culori: " << pt.culori << endl;
        ecran <<"Tipuri invelisuri: " << pt.tipuriInvelisuri << endl;
        return ecran;
    }

    friend istream& operator>>(istream& tast, PlanetaTelurica& pt)
    {
        tast >> (Planeta&)pt;
        cout << "Nume: ";
        tast >> pt.nume;
        cout << "Tipuri roci: ";
        tast >> pt.tipuriRoci;
        cout << endl;
        cout << "Culori: ";
        tast >> pt.culori;
        cout << endl;
        cout << "Tipuri invelisuri: ";
        tast >> pt.tipuriInvelisuri;
        cout << endl;
        return tast;
    }

    void setRoci(string tipRocuriRoci)
    {
        this->tipuriRoci = tipuriRoci;
    }

    string getRoci()
    {
        return this->tipuriRoci;
    }

    void setInvelisuri(string tipuriInvelisuri)
    {
        this->tipuriInvelisuri = tipuriInvelisuri;
    }

    string getInvelisuri()
    {
        return this->tipuriInvelisuri;
    }
};

class VectorCC
{
    int nrCC;
    CorpCeresc** corpuriCeresti;

public:
    VectorCC()
    {
        this->nrCC = 10;
        this->corpuriCeresti = new CorpCeresc * [10];
        for (int i = 0; i < 10; i++)
        {
            this->corpuriCeresti[i] = new Planeta;
        }
    };

        CorpCeresc*& operator[](int i)
        {
            if (i >= 0 && i < this->nrCC)
            {
                return this->corpuriCeresti[i];
            }
        }
};

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

    Constelatie() : nume(" "), nrStele(0), nrNebuloase(0), nebuloase(NULL), nrObservatii(12)
    {
        nrObservatie++;
        this->nume = nume;
        this->nrStele = nrStele;
        this->nrNebuloase = 0;
        this->nebuloase = NULL;
    }

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

    friend ostream& operator<<(ostream& constelatie, const Constelatie& c)
    {
        constelatie << "Nume: " << c.nume << endl;
        constelatie << "Numar stele: " << c.nrStele << endl;
        constelatie << "Numar nebuloase: " << c.nrNebuloase << endl;
        string nebuloase = " ";
        constelatie << "Nume nebuloase: " << endl;
        for (int i = 0; i < c.nrNebuloase; i++)
        {
            constelatie << c.nebuloase[i] << " ";
            cout << endl;
        }
        cout << endl;
        return constelatie;
    }

    friend istream& operator>>(istream& constelatie, Constelatie& c)
    {
        cout << "Nume: ";
        constelatie >> c.nume;
        cout << endl;
        cout << "Numar stele: ";
        constelatie >> c.nrStele;
        cout << endl;
        cout << "Numar nebuloase: ";
        constelatie >> c.nrNebuloase;
        cout << endl;
        c.nebuloase = new string[c.nrNebuloase];
        cout << "Nume nebuloase: " << endl;
        for (int i = 0; i < c.nrNebuloase; i++) {
            cout << "Nebuloasa " << i + 1 << " " << endl;
            constelatie >> c.nebuloase[i];
            cout << endl;
        }
        cout << endl;
        return constelatie;
    }

    const string& operator[](int index)
    {
        if (index < 0 && index >= nrNebuloase)
        {
            throw out_of_range("Index invalid pentru nebuloase");
        }
        return nebuloase[index];
    }

    friend ofstream& operator<<(ofstream& out, const Constelatie& constelatie)
    {
        out << constelatie.nume << endl;
        out << constelatie.nrStele << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& is, Constelatie& constelatie)
    {
        is >> constelatie.nume;
        cout << endl;
        is >> constelatie.nrStele;
        cout << endl;
        return is;
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

class ConstelatieZodiacala : public Constelatie
{
private:
    char* constelatiiZodiacaleVecine;
    string ziAparitie;
    string ziDisparitie;
    string nume;

public:
    ConstelatieZodiacala() : Constelatie("Pesti")
    {
        /*mentionez ca datele au fost culese cu ajutorul soft-ului "Stellarium",
        motiv pentru care nu se potrivesc mereu celor oferite de astrologi,
        insa se bazeaza pe observatii astronomice si calcule astrofizice concrete,
        alaturi de posibile previziuni pentru urmatorii ani*/
        this->ziAparitie = "20 aprilie";
        this->ziDisparitie = "15 decembrie";
        this->constelatiiZodiacaleVecine = new char[strlen("Varsator si Berbec") + 1];
        strcpy_s(this->constelatiiZodiacaleVecine, strlen("Varsator si Berbec") + 1, "Varsator si Berbec");
    }

    ConstelatieZodiacala(string nume, string ziAparitie, string ziDisparitie, const char* constelatiiZodiacaleVecine) : Constelatie(getNume())
    {
        this->nume = nume;
        this->ziAparitie = ziAparitie;
        this->ziDisparitie = ziDisparitie;
        this->constelatiiZodiacaleVecine = new char[strlen(constelatiiZodiacaleVecine) + 1];
        strcpy_s(this->constelatiiZodiacaleVecine, strlen(constelatiiZodiacaleVecine) + 1, constelatiiZodiacaleVecine);
    }

    ConstelatieZodiacala(const ConstelatieZodiacala& cz) : Constelatie(cz)
    {
        this->nume = cz.nume;
        this->ziAparitie = cz.ziAparitie;
        this->ziDisparitie = cz.ziDisparitie;
        this->constelatiiZodiacaleVecine = new char[strlen(cz.constelatiiZodiacaleVecine) + 1];
        strcpy_s(this->constelatiiZodiacaleVecine, strlen(cz.constelatiiZodiacaleVecine) + 1, cz.constelatiiZodiacaleVecine);
    }

    ~ConstelatieZodiacala()
    {
        if (this->constelatiiZodiacaleVecine)
        {
            delete[]this->constelatiiZodiacaleVecine;
        }
    }

    ConstelatieZodiacala operator=(const ConstelatieZodiacala& cz)
    {
        if (this != &cz)
        {
            Constelatie ::operator=(cz);
            this->nume = cz.nume;
            this->ziAparitie = cz.ziAparitie;
            this->ziDisparitie = cz.ziDisparitie;
            if (this->constelatiiZodiacaleVecine) {
                delete[]this->constelatiiZodiacaleVecine;
            }
            this->constelatiiZodiacaleVecine = new char[strlen(cz.constelatiiZodiacaleVecine) + 1];
            strcpy_s(this->constelatiiZodiacaleVecine, strlen(cz.constelatiiZodiacaleVecine) + 1, cz.constelatiiZodiacaleVecine);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& ecran, const ConstelatieZodiacala& cz)
    {
        ecran << (Constelatie)cz << endl;
        ecran << "Nume: " << cz.nume << endl;
        ecran << "Zi aparitie: " << cz.ziAparitie << endl;
        ecran << "Zi disparitie: " << cz.ziDisparitie << endl;
        ecran << "Constelatii zodiacale vecine: " << cz.constelatiiZodiacaleVecine << endl;
        return ecran;
    }

    friend istream& operator>>(istream& tast, ConstelatieZodiacala& cz)
    {
        tast >> (Constelatie&)cz;
        cout << "Nume: ";
        tast >> cz.nume;
        cout << "Zi aparitie: ";
        tast >> cz.ziAparitie;
        cout << "Zi disparitie: ";
        tast >> cz.ziDisparitie;
        if (cz.constelatiiZodiacaleVecine)
        {
            delete[]cz.constelatiiZodiacaleVecine;
        }
        cout << "Constelatii zodiacale vecine:";
        char buffer[30];
        tast >> buffer;
        cz.constelatiiZodiacaleVecine = new char[strlen(buffer) + 1];
        strcpy_s(cz.constelatiiZodiacaleVecine, strlen(buffer) + 1, buffer);
        return tast;
    }

    void setZiAparitie(string ziAparitie)
    {
        this->ziAparitie = ziAparitie;
    }

    string getZiAparitie()
    {
        return this->ziAparitie;
    }

    void setZiDisparitie(string ziDisparitie)
    {
        this->ziDisparitie = ziDisparitie;
    }

    string getZiDisparitie()
    {
        return this->ziDisparitie;
    }
};

class Univers
{
    string nume;
public:
    virtual void descrieObiectul() = 0;
    
    Univers()
    {
        this->nume = "Galaxie";
    }

    string getNume()
    {
        return this->nume;
    }

    void setNume(string nume)
    {
        this->nume = nume;
    }
};

class Galaxie: public Univers
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

    void descrieObiectul()
    {
        cout << "Galaxia " << this->nume << " are o lungime de " << this->lungime << endl;
    }

    Galaxie() : Univers(), nume(" "), nrObiecte(0), lungime(0), spirala(0), nrBrate(0), brate(NULL), nrObservatii(12)
    {
        nrObservatie++;
        this->nume = nume;
        this->nrObiecte = nrObiecte;
        this->lungime = lungime;
        this->nrBrate = nrBrate;
        this->brate = brate;
        this->spirala = spirala;
    }

    Galaxie(string nume) : Univers(), nrObservatii(3)
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

    Galaxie(string nume, int nrBrate, string* brate) : Univers(), nrObservatii(3)
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

    Galaxie(const Galaxie& nou) : Univers(nou), nrObservatii(nou.nrObservatii)
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
            Univers::operator=(g);
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
        galaxie << "Numar brate: " << g.nrBrate << endl;
        string brate = " ";
        galaxie << "Nume brate: " << endl;
        for (int i = 0; i < g.nrBrate; i++)
        {
            galaxie << g.brate[i] << " ";
            cout << endl;
        }
        cout << endl;
        return galaxie;
    }

    friend istream& operator>>(istream& galaxie, Galaxie& g) {
        cout << "Nume: ";
        galaxie >> g.nume;
        cout << endl;
        cout << "Lungime: ";
        galaxie >> g.lungime;
        cout << endl;
        g.brate = new string[g.nrBrate];
        cout << "Nume brate: " << endl;
        for (int i = 0; i < g.nrBrate; i++)
        {
            cout << "Bratul " << i + 1 << ": " << endl;
            galaxie >> g.brate[i];
            cout << endl;
        }
        cout << endl;
        return galaxie;
    }

    const string& operator[](int index) const
    {
        if (index < 0 && index >= nrBrate)
        {
            throw out_of_range("Index invalid pentru brate");
        }
        return brate[index];
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

void citesteMatrice(int matrice[][100], int nrLinii, int nrColoane) {
    cout << "Introduceti elementele matricei: " << endl;
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            cout << "Elementul [" << i << "][" << j << "]: ";
            cin >> matrice[i][j];
        }
    }
}

class VectorU
{
    int nrU;
    Univers** corpuriU;

public:
    VectorU()
    {
        this->nrU = 10;
        this->corpuriU = new Univers * [10];
        for (int i = 0; i < 10; i++)
        {
            this->corpuriU[i] = new Galaxie;
        }
    };

    Univers*& operator[](int i)
    {
        if (i >= 0 && i < this->nrU)
        {
            return this->corpuriU[i];
        }
    }
};

class Observatii {
private:
    string numeObservator;
    int anObservatie;
    Galaxie galaxie;

public:
    Observatii(string numeObservator, int an, const Galaxie& g)
    {
        this->numeObservator = numeObservator;
        this->anObservatie = an;
        this->galaxie = g;
    }

    int ObsGalaxie()
    {
        cout << "Galaxia " << galaxie.nume << " a fost observata de " << numeObservator << " in anul ";
        return anObservatie;
    }

    Galaxie getGalaxie()
    {
        return galaxie;
    }

    int getAnObs()
    {
        return anObservatie;
    }

    string getObs()
    {
        return numeObservator;
    }

    void setObs(string numeobs)
    {
        this->numeObservator = numeobs;
    }

    void setAnObs(int anobs)
    {
        this->anObservatie = anobs;
    }

    void setGalaxie(Galaxie& glx)
    {
        this->galaxie = glx;
    }

    Observatii operator=(const Observatii& oe)
    {
        if (this != &oe) {
            this->numeObservator = oe.numeObservator;
            this->anObservatie = oe.anObservatie;
            this->galaxie = oe.galaxie;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Observatii& o)
    {
        out << "Numele observatorului: " << o.numeObservator << endl;
        out << "Anul observatiei: " << o.anObservatie << endl;
        out << "Informatii despre galaxia observata: " << o.galaxie << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Observatii& o)
    {
        cout << "Numele observatorului : ";
        in >> o.numeObservator;
        cout << endl;
        cout << "Anul Observatiei: ";
        in >> o.anObservatie;
        cout << endl;
        cout << "Introduceti datele galaxiei observate: ";
        in >> o.galaxie;
        cout << endl;
        return in;
    }
};

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

    Constelatie c1("Carul_Mare");
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
    Constelatie c7 = c1 - c2;
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
    cout << " " << endl;
    cout << GREEN << "Functia friend: " << RESET << endl;
    cout << " " << endl;
    cout << "Afisare greutate p1: ";
    cout << afisareGreutate(p1);
    cout << " " << endl;
    cout << " " << endl;

    cout << GREEN << "Vectorii: " << RESET << endl;

    const int numar_obiecteP = 2;
    vector <Planeta> vectorPlanete(numar_obiecteP);

    for (int i = 0; i < numar_obiecteP; ++i) {
        cout << "Introduceti datele pentru obiectul Planeta la pozitia " << i << endl;
        cin >> vectorPlanete[i];
    }
    cout << endl << endl;
    for (int i = 0; i < numar_obiecteP; ++i) {
        cout << "Afisare obiect Planeta la pozitia " << i << endl;
        cout << vectorPlanete[i] << endl;
    }

    const int numar_obiecteC = 2;
    vector <Constelatie> vectorConstelatii(numar_obiecteC);

    for (int i = 0; i < numar_obiecteC; ++i) {
        cout << "Introduceti datele pentru obiectul Constelatie la pozitia " << i << endl;
        cin >> vectorConstelatii[i];
    }
    cout << endl << endl;
    for (int i = 0; i < numar_obiecteC; ++i) {
        cout << "Afisare obiect Constelatie la pozitia " << i << endl;
        cout << vectorConstelatii[i] << endl;
    }

    const int numar_obiecteG = 2;
    vector <Galaxie> vectorGalaxie(numar_obiecteG);

    for (int i = 0; i < numar_obiecteG; ++i) {
        cout << "Introduceti datele pentru obiectul Galaxie la pozitia " << i << endl;
        cin >> vectorPlanete[i];
    }
    cout << endl << endl;
    for (int i = 0; i < numar_obiecteG; ++i) {
        cout << "Afisare obiect Galaxie la pozitia " << i << endl;
        cout << vectorPlanete[i] << endl;
    }

    cout << GREEN << "Matricea: " << RESET << endl;
    cout << " " << endl;

    const int numar_linii = 2;
    const int numar_coloane = 2;

    Planeta matricePlanete[numar_linii][numar_coloane];

    for (int i = 0; i < numar_linii; ++i)
    {
        for (int j = 0; j < numar_coloane; ++j)
        {
            cout << "Introduceti datele pentru obiectul Planeta la pozitia [" << i << "][" << j << "]" << endl;
            cin >> matricePlanete[i][j];
            cout << endl;
        }
    }

    for (int i = 0; i < numar_linii; ++i)
    {
        for (int j = 0; j < numar_coloane; ++j)
        {
            cout << "Afisare obiect Planeta la pozitia [" << i << "][" << j << "]" << endl;
            cout << matricePlanete[i][j] << endl;
        }
    }

    Observatii observ1("KOKO", 1983, g2);
    cout << observ1.getGalaxie() << endl;
    cout << observ1.ObsGalaxie() << endl;
    cout << observ1.getAnObs() << endl;
    cout << observ1.getObs() << endl;

    Observatii observ2("Emiron", 2006, g3);

    Observatii observ3("Gakin", 1997, g1);
    observ3 = observ2;

    cout << observ2 << endl;
    cin >> observ2;
    cout << observ2 << endl;

    ofstream afisarePlaneta("Planeta.txt", ios::out);
    afisarePlaneta << p1;
    afisarePlaneta.close();

    ifstream citirePlaneta("Planeta.txt", ios::in);
    citirePlaneta >> p2;
    cout << p2;
    citirePlaneta.close();

    ofstream afisareConstelatie("Constelatie.txt", ios::out);
    afisareConstelatie << c1;
    afisareConstelatie.close();

    ifstream citireConstelatie("Constelatie.txt", ios::in);
    citireConstelatie >> c2;
    cout << c2;
    citireConstelatie.close();

    int nrBrate = 2;
    char sir[100] = "text salvat in fisier binar";

    fstream f("Galaxie.bin", ios::out | ios::binary);

    f.write((char*)&nrBrate, sizeof(int));
    int lungimeg = strlen(sir) + 1;
    f.write((char*)&lungimeg, sizeof(int));
    f.write((char*)sir, lungimeg);
    f.close();

    fstream g("Observatie.bin", ios::binary | ios::out);

    g.write((char*)&nrBrate, sizeof(int));
    int lungimeo = strlen(sir) + 1;
    g.write((char*)&lungimeo, sizeof(int));
    g.write((char*)sir, lungimeo);
    g.close();

    PlanetaTelurica pt1;
    PlanetaTelurica pt2("Venus", "vulcanice", "rosu, galben, portocaliu, maro", "nucleu, manta, crusta");
    PlanetaTelurica pt3 = pt1;
    PlanetaTelurica pt4;
    pt4 = pt2;

    cout << pt1 << pt2 << pt3 << pt4 << endl;
    cin >> pt2;
    cout << pt2 << endl;

    ConstelatieZodiacala cz1;
    ConstelatieZodiacala cz2("Scorpion", "1 ianuarie", "1 octombrie", "Sagetator si Balanta");
    ConstelatieZodiacala cz3 = cz1;
    ConstelatieZodiacala cz4;
    cz4 = cz2;

    cout << cz1 << cz2 << cz3 << cz4 << endl;
    cin >> cz2;
    cout << cz2 << endl;

    Constelatie* constelatiePtr = &cz2;

    constelatiePtr->afisareConstelatie();

    Planeta p10;
    p10.descrieObiect();

    Galaxie g10;
    g10.descrieObiectul();

    CorpCeresc* cc;
    cc = new Planeta();
    cc->descrieObiect();

    Univers* u;
    u = new Galaxie();
    u->descrieObiectul();

    VectorCC v1;
    v1[0] = new Planeta("Mercur", 10736);
    v1[1] = new Planeta("Venus", 22349483173);
    v1[2] = new Planeta("Pamant", 302857);
    v1[3] = new Planeta("Marte", 46392);
    v1[4] = new Planeta("Jupiter", 230493256);
    v1[5] = new Planeta("Saturn", 4694325263);
    v1[6] = new Planeta("Uranus", 403832467);
    v1[7] = new Planeta("Neptun", 5830384);
    v1[8] = new Planeta("Makemake", 4638);
    v1[9] = new Planeta("Eris", 4738);

    VectorU u1;
    u1[0] = new Galaxie("Calea_Lactee");
    u1[1] = new Galaxie("Andromeda");
    u1[2] = new Galaxie("Antennae");
    u1[3] = new Galaxie("Retrograda");
    u1[4] = new Galaxie("Bode");
    u1[5] = new Galaxie("Fluture");
    u1[6] = new Galaxie("Trabuc");
    u1[7] = new Galaxie("Compasul");
    u1[8] = new Galaxie("Cometa");
    u1[9] = new Galaxie("Artificiilor");
};
