public class Livro {
    String titulo;
    String autor;
    int anoPublicacao;

    public Livro() {
        this.titulo = "Sem título";
        this.autor = "Desconhecido";
        this.anoPublicacao = 0;
    }

    public Livro(String titulo, String autor, int anoPublicacao) {
        this.titulo = titulo;
        this.autor = autor;
        this.anoPublicacao = anoPublicacao;
    }

    public void ToString() {
        System.out.println("Título: " + this.titulo);
        System.out.println("Autor: " + this.autor);
        System.out.println("Ano de Publicação: " + this.anoPublicacao);
    }
}