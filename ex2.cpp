
#include <iostream>
using namespace std;

// Classe abstraite
class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;

    virtual ~Paiement() {}
};

// Paiement par carte bancaire
class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH par carte bancaire." << endl;
    }
};

// Paiement en especes
class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH en especes." << endl;
    }
};

// Programme principal
int main() {

    // Tableau de pointeurs
    Paiement* paiements[3];

    // Creation des objets
    paiements[0] = new PaiementCarte();
    paiements[1] = new PaiementEspece();
    paiements[2] = new PaiementCarte();

    // Montants des paiements
    double montants[3] = {500, 200, 350};

    // Simulation des paiements
    cout << "--- Simulation des paiements ---" << endl;

    for (int i = 0; i < 3; i++) {
        paiements[i]->effectuerPaiement(montants[i]);
    }

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete paiements[i];
    }

    return 0;
}
