#ifndef GAME_HPP
#define GAME_HPP

//bibliotecas
#include <iostream>
#include <string>
#include <thread>
#include <iomanip>
#include <cstdarg>
#include <vector>

//módulos
#include "attack.hpp"
#include "player.hpp"
#include "monster.hpp"

using namespace std;


#define clear_screen "clear" //caso esteja executando em windows, use "cls", caso em linux, use "clear" 

void delay_ms(int ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}

class Game {
public:
	int choice = 0;

	//menu principal, onde as opções principais estarão
	void MainMenu(Character p, Monster e) {

		system(clear_screen);
		//menu
		cout << "===== BEM VINDO AO RPG 2 =====" << endl;
		cout << "[1] Iniciar jogo" << endl;
		cout << "[2] Opções" << endl;
		cout << "[3] Sair" << endl;
		cout << ">> ";
		choice = WaitChoice();
		system(clear_screen);
			
		
		switch (choice) {
		case 1:
			StartGame(p, e);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}
	
	//loop do jogo
	void StartGame(Character p, Monster e) {
		while (true) {
			cout << "inimigo: " << e.nome << endl;
			cout << "Vida: " << e.hp << endl;
			cout << "___________________________" << endl;
			cout << endl;
			cout << "Jogador: " << p.nome << endl;
			cout << "Vida: " << p.hp << endl;
			cout << "Mana: " << p.mp << endl;
			cout << endl;
			

			p.GetAttacks();

			cout << "Sua escolha: ";
			int ch = WaitChoice();
			system(clear_screen);

			p.SelectAttack(ch, &e.hp);
			delay_ms(2000);
			system(clear_screen);

			if (p.PlayerDefeated(p.hp) == true) {
				system(clear_screen);
				cout << "Fim de jogo, você perdeu" << endl;
				delay_ms(2000);

				//realize as funções de game over aqui, como salvamento e outras coisas

				MainMenu(p, e); //voltando para o menu principal
				break; //encerrando o loop
			}

			if (e.PlayerDefeated(e.hp) == true) {
				system(clear_screen);
				cout << "Fim de jogo, você venceu" << endl;
				delay_ms(2000);

				//realize as funções de game over aqui, como salvamento e outras coisas

				MainMenu(p, e); //voltando para o menu principal
				break; //encerrando o loop
			}

			//final do loop, o final do turno, depois que tanto o inimigo quanto o jogador já atacaram

			//player regenerando mana
			p.mp += p.mp_regen;

			//------
		}
	}

private:
	//espera a escolha do usuario
	int WaitChoice() {
		int ch;
		cin >> ch;

		return ch;
	}
};


#endif