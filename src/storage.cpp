class Storage {

    private:
    	char jogo[11];
    	bool vez;
    	int resultado; 
			
	public:
		void zera(){
			strncpy(jogo, "          ", 11 );
			vez = true; 
			resultado = 0; 
		}
		char getJogo(int i) {
			return jogo[i];
		}
		void setJogo(int casa, char t) {
			jogo[casa] = t;
		}
		void setVez() {
			vez = !vez;
		}
		bool getVez() {
			return vez;
		}
		void setResultado(int r) {
			resultado = r;
		}
		int getResultado() {
			return resultado;
		}
};
