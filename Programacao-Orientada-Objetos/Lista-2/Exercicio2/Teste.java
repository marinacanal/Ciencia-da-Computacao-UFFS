public class Teste {
    public static void main(String args[]) {
        int a, b, resultado;
        double a2, b2, resultado2;

        System.out.println("--------- Teste da classe Calculadora ---------\n");
        System.out.println("Usando método soma com int:\n");
        
        a = 1;
        b = 2;
        resultado = Calculadora.soma(a, b);
        
        System.out.println(a + " + " + b + " = " + resultado);

        System.out.println("\n---------------------\n");
        System.out.println("Usando método soma com double:\n");

        a2 = 1.5;
        b2 = 2.6;
        resultado2 = Calculadora.soma(a2, b2);
        System.out.println(a2 + " + " + b2 + " = " + resultado2);
    }
}
