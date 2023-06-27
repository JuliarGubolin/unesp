/*Crie uma classe denominada Elevador para armazenar as informações de um elevador
dentro de um prédio. A classe deve armazenar o andar atual (térreo = 0), total de andares
no prédio (desconsiderando o térreo), capacidade do elevador e quantas pessoas estão
presentes nele. A classe deve também disponibilizar os seguintes métodos:
-Inicializa : que deve receber como parâmetros a capacidade do elevador e o total de
andares no prédio (os elevadores sempre começam no térreo e vazio);
-Entra : para acrescentar uma pessoa no elevador (só deve acrescentar se ainda houver
espaço);
-Sai : para remover uma pessoa do elevador (só deve remover se houver alguém
dentro dele);
-Sobe : para subir um andar (não deve subir se já estiver no último andar);
-Desce : para descer um andar (não deve descer se já estiver no térreo);*/
public class Elevador{

	private int andar;
	private int qtd;
	private int totalPessoa, totalAndar;
	
	public void setAndar(int andar){
		this.andar = andar;
	}
	public void setQtd(int qtd){
		this.qtd = qtd;
	}
	public int getAndar(){
		return andar;
	}
	public int getQtd(){
		return qtd;
	}
	public void inicializa(int totalAndar, int totalPessoa){
		this.totalAndar = totalAndar;
		this.totalPessoa = totalPessoa;
		this.andar = 0;
		this.qtd = 0;
	}
	public void entra(){
		if(this.qtd<=this.totalPessoa){
			this.qtd++;	
			System.out.println("Entrou, "+getQtd());
		}
		else{
			System.out.println("Lotado!!");
		}		
	}
	public void sai(){
		if(this.qtd>0){
			this.qtd--;
			System.out.println("Saiu, "+getQtd());	
		}
		else{
			System.out.println("Vazio!!");
		}
	}
	public void sobe(){
		if(this.andar<this.totalAndar){
			this.andar++;
			System.out.println("Sobe, "+getAndar());	
		}
		else{
			System.out.println("TOPO!!");
		}
	}
	public void desce(){
		if(this.andar>0){
			this.andar--;	
			System.out.println("Desce, "+getAndar());	
		}
		else{
			System.out.println("Terreo!!");
		}
	}
	public static void main(String[] args){
		Elevador e = new Elevador();
		e.inicializa(21, 7);
		e.sobe();
		e.entra();
		e.entra();
		e.desce();
		e.desce();
	}


}