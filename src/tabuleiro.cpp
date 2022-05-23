class Tabuleiro {
    public:
    	void rodada(){ // acum score futuro
    	
    		srand (time(NULL)); //só necessita 1 vez
			while(true) {
											
				if(!partida()) {
			
					std::cout<<aviso(3); //interrup
					return;
				} 
				std::cout<<aviso(4); //Nova partida
			}
	    }
	private:
		char quem;
		Storage sto;
		
		bool partida() { //1 completa
		
			sto.zera();
			auto jc = Computador("o");
			auto jh = Humano("x");
			while (true){ 
				
				int retLance;
							
				if(!sto.getVez()) {
					quem = 'x';
					mostra(); //aviso proximo a jogar
					retLance = lance(jh);
				} else {
					quem = 'o';
					retLance = lance(jc);
				}
					
				if(!retLance)  return false;	
			 	
				if(compara()) break;
				sto.setVez();
			}
			mostra();
			return true;
		}

		bool lance(Jogador& a){
			// method called via the generic interface
			while(true) {

				int casa = a.joga();
				if(casa == 0) return false;
				if(sto.getJogo(casa) == ' ') {

					sto.setJogo(casa, quem);
					break;
				}
			}
			return true;
		}
				
		std::string  aviso(int i){
			std::string q(1, quem);
			switch(i) {
				case 1: return "jogador \"" + q + "\" venceu!";
				case 2: return "Empatou!";
				case 3: return "*** Jogo Interrompido ***\n\n";
				case 4: return "\n\n*** Nova partida ***\n";
				default:  return "jogador \"" + q + "\", sua vez";
			}
		}
	

		bool compara() {
		
			int possibs[9][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {7, 4, 1}, {8, 5, 2}, {9, 6, 3}, {1, 5, 9}, {7, 5, 3}};
			
			//std::string v = sto.getJogo();
			for (int i=0; i<8; i++) {

				if( sto.getJogo(possibs[i][0]) == sto.getJogo(possibs[i][1]) &&
					sto.getJogo(possibs[i][1]) == sto.getJogo(possibs[i][2]) && sto.getJogo(possibs[i][2]) != ' '){
			
					sto.setResultado(1); //há vencedor
					return true;
				} 
			}
			
			for (int i=1; i<10; i++) { //começa do 1 senão é loop infinito
		
				if(sto.getJogo(i) == ' ')  return false;
			}
			sto.setResultado(2); // empatou
			
			return true; 
		}
		/*
		std::string v(int i) {
			char c = sto.getJogo()[i];
			std::string s(1, c);
			return s;
		}
		*/
		void mostra() {

			char sep[] = "|";
			//std::string q(1, quem);
			char l1[] = "\n7|8|9\t\t|";
			char l2[] = "\n4|5|6\t\t|";
			char l3[] = "\n1|2|3\t\t|";
			std::cout << l1 << sto.getJogo(7) << sep << sto.getJogo(8) << sep << sto.getJogo(9) << sep << aviso(sto.getResultado());
			std::cout << l2 << sto.getJogo(4) << sep << sto.getJogo(5) << sep << sto.getJogo(6) << sep; // aviso(sto.getResultado());
			std::cout << l3 << sto.getJogo(1) << sep << sto.getJogo(2) << sep << sto.getJogo(3) << sep << "\n"; // aviso(sto.getResultado());

		}
};