#include <iostream>
using namespace std;

//Domeniul ales este "Complex de apartamente".

class Apartament {
private:
    float suprafata;
    int nrCamere;
    int* costuriApartament;
    const int NR_MAXIM_DE_PERS;
    static int nrTotalAp;

public:
    Apartament() : NR_MAXIM_DE_PERS(4)
    {
        this->suprafata = 52;
        this->nrCamere = 2;
        this->costuriApartament = new int[this->nrCamere]();
    }

    Apartament(float suprafata, int nrCamere, const int nr, int* costuriApartament) :NR_MAXIM_DE_PERS(nr)
    {
        this->suprafata = suprafata;
        this->nrCamere = nrCamere;
        this->costuriApartament = new int[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
            this->costuriApartament[i] = costuriApartament[i];
    }

    Apartament(float suprafata, const int nr, int* costuriApartament) :NR_MAXIM_DE_PERS(nr)
    {
        this->suprafata = suprafata;
        this->nrCamere = 1;
        this->costuriApartament = new int[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
            this->costuriApartament[i] = costuriApartament[i];
    }

    void afisareAp()
    {
        cout << "Suprafata: " << this->suprafata << " mp2" << "\nNumar de camere: " << this->nrCamere
            << "\nNumar maxim de persoane: " << this->NR_MAXIM_DE_PERS << "\nIn complex se afla " << this->nrTotalAp
            << " de apartamente" << "\nCosturi apartamente:";
            for (int i = 0; i < this->nrCamere; i++)
            cout << this->costuriApartament[i] << " ";
        cout << endl;
    }

    ~Apartament() 
    {
        if (this->costuriApartament != nullptr) 
        {
            delete[] this->costuriApartament;
            this->costuriApartament = nullptr;
        }
    }

    Apartament(const Apartament& apartament) : NR_MAXIM_DE_PERS(apartament.NR_MAXIM_DE_PERS) //constructor copiere
    {
        this->suprafata = apartament.suprafata;
        this->nrCamere = apartament.nrCamere;
        this->nrTotalAp = apartament.nrTotalAp;
        this->costuriApartament = apartament.costuriApartament;
    
        if (nrCamere > 0) 
        {
            this->costuriApartament = new int[nrCamere];
            for (int i = 0; i < nrCamere; i++) 
            {
                this->costuriApartament[i] = apartament.costuriApartament[i];
            }
        }
    }

    Apartament& Apartament::operator=(const Apartament& apartament) //op atribuire
    {
        if (this != &apartament) {
            this->suprafata = apartament.suprafata;
            this->nrCamere = apartament.nrCamere;
            this->NR_MAXIM_DE_PERS = apartament.NR_MAXIM_DE_PERS;
            this->nrTotalAp = apartament.nrTotalAp;

            if (this->costuriApartament != nullptr) {
                delete[] this->costuriApartament;
            }

            this->costuriApartament = new int[this->nrCamere];

            for (int i = 0; i < this->nrCamere; i++) {
                this->costuriApartament[i] = apartament.costuriApartament[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Apartament& apartament) {
        cout << "Suprafata: " << apartament.suprafata << " mp2" << endl;
        cout << "Numar de camere: " << apartament.nrCamere << endl;
        cout << "Numar maxim de persoane: " << apartament.NR_MAXIM_DE_PERS << endl;
        cout << "In complex se afla " << apartament.nrTotalAp << " de apartamente" << endl;
        cout << "Costuri apartamente: ";
        for (int i = 0; i < apartament.nrCamere; i++)
            cout << apartament.costuriApartament[i] << " ";
        cout << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Apartament& apartament) {
        cout << "Suprafata: "; in >> apartament.suprafata;

        cout << "Numar de camere: "; in >> apartament.nrCamere;

        cout << "Numar maxim de persoane: "; in >> apartament.NR_MAXIM_DE_PERS;

        cout << "In complex se afla "; in >> apartament.nrTotalAp;

        cout << "Costuri apartamente: ";
        if (apartament.costuriApartament != nullptr) {
            delete[] apartament.costuriApartament;
        }
        apartament.costuriApartament = new int[apartament.nrCamere];
        for (int i = 0; i < apartament.nrCamere; i++)
            in >> apartament.costuriApartament[i];

        return in;
    }

    Apartament operator++(int) {
        Apartament temporar = *this;
        this->nrTotalAp++;
        return temporar;
    }

    Apartament operator--(int) {
        Apartament temporar = *this;
        this->nrTotalAp--;
        return temporar;
    }



    float getsuprafata()
    {
        return this->suprafata;
    }

    int getnrCamere()
    {
        return this->nrCamere;
    }

    int* getcosturiApartament()
    {
        return this->costuriApartament;
    }

    int getnrTotalAp()
    {
        return nrTotalAp;
    }

    int getNR_MAXIM_DE_PERS()
    {
        return this->NR_MAXIM_DE_PERS;
    }

    void setsuprafata(float suprafata)
    {
        this->suprafata = suprafata;

    }

    void setnrCamere(int nrCamere)
    {
        this->nrCamere = nrCamere;
    }

    void setcosturiApartament(int* costuriApartament) 
    {
        if (this->costuriApartament != nullptr) {
            delete[] this->costuriApartament;
        }
        this->costuriApartament = new int[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
            this->costuriApartament[i] = costuriApartament[i];
    }


    static void setnrTotalAp(int nrTotalApnou)
    {
        nrTotalAp = nrTotalApnou;
    }
};

int Apartament::nrTotalAp = 20;

void afisareApartamente()
{
    cout << " \n \n -------- LISTA APARTAMENTE --------" << endl;
    Apartament A;
    Apartament B(80, 3, 6, new int[3] {460, 470, 480});
    Apartament C(40, 1, new int{ 230 });
    A.afisareAp();
    cout << "\n" << endl;
    B.afisareAp();
    cout << "\n" << endl;
    C.afisareAp();

    Apartament CopieB = B;

}

class Bloc
{
private:
    string adresa;
    int nrEtaje;
    int* nrApPeEtaj;
    string chirias;
    const string NUME_COMPANIE_ADMIN;
    static int nrTotalBl;

public:
    Bloc() : NUME_COMPANIE_ADMIN("D.A.W Administratie")
    {
        this->adresa = "Calea Vitan nr. 2";
        this->nrEtaje = 2;
        this->chirias = "Motca Valentin";
        this->nrApPeEtaj = new int[this->nrEtaje]();
    }

    Bloc(std::string adresa, int nrEtaje, string chirias, const string nume, int* nrApPeEtaj) :NUME_COMPANIE_ADMIN(nume)
    {
        this->adresa = adresa;
        this->nrEtaje = nrEtaje;
        this->chirias = chirias;
        this->nrApPeEtaj = new int[this->nrEtaje];
        for (int i = 0; i < this->nrEtaje; i++)
            this->nrApPeEtaj[i] = nrApPeEtaj[i];
    }

    Bloc(std::string adresa, string chirias, const string nume, int* nrApPeEtaj) :NUME_COMPANIE_ADMIN(nume)
    {
        this->adresa = adresa;
        this->chirias = chirias;
        this->nrEtaje = 4;
        this->nrApPeEtaj = new int[this->nrEtaje];
        for (int i = 0; i < this->nrEtaje; i++)
            this->nrApPeEtaj[i] = nrApPeEtaj[i];
    }

    void afisareBl()
    {
        cout << "Blocul se afla la adresa: " << this->adresa << "\nChirias activ al blocului: " << this->chirias
            << "\nNumar de etaje: " << this->nrEtaje << "\nNume compania de administratie a blocului: " << this->NUME_COMPANIE_ADMIN
            << "\nNumar total blocuri: " << this->nrTotalBl
            << "\nNumar apartamente pe etaj:"; 
        for (int i = 0; i < this->nrEtaje; i++)
            cout << this->nrApPeEtaj[i] << " ";
        cout << endl;
    }

    ~Bloc()
    {
        if (this->nrApPeEtaj != nullptr)
        {
            delete[] this->nrApPeEtaj;
            this->nrApPeEtaj = nullptr;
        }
    }

    
    Bloc(const Bloc& bloc) : NUME_COMPANIE_ADMIN(bloc.NUME_COMPANIE_ADMIN) //constructor copiere
    {
        cout << "Constructor de copiere pentru Bloc\n";
        this->adresa = bloc.adresa; 
        this->nrEtaje = bloc.nrEtaje;
        this->chirias = bloc.chirias; 
        this->nrTotalBl = bloc.nrTotalBl;
        this->nrApPeEtaj = bloc.nrApPeEtaj;

        if (this->nrEtaje > 0) 
        {
            this->nrApPeEtaj = new int[this->nrEtaje];
            for (int i = 0; i < nrEtaje; i++) 
            {
                this->nrApPeEtaj[i] = bloc.nrApPeEtaj[i];
            }
        }
    }

    Bloc& Bloc::operator=(const Bloc& bloc) //op atribuire
    {
        if (this != &bloc) {
            this->adresa = bloc.adresa;
            this->nrEtaje = bloc.nrEtaje;
            this->chirias = bloc.chirias;
            this->NUME_COMPANIE_ADMIN = bloc.NUME_COMPANIE_ADMIN;
            this->nrTotalBl = bloc.nrTotalBl;

            if (this->nrApPeEtaj != nullptr) {
                delete[] this->nrApPeEtaj;
            }

            this->nrApPeEtaj = new int[this->nrEtaje];

            for (int i = 0; i < this->nrEtaje; i++) {
                this->nrApPeEtaj[i] = bloc.nrApPeEtaj[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Bloc& bloc) {
        cout << "Adresa blocului: " << bloc.adresa << endl;
        cout << "Numar de etaje: " << bloc.nrEtaje << endl;
        cout << "Chirias activ al blocului: " << bloc.chirias << endl;
        cout << "Nume companie administratie: " << bloc.NUME_COMPANIE_ADMIN << endl;
        cout << "Numar total de blocuri: " << bloc.nrTotalBl << endl;
        cout << "Numar apartamente pe etaj: ";
        for (int i = 0; i < bloc.nrEtaje; i++)
            cout << bloc.nrApPeEtaj[i] << " ";
        cout << endl;
        return consola;
    }

    friend istream& operator>>(istream& in, Bloc& bloc) {
        cout << "Adresa blocului: "; in >> bloc.adresa;

        cout << "Numar de etaje: "; in >> bloc.nrEtaje;

        cout << "Chirias activ al blocului: "; in >> bloc.chirias;

        cout << "Nume companie administratie: "; in >> bloc.NUME_COMPANIE_ADMIN;

        cout << "Numar total de blocuri: "; in >> bloc.nrTotalBl;

        cout << "Numar apartamente pe etaj: ";
        if (bloc.nrApPeEtaj != nullptr) {
            delete[] bloc.nrApPeEtaj;
        }
        bloc.nrApPeEtaj = new int[bloc.nrEtaje];
        for (int i = 0; i < bloc.nrEtaje; i++)
            in >> bloc.nrApPeEtaj[i];

        return in;
    }

    Bloc operator++(int) {
        Bloc temporar = *this;
        this->nrTotalBl++;
        return temporar;
    }

    Bloc operator--(int) {
        Bloc temporar = *this;
        this->nrTotalBl--;
        return temporar;
    }


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
        return NUME_COMPANIE_ADMIN;
    }

    static int getNrTotalBl() 
    {
        return nrTotalBl;
    }

    static void setnrTotalBl(int nrTotalBlnou)
    {
        nrTotalBl = nrTotalBlnou;
    }

    friend void verificaBloc(const Bloc& bloc);
    friend void afisareNumarTotalApartamente(const Bloc& bloc);
};

int Bloc::nrTotalBl = 5;


void afisareBlocuri()
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

class Locatar
{
private:
    string nume;
    int nrLoc;
    int varsta;
    double* consumuriLoc;
    const double cota_indv_ch;
    static int nrMaxLocatari;

public:
    Locatar() : cota_indv_ch(0.2)
    {
        this->nume = "Picus Laurentiu";
        this->nrLoc = 8;
        this->varsta = 28;
        this->consumuriLoc = new double[this->varsta]();
    }

    Locatar(std::string nume, int nrLoc, int varsta, const double cota, double* consumuriLoc) :cota_indv_ch(cota)
    {
        this->nume = nume;
        this->nrLoc = nrLoc;
        this->varsta = varsta;
        this->consumuriLoc = new double[this->varsta];
        for (int i = 0; i < this->varsta; i++)
            this->consumuriLoc[i] = consumuriLoc[i];
    }

    Locatar(std::string nume, int nrLoc, const double cota, int* consumuriLoc) :cota_indv_ch(cota)
    {
        this->nume = nume;
        this->nrLoc = nrLoc;
        this->varsta = 34;
        this->consumuriLoc = new double[this->varsta];
        for (int i = 0; i < this->varsta; i++)
            this->consumuriLoc[i] = consumuriLoc[i];
    }

    void afisareLc()
    {
        cout << "Nume locatar: " << this->nume << "\nNumar Apartament: " << this->nrLoc <<
            "\nVarsta Locatar: " << this->varsta << "\nCota individuala de cheltuiala: " <<
            this->cota_indv_ch << "\nNumar maxim de locatari in apartament: " << this->nrMaxLocatari <<
            "\nConsumuri medii Locatar: ";
        for (int i = 0; i < this->varsta; i++)
            cout << this->consumuriLoc[i] << " ";
        cout << endl;
    }

    ~Locatar()
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

    Locatar& Locatar::operator=(const Locatar& locatar) //supraincarcarti operator=
    { 
        if (this != &locatar) {
            this->nume = locatar.nume;
            this->nrLoc = locatar.nrLoc;
            this->varsta = locatar.varsta;
            this->cota_indv_ch = locatar.cota_indv_ch;

            if (this->consumuriLoc != nullptr) {
                delete[] this->consumuriLoc;
            }

            this->consumuriLoc = new double[this->varsta];

            for (int i = 0; i < this->varsta; i++) {
                this->consumuriLoc[i] = locatar.consumuriLoc[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& consola, const Locatar& locatar) {
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

    friend istream& operator>>(istream& in, Locatar& locatar) {
        cout << "Nume locatar: "; in >> locatar.nume;

        cout << "Numar Apartament: "; in >> locatar.nrLoc;

        cout << "Varsta Locatar: "; in >> locatar.varsta;

        cout << "Cota individuala de cheltuiala: "; in >> locatar.cota_indv_ch;

        cout << "Numar maxim de locatari in apartament: "; in >> locatar.nrMaxLocatari;

        cout << "Consumuri medii Locatar: ";
        if (locatar.consumuriLoc != nullptr) {
            delete[] locatar.consumuriLoc;
        }
        locatar.consumuriLoc = new double[locatar.varsta];
        for (int i = 0; i < locatar.varsta; i++)
            in >> locatar.consumuriLoc[i];

        return in;
    }

    Locatar operator++(int) {
        Locatar temporar = *this;
        this->nrMaxLocatari++;
        return temporar;
    }

    Locatar operator--(int) {
        Locatar temporar = *this;
        this->nrMaxLocatari--;
        return temporar;
    }


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

    friend void afisareInformatiiLocatar(const Locatar& locatar);
};

int Locatar::nrMaxLocatari = 4;


void afisareLocatari()
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

void afisareInformatiiLocatar(const Locatar& locatar) {
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

void waitForKey()
{
    cout << "\n \n ~Apasa Enter pentru urmatorul obiect!";
    cin.ignore();
    cin.get();
}

void afisareNumarTotalApartamente(const Bloc& bloc) {
    int numarTotal = 0;
    for (int i = 0; i < bloc.nrEtaje; ++i) {
        numarTotal += bloc.nrApPeEtaj[i];
    }

    cout << "Numarul total de apartamente in blocul de pe adresa " << bloc.adresa << " este: " << numarTotal << endl;
}


void main()
{
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

    Bloc TestBloc("Strada Test 1", 3, "Chirias Test", "Test Administratie", new int[3] {2, 3, 4});
    cout << "\n \n-----> Afisare Numar Total Apartamente in Bloc \n " << afisareNumarTotalApartamente(TestBloc) << endl;

    cout << "\n \n-----> Testare operatori:" \n << endl;

    Bloc TestBl("Strada Test 1", 3, "Chirias Test", "Test Administratie", new int[3] {2, 3, 4});
    cout << "Numar total blocuri initial: " << Bloc::getNrTotalBl() << endl;
    TestBloc++;
    cout << "Numar total blocuri dupa operator++ pentru TestBloc: " << Bloc::getNrTotalBl() << endl;
    TestBloc--;
    cout << "Numar total blocuri dupa operator-- pentru TestBloc: " << Bloc::getNrTotalBl() << endl;

    Apartament TestApartament(60, 2, new int[2] {300, 400});
    cout << "Numar total apartamente initial: " << Apartament::getnrTotalAp() << endl;
    TestApartament++;
    cout << "Numar total apartamente dupa operator++ pentru TestApartament: " << Apartament::getnrTotalAp() << endl;
    TestApartament--;
    cout << "Numar total apartamente dupa operator-- pentru TestApartament: " << Apartament::getnrTotalAp() << endl;

    Locatar TestLocatar("Test Locatar", 1, 0.2, new double[30] {150, 160, 170});
    cout << "Numar maxim locatari initial: " << Locatar::getNrMaxLocatari() << endl;
    TestLocatar++;
    cout << "Numar maxim locatari dupa operator++ pentru TestLocatar: " << Locatar::getNrMaxLocatari() << endl;
    TestLocatar--;
    cout << "Numar maxim locatari dupa operator-- pentru TestLocatar: " << Locatar::getNrMaxLocatari() << endl;


    // *************************   FAZA 4    *****************************


  //Vector de obiecte Apartament
    Apartament vectorA[3];
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

    Jucator matriceA[2][3];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriceA[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriceA[i][j] << "----";
        }
        cout << endl;
    }
}