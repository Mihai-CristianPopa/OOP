#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <map>
using namespace std;

class Review {

protected:
    string clientName;
    int timeStayed;
    double grade;
public:
    Review() : Review("", 0, 0) {}

    Review(const string &numeClient, int durataSederii, double nota) : clientName(numeClient),
                                                                       timeStayed(durataSederii), grade(nota) {}

    friend ostream &operator<<(ostream &os, const Review &recenzie) {
        os << "clientName: " << recenzie.clientName << " , " << " timeStayed: " << recenzie.timeStayed << " , "
           << " grade: "
           << recenzie.grade;
        return os;
    }

    friend istream &operator>>(istream &is, Review &r) {
        cout << "clientName: ";
        is >> r.clientName;
        cout << "timeStayed: ";
        is >> r.timeStayed;
        cout << "grade: ";
        is >> r.grade;
        return is;
    }

    double getGrade() const {
        return grade;
    }

    void setClientName(const string &numeClient) {
        Review::clientName = numeClient;
    }

    void setTimeStayed(int durataSederii) {
        Review::timeStayed = durataSederii;
    }

    void setGrade(double nota) {
        Review::grade = nota;
    }

};
void addReviews(vector<Review> &reviews) {
    cout << " number of reviews: ";
    int in;
    cin >> in;
    for (int i = 0; i < in; i++) {
        Review tempReview;
        cin >> tempReview;
        reviews.push_back(tempReview);
    }
}

/// Here i have tried to play a bit with the random functions and generate my Reviews automatically
//void adaugaRecenziiRandom(vector<Review> &reviews) {
////    cout << " numar reviews: ";
//    int in = rand() % 5+1;
////    cin >> in;
//    Review recenzie;
//    srand(time(NULL));
//    string v[10]={"Liam", "Olivia", "Noah", "Emma", "Oliver", "Charlotte", "William", "Sophia","James", "Isabella"};
//    for (int i = 0; i < in; i++) {
//        recenzie.setClientName(v[(int)rand()%9]);
//        recenzie.setGrade(rand()%10+1);
//        recenzie.setTimeStayed(rand()%7+1);
//        reviews.push_back(recenzie);
//    }
//}


class Destination {
protected:
    string country;
    string city;
    string turisticAttraction;
    double price;
    vector<Review> reviews;
public:
    Destination() {
        country = "";
        city = "";
        turisticAttraction = "";
        price = 0;
        reviews.resize(0);
    }

    Destination(const string &tara, const string &oras, const string &denumire, double price,
                const vector<Review> &recenzii) : country(tara), city(oras), turisticAttraction(denumire), price(price),
                                                  reviews(recenzii) {}

    virtual void print() {
        cout << "[ ";
        cout << "country: " << country << " , " << "city: " << city << " , " << "turisticAttraction: " << turisticAttraction
             << " , " << "price: " << price << " , ";
        cout << "reviews :{";
        for (auto tempReview: reviews) {
            cout << tempReview << " ";
            reviews.pop_back();
        }
        cout << "}" << " , ";
    }

    friend ostream &operator<<(ostream &os, Destination &destination) {
        destination.print();
        return os;
    }



    virtual void input() {
        cout << "country: ";
        cin >> country;
        cout << " city: ";
        cin >> city;
        cout << " turisticAttraction: ";
        cin >> turisticAttraction;
        cout << " price: ";
        cin >> price;
        addReviews(reviews);
    }


    friend istream &operator>>(istream &is, Destination &destination) {
        destination.input();
        return is;
    }

    double getPrice() const {
        return price;
    }

    const string &getTara() const {
        return country;
    }

    const string &getOras() const {
        return city;
    }

    const string &getDenumire() const {
        return turisticAttraction;
    }

    double average() {
        double average = 0;
        double grade;
        int number = 0;
        for (auto tempReview: reviews) {
            number++;
            grade = tempReview.getGrade();
            average = average + grade;
        }
        return average / number;
        return 0;
    }

    int reviewNumber() {
        int nr = 0;
        for (auto tempReview: reviews) {
            nr++;
        }
        return nr;
        return 0;
    }

    const vector<Review> &getRecenzii() const {
        return reviews;
    }

};


class MountainTourism : public Destination {
private:
    double mountainPeak;
    double distanceToPeak;
    int routeNumber;
public:

    MountainTourism() : Destination(), mountainPeak(0), distanceToPeak(0), routeNumber(0) {};

    MountainTourism(const string &tara, const string &oras, const string &denumire, double price,
                    const vector<Review> &recenzii, double inaltimeVf, double distantaVf, int nrTrasee)
            : Destination(tara, oras, denumire, price, recenzii), mountainPeak(inaltimeVf), distanceToPeak(distantaVf),
              routeNumber(nrTrasee) {}

    void print() override {
        Destination::print();
        cout << "{ ";
        cout << "mountainPeak: " << mountainPeak << " , ";
        cout << "distanceToPeak: " << distanceToPeak << " , ";
        cout << "routeNumber: " << routeNumber << " } ]";
    }

    void input() override {
        Destination::input();
        cout << "mountainPeak: ";
        cin >> mountainPeak;
        cout << "distanceToPeak: ";
        cin >> distanceToPeak;
        cout << "routeNumber: ";
        cin >> routeNumber;
    }

};

class IslandTourism : public Destination {
private:
    int islandNumber;
    bool isAtTheSea;
    bool isAtTheOcean;
public:
    IslandTourism() : Destination(), islandNumber(0), isAtTheSea(0), isAtTheOcean(0) {};

    IslandTourism(const string &tara, const string &oras, const string &denumire, double price,
                  const vector<Review> &recenzii, int nrInsule, bool areIesireLaMare, bool areIesireLaOcean)
            : Destination(tara, oras, denumire, price, recenzii), islandNumber(nrInsule), isAtTheSea(areIesireLaMare),
              isAtTheOcean(areIesireLaOcean) {}

    void print() override {
        Destination::print();
        cout << "{ ";
        cout << "islandNumber: " << islandNumber << " , ";
        cout << "isAtTheSea: " << isAtTheSea << " , ";
        cout << "isAtTheOcean: " << isAtTheOcean << " } ]";
    }

    void input() override {
        Destination::input();
        cout << "islandNumber: ";
        cin >> islandNumber;
        cout << "isAtTheSea: ";
        cin >> isAtTheSea;
        cout << "isAtTheOcean: ";
        cin >> isAtTheOcean;
    }
};

Destination *createDestination() {
    int type;
    cout << "Destination type (0=mountain, 1=island): ";
    cin >> type;

    Destination *d = nullptr;
    if (type == 0) {
        d = new MountainTourism;
    } else if (type == 1) {
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
    double reducedValue;
public:
    MountainDiscount(double valoareRedusa = 0) : reducedValue(valoareRedusa) {}

    double discountedValue(Destination &d) {
        /// If it is a MountainDestination the function returns the initial price
        if (dynamic_cast<IslandTourism *>(&d)) {
            return d.getPrice();
        }
        double p = d.getPrice();
        return p - reducedValue;
    }

    friend istream &operator>>(istream &is, MountainDiscount &discount) {
        cout << "reducedValue: ";
        is >> discount.reducedValue;
        return is;
    }
};

class IslandDiscount {
private:
    double reducedValue;
public:
    IslandDiscount(double valoareRedusa = 0) : reducedValue(valoareRedusa) {}

    double discountedValue(Destination &d) {
        ///If it is an IslandDestination the function returns the initial price
        if (dynamic_cast<MountainTourism *>(&d)) {
            return d.getPrice();
        }
        double p = d.getPrice();
        return p - reducedValue;
    }

    friend istream &operator>>(istream &is, IslandDiscount &discount) {
        cout << "reducedValue: ";
        is >> discount.reducedValue;
        return is;
    }
};

class PercentileDiscount {
private:
    double percentileDiscount;
public:
    PercentileDiscount(double procentReducere = 0) : percentileDiscount(procentReducere) {}

    friend istream &operator>>(istream &is, PercentileDiscount &discount) {
        cout << "percentileDiscount: ";
        is >> discount.percentileDiscount;
        if (discount.percentileDiscount >= 50) { throw 1; }
        return is;
    }

    double discountedValue(Destination &d) {
        double p = d.getPrice();
        return p = p * (100 - percentileDiscount) / 100;
    }

    double getPercentileDiscount() const {
        return percentileDiscount;
    }
};



class TravelAgency {
protected:
    vector<Destination *> destinations;
    MountainDiscount md;
    IslandDiscount id;
    PercentileDiscount pd;
/// 1. Implementation of a singleton class
/// The constructor is private
private:
    TravelAgency(const vector<Destination *> &_destinations, const MountainDiscount &md, const IslandDiscount &id,
                 const PercentileDiscount &pd) : md(md), id(id), pd(pd) {
        for (auto *destination: _destinations) {
            destinations.push_back(allocate(destination));
            if (pd.getPercentileDiscount() > 50) { throw 1; }
        }
    }


    TravelAgency(const vector<Destination *> &_destinations) {
        for (auto *destination: _destinations) {
            destinations.push_back(allocate(destination));
        }
    }

    /// 2. We make a static pointer towards TravelAgency such that we can save an instance over here

public:
    static TravelAgency *app;


    /// 3. In the static function, if app doesn't exist we create it, otherwise we return the already existent app

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

/// Here is the form of the constructors before implementing the singleton class

public:

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

//    map<Destination*, vector<Review*> > reviews(){
//        map <Destination*, vector<Review*> > rev;
//    }
//
//
//    map<Review*, Destination*> reviewsDestination(){
//        map<Review*, Destination*> rev2;
//        vector <Review> reviews;
//        adaugaRecenziiRandom(reviews);
//        for (auto recenzie : reviews){
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

    float reducedPrice(Destination *destination) {
        float pret1 = pd.discountedValue(*destination);
        float pret2 = id.discountedValue(*destination);
        float pret3 = md.discountedValue(*destination);
        /// return the minimum
        return min(pret1, min(pret2, pret3));
    }

    void print() {
        for (auto *destination: destinations) {
            cout << "{ ";
            cout << "Denumirea destinatiei: " << destination->getDenumire() << " , ";
            cout << "Orasul: " << destination->getOras() << " , ";
            cout << "Tara: " << destination->getTara() << " , ";
            cout << "Numarul de reviewuri: " << destination->reviewNumber() << " , ";
            cout << "Media recenziilor: " << destination->average() << " , ";
            cout << "Pretul dupa discount: " << reducedPrice(destination);

            cout << "}" << endl;
        }
    }

    void printDestinations() {
        for (auto *destination: destinations) {
            cout << *destination << " , ";
        }
        cout << endl;
    }

    void showMenu() {
        cout << "1. Add destinations " << endl;
        cout << "2. Delete destinations " << endl;
        cout << "3. Show Destinations" << endl;
        cout << "4. Task 4 " << endl;
        cout << "5. Change the discounts" << endl;
        cout << "6. Exit" << endl;
    }

    void run() {
        int option;
        while (true) {
            showMenu();
            cout << "Option: ";
            cin >> option;

            if (option == 1) {
                addDestination();
            } else if (option == 2) {
                deleteDestination();
            } else if (option == 3) {
                printDestinations();
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

/// We initialize the static variable with nullptr

TravelAgency *TravelAgency::app = nullptr;

int main() {
    vector<Review>  r = {{"Marian", 5, 8.5},
                         {"Ion",    2, 7}};
    vector <Review> r1,r2,r3,r4;
    cout <<"addReviews1: ";
    addReviews(r1);
    cout <<"addReviews2: ";
    addReviews(r2);
    cout <<"addReviews3: ";
    addReviews(r3);
    cout <<"addReviews4:" << endl;
    addReviews(r4);
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

