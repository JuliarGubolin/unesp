//Inclui a classe Editora no pacote biblioteca
package biblioteca;
public class Editora{

	//Declaração dos atributos de Editora
	private String nome, endereco;

	//Contrutor de Editora (Cria um objeto da classe Editora)
	public Editora(String nome, String endereco){
		this.nome = nome;
		this.endereco = endereco;
	}
	//Setters e Getters dos atributos
	public String getNome(){
		return nome;
	}
	public String getEndereco(){
		return endereco;
	}
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setEndereco(){
		this.endereco = endereco;
	}


}