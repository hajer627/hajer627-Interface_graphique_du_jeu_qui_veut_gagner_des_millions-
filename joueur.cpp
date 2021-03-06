#include "joueur.h"

joueur::joueur(string ch)
{
    nom = ch;
    score = 500;
}


bool joueur::verif(const int& x)const
{
    return(tabjocker[x] == 1);
}
void joueur::settabjocker(const int& x)
{
    tabjocker[x] = 0;
}

void joueur::setgain(int& a)///****
{
    switch (a)
    {
    case 1:
    {score += 900;
    break; }
    case 2:
    {score += 9000;
    break; }
    case 3:
    {score += 190000;
    break; }
    }
    cout << "             gain " << score << endl;
}

void joueur::setscore(int& a)///***
{
    switch (a)
    {
    case 1:
    {score = 500; break; }
    case 2:
    {score = 5000; break; }
    case 3:
    {score = 50000; break; }
    }
}

int joueur::getid() const
{
    return id;
}
void joueur::setid()
{
    int x = 0;

    ifstream entree("id.txt", ios::in);
    if (entree)
    {
        string ligne;
        string ch;

        while (getline(entree, ligne))
        {
            if (!ligne.empty())
                ch = ligne;
        };

        x = stoi(ch) + 1;
        id = x;
    }
    else
    {
        //cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    entree.close();
    ofstream sortie("id.txt", ios::app);
    sortie << x << endl;
    sortie.close();
}


string joueur::getnom() const
{
    return(nom);
}
int joueur::getscore() const
{
    return(score);
}
void joueur::afficher() const
{
    //cout << id << setw(15) << nom << setw(10) << score << setw(6) << endl;
}