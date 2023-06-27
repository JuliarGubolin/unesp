package lavaJato;
public class LavaJatoCarro{

	private String tipo;
	private double price;
	
	public LavaJatoCarro(String tipo){
		this.tipo = tipo;
	}
	public double priceWash(){
		if(this.tipo.equals("Padrao")){
			this.price = 34.60;
			return (price);
		}
		else{
			this.price = 45.80;
			return (price);
		}
	}


}