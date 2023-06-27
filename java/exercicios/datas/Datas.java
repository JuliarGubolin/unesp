/*Crie uma classe para representar datas.
1. Represente uma data usando três atributos: o dia, o mês, e o ano.
2. Sua classe deve ter um construtor que inicializa os três atributos e verifica a validade dos valores
fornecidos.
3. Forneça um construtor sem parâmetros que inicializa a data com a data atual fornecida pelo sistema
operacional.
4. Forneça um método set um get para cada atributo.
5. Forneça o método toString para retornar uma representação da ata como string. Considere que a
data deve ser formatada mostrando o dia, o mês e o ano separados por barra (/).
6. Forneça uma operação para avançar uma data para o dia seguinte.
7. Escreva um aplicativo de teste que demonstra as capacidades da classe.*/
import java.util.Calendar;
public class Datas{

	private int dia, mes, ano;
	private int dia_a, mes_a, ano_a;

	public Datas(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	public void receberData(){	
		Calendar c = Calendar.getInstance();
        	System.out.println("Data e Hora atual: "+c.getTime());
	}
	public int getDia(){
		return dia;
	}
	public int getMes(){
		return mes;
	}
	public int getAno(){
		return ano;
	}
	public int getAnoa(){
		return ano_a;
	}
	public int getMesa(){
		return mes_a;
	}
	public int getDiaa(){
		return dia_a;
	}
	public void setDia(int dia){
		this.dia = dia;
	}
	public void setMes(int mes){
		this.mes = mes;
	}
	public void setAno(int ano){
		this.ano = ano;
	}
	public void setMesa(int mes_a){
		this.mes_a = mes_a;
	}
	public void setAnoa(int ano_a){
		this.ano_a = ano_a;
	}
	public void set(int dia_a){
		this.dia_a = dia_a;
	}
	public void info(){
		System.out.println("DATA: "+getDia()+"/"+getMes()+"/"+getAno());
	}
	public static void main(String[] args){
		Datas d = new Datas(13, 06, 2001);
		d.info();
		d.receberData();
		
	}



}