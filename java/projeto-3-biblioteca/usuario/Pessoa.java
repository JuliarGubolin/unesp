//Bibliotecas para utilizar lista dinâmica e incluí-lo no pacote usuario
package usuario;
import biblioteca.Livro;
import java.util.ArrayList;
//Início da classe "mãe" de Graduacao e Posgraduacao
public class Pessoa{

	//Atributos de pessoa
	private String nome, email;
	private ArrayList<Livro> livros;
	private String senha;
	private String categoria;

	//Contrutor de Pessoa (Cria um objeto da classe Pessoa)
	public Pessoa(String nome, String email, ArrayList<Livro> livros, String senha, String categoria){
		this.nome = nome;
		this.email = email;
		this.livros = livros;
		this.senha = senha;
		this.categoria = categoria;
	}
	//Setters e Getters dos atributos, além dos métodos de reservar e devolver livros
	//Que serão sobrescritos em Graduação e Pós Graduação
	public void reservarLivro(ArrayList<Livro> livros, Livro book){

	}
	public void devolverLivro(ArrayList<Livro> livros, int info){

	}
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setEmail(String email){
		this.email = email;
	}
	public void setSenha(String senha){
		this.senha = senha;
	}
	public void setLivros(ArrayList<Livro> livros){
		this.livros = livros;
	}
	public void setCategoria(String categoria){
		this.categoria = categoria;
	}
	public ArrayList<Livro> getLivros(){
		return livros;
	}
	public String getNome(){
		return nome;
	}
	public String getEmail(){
		return email;
	}
	public String getSenha(){
		return senha;
	}
	public String getCategoria(){
		return categoria;
	}
}