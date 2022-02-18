public class Transporte{

	//Declaração dos atributos
	private Assento [][]assentos;
	private int TotalAssentos, AssentosNormais, AssentosPref;

	//Contrutor de Transporte. Já possui a qtd total de assentos, de preferenciais e normais pré definida
	//Já que só há um meio de transporte 
	public Transporte(Assento [][]assentos){
		this.assentos = assentos;
		this.TotalAssentos = 80;
		this.AssentosNormais = 60;
		this.AssentosPref = 20;
	}
	//Setters e Getters dos atributos
	public void setAssentos(Assento [][]assentos){
		this.assentos = assentos;
	}
	public void setTotalAssentos(int TotalAssentos){
		this.TotalAssentos = TotalAssentos;
	}
	public void setAssentosNormais(int AssentosNormais){
		this.AssentosNormais = AssentosNormais;
	}
	public void setAssentosPref(int AssentosPref){
		this.AssentosPref = AssentosPref;
	}
	public Assento[][] getAssentos(){
		return assentos;
	}
	public int getTotalAssentos(){
		return TotalAssentos;
	}
	public int getAssentosNormais(){
		return AssentosNormais;
	}
	public int getAssentosPref(){
		return AssentosPref;
	}
}