//Biblioteca para utilizar lista dinâmica no método Reservar
import java.util.ArrayList;
public class Idoso extends Pessoa{

	//Construtor de Idoso, o qual não possui nenhum atributo novo
	public Idoso(String nome, int idade, Assento assento){
		super(nome, idade, assento);
	}
	//Reservar para idosos que optaram pelo assento preferencial
	public void Reservar(Assento a[][], ArrayList<Pessoa> listaPessoa, Assento s){

		a[s.getFileira()][s.getCadeira()].setCadeira(1);
		a[s.getFileira()][s.getCadeira()].setFileira(1);
	}


}