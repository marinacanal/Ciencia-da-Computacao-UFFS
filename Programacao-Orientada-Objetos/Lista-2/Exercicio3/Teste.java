public class Teste {
    public static void main(String[] args) {
        double c, f;

        System.out.println("--------- Teste da classe Conversor ---------\n");
        System.out.println("Usando método celsiusParaFahrenheit:\n");
        
        c = 25;
        
        System.out.println(c + "°C para Fahreinheit: " + Conversor.celsiusParaFahrenheit(c));

        System.out.println("\n---------------------\n");
        System.out.println("Usando método fahrenheitParaCelsius:\n");

        f = 100;
        System.out.println(f + "°F para Celsius: " + Conversor.fahrenheitParaCelsius(f));
    }
}
