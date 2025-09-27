public class Teste {
    public static void main(String args[]) {
        System.out.println("--------- Teste da classe Livro ---------\n");
        System.out.println("Usando construtor padrão:\n");

        Livro livro = new Livro();
        livro.ToString();

        System.out.println("\n---------------------\n");
        System.out.println("Usando construtor com parâmetros:\n");

        Livro livro2 = new Livro("1984", "George Orwell", 1949);
        livro2.ToString();
    }
}
