//Bibliotecas para utilizar lista dinâmica e incluí-lo no pacote usuario
package usuario;
import biblioteca.Livro;
import java.util.ArrayList;
public class Posgraduacao extends Pessoa{

	//Atributo inerente apenas aos alunos de Pós graduação
	private String CCO;

	//Contrutor de Pós graduação
	public Posgraduacao(String nome, String email, ArrayList<Livro> livros, String CCO, String senha, String categoria){
		super(nome, email, livros, senha, categoria);
		this.CCO = CCO;
	}
	public void reservarLivro(ArrayList<Livro> livros, Livro book){
		livros.add(book);
	}
	public void devolverLivro(ArrayList<Livro> livros, int info){
		livros.remove(info);
	}
	//Setters e Getters dos atributos
	public void setCCO(String CCO){
		this.CCO = CCO;
	}
	public String getCCO(){
		return CCO;
	}
}