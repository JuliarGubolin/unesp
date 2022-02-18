//Biblioteca para utilizar lista dinâmica 
import java.util.ArrayList;
public class Pessoa{	

	//Declaração dos atributos
	private String nome;
	private int idade;
	private Assento assento;

	//Construtor de Pessoa
  	public Pessoa(String nome, int idade, Assento assento){
     	 	this.nome = nome;
      		this.idade = idade;
      		this.assento = assento;
  	}
	//Reservar para menores, adultos e idosos que optaram pelo assento normal
	public void Reservar(Assento [][]a, ArrayList<Pessoa> listaPessoa, Assento s){
		
		a[s.getFileira()][s.getCadeira()].setCadeira(1);
		a[s.getFileira()][s.getCadeira()].setFileira(1); 	
	}
	
	//Setters e Getters dos atributos
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setIdade(int idade){
		this.idade = idade;
	}
	public void setAssento(Assento assento){
		this.assento =  assento;
	}
	public String getNome(){
		return nome;
	}	
	public int getIdade(){
		return idade;
	}
	public Assento getAssento(){
		return assento;
	}
	//Retorna o assento de determinada Pessoa cadastrada
	public String pesquisa(){
		return assento.toString();
	}
}