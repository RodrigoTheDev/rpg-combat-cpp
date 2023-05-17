#ifndef MENU_HPP
#define MENU_HPP

//bibliotecas
#include <iostream>
#include <string>
#include <thread>
#include <iomanip>
#include <cstdarg>
#include <vector>
#include <random>

//módulos
#include "attack.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "input.hpp"
#include "game.hpp"

using namespace std;

// Cria um gerador de números aleatórios com semente baseada no relógio do sistema
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define clear_screen "clear" //caso esteja executando em windows, use "cls", caso em linux, use "clear"
#define exit_system "exit"



class Menu {
public:
	int choice = 0;

	//menu principal, onde as opções principais estarão
	void MainMenu() {
		while(true) {

		system(clear_screen);
		//menu
		cout << "===== BEM VINDO AO RPG 2 =====" << endl;
		cout << "[1] Combate único" << endl;
		cout << "[2] Modo Campanha" << endl;
		cout << "[3] Sair" << endl;
		cout << ">> ";
		choice = getInput.WaitChoice();
		system(clear_screen);
			
		
		switch (choice) {
			case 1: //inicio do jogo
				game.SigleCombat(CreatePlayer());
				break;
			case 2:
				break;
			case 3: //sair do jogo
				exit(1);
				break;
			case 4:
				break;
			}
		}
	}

	private:
	Character CreatePlayer() {
		system(clear_screen);

		string nome;

		cout << "Insira o nome do jogador: ";
		cin >> nome;
		//array de ataques
		vector<Attack> player_attacks;

		player_attacks.assign({
			Attack("Soco", 2, 0),
			Attack("Corte", 3, 3),
			Attack("Magica", 15, 20),
			Attack("Bola de fogo", 10, 10)
		});

		system(clear_screen);

		return Character(nome,20,20,player_attacks);
	}
};


#endif
