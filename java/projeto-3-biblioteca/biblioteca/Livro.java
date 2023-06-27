//Inclui a classe Livro no pacote biblioteca
package biblioteca;
public class Livro{

	//Declaração dos atributos de Livro
	private String autor, titulo;
	private Editora editora;

	//Construtor de Livro (cria um objeto da classe Livro)
	public Livro(String titulo, String autor, Editora editora){
		this.titulo = titulo;
		this.autor = autor;
		this.editora = editora;
	}
	//Setters e Getters dos atributos
	public void setAutor(String autor){
		this.autor = autor;
	}
	public void setTitulo(String titulo){
		this.titulo = titulo;
	}
	public void setEditora(Editora editora){
		this.editora = editora;
	}
	public String getAutor(){
		return autor;
	}
	public String getTitulo(){
		return titulo;
	}
	public Editora getEditora(){
		return editora;
	}

}