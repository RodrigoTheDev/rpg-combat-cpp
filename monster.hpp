#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <locale.h>
#include <vector>
#include "attack.hpp"

using namespace std;

class Monster {
    public:
        string nome;
        int hp;
        vector<Attack> attackGroup;


        Monster(string NAME, int HP, vector<Attack> ataques) {
            nome = NAME;
            hp = HP;

            init_hp = HP;

            for(int i=0; i < ataques.size(); i++) {
                attackGroup.push_back(ataques[i]);
            }

        }

        void ResetStats() {
            hp = init_hp;
        }

        //retorna verdadeiro caso o hp do objeto seja menor ou igual a zero
		bool PlayerDefeated(int hp) {
			return (hp <= 0);
		}

    
    private:
        int init_hp = hp;
};


#endif