class Humano: public Jogador {
public:
    // need to forward the constructor arguments
    Humano(char const* name): Jogador(name) {}

    // here we implement the interface
    int joga() override {
		std::string n;
		std::cout << "\ndigite o nr: ";
		std::getline(std::cin, n);	
		if(n.length() != 0){
			int r = std::string("0123456789").find(n.c_str());
			if(r != std::string::npos){
				return r;
			}
		} 
		return 0;
    }
};
