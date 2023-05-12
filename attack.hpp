#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <iostream>

using namespace std;

class Attack {
	public:
		string at_label = "default_attack"; //nome do ataque
		int dano = 0; //dano que o ataque causa
		int custo = 0; //custo de mana que ele consumirá

		Attack () {
			at_label = "";
			dano = 0;
			custo = 0;
		}
		//função construtora
		Attack (string lbl, int dmg, int cost) {
			at_label = lbl;
			dano = dmg;
			custo = cost;
		}


		void GetStatus() {
			cout << "Nome: "<< at_label << "\nDano: " << dano << "\nCusto: " << custo;
		}
};

#endif