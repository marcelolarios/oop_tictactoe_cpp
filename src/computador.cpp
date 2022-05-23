class Computador: public Jogador {
public:
    Computador(char const* name): Jogador(name) {}

    int joga() override {
		
		int p = rand() % 9 + 1;
		return p;
    }

};

