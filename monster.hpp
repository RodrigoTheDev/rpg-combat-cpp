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
        int exp_ammount;
        vector<Attack> attackGroup;


        Monster(string NAME, int HP, int exp,  vector<Attack> ataques) {
            nome = NAME;
            hp = HP;
            exp_ammount = exp;

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

        void UseAttack(int* otherHP, Attack atk) {

			//printando na tela o ataque
			cout << this->nome << " usou " << atk.at_label << " causando " << atk.dano << " de dano " << endl;


			//atualizando os valores
			*otherHP -= atk.dano;

			//na hora de usar essa função, colocar &variável como parâmetro
		}

    
    private:
        int init_hp = hp;
};


#endif