//	WARNINGS
//	- Esse código ainda está em produção, ou seja ele NÃO ESTÁ 100% pronto
//	- Código feito por @RodrigoTheDev, se for usar em algum lugar, dê os créditor por favor


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
#include "menu.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8"); //idioma
	
	Menu().MainMenu(); //menu principal

}
