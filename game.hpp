#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <thread>
#include <vector>
#include <random>

//módulos
#include "monster.hpp"
#include "player.hpp"
#include "menu.hpp"

#define clear_screen "clear"

using namespace std;

void delay_ms(int ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}

class Game {
	public:
	Monster monstro = createEnemy();
	//Character jogador;

    //classe jogo, onde as partidas acontecem, separado do menu
    void SigleCombat(Character jogador) {
        while (true) {

			// Cria um gerador de números aleatórios com semente baseada no relógio do sistema
			std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

			//combate display
			cout << "------ test mode ------" << endl;
			cout << "inimigo: " << monstro.nome << endl;
			cout << "Vida: " << monstro.hp << endl;
			cout << "___________________________" << endl;
			cout << endl;
			cout << "Jogador: " << jogador.nome << endl;
			cout << "Nível: " << jogador.lvl << endl;
			cout << "Vida: " << jogador.hp << endl;
			cout << "Mana: " << jogador.mp << endl;
			cout << endl;
			
			//printando todos os ataques
			jogador.GetAttacks();

			cout << "Sua escolha: ";
			int ch = getInput.WaitChoice();
			system(clear_screen);

			if(ch < jogador.attackGroup.size()) {

				jogador.SelectAttack(ch, &monstro.hp);
				delay_ms(2000);

			}
			//caso o comando selecionado não esteja dentro das opções
			else {

				system(clear_screen);
				cout << "Esse comando não existe!" << endl;
				delay_ms(2000);

			}

			// número aleatório onde o alcance é o índice do attackGroup
			uniform_int_distribution<int> distribuicao(0, monstro.attackGroup.size()-1);
			int numero_aleatorio = distribuicao(rng);

			//monstro atacando
			monstro.UseAttack(&jogador.hp, monstro.attackGroup[numero_aleatorio]);

			delay_ms(2000);
			system(clear_screen);

			if (jogador.PlayerDefeated(jogador.hp) == true) {
				system(clear_screen);
				cout << "Fim de jogo, você perdeu" << endl;
				delay_ms(2000);

				//realize as funções de game over aqui, como salvamento e outras coisas

				//MainMenu(jogador, monstro); //voltando para o menu principal
				break; //encerrando o loop
			}

			if (monstro.PlayerDefeated(monstro.hp) == true) {
				system(clear_screen);
				cout << "Fim de jogo, você venceu" << endl;
				delay_ms(2000);

				//realize as funções de game over aqui, como salvamento e outras coisas

				// MainMenu(jogador, inimigo); //voltando para o menu principal
				break; //encerrando o loop
			}

			//final do loop, o final do turno, depois que tanto o inimigo quanto o jogador já atacaram

			//player regenerando mana
			jogador.mp += jogador.mp_regen;

			//------
		}

    }

private:
	//função que cria monstros
	Monster createEnemy() {
		vector<Attack> monster_attacks;

		monster_attacks.assign({
			Attack("mordida",5,0),
			Attack("arranhão",3,0),
			Attack("empurrão",2,0)
		});

		Monster enemy("Monstro",20, 20, monster_attacks);

		return enemy;
	}
};

Game game;

#endif