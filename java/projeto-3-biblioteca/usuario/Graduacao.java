//Bibliotecas para utilizar lista dinâmica e incluí-lo no pacote usuario
package usuario;
import biblioteca.Livro;
import java.util.ArrayList;
//Esta classe extende pessoa, portanto herda todos os seus atributos
public class Graduacao extends Pessoa{

	//Atributo inerente apenas aos alunos de graduação
	private String RA;

	//Contrutor de Graduação
	public Graduacao(String nome, String email, ArrayList<Livro> livros, String RA, String senha, String categoria){
		super(nome, email, livros, senha, categoria);
		this.RA = RA;
	}
	public void reservarLivro(ArrayList<Livro> livros, Livro book){
		livros.add(book);
	}
	public void devolverLivro(ArrayList<Livro> livros, int info){
		livros.remove(info);
	}
	//Setters e Getters dos atributos
	public void setRA(String RA){
		this.RA = RA;
	}
	public String getRA(){
		return RA;
	}
}