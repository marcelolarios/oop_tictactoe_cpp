/*************************************************** 
  Project
  - tic tac toe oop
  - jogo da velha poo

  Written by Marcelo Larios 2022MAR
  
  AGLP-3.0 license, all text above must be included in any redistribution
****************************************************/
#include <iostream>
#include "storage.cpp"
#include "jogador.cpp"
#include "humano.cpp"
#include "computador.cpp"
#include "tabuleiro.cpp"

using namespace std;

int main() {

	cout << "\n*** Jogo da velha ***\n";
		
	Tabuleiro tb;
	tb.rodada();
	
	return 0;
}
