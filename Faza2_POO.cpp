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

    Apartament(const Apartament& apartament) : NR_MAXIM_DE_PERS(apartament.NR_MAXIM_DE_PERS)
    {
        suprafata = apartament.suprafata;
        nrCamere = apartament.nrCamere;
        nrTotalAp = apartament.nrTotalAp;
        costuriApartament = apartament.costuriApartament;
    
        if (nrCamere > 0) 
        {
            costuriApartament = new int[nrCamere];
            for (int i = 0; i < nrCamere; i++) 
            {
                costuriApartament[i] = apartament.costuriApartament[i];
            }
        }
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

    
    Bloc(const Bloc& bloc) : NUME_COMPANIE_ADMIN(bloc.NUME_COMPANIE_ADMIN) 
    {

        adresa = bloc.adresa; 
        nrEtaje = bloc.nrEtaje;
        chirias = bloc.chirias; 
        nrTotalBl = bloc.nrTotalBl;
        nrApPeEtaj = bloc.nrApPeEtaj;

        if (nrEtaje > 0) 
        {
            nrApPeEtaj = new int[nrEtaje];
            for (int i = 0; i < nrEtaje; i++) 
            {
                nrApPeEtaj[i] = bloc.nrApPeEtaj[i];
            }
        }
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
};

int Bloc::nrTotalBl = 5;

void afisareBlocuri()
{
    cout << " \n \n -------- LISTA BLOCURI --------" << endl;
    Bloc B22;
    Bloc C4("Mihai Bravu 14", 8, "Ene Mihail", "NETLINK Administratie", new int[8] {6, 7, 8, 9, 10, 11, 12, 13});
    Bloc Bis8("Calea Vacaresti 6", "Ion Vasile", "FRONTLIFE Administratie", new int[4] {1, 2, 3, 4});
    B22.afisareBl();
    cout << "\n" << endl;
    C4.afisareBl();
    cout << "\n" << endl;
    Bis8.afisareBl();

    Bloc CopieC4 = C4; 

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


    Locatar(const Locatar& locatar) : cota_indv_ch(locatar.cota_indv_ch)
    {
        nume = locatar.nume;
        nrLoc = locatar.nrLoc; 
        varsta = locatar.varsta;
        nrMaxLocatari = locatar.nrMaxLocatari;
        consumuriLoc = locatar.consumuriLoc;

        if (varsta > 0) 
        {
            consumuriLoc = new double[varsta];
            for (int i = 0; i < varsta; i++) 
            {
                consumuriLoc[i] = locatar.consumuriLoc[i];
            }
        }
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
    cout << " \n \n -------- LISTA LOCATARI --------" << endl;
    Locatar Picus;
    Locatar Anghel("Anghel Melania", 10, 62, 0.7, new double[62] {250, 260, 270, 280});
    Locatar Popescu("Pop Adrian", 22, 1.0, new int[34] {340, 350, 360, 370, 380, 390, 400});
    Picus.afisareLc();
    cout << "\n" << endl;
    Anghel.afisareLc();
    cout << "\n" << endl;
    Popescu.afisareLc();

    cout << "\n ---> Test functie:" << endl;
    afisareInformatiiLocatar(Picus);

    Locatar CopiePicus = Picus;  
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


}