class Jogador
{
public:
    Jogador(char const* name): tipo(name) {}

    // this is required to properly delete virtual classes
    virtual ~Jogador() {}

    // with this strange syntax we define an unimplemeted "interface" function
    virtual int joga() = 0;

protected:
    // shared data field
    std::string tipo;
};