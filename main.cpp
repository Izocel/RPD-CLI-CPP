#include <iostream>
#include "main.h"


int main() {
    Utilities::init_random();
    gameLoop();
    return 0;
}

void gameLoop()
{
    int choixMenu{};
    string choixQuitter{ "" };

    // Entité joueur
    Joueur joueur{ debutPartie() };

    while (choixQuitter != "o")
    {
        system("CLS");
        // En attendant les potions....
        if (joueur.getHp() < joueur.getHpBase()) {
            Utilities::afficheDelai("Vous recuperez vos points de vie perdues...\n", Constante::DELAY);
            cout << "(Appuyez sur une touche pour commencer)\n";
            string trash;
            getline(cin, trash);
            joueur.recupHp();
        }
        
        system("CLS");
        ////////////////
        //    Menu    //
        choixMenu = menuJoueur(joueur, "MENU PRINCIPAL");
        
        // Partir aventure ?
        if (choixMenu == 1)
            combat(joueur);

        // Inventaire ?
        else if (choixMenu == 2)
            gestionInventaire(joueur);
        
        // Quitter?
        else {
            Utilities::afficheDelai("Voulez vous vraiment quitter?(o,n):", Constante::DELAY);
            getline(cin, choixQuitter);
        }
    }
}

int menuJoueur(Joueur& joueur, string action)
{
    int choixMenu{ };
    const int LARGEURMAX = Constante::LARGEURMENU;

    //Entete
    string text{ Constante::OPENINGLINE };

    string niveauJoueur{ " lvl." + to_string(joueur.getLevel()) };
    string roleJoueur{ "    [" + joueur.getClasse()->name + "]"};

    //Ligne des noms
    text += "|";
    text += joueur.getName() + niveauJoueur + roleJoueur;
    text += string(LARGEURMAX/2 +1 - joueur.getName().size() - niveauJoueur.size() - roleJoueur.size(), ' ');
    text += Constante::HALFEMPTYLINE;

    //Ligne des stats
    string statsJoueur{ "" };
    statsJoueur += "HP:" + to_string(joueur.getHp()) + "/" + to_string(joueur.getHpBase());
    statsJoueur += " " + joueur.getClasse()->nomRessource + ":" + to_string(joueur.getRessource()) + "/" + to_string(joueur.getRessourceMax());
    statsJoueur += " BufDmg:" + to_string(joueur.getDommageBuff());
    statsJoueur += " BufDef:" + to_string(joueur.getDefenseBuff());

    string statsArme;
    if (joueur.getArme() != NULL) {
        Arme* arme{ joueur.getArme() };
        string min = to_string(arme->getMinDommage());
        string max = to_string(arme->getMaxDommage());
        statsArme = "Arme:   " + arme->getName() + "-> domage[" + min + "-" + max + "]";
    }

    string statsArmure;
    if (joueur.getArmure() != NULL) {
        Armure* armure{ joueur.getArmure() };
        string def = to_string(armure->getDefense());
        statsArmure = "Armure: " + armure->getName() + "-> defense[" + def + "]";
    }

    text += "|";
    text += statsJoueur;
    text += string(LARGEURMAX/2 +1 - statsJoueur.size(), ' ');
    text += Constante::HALFEMPTYLINE;

    //Stats Arme/Armure
    if (!statsArme.empty()) {
        text += "|";
        text += statsArme;
        text += string(LARGEURMAX/2 +1 - statsArme.size(), ' ');
        text += Constante::HALFEMPTYLINE;
    }
    else
        text += Constante::EMPTYLINE;
   

    if (!statsArmure.empty()) {
        text += "|";
        text += statsArmure;
        text += string(LARGEURMAX/2 +1 - statsArmure.size(), ' ');
        text += Constante::HALFEMPTYLINE;
    }
    else
        text += Constante::EMPTYLINE;

    text += Constante::SUBCLOSINGLINE;
    text += Constante::EMPTYLINE;
    text += Constante::EMPTYLINE;

    // Actions
    text += "|";
    text += string((LARGEURMAX/2 -1 - action.size()/2), ' ');
    text += action;
    text += string((LARGEURMAX/2 -1 - action.size()/2), ' ');
    if (action.size() % 2 == 0)
        text += " ";
    text += "|";
    text += "\n";

    text += Constante::EMPTYLINE;

    // Fin de la boite
    text += Constante::CLOSINGLINE;
    text += "\n";


    if (joueur.estVivant()) {
        text += "1- Partir a l'aventure\n";
        text += "2- Gestion inventaire\n";
        text += "3- Terminer la partie\n";
        cout << text;
        choixMenu = prendreChoix(1, 3);
    }
    else {
        text += "1- Gestion inventaire\n";
        text += "2- Terminer la partie\n";
        cout << text;
        choixMenu = prendreChoix(1, 2);
        choixMenu++;
    }
    return choixMenu;
}

string affichageCombat(Joueur& joueur, Ennemi& ennemi, string action)
{
    const int LARGEURMAX = Constante::LARGEURMENU;

    //Entete
    string text{ Constante::OPENINGLINE };

    // Action to upper
    std::transform(action.begin(), action.end(), action.begin(), ::toupper);

    string niveauJoueur{ " lvl." + to_string(joueur.getLevel())};
    string roleJoueur{ "    [" + joueur.getClasse()->name + "]" };
    string niveauEnemmi{ " lvl." + to_string(ennemi.getLevel())};

    //Ligne des noms
    text += "|";
    text += joueur.getName() + niveauJoueur + roleJoueur;
    text += string(LARGEURMAX/2 +1 - joueur.getName().size() - niveauJoueur.size() - roleJoueur.size(), ' ');
    text += "|";
    text += string(LARGEURMAX/2 -3 - ennemi.getName().size() - niveauEnemmi.size(), ' ');
    text += ennemi.getName() + niveauEnemmi;
    text += "|";
    text += "\n";

    //Ligne des stats
    string statsJoueur{ "" };
    statsJoueur += "HP:" + to_string(joueur.getHp()) + "/" + to_string(joueur.getHpBase());
    statsJoueur += " " + joueur.getClasse()->nomRessource + ":" + to_string(joueur.getRessource()) + "/" + to_string(joueur.getRessourceMax());

    string buffStats;
    if(joueur.estAtkBufTemp())
        buffStats += " BufDmg:" + to_string(joueur.getDommageBuff()) + "++";
    else
        buffStats += " BufDmg:" + to_string(joueur.getDommageBuff());
    if (joueur.estDefBufTemp())
        buffStats += " BufDef:" + to_string(joueur.getDefenseBuff()) + "++";
    else
        buffStats += " BufDef:" + to_string(joueur.getDefenseBuff());
    statsJoueur += buffStats;


    string statsArme;
    if (joueur.getArme() != NULL) {
        Arme* arme{ joueur.getArme() };
        string min = to_string(arme->getMinDommage());
        string max = to_string(arme->getMaxDommage());
        statsArme = "Arme:   " + arme->getName() + "-> domage[" + min + "-" + max + "]";
    }

    string statsArmure;
    if (joueur.getArmure() != NULL) {
        Armure* armure{ joueur.getArmure() };
        string def = to_string(armure->getDefense());
        statsArmure = "Armure: " + armure->getName() + "-> defense[" + def + "]";
    }

    string statsEnnemi{ "" };
    statsEnnemi += "Vie:" + to_string(ennemi.getHp()) + "/" + to_string(ennemi.getHpBase());
    statsEnnemi += " Defense:" + to_string(ennemi.getDefenseCoef());
    statsEnnemi += " Attaque:" + to_string(ennemi.getAttackCoef());

    //Stats Personnages
    text += "|";
    text += statsJoueur;
    text += string(LARGEURMAX/2 +1 - statsJoueur.size(), ' ');
    text += "|";
    text += string(LARGEURMAX/2 -3 - statsEnnemi.size(), ' ');
    text += statsEnnemi;
    text += "|";
    text += "\n";

    //Stats Arme/Armure
    if (!statsArme.empty()) {
        text += "|";
        text += statsArme;
        text += string(LARGEURMAX/2 +1 - statsArme.size(), ' ');
        text += Constante::HALFEMPTYLINE;
    }
    else
        text += Constante::EMPTYLINE;

    if (!statsArmure.empty()) {
        text += "|";
        text += statsArmure;
        text += string(LARGEURMAX/2 +1 - statsArmure.size(), ' ');
        text += Constante::HALFEMPTYLINE;
    }
    else 
        text += Constante::EMPTYLINE;

    //Action
    text += Constante::SUBCLOSINGLINE;
    text += Constante::EMPTYLINE;

    // Actions
    text += "|";
    text += string((LARGEURMAX/2 -1 - action.size() / 2), ' ');
    text += action;
    text += string((LARGEURMAX/2 -1 - action.size() / 2), ' ');
    if (action.size() % 2 == 0)
        text += " ";
    text += "|";
    text += "\n";

    //Fin de la boite
    text += Constante::CLOSINGLINE;
    text += "\n";

    return text;
}

string affichageChoix(Joueur joueur)
{
    string text{ "" };

    text += "1-Attaquer.\n";

    int i{ 2 };

    const map<string, const Action> actions{ joueur.getActions() };
    auto it = actions.begin();

    for(it = actions.begin(); it != actions.end(); it++)
    {
        text += to_string(i) + "-" + it->first + ": ";
        if (it->second.attackCoef != 0)
        {
            text += "Attaque avec +" + to_string(it->second.attackCoef) + " attaque. ";
        }
        else if (it->second.defenseCoef != 0)
        {
            text += "+" + to_string(it->second.defenseCoef) + " defense. ";
        }
        else if (it->second.recupHP != 0)
        {
            text += "+" + to_string(it->second.recupHP) + " hp. ";
        }

        if (it->second.depenseRessources != 0)
        {
            text += "-" + to_string(it->second.depenseRessources) + " " + joueur.getClasse()->nomRessource + ".";
        }
        else if (it->second.recupRessources != 0)
        {
            text += "+" + to_string(it->second.recupRessources) + " " + joueur.getClasse()->nomRessource + ".";;
        }
        text += "\n";
        i++;
    }
    text += to_string(i) + "-Gestion d'inventaire\n";
    text += to_string(++i) + "-Fuir.\n";

    return text;
}

Joueur debutPartie()
{
    system("CLS");
    Utilities::afficheDelai("Bonjour aventurier!\n", Constante::DELAY);
    Utilities::delai(Constante::DELAY * 4);
    Utilities::afficheDelai("Quel est votre nom?: ", Constante::DELAY);
    string name{ "" };
    string error{ "" };
    while (name == "")
    {
        cout << error;
        getline(cin, name);
        if (name == "")
        {
            error = "Vous devez entrer un nom: ";
        }
    }

    system("CLS");
    Utilities::afficheDelai("Bonjour " + name + "!\n", Constante::DELAY);
    Utilities::delai(Constante::DELAY * 4);
    Utilities::afficheDelai("En tant que nouvel aventurier, vous devez choisir une classe de depart.\n", Constante::DELAY);
    Utilities::delai(Constante::DELAY * 4);
    Utilities::afficheDelai("Vous pouvez choisir parmis celles-ci:\n\n", Constante::DELAY);

    vector<string> keys{ vectorKeys(Constante::ROLEBASE_ATKDEFHP_MAP) };
    const string typesJeu[3]{" ---- BALANCER "," ---- DEFENSIF "," ---- ATTAQUANT "};


    for(size_t i = 0; i < keys.size(); i++)
    {
        Utilities::afficheDelai(to_string(i + 1) + "-" + keys[i] + typesJeu[i] + "\n", Constante::DELAY / 2);
    }

    int choix{ prendreChoix(1, keys.size()) };

    system("CLS");
    Utilities::afficheDelai("\nBravo " + name + ", vous etes maintenant " + keys[choix - 1] + "!\n", Constante::DELAY);
    Utilities::afficheDelai("Votre aventure va maintenant commencer...\n", Constante::DELAY);
    cout << "(Appuyez sur une touche pour continuer)\n";
    getchar();
    return Joueur(name, &Constante::ROLEBASE_ATKDEFHP_MAP.at(keys[choix - 1]));
}

int prendreChoix(int min, int max)
{
    string error{ "" };
    string entry{ "" };
    int entryInt{ -1 };
    while (entryInt < min || entryInt > max)
    {
        cout << error + "\n";
        cout << "Votre choix: ";

        getline(cin, entry);
        if (entry != "")
        {
            bool tryConvert{ false };
            try
            {
                entryInt = stoi(entry);
            }
            catch (const std::exception&)
            {
                tryConvert = true;
            }

            if (tryConvert)
            {
                error = "Vous devez entrer un nombre.";
            }

            else if (entryInt < min || entryInt > max)
            {
                error = "Vous devez entrer un nombre de " + to_string(min) + " a " + to_string(max) + ".";
            }
        }
        else
        {
            error = "Vous devez entrer un choix.";
        }
    }
    return entryInt;
}

template <typename T, typename R>
vector<T> vectorKeys(const map<T, R> map)
{
    vector<T> keys{};
    for(auto it = map.begin(); it != map.end(); it++)
    {
        keys.push_back(it->first);
    }
    return keys;
}

void combat(Joueur& joueur)
{
    bool fuite{ false };
    joueur.resetBuff();

    // Entité de combat
    unsigned int niveauJoueur = joueur.getLevel();
    Ennemi ennemi{ genererEnnemi(niveauJoueur) };


    Utilities::afficheDelai("Vous allez combattre un " + ennemi.getName() + " niveau " + to_string(ennemi.getLevel()) + "!\n", Constante::DELAY);
    cout << "(Appuyez sur une touche pour commencer)\n";
    getchar();

    vector<string> actionKeys{ vectorKeys(joueur.getActions()) };
    system("CLS");
    cout << affichageCombat(joueur, ennemi, "Debut du combat");


    //////////////////////////////////////////////////
    /////////////// Boucle de combat /////////////////
    while (joueur.getHp() != 0 && ennemi.getHp() != 0)
    {
        joueur.resetBuff();
        cout << affichageChoix(joueur);
        int choix{ prendreChoix(1, 6) };

        if (choix == 6 ){
            fuite = true;
            break;
        }

        if (choix == 5) {
            gestionInventaire(joueur);
            continue;
        }

        system("CLS");
        if (choix == 1)
        {
            system("CLS");
            //attaquer l'ennemi
            string affichage{ to_string(joueur.attaquer(ennemi)) + " degats." };
            cout << affichageCombat(joueur, ennemi, joueur.getName() + " attaque pour " + affichage);
        }
        else
        {
            string affichage{joueur.action(ennemi, actionKeys[choix-2])};
            cout << affichageCombat(joueur, ennemi, affichage);
        }

        if (ennemi.getHp() > 0)
        {
            cout << "C'est maintenant le tour de votre adversaire!\n";
            cout << "(Appuyez sur une touche pour continuer)\n";
            getchar();

            string affichage{ " attaque pour " + to_string(ennemi.attaquer(joueur)) + " degats." };
            cout << affichageCombat(joueur, ennemi, ennemi.getName() + affichage);
        }
        else
        {
            cout << ennemi.getName() + " niveau " + to_string(ennemi.getLevel()) + " est mort.\n";
            cout << "(Appuyez sur une touche pour continuer)\n";
            getchar();
        }
    }

    //////////////////////////////////////////////////
    ////////////////// Fin de combat /////////////////
    if (fuite)
        Utilities::afficheDelai("Vous avez fuit le combat.", Constante::DELAY);
    
    else if (joueur.getHp() == 0)
    {
        Utilities::afficheDelai("Vous etes mort. La partie s'arrete ici pour le " + joueur.getClasse()->name + " " + joueur.getName() + "...\n", Constante::DELAY);
        cout << "(Appuyez sur une touche pour retourner au menu principal)";
        getchar();
    }
    else
    {
        Utilities::afficheDelai("Vous avez gagne!!!!\n", Constante::DELAY);

        unsigned int memLevel{ joueur.getLevel() };
        Utilities::afficheDelai(joueur.gainXP(calculXP(joueur.getLevel(), ennemi.getLevel())), Constante::DELAY);
        if (memLevel != joueur.getLevel())
        {
            unsigned int diff{ joueur.getLevel() - memLevel };
            for(int i = 0; i < diff; i++)
                augmentStats(joueur);
        }

        cout << "(Appuyez sur une touche pour continuer)\n";
        getchar();
        system("CLS");
        gestionLoot(joueur, ennemi.getDrop());
    }
}

Ennemi genererEnnemi(unsigned int& niveauJoueur)
{
    using namespace Utilities;
    using namespace Constante;

    const int nCommun = ENNEMICOMMUN_ATKDEFHP_MAP.size();
    const int nRare = ENNEMIRARE_ATKDEFHP_MAP.size();

    const int deltaNiveauBas = niveauJoueur - random_number(0,3);
    const int deltaNiveauHaut = niveauJoueur + random_number(0, 4);
    const int niveauMinBorner = deltaNiveauBas > 0 ? deltaNiveauBas : niveauJoueur;

    const int rndLvl = random_number(niveauMinBorner, deltaNiveauHaut);

    string nomEnnemi;
    bool rare{false};
    vector<Item*> vectorDrop{};
    if (niveauJoueur % 10 == 0){
        rare = true;
        const int rndNomRare = random_number(0, nRare);
        nomEnnemi = ENNEMIRARE_NOM_TAB[rndNomRare];

        // DropVector SPECIAL
        vectorDrop = newVecteurDrop(10);
    }
    else {
        const int rndNomCommun = random_number(0, nCommun);
        nomEnnemi =  ENNEMICOMMUN_NOM_TAB[rndNomCommun];

        // Drop vector
        vectorDrop = newVecteurDrop(3);
    }
    // Ennemi
    const string type = rare ? "Rare" : "Commun";
    Ennemi ennemi{ nomEnnemi, type, rndLvl };
    ennemi.setDropItem(vectorDrop);
    return ennemi;
}

void gestionLoot(Joueur& joueur, vector<Item*> loot)
{
    int entry{ -1 };
    bool itemAquiert{ false };
    size_t lootSize{ loot.size() };
    int nChoixBase{ 3 };
    introGestionLoot(lootSize);

    while (entry != nChoixBase && ! loot.empty()) {
        system("CLS");
        afficherVecteurItem(loot);

        lootSize = loot.size();
        nChoixBase = lootSize;

        cout << to_string(++nChoixBase) << "- Gestion inventaire.\n";
        if (lootSize != 0)
            cout << to_string(++nChoixBase) << "- Prendre tout.\n";
        cout << to_string(++nChoixBase) << "- Partir....\n";

        entry = prendreChoix(1, nChoixBase);

        if (entry == lootSize + 1)
            gestionInventaire(joueur);

        //////////////////////////////////////////////////
        ////////////////// Prendre tout //////////////////
        else if (entry == lootSize + 2 ) {
            size_t i{ 0 };
            int max = lootSize;
            for(i; i < max; i++)
            {
                itemAquiert = joueur.takeItem(loot[0]);
                if (itemAquiert)
                    loot.erase(loot.begin());
                else
                    break;
            }

            if(i > 0)
                Utilities::afficheDelai(to_string(i) + " items acquis!!!\n", Constante::DELAY);
            else
                Utilities::afficheDelai("Votre inventaire est plein...\n", Constante::DELAY);
        }
        
        //////////////////////////////////////////////////
        ////////////////// Prendre X /////////////////////
        else if (entry > 0 && entry <= lootSize) {
            itemAquiert = joueur.takeItem(loot[entry-1]);
            if (itemAquiert) {
                loot.erase(loot.begin() + entry - 1);
                Utilities::afficheDelai("Item acquis !\n", 40);
            }
            else
                Utilities::afficheDelai("Votre inventaire est plein...\n", Constante::DELAY);
        }
    }
    Utilities::afficheDelai("Vous quitter la zone....\n", Constante::DELAY);
    std::cout << "(Appuyez sur une touche pour continuer)\n";
    getchar();
}

void introGestionLoot(size_t& lootSize) {
    Utilities::afficheDelai("\n\nVous fouillez l'ennemi...\n", Constante::DELAY);
    Utilities::afficheDelai("...\n...\n...\n\n", Constante::DELAY*2);

    if (lootSize == 0) 
        cout << "L'ennemi n'a laisser aucun item derriere lui dommage...\n";
    
    else 
        cout << "L'ennemi a laisser " + to_string(lootSize) +" items deriere lui !!!\n";

    std::cout << "(Appuyez sur une touche pour continuer)\n";
    getchar();
}

int calculXP(int joueur, int ennemi)
{    
    return pow(1.3, (joueur - ennemi) / 2) + 1000 + pow(ennemi, 2.8);
}

string typeOfItem(Item*& itemPtr)
{
    Arme* armePtr{ dynamic_cast<Arme*>(itemPtr) };
    if (armePtr != NULL) 
        return "Arme";

    Armure* armurePtr{ dynamic_cast<Armure*>(itemPtr) };
    if (armurePtr != NULL)
        return "Armure";

    return "Item";
}

Arme itemAsArme(Item*& armePtr)
{
    Arme* newArmePtr{ dynamic_cast<Arme*>(armePtr) };
    if (newArmePtr == NULL)
        return Arme();

    Arme newArme{ *newArmePtr };
    return newArme;
}

Armure itemAsArmure(Item*& armurePtr)
{
    Armure* newArmurePtr{ dynamic_cast<Armure*>(armurePtr) };
    if (newArmurePtr == NULL)
        return Armure();

    Armure newArmure{ *newArmurePtr };
    return newArmure;
}

const Arme armeHasard() {
    using namespace Utilities;
    using namespace Constante;
    int rnd{ random_number(0,4) };
    string nom;

    if (rnd == 0) {
        rnd = random_number(0,3);
        nom = ARMENOM_GUERRIER_TAB[rnd];
    }
    else if (rnd == 1) {
        rnd = random_number(0,3);
        nom = ARMENOM_MAGICIEN_TAB[rnd];
    }
    else if (rnd == 2) {
        rnd = random_number(0,3);
        nom = ARMENOM_ASSASSIN_TAB[rnd];
    }
    else if (rnd == 3) {
        rnd = random_number(0,3);
        nom = ARMENOM_COMMUNES_TAB[rnd];
    }
    rnd = random_number(0,4);
    return Arme( nom, rnd );
}

const Armure armureHasard() {
    int rnd{ Utilities::random_number(0,6) };
    return Armure( Constante::ARMURE_NOM_TAB[rnd] );
}

bool rollItem(const float& itemDropRate) {
    return Utilities::random_float(0, 2) <= itemDropRate * Constante::RARETER_TAB_SIZE;
}

vector<Item*> newVecteurDrop(const int& size) {
    // Vecteur Item
    vector<Item*> vctrItem{};

    for(int i = 0; i < size; i++) {
        int rndType{ Utilities::random_number(0,2) };

        // Arme
        if (rndType == 0) {
            Arme newArme{ armeHasard() };
            bool asDropped = rollItem(newArme.getDropRate());
            if (asDropped)
                vctrItem.push_back(new Arme(newArme));
        }
        // Armure
        else if (rndType == 1) {
            Armure newArmure{ armureHasard() };
            bool asDropped = rollItem(newArmure.getDropRate());
            if (asDropped)
                vctrItem.push_back(new Armure(newArmure));
        }
    }
    return vctrItem;
}

void afficherVecteurItem(vector<Item*>& vctrItem) {

    if (vctrItem.size() < 1) return;
 
    string typeItem{};
    size_t compteur{1};
    
    for(auto itemPtr : vctrItem)
    {
        typeItem = typeOfItem(itemPtr);
        cout << to_string(compteur++) << "-";

        if (typeItem == "Arme") {
            cout << itemAsArme(itemPtr).getDescription() << " Roles->" << itemPtr->rolesToString() << "\n";
        }
        else if (typeItem == "Armure") {
            cout << itemAsArmure(itemPtr).getDescription() << " Roles->" << itemPtr->rolesToString() << "\n";
        }
        else if (typeItem == "Item") {
            cout << itemPtr->getDescription() << " Roles->" << itemPtr->rolesToString() << "\n";
        }
        else {
            throw("[???] Cet item est inconnu...");
        }
    }
}

void augmentStats(Joueur& joueur)
{
    Utilities::afficheDelai("Vous pouvez augmenter une statistique:\n\n", Constante::DELAY);
    Utilities::afficheDelai("1-Attaque\n2-Defense", Constante::DELAY/2);

    int choix{ prendreChoix(1, 2) };

    if (choix == 1)
    {
        joueur.augmentAttack();
        Utilities::afficheDelai("\nVous avez augmente votre attaque de " + to_string(Constante::ATTACK_AUGM) + "!\n", Constante::DELAY);
    }
    else if (choix == 2)
    {
        joueur.augmentDefense();
        Utilities::afficheDelai("\nVous avez augmente votre defense de " + to_string(Constante::DEFENSE_AUGM) + "!\n", Constante::DELAY);
    }
}

void gestionInventaire(Joueur& joueur)
{
    int posInv{ 0 };
    string text;
    auto inventaire{ joueur.getInventaire() };

    do
    {
        system("CLS");
        inventaire = joueur.getInventaire();

        std::cout << "Equipement: \n";
        afficherEquipement(joueur);

        std::cout << "\n\n";
        std::cout << "Inventaire:\n";
        if (inventaire.size() > 0)
            afficherVecteurItem(inventaire);
        else
            std::cout << "Aucun item se trouve dans votre inventaire!\n\n\n";

        // Menu base +1
        std::cout << to_string(inventaire.size() + 1) + "-Retour";
        posInv = prendreChoix(1, inventaire.size() + 1) -1;

        // Si non égale à retour (size+1)
        if (posInv != inventaire.size())
        {
            int action{ 0 };
            std::cout << "1-Equiper\n";
            std::cout << "2-Lacher\n";
            action = prendreChoix(1, 2);

            if (action == 1)
            {
                string type{ typeOfItem(inventaire[posInv]) };
                if (type == "Arme")
                {
                    if (joueur.setArme(posInv) )
                        text = "Arme equipee!\n";
                    else
                        text = "Vous ne pouvez pas equiper cette arme.\n";
                }
                else if (type == "Armure")
                {
                    if (joueur.setArmure(posInv))
                        text = "Armure equipee!\n";
                    else
                        text = "Vous ne pouvez pas equiper cette armure.\n";
                }
            }
            else
            {
                joueur.dropItem(posInv);
                text = "Item lache!\n";
            }
            std::cout << text;
            std::cout << "(Appuyez sur une touche pour continuer)\n";
            getchar();
        }
    } while (posInv != inventaire.size());
}

void afficherEquipement(Joueur& joueur) {
    if (joueur.getArme() != NULL)
        cout << joueur.getArme()->getDescription() << " Roles->" << joueur.getArme()->rolesToString() << "\n";
    else
        cout << "Aucune arme equiper!!!!\n";

    if(joueur.getArmure() != NULL)
        cout << joueur.getArmure()->getDescription() << " Roles->" << joueur.getArmure()->rolesToString() << "\n";
    else
        cout << "Aucune armure equiper!!!!\n";
}