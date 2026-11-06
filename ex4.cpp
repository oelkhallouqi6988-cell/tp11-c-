
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe abstraite
class NoeudFichier {
public:
    virtual string nom() const = 0;

    virtual int taille() const = 0;

    virtual ~NoeudFichier() {}
};

// Classe Fichier
class Fichier : public NoeudFichier {
private:
    string nomF;
    int tailleF;

public:
    Fichier(string n, int t) {
        nomF = n;
        tailleF = t;
    }

    string nom() const override {
        return nomF;
    }

    int taille() const override {
        return tailleF;
    }
};

// Classe Dossier
class Dossier : public NoeudFichier {
private:
    string nomD;
    vector<NoeudFichier*> enfants;

public:
    Dossier(string n) {
        nomD = n;
    }

    string nom() const override {
        return nomD;
    }

    // Ajouter un fichier ou un sous-dossier
    void ajouter(NoeudFichier* element) {
        enfants.push_back(element);
    }

    // Calculer la taille totale du dossier
    int taille() const override {
        int total = 0;

        for (int i = 0; i < enfants.size(); i++) {
            total += enfants[i]->taille();
        }

        return total;
    }

    // Afficher les elements du dossier
    void afficher() const {
        cout << "\nDossier : " << nomD << endl;

        for (int i = 0; i < enfants.size(); i++) {
            cout << enfants[i]->nom()
                 << " - Taille : "
                 << enfants[i]->taille() << " Ko"
                 << endl;
        }
    }

    // Liberer la memoire des enfants
    ~Dossier() {
        for (int i = 0; i < enfants.size(); i++) {
            delete enfants[i];
        }
    }
};

// Programme principal
int main() {

    // Creation du dossier principal
    Dossier* principal = new Dossier("Documents");

    // Creation des fichiers
    Fichier* f1 = new Fichier("Cours.txt", 100);
    Fichier* f2 = new Fichier("Exercice.pdf", 200);

    // Creation d'un sous-dossier
    Dossier* sousDossier = new Dossier("Programmation");

    // Ajout d'un fichier dans le sous-dossier
    sousDossier->ajouter(new Fichier("Code.cpp", 150));

    // Ajout des elements dans le dossier principal
    principal->ajouter(f1);
    principal->ajouter(f2);
    principal->ajouter(sousDossier);

    // Affichage
    cout << "--- Systeme de fichiers ---" << endl;

    principal->afficher();
    sousDossier->afficher();

    cout << "\nTaille totale du dossier "
         << principal->nom() << " : "
         << principal->taille() << " Ko" << endl;

    cout << "Taille totale du sous-dossier "
         << sousDossier->nom() << " : "
         << sousDossier->taille() << " Ko" << endl;

    // Liberation de la memoire
    delete principal;

    return 0;
}
