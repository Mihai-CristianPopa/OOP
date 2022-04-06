#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Recenzie {

protected:
    string numeClient;
    int durataSederii;
    double nota;
public:
    Recenzie() : Recenzie("", 0, 0) {}

    Recenzie(const string &numeClient, int durataSederii, double nota) : numeClient(numeClient),
                                                                         durataSederii(durataSederii), nota(nota) {}

    friend ostream &operator<<(ostream &os, const Recenzie &recenzie) {
        os << "numeClient: " << recenzie.numeClient << " , " << " durataSederii: " << recenzie.durataSederii << " , "
           << " nota: "
           << recenzie.nota;
        return os;
    }

    friend istream &operator>>(istream &is, Recenzie &r) {
        cout << "numeClient: ";
        is >> r.numeClient;
        cout << "durataSederii: ";
        is >> r.durataSederii;
        cout << "nota: ";
        is >> r.nota;
        return is;
    }

    double getNota() const {
        return nota;
    }

    void setNumeClient(const string &numeClient) {
        Recenzie::numeClient = numeClient;
    }

    void setDurataSederii(int durataSederii) {
        Recenzie::durataSederii = durataSederii;
    }

    void setNota(double nota) {
        Recenzie::nota = nota;
    }

};
void adaugaRecenzii(vector<Recenzie> &recenzii) {
    cout << " numar recenzii: ";
    int in;
    cin >> in;
    for (int i = 0; i < in; i++) {
        Recenzie recenzie;
        cin >> recenzie;
        recenzii.push_back(recenzie);
    }
}
//void adaugaRecenziiRandom(vector<Recenzie> &recenzii) {
////    cout << " numar recenzii: ";
//    int in = rand() % 5+1;
////    cin >> in;
//    Recenzie recenzie;
//    srand(time(NULL));
//    string v[10]={"Liam", "Olivia", "Noah", "Emma", "Oliver", "Charlotte", "William", "Sophia","James", "Isabella"};
//    for (int i = 0; i < in; i++) {
//        recenzie.setNumeClient(v[(int)rand()%9]);
//        recenzie.setNota(rand()%10+1);
//        recenzie.setDurataSederii(rand()%7+1);
//        recenzii.push_back(recenzie);
//    }
//}


class Destination {
protected:
    string tara;
    string oras;
    string denumire;
    double price;
    vector<Recenzie> recenzii;
public:
    Destination() {
        tara = "";
        oras = "";
        denumire = "";
        price = 0;
        recenzii.resize(0);
    }

    Destination(const string &tara, const string &oras, const string &denumire, double price,
                const vector<Recenzie> &recenzii) : tara(tara), oras(oras), denumire(denumire), price(price),
                                                    recenzii(recenzii) {}

    virtual void afisare() {
        cout << "[ ";
        cout << "tara: " << tara << " , " << "oras: " << oras << " , " << "denumire: " << denumire
             << " , " << "price: " << price << " , ";
        cout << "recenzii :{";
        for (auto recenzie: recenzii) {
            cout << recenzie << " ";
            recenzii.pop_back();
        }
        cout << "}" << " , ";
    }

    friend ostream &operator<<(ostream &os, Destination &destination) {
        destination.afisare();
        return os;
    }

//    void adaugaRecenzii() {
//        cout << " numar recenzii: ";
//        int in;
//        cin >> in;
//        for (int i = 0; i < in; i++) {
//            Recenzie recenzie;
//            cin >> recenzie;
//            recenzii.push_back(recenzie);
//        }
//    }

    virtual void citire() {
        cout << "tara: ";
        cin >> tara;
        cout << " oras: ";
        cin >> oras;
        cout << " denumire: ";
        cin >> denumire;
        cout << " price: ";
        cin >> price;
        adaugaRecenzii(recenzii);
    }


    friend istream &operator>>(istream &is, Destination &destination) {
        destination.citire();
        return is;
    }

    double getPrice() const {
        return price;
    }

    const string &getTara() const {
        return tara;
    }

    const string &getOras() const {
        return oras;
    }

    const string &getDenumire() const {
        return denumire;
    }

    double media() {
        double media = 0;
        double nota;
        int nr = 0;
        for (auto recenzie: recenzii) {
            nr++;
            nota = recenzie.getNota();
            media = media + nota;
        }
        return media / nr;
        return 0;
    }

    int nrRecenzii() {
        int nr = 0;
        for (auto recenzie: recenzii) {
            nr++;
        }
        return nr;
        return 0;
    }

    const vector<Recenzie> &getRecenzii() const {
        return recenzii;
    }

};


class MountainTourism : public Destination {
private:
    double inaltimeVf;
    double distantaVf;
    int nrTrasee;
public:

    MountainTourism() : Destination(), inaltimeVf(0), distantaVf(0), nrTrasee(0) {};

    MountainTourism(const string &tara, const string &oras, const string &denumire, double price,
                    const vector<Recenzie> &recenzii, double inaltimeVf, double distantaVf, int nrTrasee)
            : Destination(tara, oras, denumire, price, recenzii), inaltimeVf(inaltimeVf), distantaVf(distantaVf),
              nrTrasee(nrTrasee) {}

    void afisare() override {
        Destination::afisare();
        cout << "{ ";
        cout << "inaltimeVf: " << inaltimeVf << " , ";
        cout << "distantaVf: " << distantaVf << " , ";
        cout << "nrTrasee: " << nrTrasee << " } ]";
    }

    void citire() override {
        Destination::citire();
        cout << "inaltimeVf: ";
        cin >> inaltimeVf;
        cout << "distantaVf: ";
        cin >> distantaVf;
        cout << "nrTrasee: ";
        cin >> nrTrasee;
    }

};

class IslandTourism : public Destination {
private:
    int nrInsule;
    bool areIesireLaMare;
    bool areIesireLaOcean;
public:
    IslandTourism() : Destination(), nrInsule(0), areIesireLaMare(0), areIesireLaOcean(0) {};

    IslandTourism(const string &tara, const string &oras, const string &denumire, double price,
                  const vector<Recenzie> &recenzii, int nrInsule, bool areIesireLaMare, bool areIesireLaOcean)
            : Destination(tara, oras, denumire, price, recenzii), nrInsule(nrInsule), areIesireLaMare(areIesireLaMare),
              areIesireLaOcean(areIesireLaOcean) {}

    void afisare() override {
        Destination::afisare();
        cout << "{ ";
        cout << "nrInsule: " << nrInsule << " , ";
        cout << "areIesireLaMare: " << areIesireLaMare << " , ";
        cout << "areIesireLaOcean: " << areIesireLaOcean << " } ]";
    }

    void citire() override {
        Destination::citire();
        cout << "nrInsule: ";
        cin >> nrInsule;
        cout << "areIesireLaMare: ";
        cin >> areIesireLaMare;
        cout << "areIesireLaOcean: ";
        cin >> areIesireLaOcean;
    }
};

Destination *createDestination() {
    int tip;
    cout << "Tip destinatie (0=munte, 1=mare): ";
    cin >> tip;

    Destination *d = nullptr;
    if (tip == 0) {
        d = new MountainTourism;
    } else if (tip == 1) {
        d = new IslandTourism;
    }

    if (d) {
        cin >> *d;
    }
    return d;
}

Destination *allocate(Destination *d) {
    auto *asMountainTourism = dynamic_cast<MountainTourism *>(d);
    auto *asIslandTourism = dynamic_cast <IslandTourism * > (d);
    if (asIslandTourism) {
        return new IslandTourism(*asIslandTourism);
    } else if (asMountainTourism) {
        return new MountainTourism(*asMountainTourism);
    }
    return nullptr;
}

class MountainDiscount {
private:
    double valoareRedusa;
public:
    MountainDiscount(double valoareRedusa = 0) : valoareRedusa(valoareRedusa) {}

    double valoareDupaReducere(Destination &d) {
        // TODO daca este Mountains, returnezi pretul original
        if (dynamic_cast<IslandTourism *>(&d)) {
            return d.getPrice();
        }
        double p = d.getPrice();
        return p - valoareRedusa;
    }

    friend istream &operator>>(istream &is, MountainDiscount &discount) {
        cout << "valoareRedusa: ";
        is >> discount.valoareRedusa;
        return is;
    }
};

class IslandDiscount {
private:
    double valoareRedusa;
public:
    IslandDiscount(double valoareRedusa = 0) : valoareRedusa(valoareRedusa) {}

    double valoareDupaReducere(Destination &d) {
        // TODO daca este Mountains, returnezi pretul original
        if (dynamic_cast<MountainTourism *>(&d)) {
            return d.getPrice();
        }
        double p = d.getPrice();
        return p - valoareRedusa;
    }

    friend istream &operator>>(istream &is, IslandDiscount &discount) {
        cout << "valoareRedusa: ";
        is >> discount.valoareRedusa;
        return is;
    }
};

class PercentileDiscount {
private:
    double procentReducere;
public:
    PercentileDiscount(double procentReducere = 0) : procentReducere(procentReducere) {}

    friend istream &operator>>(istream &is, PercentileDiscount &discount) {
        cout << "procentReducere: ";
        is >> discount.procentReducere;
        if (discount.procentReducere >= 50) { throw 1; }
        return is;
    }

    double valoareDupaReducere(Destination &d) {
        double p = d.getPrice();
        return p = p * (100 - procentReducere) / 100;
    }

    double getProcentReducere() const {
        return procentReducere;
    }
};

#include <map>

class TravelAgency {
protected:
    vector<Destination *> destinations;
    MountainDiscount md;
    IslandDiscount id;
    PercentileDiscount pd;

private: // TODO 1
    TravelAgency(const vector<Destination *> &_destinations, const MountainDiscount &md, const IslandDiscount &id,
                 const PercentileDiscount &pd) : md(md), id(id), pd(pd) {
        for (auto *destination: _destinations) {
            destinations.push_back(allocate(destination));
            if (pd.getProcentReducere() > 50) { throw 1; }
        }
    }


    TravelAgency(const vector<Destination *> &_destinations) {
        for (auto *destination: _destinations) {
            destinations.push_back(allocate(destination));
        }
    }
    /// TODO 2   pastram un pointer static, catre TravelAgency, ca sa putem retine o instanta aici
public:
    static TravelAgency *app;

    // TODO 4 in functia static, daca app nu exista o cream, altfel returnap app care deja exista
    static TravelAgency *
    create(const vector<Destination *> &_destinations, const MountainDiscount &md, const IslandDiscount &id,
           const PercentileDiscount &pd) {
        if (app==0) {
            app = new TravelAgency(_destinations, md, id, pd);
            return app;
        } else {
            return app;
        }
    }

public:
//    TravelAgency(const vector<Destination *> &_destinations, const MountainDiscount &md, const IslandDiscount &id,
//                 const PercentileDiscount &pd) : md(md), id(id), pd(pd) {
//        for (auto *destination: _destinations) {
//            destinations.push_back(allocate(destination));
//            if (pd.getProcentReducere() > 50) { throw 1; }
//        }
//    }
//
//
//    TravelAgency(const vector<Destination *> &_destinations) {
//        for (auto *destination: _destinations) {
//            destinations.push_back(allocate(destination));
//        }
//    }
    map<Destination *, int> mapare() {

        map < Destination * , int > tip;

        for (auto *destination: destinations) {
            if (dynamic_cast<MountainTourism *>(destination)) {
                tip[destination] = 1;
            }
            if (dynamic_cast<IslandTourism *>(destination)) {
                tip[destination] = 2;
            }
        }

//        tip[destinations[3]]; // ne va spune tipul celui de-al patrulea element

        return tip;

    }
    map<int, vector<Destination*> > mapareInversa() {

        map<int, vector<Destination*> > deUnTip;
        deUnTip [1] = {};
        deUnTip [2] = {};

        for (auto *destination: destinations) {
            if (dynamic_cast<MountainTourism *>(destination)) {
                deUnTip[1].push_back(destination);
            }
            if (dynamic_cast<IslandTourism *>(destination)) {
                deUnTip[2].push_back(destination);
            }
        }

//        deUnTip[1]; // ne va spune toate destinatiile de acel tip.
        return deUnTip;

    }
///    Prima functie va calcula asocierea dintre fiecare destinatie in parte si recenziile acesteia,
///    iar cea de-a doua va retine pentru fiecare recenzie in parte destinatia din care aceasta face parte.
///    Aveti grija ca daca implementati aceasta functie, veti castiga pana la +2.5p bonus complex.

//    map<Destination*, vector<Recenzie*> > reviews(){
//        map <Destination*, vector<Recenzie*> > rev;
//    }
//
//
//    map<Recenzie*, Destination*> reviewsDestination(){
//        map<Recenzie*, Destination*> rev2;
//        vector <Recenzie> recenzii;
//        adaugaRecenziiRandom(recenzii);
//        for (auto recenzie : recenzii){
//        for(auto* destination : destinations){
//            for (auto recenzie : destination->getRecenzii())
//                rev2[recenzie].push_back(*destination);
//        }}
//    }



    friend ostream &operator<<(ostream &os, TravelAgency &agency) {
        os << "destinations: {";
        for (auto *destination: agency.destinations) {
            cout << *destination << endl;
            agency.destinations.pop_back();
        }
        os << "}";
        return os;
    }

    void addDestination() {
        destinations.push_back(createDestination());
    };

    void deleteDestination() {
        destinations.pop_back();
    }

    void changeDiscounts() {
        cout << "Mountain Discount: ";
        cin >> md;
        cout << "Island Discount: ";
        cin >> id;
        cout << "Percentile Discount: ";
        cin >> pd;
    }

    float pretRedus(Destination *destination) {
        float pret1 = pd.valoareDupaReducere(*destination);
        float pret2 = id.valoareDupaReducere(*destination);
        float pret3 = md.valoareDupaReducere(*destination);
        // returnam minimul:
        return min(pret1, min(pret2, pret3));
    }

    void print() {
        for (auto *destination: destinations) {
            cout << "{ ";
            cout << "Denumirea destinatiei: " << destination->getDenumire() << " , ";
            cout << "Orasul: " << destination->getOras() << " , ";
            cout << "Tara: " << destination->getTara() << " , ";
            cout << "Numarul de reviewuri: " << destination->nrRecenzii() << " , ";
            cout << "Media recenziilor: " << destination->media() << " , ";
            cout << "Pretul dupa discount: " << pretRedus(destination);
//            if (dynamic_cast<MountainTourism *>(destination)) {
//                if (md.valoareDupaReducere(*destination) < pd.valoareDupaReducere(*destination))
//                    cout << md.valoareDupaReducere(*destination) << endl;
//                else
//                    cout << pd.valoareDupaReducere(*destination) << endl;
//            }
//            if (dynamic_cast<IslandTourism *>(destination)) {
//                if (id.valoareDupaReducere(*destination) < pd.valoareDupaReducere(*destination))
//                    cout << id.valoareDupaReducere(*destination) << endl;
//                else
//                    cout << pd.valoareDupaReducere(*destination) << endl;
//            }
            cout << "}" << endl;
        }
    }

    void afisDestinatii() {
        for (auto *destination: destinations) {
            cout << *destination << " , ";
        }
        cout << endl;
    }

    void showMenu() {
        cout << "1. Adauga destinatii " << endl;
        cout << "2. Sterge destinatii " << endl;
        cout << "3. Afiseaza Destinatii" << endl;
        cout << "4. Cerinta 4 " << endl;
        cout << "5. Schimba Discounturile" << endl;
        cout << "6. Exit" << endl;
    }

    void run() {
        int option;
        while (true) {
            showMenu();
            cout << "Optiune: ";
            cin >> option;

            if (option == 1) {
                addDestination();
            } else if (option == 2) {
                deleteDestination();
            } else if (option == 3) {
                afisDestinatii();
            } else if (option == 4) {
                print();
            } else if (option == 5) {
                changeDiscounts();
            } else {
                break;
            }
        }
    }
};

// TODO 3  initializam cu null var. statica
TravelAgency *TravelAgency::app = nullptr;

int main() {
    vector<Recenzie>  r = {{"Marian", 5, 8.5},
                          {"Ion",    2, 7}};
    vector <Recenzie> r1,r2,r3,r4;
    cout <<"adaugaRecenzii1: ";
    adaugaRecenzii(r1);
    cout <<"adaugaRecenzii2: ";
    adaugaRecenzii(r2);
    cout <<"adaugaRecenzii3: ";
    adaugaRecenzii(r3);
    cout <<"adaugaRecenzii" << endl;
    adaugaRecenzii(r4);
    for(auto i : r1){cout << i<< " , " << endl;}
    for(auto i : r2){cout << i << " , " << endl;}
    for(auto i : r3){cout << i << " , " << endl;}

    vector<Destination *> v{
            new IslandTourism("USA", "Hawaii", "Maui", 1000, r, 7, 0, 1),
            new MountainTourism("Austria", "Insbruck", "smth", 2000, r1, 4000, 500, 8),
            new IslandTourism("Maldive", "M", "smth", 1500, r2, 4, 0, 1),
            new MountainTourism("Romania", "Predeal", "Clabucet", 500, r3, 1500, 200, 3),
            new MountainTourism("Romania", "Poiana Brasov", "Bradul", 1000, r4, 2000, 400, 5)
    };

    try {
//        TravelAgency t(v,300,500,5);
//        t.run();
        TravelAgency *app = TravelAgency::create(v, 300, 500, 5);
        app->run();
//        for(const auto& elem : app->mapare())
//        {
//            cout << *elem.first << " , " << elem.second<<endl;
//    }
//        for (const auto& elem : app->mapareInversa()){
//            cout << elem.first << " , " ;
//            for (auto e : elem.second){
//                cout << *e << " , ";
//            }
//            cout << endl;
//        }
    }
    catch (int err) {
        if (err == 1) {
            cout << "The percentile discount has to be smaller than 50% ";
        }
    }
    return 0;
}

