import bomba.BombaCarro;
import lavaJato.LavaJatoCarro;
public class Teste{
	public static void main(String[] args){
		double bomb, lava;
		BombaCarro bomba = new BombaCarro("Gasolina", 27.0);
		bomb = bomba.calculoCombustivel();
		System.out.println("Valor combustivel: "+bomb);
		LavaJatoCarro wash = new LavaJatoCarro("Padrao");
		lava = wash.priceWash();
		System.out.println("Valor lavagem: "+lava);

	}
}