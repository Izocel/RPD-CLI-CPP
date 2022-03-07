#include "TestItems.h"

int TestItems::findClasse(const Role& roleJoueur, vector<const Role*> rolesArme) {
    int index = -1;
    const size_t n = rolesArme.size();

    for(size_t i = 0; i < n; i++)
    {
        if (rolesArme[i]->name == roleJoueur.name) {
            index = i;
            break;
        }
    }
    return index;
}

void resultatRollItemEnnemy()
{
    
    int sizeMax = 100000;
    auto bob = newVecteurDrop(sizeMax);

    int gen0{0}, gen1{0}, gen2{0}, gen3{0};
    float gen0D{}, gen1D{}, gen2D{}, gen3D{};
    for(size_t i = 0; i < bob.size(); i++)
    {
        switch (bob[i]->getRarity())
        {
        case 0:
            gen0++;
            gen0D = bob[i]->getDropRate();
            break;
        case 1:
            gen1++;
            gen1D = bob[i]->getDropRate();
            break;
        case 2:
            gen2++;
            gen2D = bob[i]->getDropRate();
            break;
        case 3:
            gen3++;
            gen3D = bob[i]->getDropRate();
            break;
        default:
            break;
        }
    }

    cout << "\n\nTEST ITEM DROP RATE:";
    cout << "\n[Commun: " << to_string(gen0D) << "]";
    cout << "\n[Rare: " << to_string(gen1D) << "]";
    cout << "\n[Epique: " << to_string(gen2D) << "]";
    cout << "\n[Legendaire: " << to_string(gen3D) << "]";

    cout << "\n\nTotal: " << to_string(bob.size()) << " / " << to_string(sizeMax) << " demander.";
    cout << "\nCommun: " << to_string(gen0);
    cout << "\nRare: " << to_string(gen1);
    cout << "\nEpique: " << to_string(gen2);
    cout << "\nLegendaire: " << to_string(gen3);
}

void TestItems::dynamicCast()
{
    // Preuve avec pr�-Initializsation
    const Arme arme{ "Epee", 2 };
    const Armure armure{ "Armure de fer" };

    // Copie et attribution des pointeurs.
    // Arme/Armure en tant qu'item.
    Item* armeItemPtr{ new Arme(arme) };
    Item* armureItemPtr{ new Armure(armure) };

    // Cast dynamique avec pointeurs de classe polymorphique avec Item
    Arme* newArme = dynamic_cast<Arme*>(armeItemPtr);
    Armure* newArmure = dynamic_cast<Armure*>(armureItemPtr);

    // Test pour echec
    Arme* newArme2 = dynamic_cast<Arme*>(armureItemPtr);
    Armure* newArmure2 = dynamic_cast<Armure*>(armeItemPtr);

    // Verif "typeoff"
    bool newArmeReussi = newArme != nullptr;
    bool newArmureReussi = newArmure != nullptr;

    // Devrait etre False les dynamic cast se v�rifie seulement en runtime
    bool newArmeReussi2 = newArme2 != nullptr;
    bool newArmureReussi2 = newArmure2 != nullptr;

    // Verif meme adresse
    bool sameAdress1 = newArme == armeItemPtr;
    bool sameAdress2 = newArmure == armureItemPtr;

    // Verif valeurs et accesseurs...
    int dommage = newArme->getDommage();
    int deffense = newArmure->getDefense();
}

void TestItems::armesRandom()
{
    using namespace Utilities;
    using namespace Constante;

    init_random();

    armesGuerrier.clear();
    armesMagicien.clear();
    armesAssassin.clear();
    armesCommunes.clear();

    Item itemDef;
    Arme armeDef;
    Armure armureDef;

    Item itemX{ "Item de quete", 0 };
    Arme itemY{ "Arme de quete", 0,0 };
    Armure itemZ{ "Armure de fer" };

    for(size_t i = 0; i < 50; i++)
    {
        int rnd{ random_number(0,3) };
        string nom;

        if (rnd == 0) {
            nom = ARMENOM_GUERRIER_TAB[rnd];
        }
        else if (rnd == 1) {
            nom = ARMENOM_MAGICIEN_TAB[rnd];
        }
        else if (rnd == 2) {
            nom = ARMENOM_ASSASSIN_TAB[rnd];
        }

        if (i % 5 == 0) {
            nom = ARMENOM_COMMUNES_TAB[rnd];
        }
        Arme arme{ nom,rnd };
        auto rolePoss = arme.getClassesAutorise();

        int indexGuerrier = -1;
        int indexMagicien = -1;
        int indexAssassin = -1;
        if (rolePoss.size() > 0) {
            indexGuerrier = findClasse(ROLEBASE_ATKDEFHP_MAP.at("Guerrier"), rolePoss);
            indexMagicien = findClasse(ROLEBASE_ATKDEFHP_MAP.at("Magicien"), rolePoss);
            indexAssassin = findClasse(ROLEBASE_ATKDEFHP_MAP.at("Assassin"), rolePoss);


            if (indexGuerrier != -1)
                armesGuerrier.push_back(arme);
            if (indexMagicien != -1)
                armesMagicien.push_back(arme);
            if (indexAssassin != -1)
                armesAssassin.push_back(arme);
        }
        else {
            armesCommunes.push_back(arme);
        }
    }
}