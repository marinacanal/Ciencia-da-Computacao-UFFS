using namespace std;

class Circulo {
    public:
        Circulo(double raio);
        double calcula_area();
        double calcula_perimetro();
        void imprime_area();
        void imprime_perimetro();
    
    private:
        double raio_;
};