#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include "attack.hpp"

using namespace std;

class Character {
	public: //public variables
		int hp = 0; //health points
		int mp = 0; //mana points
		int mp_regen = 1; //regeneração de mana
		int hp_regen = 1; //regeneração de vida
		int exp = 0; //experiêcia do jogador
		int lvl = 0; //nível do jogador, responsável por melhorar os atributos acima
		string nome = "";

		// Attack* attackGroup = new Attack[4];
        vector<Attack> attackGroup;

		//função construtora
		Character (string NOME, int HP, int MP, vector<Attack> ataques) {
			nome = NOME;
			hp = HP;
			mp = MP;
            // attackGroup = ataques;
            
            for(int i=0; i < ataques.size(); i++) {
                attackGroup.push_back(ataques[i]);
            }

            init_hp = HP;
            init_mp = MP;
		}

		//gameplay functions
		//tira uma determinada quantidade do hp inimigo
		void UseAttack(int* otherHP, Attack atk) {

			//checando se o jogador ainda possui mana
			if (this->mp < atk.custo) {
				cout << "Não há mana o suficiente para isso!" << endl;
				return;
			}

			//printando na tela o ataque
			cout << this->nome << " usou " << atk.at_label << " causando " << atk.dano << " de dano, consumindo " <<
				atk.custo << " de mana " << endl;


			//atualizando os valores
			*otherHP -= atk.dano;
			this->mp -= atk.custo;

			//na hora de usar essa função, colocar &variável como parâmetro
		}

		//retorna verdadeiro caso o hp do objeto seja menor ou igual a zero
		bool PlayerDefeated(int hp) {
			return (hp <= 0);
		}

		//stats functions
		//define os valores para os status do personagem (uma vez setado, ele passa a ser o valor inicial)
		void SetStats(string NAME, int HP, int MP) {
			hp = HP;
            init_hp = HP;
            init_mp = MP;
			mp = MP;
			nome = NAME;
			init_mp = mp;
			init_hp = hp;
		}

		//reseta para o valor inicial
		void ResetStats() {
            hp = init_hp;
            mp = init_mp;

		}

		//printa os status do personagem na tela
		void GetStats() {
			cout << "nome: " << nome << "\nvida: " << hp << "\nmana: " << mp << endl;

		}

		//define os ataques (FUNÇÃO DATADA, AGORA OS ATAQUES SÃO DEFINIDOS NA CONSTRUTORA)
		void SetAttacks(Attack ataques[4]) {
			for (int i = 0; i < 4; i++) {

				attackGroup[i] = Attack(ataques[i].at_label,ataques[i].dano,ataques[i].custo);

			}
		}

		//lista todos os ataques dentro do array attackGroup
		void GetAttacks() {
			for (int i=0; i < attackGroup.size(); i++) {
				cout << i << "." << left << setw(15) << attackGroup[i].at_label << " Custo: " << attackGroup[i].custo << endl;
			}
		}

		void SelectAttack(int num, int* otherHP) {
			UseAttack(otherHP, attackGroup[num]);
		}
		

	private:
		//variáveis que armazenam o valor inicial
		int init_hp=hp;
		int init_mp=mp;
};

#endif