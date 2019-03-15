#include <iostream>
#include <math.h>
#include <fstream>
// TODO: Langues.

using namespace std;
bool errBadVAlue ( string texteBadValue, auto min, auto max )
{
    cerr << "Min = "  << min << endl;
    cerr << "Max = "  << max << endl;
    cerr << texteBadValue << endl;
    return false;
}

auto inputNb ( auto max = 42, auto min = 0, string texteDemande = "How many?", string texteBadValue = "A good number!" )
{
    if ( max < min ) // En général, on donne le minimum avant le maximum, et parfois pas la valeur par défaut.
        {
        auto temp = max;
        max = min;
        min = temp;
        }
// Textes par défaut par fichier lgg ?

    auto a = max; // Valeur valide.
    string tentativeString = "";
    bool inputOk  = true;
    do
        {
        cout << texteDemande << endl;
        inputOk = true; // Pour autre demande éventuelle.
        try
            {
            getline ( cin, tentativeString ); // Pour éviter des bugs de non nombre.
            }
        catch ( const std::invalid_argument& e )
            {
            cerr << "Standard exception: " << e.what() << endl;
            inputOk = errBadVAlue ( texteBadValue, min, max );
            }
        try
            {
            a = stoi ( tentativeString ); // cin.;
            }
        catch ( exception& e ) // Nombre dépassant la limite : 99999999999999999999999999999999 par exemple.
            {
            cerr << "Standard exception: " << e.what() << endl;
            inputOk = errBadVAlue ( texteBadValue, min, max );
            }
        if ( ( a < min ) || ( a > max ) )
            {
            a = max; // Valeur valide.
            inputOk = errBadVAlue ( texteBadValue, min, max );
            }
        }
    while ( inputOk == false );
    return a;
}

int main()
{

    cout << "Ce logiciel donne la longueur de bois à prévoir pour les pièces d'échecs. \n Généralement on a besoin d'environ un mètre et demi par couleur !" << endl;
    cout << "On prévoit une couleur, on l'affiche." << endl;
    cout << "Puis on affiche le double pour les 2 couleurs." << endl;
    cout << "Toutes les dimensions sont en millimètres, arrondies à la valeur supérieure." << endl; // unsigned int  : 65535 max.
    cout << "Les hauteurs demandées sont les hauteurs en bois : \n si vous voulez ajouter une base en feutre, cela ne compte pas.\n" << endl;
    cout << "Quel est le nom du fichier pour la sauvegarde ? \n (Avec l'extension, en ajout.) \n Attention : Si le nom n'est pas valide, par exemple vide : pas de sauvegarde." << endl;
    string file = "";)
    getline ( cin, file );

    cout << "Je vais supposer que vous utilisez une seule lame." << endl;
    // Ordre choisi : le plus facile à comprendre, progressif. Pas l'ordre de placement, ni de valeur croissante.
    unsigned int lame = inputNb ( 1, 42, "Quelle est la largeur de cette lame, en mm ? \n(Ajoutez-y une marge éventuelle.)", "Un nombre normal !" );
    unsigned int pion = inputNb ( 1, 4200, "Quelle est la hauteur de chaque pion, en mm ? \n(Sa valeur vaut 1.)", "Un nombre normal !" ); // 1 mm = une rondelle avec une image dessus.
    unsigned int tour = inputNb ( 1, 4200, "Quelle est la hauteur de chaque tour, en mm ? \n(Sa valeur vaut 5.)", "Un nombre normal !" );
    unsigned int cavalier = inputNb ( 1, 4200, "Quelle est la hauteur de chaque cavalier, en mm ? \n(Sa valeur vaut 3.)", "Un nombre normal !" );
    unsigned int dame = inputNb ( 1, 4200, "Quelle est la hauteur de chaque dame, en mm ? \n(Sa valeur vaut 9. Deux dames par couleur !)", "Un nombre normal !" );
    unsigned int roi = inputNb ( 1, 4200, "Quelle est la hauteur du roi, en mm ? \n(Sa valeur vaut 4 en attaque, la partie en défense. \n En général, on y donne la même valeur que la dame.)", "Un nombre normal !" );
    unsigned int fou = inputNb ( 1, 4200, "Quelle est la hauteur de chaque fou, en mm ? \n(Sa valeur vaut 4 pour le premier pris de chaque camp, et 3 pour l\'autre.)", "Un nombre normal !" );
    cout << "Pour chaque couleur (blanc ou noir) : ";
    unsigned int longueurBois = ( 16 * lame ) + ( 8 * pion ) + ( 2 * tour ) + ( 2 * cavalier ) + ( 2 * fou ) + ( 2 * dame ) + ( 1 * roi );
    cout << longueurBois << " mm. " << endl;
    cout << "Donc au total : ";

    unsigned int longueurBoisTotale = 2 * longueurBois;
    cout << longueurBoisTotale << " mm. " << endl;




    ofstream ajouteFichier ( file.c_str(), ios::app );
    if ( !ajouteFichier )
        {
        cerr << "Impossible to open the file!" << endl;
        clog << "Pas de sauvegarde." << endl;
        }
    else
        {
        ajouteFichier << "Par ordre de placement, vous avez indiqué, pour chaque objet :" << endl;
        ajouteFichier << "Lame : " << lame << " mm" << endl;
        ajouteFichier << "Pion : " << pion << " mm" << endl;
        ajouteFichier << "Tour : " << tour << " mm" << endl;
        ajouteFichier << "Cavalier : " << cavalier << " mm" << endl;
        ajouteFichier << "Fou : " << fou << " mm" << endl;
        ajouteFichier << "Dame : " << dame << " mm" << endl;
        ajouteFichier << "Roi : " << roi << " mm" << endl;
         ajouteFichier << "Pour chaque couleur (blanc ou noir) : " << longueurBois << " mm" << endl;
         ajouteFichier << "Donc au total : " << longueurBoisTotale << " mm" << endl;
                 }
    ajouteFichier.close();


    return 0;
}

