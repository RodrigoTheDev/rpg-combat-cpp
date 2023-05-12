//	WARNINGS
//	- Esse código ainda está em produção, ou seja ele NÃO ESTÁ 100% pronto
//	- Código feito por @RodrigoTheDev, se for usar em algum lugar, dê os créditor por favor


/*
	[AFAZERES]						[PRIORIDADE]
	- Nível que influencia nos atributos	  		[A]
	- Ataques de monstro                      		[S]
	- Arquivo de salvamento                   		[A]
	- Pontuação final                         		[C]
	- Separar o arquivo em módulos				[A]
*/

//bibliotecas
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <iomanip>
#include <cstdarg>
#include <vector>

//módulos
#include "attack.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "game.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8"); //idioma

	//array de ataques
	//Attack player_attacks[] = { Attack("Soco", 2, 0),Attack("Corte", 3, 3),Attack("Magica", 15, 20),Attack("Bola de fogo", 10, 10) };


	vector<Attack> player_attacks;
	player_attacks.assign({ Attack("Soco", 2, 0),Attack("Corte", 3, 3),Attack("Magica", 15, 20),Attack("Bola de fogo", 10, 10) });

	//Objeto game
	Game game;

	//objeto de jogador e inimigo
	Character player("Jogador",20,10,player_attacks);
	Monster enemy("slime",30,player_attacks);
	//função que inicia o jogo e seus menus
	game.MainMenu(player, enemy);
}
