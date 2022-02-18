public class Assento{

	//Declaração dos atributos
	private int fileira, cadeira;
	
	//Contrutor de Assento
	public Assento(int fileira, int cadeira){
		this.fileira = fileira;
		this.cadeira = cadeira;
	}
	//Setters e Getters dos atributos
	public void setFileira(int fileira){
		this.fileira = fileira;
	}
	public void setCadeira(int cadeira){
		this.cadeira = cadeira;
	}
	public int getFileira(){
		return fileira;
	}
	public int getCadeira(){
		return cadeira;
	}
	//Retorna a fileira e a cadeira que compõe o assento. É chamada na classe pessoa 
	//Para relacionar um assento a uma Pessoa
	public String toString(){
		return getFileira()+""+getCadeira();
	}


}