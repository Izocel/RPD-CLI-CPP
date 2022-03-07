#include "TestCombats.h"

void TestCombats::TestCombats() {
    Joueur joueur{ debutPartie() };
    Ennemi en0{"Ogre", "Commun", 2};

    for(size_t i = 0; i < 500; i++)
    {
        string jDef = to_string(joueur.getDefenseCoef());
        cout << "Joueur HP:" << to_string(joueur.getHp()) << " Def:" << jDef << 
            " ATKMAX:" << to_string(joueur.getArme().getMaxDommage()) +
            " ATKR:" << to_string(joueur.attaquer(en0)) + "\n";
        string eDef = to_string(en0.getDefenseCoef());
        cout << "Ennemi HP:" << to_string(en0.getHp()) << " Def:" << eDef << 
            " ATK:" << to_string(en0.getAttackCoef()) +
            " ATKR:" << to_string(en0.attaquer(joueur)) + "\n\n";
    }
}
    
  