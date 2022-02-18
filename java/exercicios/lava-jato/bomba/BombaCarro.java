package bomba;
public class BombaCarro{

	private double price;
	private double qtd;
	private String combustivel;

	public BombaCarro(String combustivel, double qtd){
		this.qtd = qtd;
		this.combustivel = combustivel;
	}
	public double calculoCombustivel(){
		if(this.combustivel.equals("Etanol")){
			this.price = 2.49;
			return (this.price*this.qtd);
		}
		else{
			this.price = 3.27;
			return (this.price*this.qtd);
		}		
	
	}
}
