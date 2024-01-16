#include <iostream>
#include <fstream>
using namespace std;

//Domeniul ales este "Complex de apartamente".

class BlocComercial //clasa abstracta 1; class nr. 7
{
private:
    string nume;
    int suprafata;
public:

    virtual ~BlocComercial()
    {

    }

    virtual void areFoodCourt() = 0; //afiseaza daca complexul comercial are zona de mancare sau nu
    virtual void prezBlocCo() = 0; //afiseaza locatia si magazinele aflate

    BlocComercial()
    {
        this->nume = "Winmarkt";
        this->suprafata = 44;
    }
};

class AirBnb //clasa abstracta 2; class nr. 8
{
private:
    string nume;
    int PretNoapte;
public:

    virtual ~AirBnb()
    {

    }

    virtual int numarCazati() = 0; //afiseaza cate persoane permite cazarea
    virtual void cateCamereRezerv() = 0; //afiseaza cate camere sunt disponibile pentru un sejur

    AirBnb()
    {
        this->nume = "Dya's Home";
        this->PretNoapte = 220;
    }
};

class Apartament : public AirBnb //Clasa primara 1
{
private:
    int suprafata; //suprafata apartamentului
    int nrCamere; 
    int* costuriAp; //costuri precum intretinerea
    const int nrMaxPers; //nr max persoane permise in ap
    static int nrTotalAp;

public:

    virtual void cateCamereRezerv() //functie virtuala a clasei AirBnb
    {
        cout << "La aceasta cazare se pot rezerva " << this->nrCamere << " camere";
    }

    virtual int numarCazati() //functie virtuala a clasei AirBnb
    {
        return this->nrMaxPers;
    }

    Apartament() : nrMaxPers(4) //constructor fara parametrii
    {
        this->suprafata = 52;
        this->nrCamere = 2;
        this->costuriAp = new int[this->nrCamere]();
        for (int i = 0; i < this->nrCamere; i++)
            this->costuriAp[i] = costuriAp[i];
    }

    Apartament(int suprafata, int nrCamere, const int nr, int* costuriAp) :nrMaxPers(nr) //constructor cu toti parametrii
    {
        this->suprafata = suprafata;
        this->nrCamere = nrCamere;
        this->costuriAp = new int[this->nrCamere]();
        for (int i = 0; i < this->nrCamere; i++)
        {
            this->costuriAp[i] = costuriAp[i];
        }
    }

    Apartament(int suprafata, const int nr, int* costuriAp) :nrMaxPers(nr) //constructor cu 3 parametrii
    {
        this->suprafata = suprafata;
        this->nrCamere = 1;
        this->costuriAp = new int[this->nrCamere]();
        for (int i = 0; i < this->nrCamere; i++)
        {
            this->costuriAp[i] = costuriAp[i];
        }
    }

    void afisareAp() //functie pentru afisarea unui obiect al clasei
    {
        cout << "Suprafata: " << this->suprafata << " mp2" << "\nNumar de camere: " << this->nrCamere
            << "\nNumar maxim de persoane: " << this->nrMaxPers << "\nIn complex se afla: " << this->nrTotalAp
            << " de apartamente" << "\nCosturi apartamente:";
        for (int i = 0; i < this->nrCamere - 1; i++)
        {
            cout << this->costuriAp[i] << ", ";
        }

        cout << this->costuriAp[this->nrCamere - 1] << endl;
    }

    ~Apartament() //destructor
    {
        if (this->costuriAp != nullptr)
        {
            delete[] this->costuriAp;
            this->costuriAp = nullptr;
        }
    }

    Apartament(const Apartament& a) : nrMaxPers(a.nrMaxPers) //constructor copiere
    {
        this->suprafata = a.suprafata;
        this->nrCamere = a.nrCamere;
        this->nrTotalAp = a.nrTotalAp;
        this->costuriAp = a.costuriAp;

        if (nrCamere > 0)
        {
            this->costuriAp = new int[nrCamere];
            for (int i = 0; i < nrCamere; i++)
            {
                this->costuriAp[i] = a.costuriAp[i];
            }
        }
    }

    Apartament& operator=(const Apartament& a) //op atribuire
    {
        if (this != &a) {
            this->suprafata = a.suprafata;
            this->nrCamere = a.nrCamere;
            if (this->costuriAp != NULL) {
                delete[]this->costuriAp;
            }

            this->costuriAp = new int[this->nrCamere];

            for (int i = 0; i < this->nrCamere; i++) {
                this->costuriAp[i] = a.costuriAp[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Apartament& a) //operator<< citire
    {
        cout << "Suprafata: " << a.suprafata << " mp2" << endl;
        cout << "Nr camere: " << a.nrCamere << endl;
        cout << "Nr max persoane: " << a.nrMaxPers << endl;
        cout << "Nr apartamente: " << a.nrTotalAp << endl;
        cout << "Costuri apartamente: ";
        for (int i = 0; i < a.nrCamere - 1; i++)
            cout << a.costuriAp[a.nrCamere - 1] << " ";
        cout << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Apartament& a) //operator>> scriere
    {
        cout << "Suprafata: "; 
        in >> a.suprafata;

        cout << "Nr camere: "; 
        in >> a.nrCamere;

        cout << "Nr apartamente: "; 
        in >> a.nrTotalAp;

        if (a.costuriAp != NULL) {
            delete[] a.costuriAp;
        }
        a.costuriAp = new int[a.nrCamere];
        cout << "Costuri apartamente: ";
        for (int i = 0; i < a.nrCamere; i++)
        {
            in >> a.costuriAp[i];
        }

        return in;
    }

    Apartament operator++(int) //operator incrementare
    {
        Apartament temporar = *this;
        this->nrTotalAp++;
        return temporar;
    }

    Apartament operator--(int) //operator decrementare
    {
        Apartament temporar = *this;
        this->nrTotalAp--;
        return temporar;
    }

    //get
    int getsuprafata()
    {
        return this->suprafata;
    }

    int getnrCamere()
    {
        return this->nrCamere;
    }

    int* getcosturiAp()
    {
        return this->costuriAp;
    }

    int getnrTotalAp()
    {
        return nrTotalAp;
    }

    int getNrMaxPers()
    {
        return this->nrMaxPers;
    }

    //set
    void setsuprafata(int suprafata)
    {
        this->suprafata = suprafata;

    }

    void setnrCamere(int nrCamere)
    {
        this->nrCamere = nrCamere;
    }

    void setcosturiAp(int* costuriAp)
    {
        if (this->costuriAp != nullptr) {
            delete[] this->costuriAp;
        }
        this->costuriAp = new int[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
            this->costuriAp[i] = costuriAp[i];
    }


    static void setnrTotalAp(int nrTotalApnou)
    {
        nrTotalAp = nrTotalApnou;
    }

    //operatori fisier binar ----  FAZA 6

    fstream& scriereFisierBinar(fstream& fisierBinar) {
        fisierBinar.write((char*)&this->suprafata, sizeof(int));
        fisierBinar.write((char*)&this->nrCamere, sizeof(int));
        fisierBinar.write((char*)this->costuriAp, sizeof(int) * this->nrCamere);
        fisierBinar.write((char*)&this->nrMaxPers, sizeof(int));
        fisierBinar.close();
        return fisierBinar;
    }

    fstream& citireFisierBinar(fstream& fisierBinar) {
        fisierBinar.read((char*)&this->suprafata, sizeof(int));
        fisierBinar.read((char*)&this->nrCamere, sizeof(int));

        if (this->costuriAp != nullptr) {
            delete[] this->costuriAp;
        }

        this->costuriAp = new int[this->nrCamere];
        fisierBinar.read((char*)this->costuriAp, sizeof(int) * this->nrCamere);

        fisierBinar.read((char*)&this->nrMaxPers, sizeof(int));
        fisierBinar.close();
        return fisierBinar;
    }

};

int Apartament::nrTotalAp = 20;

void afisareApartamente() //functie afisare pentru a scurta codul din main
{
    cout << " \n \n -------- LISTA APARTAMENTE --------" << endl;
    Apartament A;
    Apartament B(80, 3, 5, new int[7]);
    Apartament C(45, 3, new int[5]);
    A.afisareAp();
    cout << "\n" << endl;
    B.afisareAp();
    cout << "\n" << endl;
    C.afisareAp();

    Apartament CopieB = B;

}

class Bloc : public BlocComercial //Clasa primara 2
{
private:
    string adresa;
    int nrEtaje;
    int* nrApPeEtaj;
    string chirias;
    const string numeAdmin;
    static int nrTotalBl;

public:

    virtual void areFoodCourt() //functie virtuala a clasei BlocComercial
    {
        if (this->nrEtaje >= 2)
        {
            cout << "Exista Food Court.";

        }
        else
            cout << "Nu exista Food Court.";
    }

    virtual void prezBlocCo() //functie virtuala a clasei BlocComercial
    {
        cout << "Complexul se afla la adresa: " << this->adresa << "si are magazinul: " << this->chirias;
    }

    Bloc() : numeAdmin("D.A.W Administratie") //constructor fara parametrii
    {
        this->adresa = "Calea Vitan nr. 2";
        this->nrEtaje = 2;
        this->chirias = "Motca Valentin";
        this->nrApPeEtaj = new int[this->nrEtaje];
    }

    Bloc(string adresa, int nrEtaje, string chirias, const string nume, int* nrApPeEtaj) :numeAdmin(nume) //constructor cu toti parametrii
    {
        this->adresa = adresa;
        this->nrEtaje = nrEtaje;
        this->chirias = chirias;
        this->nrApPeEtaj = new int[this->nrEtaje];
        for (int i = 0; i < this->nrEtaje; i++)
            this->nrApPeEtaj[i] = nrApPeEtaj[i];
    }

    Bloc(string adresa, string chirias, const string nume, int* nrApPeEtaj) :numeAdmin(nume) //constructor cu 4 parametrii
    {
        this->adresa = adresa;
        this->chirias = chirias;
        this->nrEtaje = 4;
        this->nrApPeEtaj = new int[this->nrEtaje];
        for (int i = 0; i < this->nrEtaje; i++)
            this->nrApPeEtaj[i] = nrApPeEtaj[i];
    }

    void afisareBl() //afisare obiect al clasei Bloc
    {
        cout << "Blocul se afla la adresa: " << this->adresa << "\nChirias activ al blocului: " << this->chirias
            << "\nNumar de etaje: " << this->nrEtaje << "\nNume compania de administratie a blocului: " << this->numeAdmin
            << "\nNumar total blocuri: " << this->nrTotalBl
            << "\nNumar apartamente pe etaj:";
        for (int i = 0; i < this->nrEtaje; i++)
            cout << this->nrApPeEtaj[i] << " ";
        cout << endl;
    }

    ~Bloc() //destructor
    {
        if (this->nrApPeEtaj != NULL)
        {
            delete[]this->nrApPeEtaj;
            this->nrApPeEtaj = NULL;
        }
    }


    Bloc(const Bloc& b) : numeAdmin(b.numeAdmin) //constructor copiere
    {
        this->adresa = b.adresa;
        this->nrEtaje = b.nrEtaje;
        this->chirias = b.chirias;
        this->nrTotalBl = b.nrTotalBl;
        this->nrApPeEtaj = b.nrApPeEtaj;

        if (this->nrEtaje > 0)
        {
            this->nrApPeEtaj = new int[this->nrEtaje];
            for (int i = 0; i < nrEtaje; i++)
            {
                this->nrApPeEtaj[i] = b.nrApPeEtaj[i];
            }
        }
    }

    Bloc& operator=(const Bloc& b) //op atribuire
    {
        if (this != &b) 
        {
            this->adresa = b.adresa;
            this->nrEtaje = b.nrEtaje;
            this->chirias = b.chirias;
            this->nrTotalBl = b.nrTotalBl;

            if (this->nrApPeEtaj != NULL) {
                delete[]this->nrApPeEtaj;
            }

            this->nrApPeEtaj = new int[this->nrEtaje];

            for (int i = 0; i < this->nrEtaje; i++) 
            {
                this->nrApPeEtaj[i] = b.nrApPeEtaj[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Bloc& b) //operator<< citire
    {
        cout << "Adresa blocului: " << b.adresa << endl;
        cout << "Nr etaje: " << b.nrEtaje << endl;
        cout << "Chirias: " << b.chirias << endl;
        cout << "Nume companie administratie: " << b.numeAdmin << endl;
        cout << "Nr total blocuri: " << b.nrTotalBl << endl;
        cout << "Nr ap pe etaj: ";
        for (int i = 0; i < b.nrEtaje; i++)
        {
            cout << b.nrApPeEtaj[i] << " ";
        }
        cout << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Bloc& b) //operator>> scriere
    {
        cout << "Adresa blocului: "; 
        in >> b.adresa;

        cout << "Numar de etaje: "; 
        in >> b.nrEtaje;

        cout << "Chirias activ al blocului: "; 
        in >> b.chirias;

        cout << "Numar total de blocuri: "; 
        in >> b.nrTotalBl;

        cout << "Numar apartamente pe etaj: ";
        if (b.nrApPeEtaj != NULL) {
            delete[] b.nrApPeEtaj;
        }
        b.nrApPeEtaj = new int[b.nrEtaje];
        for (int i = 0; i < b.nrEtaje; i++)
        {
            in >> b.nrApPeEtaj[i];
        }
        return in;
    }

    Bloc operator++(int) //operator incrementare
    {
        Bloc temporar = *this;
        this->nrTotalBl++;
        return temporar;
    }

    Bloc operator--(int) //operator decrementare
    {
        Bloc temporar = *this;
        this->nrTotalBl--;
        return temporar;
    }

    //get si set
    string getadresa()
    {
        return adresa;
    }

    void setadresa(string adresa)
    {
        this->adresa = adresa;
    }

    int getNrEtaje()
    {
        return nrEtaje;
    }

    void setNrEtaje()
    {
        this->nrEtaje = nrEtaje;
    }

    int* getNrApPeEtaj()
    {
        return nrApPeEtaj;
    }

    void setNrApPeEtaj(int* nrApPeEtaj)
    {
        if (this->nrApPeEtaj != nullptr) {
            delete[] this->nrApPeEtaj;
        }
        this->nrApPeEtaj = new int[this->nrEtaje];
        for (int i = 0; i < this->nrEtaje; i++)
            this->nrApPeEtaj[i] = nrApPeEtaj[i];
    }

    string getchirias()
    {
        return chirias;
    }

    void setchirias()
    {
        this->chirias = chirias;
    }

    string getNumeCompanieAdmin()
    {
        return numeAdmin;
    }

    static int getNrTotalBl()
    {
        return nrTotalBl;
    }

    static void setnrTotalBl(int nrTotalBlnou)
    {
        nrTotalBl = nrTotalBlnou;
    }

    friend void verificaBloc(const Bloc& bloc); //functie globala
    friend void afisareNumarTotalApartamente(const Bloc& bloc); //functie globala

    //operatori fisiere text

    friend ofstream& operator<<(ofstream& fisier, const Bloc& b) {
        fisier << b.adresa << "\n" << b.nrEtaje << "\n" << b.chirias << "\n" << b.numeAdmin << "\n";
        for (int i = 0; i < b.nrEtaje; ++i) {
            fisier << b.nrApPeEtaj[i] << " ";
        }
        fisier << "\n";
        return fisier;
    }

    friend ifstream& operator>>(ifstream& fisier, Bloc& b) {
        fisier >> b.adresa >> b.nrEtaje >> b.chirias;
        if (b.nrApPeEtaj != nullptr) {
            delete[] b.nrApPeEtaj;
        }
        b.nrApPeEtaj = new int[b.nrEtaje]();
        for (int i = 0; i < b.nrEtaje; ++i) {
            fisier >> b.nrApPeEtaj[i];
        }
        return fisier;
    }

    //operatori fisiere binare ----  FAZA 6

    fstream& scriereFisierBinar(fstream& fisierBinar) {
        fisierBinar.write((char*)&this->nrTotalBl, sizeof(int));
        fisierBinar.write((char*)this->adresa.c_str(), this->adresa.size() + 1);
        fisierBinar.write((char*)&this->nrEtaje, sizeof(int));
        fisierBinar.write(this->chirias.c_str(), this->chirias.size() + 1);
        fisierBinar.write(this->numeAdmin.c_str(), this->numeAdmin.size() + 1);
        fisierBinar.write((char*)this->nrApPeEtaj, sizeof(int) * this->nrEtaje);
        return fisierBinar;
    }

    fstream& citireFisierBinar(fstream& fisierBinar) {
        fisierBinar.read((char*)&this->nrTotalBl, sizeof(int));

        char buffer[100];
        fisierBinar.read(buffer, sizeof(buffer));
        this->adresa = buffer;

        fisierBinar.read((char*)&this->nrEtaje, sizeof(int));

        fisierBinar.read(buffer, sizeof(buffer));
        this->chirias = buffer;


        if (this->nrApPeEtaj != nullptr) {
            delete[] this->nrApPeEtaj;
        }
        this->nrApPeEtaj = new int[this->nrEtaje]();
        fisierBinar.read((char*)this->nrApPeEtaj, sizeof(int) * this->nrEtaje);

        return fisierBinar;
    }

};

int Bloc::nrTotalBl = 5;


void afisareBlocuri() //functie afisare pentru a scurta codul din main
{
    cout << " \n \n -------- LISTA BLOCURI --------" << endl;
    Bloc B22;
    Bloc C4("Mihai Bravu 14", 8, "Ene Mihail", "NETLINK Administratie", new int[8] {6, 7, 8, 9, 10, 11, 12, 13});
    Bloc Bis8("Calea Vacaresti 6", "Ion Vasile", "FRONTLIFE Administratie", new int[4] {1, 2, 3, 4});
    Bloc Bis17 = B22;

    B22.afisareBl();
    cout << "\n" << endl;
    C4.afisareBl();
    cout << "\n";
    Bis8.afisareBl();
    cout << "\nTest bloc copiat: " << endl;
    Bis17.afisareBl();

    cout << "\n ---> Test functie:" << endl;
    verificaBloc(B22);
}

class Locatar //Clasa primara 3
{
private:
    string nume;
    int nrLoc;
    int varsta;
    double* consumuriLoc;
    const double cota_indv_ch;
    static int nrMaxLocatari;

public:
    Locatar() : cota_indv_ch(0.2) //constructor fara parametrii
    {
        this->nume = "Picus Laurentiu";
        this->nrLoc = 8;
        this->varsta = 28;
        this->consumuriLoc = new double[this->varsta]();
    }

    Locatar(string nume, int nrLoc, int varsta, const double cota, double* consumuriLoc) :cota_indv_ch(cota) //constructor cu toti parametrii
    {
        this->nume = nume;
        this->nrLoc = nrLoc;
        this->varsta = varsta;
        this->consumuriLoc = new double[this->varsta];
        for (int i = 0; i < this->varsta; i++)
            this->consumuriLoc[i] = consumuriLoc[i];
    }

    Locatar(string nume, int nrLoc, const double cota, int* consumuriLoc) :cota_indv_ch(cota) //constructor cu 4 parametrii
    {
        this->nume = nume;
        this->nrLoc = nrLoc;
        this->varsta = 34;
        this->consumuriLoc = new double[this->varsta];
        for (int i = 0; i < this->varsta; i++)
            this->consumuriLoc[i] = consumuriLoc[i];
    }

    void afisareLc() //functie afisare obiect al clasei
    {
        cout << "Nume locatar: " << this->nume << "\nNumar Apartament: " << this->nrLoc <<
            "\nVarsta Locatar: " << this->varsta << "\nCota individuala de cheltuiala: " <<
            this->cota_indv_ch << "\nNumar maxim de locatari in apartament: " << this->nrMaxLocatari <<
            "\nConsumuri medii Locatar: ";
        for (int i = 0; i < this->varsta; i++)
            cout << this->consumuriLoc[i] << " ";
        cout << endl;
    }

    ~Locatar() //destructor
    {
        if (this->consumuriLoc != nullptr)
        {
            delete[]this->consumuriLoc;
            this->consumuriLoc = nullptr;
        }
    }


    Locatar(const Locatar& locatar) : cota_indv_ch(locatar.cota_indv_ch) //constructor de copiere
    {
        this->nume = locatar.nume;
        this->nrLoc = locatar.nrLoc;
        this->varsta = locatar.varsta;
        this->nrMaxLocatari = locatar.nrMaxLocatari;
        this->consumuriLoc = locatar.consumuriLoc;

        if (varsta > 0)
        {
            this->consumuriLoc = new double[varsta];
            for (int i = 0; i < this->varsta; i++)
            {
                this->consumuriLoc[i] = locatar.consumuriLoc[i];
            }
        }
    }

    Locatar& operator=(Locatar& locatar) //supraincarcati operator=
    {
        if (this != &locatar) {
            this->nume = locatar.nume;
            this->nrLoc = locatar.nrLoc;
            this->varsta = locatar.varsta;

            if (this->consumuriLoc != NULL) {
                delete[] this->consumuriLoc;
            }

            this->consumuriLoc = new double[this->varsta];

            for (int i = 0; i < this->varsta; i++) {
                this->consumuriLoc[i] = locatar.consumuriLoc[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Locatar& locatar) //operator<< citire
    {
        cout << "Nume locatar: " << locatar.nume << endl;
        cout << "Numar Apartament: " << locatar.nrLoc << endl;
        cout << "Varsta Locatar: " << locatar.varsta << endl;
        cout << "Cota individuala de cheltuiala: " << locatar.cota_indv_ch << endl;
        cout << "Numar maxim de locatari in apartament: " << locatar.nrMaxLocatari << endl;
        cout << "Consumuri medii Locatar: ";
        for (int i = 0; i < locatar.varsta; i++)
            cout << locatar.consumuriLoc[i] << " ";
        cout << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Locatar& locatar) //operator>> scriere
    {
        cout << "Nume locatar: "; 
        in >> locatar.nume;

        cout << "Numar Apartament: "; 
        in >> locatar.nrLoc;

        cout << "Varsta Locatar: "; 
        in >> locatar.varsta;

        cout << "Numar maxim de locatari in apartament: "; 
        in >> locatar.nrMaxLocatari;

        cout << "Consumuri medii Locatar: ";
        if (locatar.consumuriLoc != NULL) {
            delete[] locatar.consumuriLoc;
        }
        locatar.consumuriLoc = new double[locatar.varsta];
        for (int i = 0; i < locatar.varsta; i++)
            in >> locatar.consumuriLoc[i];

        return in;
    }

    Locatar operator++(int) //operator incrementare
    {
        Locatar temporar = *this;
        this->nrMaxLocatari++;
        return temporar;
    }

    Locatar operator--(int) //operator decrementare
    {
        Locatar temporar = *this;
        this->nrMaxLocatari--;
        return temporar;
    }

    //get si set
    string getNume() const
    {
        return this->nume;
    }

    void setNume(string nume)
    {
        this->nume = nume;
    }

    int getNrLoc()
    {
        return nrLoc;
    }

    void setNrLoc(int nrLoc)
    {
        this->nrLoc = nrLoc;
    }

    int getVarsta() const
    {
        return this->varsta;
    }

    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }

    const double getCotaIndvCh()
    {
        return cota_indv_ch;
    }

    const double* getConsumuriLoc()
    {
        return consumuriLoc;
    }

    void setConsumuriLoc(double* consumuriLoc)
    {
        if (this->consumuriLoc != nullptr) {
            delete[] this->consumuriLoc;
        }
        this->consumuriLoc = new double[this->varsta];
        for (int i = 0; i < this->varsta; i++)
            this->consumuriLoc[i] = consumuriLoc[i];
    }

    static int getNrMaxLocatari()
    {
        return nrMaxLocatari;
    }


    static void setnrMaxLocatari(int nrMaxLocatarinou)
    {
        nrMaxLocatari = nrMaxLocatarinou;
    }

    friend void afisareInformatiiLocatar(const Locatar& locatar); //functie friend

    //operatori fisier text ----  FAZA 6
    friend ofstream& operator<<(ofstream& fisier, const Locatar& locatar) {
        fisier << locatar.nume << "\n" << locatar.nrLoc << "\n" << locatar.varsta << "\n";
        for (int i = 0; i < locatar.nrLoc; ++i) {
            fisier << locatar.consumuriLoc[i] << " ";
        }
        fisier << "\n" << locatar.cota_indv_ch;
        return fisier;
    }


    friend ifstream& operator>>(ifstream& fisier, Locatar& locatar) {
        fisier >> locatar.nume >> locatar.nrLoc >> locatar.varsta;
        locatar.consumuriLoc = new double[locatar.nrLoc];
        for (int i = 0; i < locatar.nrLoc; ++i) {
            fisier >> locatar.consumuriLoc[i];
        }
        

        return fisier;
    }
};

int Locatar::nrMaxLocatari = 4;


void afisareLocatari() //functie afisare pentru a scurta codul din main
{
    cout << " \n -------- LISTA LOCATARI --------" << endl;
    Locatar Picus;
    Locatar Anghel("Anghel Melania", 10, 62, 0.7, new double[62] {250, 260, 270, 280});
    Locatar Popescu("Pop Adrian", 22, 1.0, new int[34] {340, 350, 360, 370, 380, 390, 400});
    Locatar Mihail = Picus;

    Picus.afisareLc();
    Mihail.afisareLc();
    cout << "\n" << endl;
    Anghel.afisareLc();
    cout << "\n" << endl;
    Popescu.afisareLc();

    cout << "\n ---> Test functie:" << endl;
    afisareInformatiiLocatar(Picus);

}

class ComplexRezidential //FAZA 5 - RELATIE HAS-A; class nr. 4
{
private:
    string numeComplex;
    int anConstructie;
    Apartament* listaAp;  // Relatie has-a cu clasa Apartament
    int nrAp;

public:
    ComplexRezidential() //constructor fara parametrii
    {
        this->numeComplex = "CORESI TOWN";
        this->anConstructie = 2021;
        this->nrAp = 1;
        this->listaAp = new Apartament[this->nrAp];
    }

    ComplexRezidential(string numeComplex, int anConstructie, int nrAp, Apartament* li) //constructor cu toti parametrii
    {
        this->numeComplex = numeComplex;
        this->anConstructie = anConstructie;
        this->nrAp = nrAp;
        this->listaAp = new Apartament[this->nrAp];
        for (int i = 0; i < this->nrAp; i++)
        {
            this->listaAp[i] = li[i];
        }
    }

    ComplexRezidential(const ComplexRezidential& c) //constructor de copiere
    {
        this->numeComplex = c.numeComplex;
        this->anConstructie = c.anConstructie;
        this->nrAp = c.nrAp;
        this->listaAp = new Apartament[c.nrAp];
        for (int i = 0; i < c.nrAp; i++)
        {
            this->listaAp[i] = c.listaAp[i];
        }
    }

    ComplexRezidential& operator=(const ComplexRezidential& c) //operator de atribuire
    {
        this->numeComplex = c.numeComplex;
        this->anConstructie = c.anConstructie;
        this->nrAp = c.nrAp;
        if (this->listaAp != NULL)
        {
            delete[]this->listaAp;
        }
        this->listaAp = new Apartament[c.nrAp];
        for (int i = 0; i < c.nrAp; i++)
        {
            this->listaAp[i] = c.listaAp[i];
        }
        return *this;
    }

    ~ComplexRezidential() //destructor
    {
        if (this->listaAp != NULL)
        {
            delete[]this->listaAp;
        }
    }

    //getteri
    string getNumeComplex()
    {
        return this->numeComplex;
    }

    int getAnConst()
    {
        return this->anConstructie;
    }

    int getNrAp()
    {
        return this->nrAp;
    }

    void afisareVectorApartament() {
        for (int i = 0; i < this->nrAp; i++) {
            cout << this->listaAp[i] ;
        }
    }

    //setteri
    void setNumeComplex(string numeComplex)
    {
        if (numeComplex.length() > 3)
        {
            this->numeComplex = numeComplex;
        }
    }

    void setAnConst(int anConstructie)
    {
        if (anConstructie >= 0)
        {
            this->anConstructie = anConstructie;
        }
    }

    void setNrAp(int nr)
    {
        if (nr >= 0)
        {
            this->nrAp = nr;
        }
    }

    void setListaAp(Apartament* li, int nr)
    {
        if (this->listaAp != NULL)
        {
            delete[]this->listaAp;
        }
        this->listaAp = new Apartament[nr];
        for (int i = 0; i < nr; i++)
        {
            this->listaAp[i] = li[i];
        }
    }

    friend ostream& operator<<(ostream& consola, ComplexRezidential c) //operator<< citire
    {
        consola << endl << "Nume complex: " << c.numeComplex << endl;
        consola << "An constructie: " << c.anConstructie << endl;
        consola << "Nr apartamente: " << c.nrAp << endl;
        consola << "Vector cu lista apartamente: " << endl;
        for (int i = 0; i < c.nrAp; i++)
        {
            consola << endl << "Suprafata: " << c.listaAp[i].getsuprafata() << " mp2" << endl;
            consola << "Nr camere: " << c.listaAp[i].getnrCamere() << endl;
            consola << "Nr max persoane: " << c.listaAp[i].getNrMaxPers() << endl;
            consola << "Nr apartamente: " << c.listaAp[i].getnrTotalAp() << endl;
        }
        return consola;
    }

    friend istream& operator>>(istream& input, ComplexRezidential& c) //operator>> scriere
    {
        cout << endl << "Nume complex: ";
        input >> c.numeComplex;
        
        cout << "An constructie: ";
        input >> c.anConstructie;

        cout << "Nr apartamente: ";
        input >> c.nrAp;

        return input;
    }
};

class Penthouse : public Apartament //FAZA 7 --- Relatie is-a 1; class  nr. 5
{
private: 
    int nrDormitoare;
    int nrBai;
    int* ConsumEnergetic;

public:
    //constructor fara parametri
    Penthouse() : Apartament()
    {
        this->nrDormitoare = 4;
        this->nrBai = 2;
        this->ConsumEnergetic = new int[this->nrDormitoare];
        for (int i = 0; i < this->nrDormitoare; i++)
        {
            this->ConsumEnergetic[i] = i + 120;
        }
    }

    //constructor cu toti parametrii
    Penthouse(int suprafata, int nrCamere, int* costuriAp, const int nrMaxPers, int nrDormitoare, int nrBai, int* ConsumEnergetic)
    {
        this->nrDormitoare = nrDormitoare;
        this->nrBai = nrBai;
        this->ConsumEnergetic = new int[this->nrDormitoare];
        for (int i = 0; i < this->nrDormitoare; i++)
        {
            this->ConsumEnergetic[i] = ConsumEnergetic[i];
        }
    }

    //constructor copiere
    Penthouse(const Penthouse& ph) :Apartament(ph)
    {
        this->nrDormitoare = ph.nrDormitoare;
        this->nrBai = ph.nrBai;
        this->ConsumEnergetic = new int[ph.nrBai];
        for (int i = 0; i < this->nrBai; i++)
        {
            this->ConsumEnergetic[i] = ph.ConsumEnergetic[i];
        }
    }


    //destructor
    ~Penthouse() 
    {
        if (this->ConsumEnergetic != NULL)
        {
            delete[]this->ConsumEnergetic;
        }
    }

    //getteri
    int getnrDormitoare()
    {
        return this->nrDormitoare;
    }

    int getnrBai()
    {
        return this->nrBai;
    }

    int* getConsumEnergetic()
    {
        return this->ConsumEnergetic;
    }

    //setteri
    void setnrDormitoare(int nrD)
    {
        this->nrDormitoare = nrD;
    }

    void setnrBai(int nrB)
    {
        this->nrBai = nrB;
    }

    void setConsumEnergetic(int* ConsumEnergetic)
    {
        if (this->ConsumEnergetic != NULL)
        {
            delete[]this->ConsumEnergetic;
        }
        this->ConsumEnergetic = new int[this->nrDormitoare];
        for (int i = 0; i < this->nrDormitoare; i++)
        {
            this->ConsumEnergetic[i] = ConsumEnergetic[i];
        }
    }

    //operator=
    Penthouse& operator=(const Penthouse& ph)
    {
        if (this != &ph)
        {
            (Apartament)*this = ph;
            this->nrDormitoare = ph.nrDormitoare;
            this->nrBai = ph.nrBai;
            this->ConsumEnergetic = new int[ph.nrBai];
            for (int i = 0; i < this->nrBai; i++)
            {
                this->ConsumEnergetic[i] = ph.ConsumEnergetic[i];
            }
        }

        return *this;
    }
};

class BlocDeBirouri : public Bloc //FAZA 7 --- Relatie is-a 2; class nr. 6
{
private:
    string numeCorporatie;
    int nrBirouri;
    int* nrBirouriPeEtaj;

public:
    //constructor fara parametrii
    BlocDeBirouri() :Bloc()
    {
        this->numeCorporatie = "FizzyEnts";
        this->nrBirouri = 7;
        this->nrBirouriPeEtaj = new int[this->nrBirouri];
        {
            for (int i = 0; i < this->nrBirouri; i++)
            {
                this->nrBirouriPeEtaj[i] = i * 2;
            }
        }
    }

    //constructor cu toti parametrii
    BlocDeBirouri(string adresa, int nrEtaje, int* nrApPeEtaj, string chirias, const string numeAdmin, int nrBirouri, string numeCorporatie, int* nrBirouriPeEtaj)
    {
        this->numeCorporatie = numeCorporatie;
        this->nrBirouri = nrBirouri;
        this->nrBirouriPeEtaj = new int[nrBirouri];
        for (int i = 0; i < nrBirouri; i++)
        {
            this->nrBirouriPeEtaj[i] = nrBirouriPeEtaj[i];
        }
    }

    //constructor copiere
    BlocDeBirouri(const BlocDeBirouri& bir) : Bloc(bir)
    {
        this->numeCorporatie = bir.numeCorporatie;
        this->nrBirouri = bir.nrBirouri;
        this->nrBirouriPeEtaj = new int[bir.nrBirouri];
        for (int i = 0; i < this->nrBirouri; i++)
        {
            this->nrBirouriPeEtaj[i] = bir.nrBirouriPeEtaj[i];
        }
    }

    //destructor
    ~BlocDeBirouri()
    {
        if (this->nrBirouriPeEtaj != NULL)
        {
            delete[]this->nrBirouriPeEtaj;
        }
    }

    //operator=
    BlocDeBirouri& operator=(const BlocDeBirouri& bir)
    {
        if (this != &bir)
        {
            (Bloc)*this = bir;
            this->numeCorporatie = bir.numeCorporatie;
            this->nrBirouri = bir.nrBirouri;
            this->nrBirouriPeEtaj = new int[bir.nrBirouri];
            for (int i = 0; i < this->nrBirouri; i++)
            {
                this->nrBirouriPeEtaj[i] = bir.nrBirouriPeEtaj[i];
            }
        }
    }

    //getteri
    string getNumeCorp()
    {
        return this->numeCorporatie;
    }

    int getNrBirouri()
    {
        return this->nrBirouri;
    }

    int* setBirEtaj()
    {
        return this->nrBirouriPeEtaj;
    }

    //setteri
    void setNumeCorp(string nume)
    {
        this->numeCorporatie = nume;
    }

    void setNrBirouri(int nr)
    {
        this->nrBirouri = nr;
    }

    void setBirEtaj(int* nrBirouriPeEtaj)
    {
        if (this->nrBirouriPeEtaj != NULL)
        {
            delete[]this->nrBirouriPeEtaj;
        }
        this->nrBirouriPeEtaj = new int[this->nrBirouri];
        for (int i = 0; i < this->nrBirouri; i++)
        {
            this->nrBirouriPeEtaj[i] = nrBirouriPeEtaj[i];
        }
    }

};




void afisareInformatiiLocatar(const Locatar& locatar) 
{
    cout << "Nume locatar: " << locatar.getNume() << "\nVarsta Locatar: " << locatar.getVarsta() << endl;
}

void verificaBloc(const Bloc& bloc) {
    if (Bloc::nrTotalBl >= 5) {
        cout << "Numarul total de blocuri este suficient de mare." << endl;
    }
    else {
        cout << "Numarul total de blocuri este prea mic." << endl;
    }
}

void waitForKey() //functie ca sa treaca la afisarea urmatoarei clase in main
{
    cout << "\n \n ~Apasa Enter pentru urmatorul obiect!";
    cin.ignore();
    cin.get();
}

void afisareNumarTotalApartamente(const Bloc& b) {
    int numarTotal = 0;
    for (int i = 0; i < b.nrEtaje; ++i) {
        numarTotal += b.nrApPeEtaj[i];
    }

    cout << "Numarul total de apartamente in blocul de pe adresa " << b.adresa << " este: " << numarTotal << endl;
}


void main()
{
    /*FAZA 1 + 2 + 3
    afisareApartamente();

    cout << "\n " << endl;

    waitForKey();

    afisareBlocuri();

    waitForKey();

    cout << "\n " << endl;

    afisareLocatari();

    cout << "\n \n-----> Testare get si set: \n " << endl;

    Apartament D;
    cout << "Suprafata apartamentului D: " << D.getsuprafata() << " mp2" << endl;
    D.setsuprafata(60);

    cout << "Suprafata apartamentului D dupa actualizare: " << D.getsuprafata() << " mp2" << endl;
    cout << "\n " << endl;

    Bloc B;
    cout << "Adresa blocului B: " << B.getadresa() << endl;
    B.setadresa("Calea Dorobantilor 20");

    cout << "Adresa blocului B dupa actualizare: " << B.getadresa() << endl;
    cout << "\n " << endl;

    Locatar L;
    cout << "Numele locatarului L: " << L.getNume() << endl;
    L.setNume("Ionescu Maria");

    cout << "Numele locatarului L dupa actualizare: " << L.getNume() << endl;

     */

    // ------- FAZA 5 -------: Clasa ComplexRezidential cu relatie de has-a cu clasa Bloc

    ComplexRezidential complex1; // test constructor fara parametrii
    cout << complex1 << endl;

    Apartament* listaApartamente = new Apartament[1];
    ComplexRezidential complex2("PIPERA", 2022, 1, listaApartamente); //test constructor cu toti parametrii
    cout << complex2 << endl;

    ComplexRezidential complex3; //test constructor copiere
    complex3 = complex1;
    cout << complex3 << endl;



    //Test get si set
    complex1.setNumeComplex("RAHOVA");
    cout << "Numele complexului 1 este " << complex1.getNumeComplex() << ". " << endl;
    complex2.setAnConst(2008);
    cout << "Complexul 2 a fost construcit in anul " << complex2.getAnConst() << ". " << endl;
    complex3.setNrAp(2);
    cout << "Complexul 3 are un numar de " << complex3.getNrAp() << " apartamente ocupate." << endl;
    /*complex2.setListaAp(listaApartamente, 4);
    cout << "\nInformatii despre complex2 dupa modificare:\n" << complex2 << endl;*/

    //Test operatori
    complex2 = complex1;
    cout << "\nInformatii despre complex2 dupa atribuire:\n" << complex2 << endl;

    ComplexRezidential complex4;
    cout << "\nInformatii despre complexul 4:\n" << endl;
    cin >> complex4;
    cout << complex4 << endl;


    delete[] listaApartamente;


/* ----- FAZA 4 ----
  //Vector de obiecte Apartament
    Apartament vectorA[2];
    for (int i = 0; i < 3; i++) {
        cin >> vectorA[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << vectorA[i] << endl;
    }

    //Vector de obiecte Bloc
    Bloc vectorB[3];
    for (int i = 0; i < 3; i++) {
        cin >> vectorB[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << vectorB[i] << endl;
    }

    //Vector de obiecte Locatar
    Locatar vectorL[3];
    for (int i = 0; i < 3; i++) {
        cin >> vectorL[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << vectorL[i] << endl;
    }
    */
}
