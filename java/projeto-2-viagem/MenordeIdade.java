public class MenordeIdade extends Pessoa{

	//Declaração do atributo que só o menor de idade possui: a autorização
	private String autorizacao;
	
	//Construtor de Menor de Idade
	public MenordeIdade(String nome, int idade, Assento assento, String autorizacao){
		super(nome, idade, assento);
		this.autorizacao = autorizacao;
	}
	//Setter e Getter do novo atributo
	public void setAutorizacao(String autorizacao){
		this.autorizacao = autorizacao;
	}
	public String getAutorizacao(){
		return autorizacao;
	}


}