//Biblioteca para obter as informações digitadas pelo usuário
import java.util.Scanner;
//Início do programa com a classe conta
public class Conta{
		//Declaração dos atributos privados
          	private String nome;
          	private String CPF;
          	private double saldo;
          	private int num;
          	private String RG;
	  	private int senha;
      //Salva os dados da conta, recebendo como parâmetro os dados dela
      public Conta(String nome, String CPF, double saldo, int num, String RG, int senha){
                this.nome = nome;
                this.CPF = CPF;
                this.saldo = saldo;
                this.num = num;
                this.RG = RG;
	        this.senha = senha;
      }
      //Declaração dos "gets" para retornar
      public String getNome(){
		return nome;
      }
      public double getSaldo(){
		return saldo;
      }
      public String getCPF(){
		return CPF;
      }
      public String getRG(){
		return RG;
      }
      public int getNum(){
		return num;
      }
      public int getSenha(){
		return senha;
      }
      //Declaração dos "sets" para salvar os dados
      public void setNome(String nome){
		this.nome = nome;
      }
      public void setSaldo(double saldo){
		this.saldo = saldo;
      }
      public void setCPF(String CPF){
		this.CPF = CPF;
      }
      public void setRG(String RG){
		this.RG = RG;
      }
      public void setNum(int num){
		this.num = num;
      }
      //Deposita na conta com o número indicado pelo usuário
      public void depositaConta(Conta c[], double valor){
		if(valor <= 0){
			System.out.println("N\u00e3o foi poss\u00edvel fazer o deposito.\n");
		}
                else{
			this.saldo = this.saldo +valor;
		}       		
      }
      //Saca da conta com o número indicado pelo usuário
      public void sacaConta(Conta c[], double valor){
		if(valor <= 0 || valor > this.saldo){
			System.out.println("N\u00e3o foi poss\u00edvel fazer o saque.\n");
		}
		else{
			this.saldo = this.saldo-valor;            	
  		}
      }
      //Transfere valores entre duas contas. Parâmetros: conta destino, vetor de contas, valor da transferência
      public void tranfereConta(int d, Conta c[], double valor, int total){
		if(d == this.num || valor <= 0.0 || this.saldo == 0 || valor> this.saldo || d>=total){
			System.out.println("N\u00e3o foi poss\u00edvel fazer a tranfer\u00eancia.\n");
		}
		else{
			this.saldo -= valor;
			c[d].depositaConta(c, valor);
			System.out.println("ATUALIZADO TRANFER\u00caNCIA.\n");
			
		}
      }
      //Imprime todas as contas cadastradas no vetor 
      public static void imprimeConta(Conta c[], int contas_cad){
		for(int i=0;i<contas_cad;i++){
			System.out.println("\nConta "+i);
			System.out.print("\nNome: "+c[i].getNome()+"\nCPF: "+c[i].getCPF()+"\nSaldo: "+c[i].getSaldo()+"\nN\u00famero: "+c[i].getNum()+"\nRG: "+c[i].getRG()+"\nSenha: ****");
			System.out.print("\n");
                 }
			System.out.print("\n");
       }
      //Função principal
      public static void main(String[] args){
		 
                 //Declaração do Scanner para obter os dados necessários
                 Scanner sc = new Scanner(System.in);
                 int op, o, d, opcao, g=0, contas_cad=0;
		 //Variáveis auxiliares para criar um cadastro novo
                 double val;
		 String name, rg, cpf, last_name;	
		 int lock, cont=0;
                 //Criação de um vetor para salvar as contas
                 Conta[] c = new Conta[100];
                 //Optei por supor algumas contas exemplo, além da opção de criar uma nova
          	 c[contas_cad] = new Conta("Ana Maria do Prado", "123.678.439-10", 678900.00, contas_cad, "56.090.060-12", 1234);contas_cad++;//0
          	 c[contas_cad] = new Conta("Bernardo Antunes Carneiro", "907.647.098-14", 78.00, contas_cad, "45.879.411-78", 8988);contas_cad++;//1
          	 c[contas_cad] = new Conta("Cassia Maria dos Santos Borges", "400.289.225-90", 900.00, contas_cad,  "23.483.321-8", 6752);contas_cad++;  //2            
                 //Loop para o MENU PRINCIPAL
		 do{
			System.out.print("***********MENU PRINCIPAL***********\n\n");
        		System.out.print("1 - Cadastrar Conta\n2 - Entrar na Conta\n3 - Contas cadastradas \n4 - Sair");
			System.out.print("\n\n************************************\n-> ");
        		opcao  = sc.nextInt();
			
			switch(opcao){
        		     //Cadastra um novo usuário
        		     case 1:
				//Se a quantidade de contas exceder o limite, não será mais permitida
            			if(contas_cad>=100){
					System.out.print("\033[H\033[2J");
					System.out.println("Limite de Contas atingido!!");
					break;
				}
				//Caso ainda haja espaço para armazenar contas
				else{
					System.out.print("\033[H\033[2J");
					System.out.println("CADASTRO DE CONTA");
					System.out.print("PRIMEIRO NOME: ");
					name = sc.next();
					System.out.print("SOBRENOME: ");
					last_name = sc.next();
					//Este trecho é para juntar o nome e o sobrenome, de forma ter um espaço
					//entre os dois
					String space = " ";
					String nomeCompleto = name.concat(space);
					nomeCompleto = nomeCompleto.concat(last_name);
					System.out.print("CPF Ex:(xxx.xxx.xxx-xx): ");
					cpf = sc.next();	
					System.out.print("RG Ex:(xx.xxx.xxx-xx): ");
					rg = sc.next();
					System.out.print("SENHA DE QUATRO N\u00daMEROS: ");
					lock = sc.nextInt();
					System.out.println("ANOTE O N\u00daMERO DA SUA CONTA: "+contas_cad);
					c[contas_cad] = new Conta(nomeCompleto, cpf, 0.0, contas_cad, rg, lock);contas_cad++;
				}        
				break;
			   //Entra na conta de um usuário para fazer as operações
      			     case 2:
				System.out.print("\033[H\033[2J");
        			System.out.print("N\u00famero da Conta: ");
        			o = sc.nextInt();
        			System.out.print("SENHA: ");
			  	lock = sc.nextInt();			
				for(int i=0;i<contas_cad;i++){
				  if(o==c[i].getNum() && lock == c[i].getSenha()){
				   //MENU DE OPERAÇÕES
                 		     do{
                     			System.out.print("*************MENU CONTA***************\n\n1 - Depositar\n2 - Sacar\n3 - Transferir \n4 - Saldo \n5 - Sair para o inicio \n\n");
					System.out.print("**************************************\n-> ");
                     			op = sc.nextInt();
		     
					switch(op){
                     			  //Deposita na conta escolhida pelo usuário (variável "o")
                     			  case 1:
						System.out.print("\033[H\033[2J");
                               			System.out.println("DEP\u00d3SITO");
                               			System.out.print("Valor: ");
                               			val = sc.nextDouble();
                              			c[o].depositaConta(c, val);
						break;
                     			  //Saca da conta escolhida pelo usuário (variável "o")
                     			  case 2:
						System.out.print("\033[H\033[2J");
                               			System.out.println("SAQUE");
                               			System.out.print("Valor: ");
                               			val = sc.nextDouble();
				                c[o].sacaConta(c, val);
						break;	                 			
                     			  //Tranfere da conta escolhida pelo usuário para outra a qual será indicada por ele (variável "o")
                     			  case 3:
						System.out.print("\033[H\033[2J");
						System.out.println("TRANFER\u00caNCIA");
                            		        System.out.print("N\u00famero da Conta de DESTINO: ");
			                        d = sc.nextInt();
		                                System.out.print("Valor: ");
			                        val = sc.nextDouble();
					        c[o].tranfereConta(d, c, val, contas_cad);	
					        break;	
                     			  //Mostra na tela o saldo da conta escolhida pelo usuário (variável "o")
                     			  case 4:
						System.out.print("\033[H\033[2J");
                               		        System.out.println("SALDO DE CONTA");
                               		        val = c[o].getSaldo();
                               		        System.out.print("SALDO: R$ "+val+ ".\n\n");
             	      			        break;
					  //Retorna ao MENU PRINCIPAL
                    			  case 5:
						System.out.print("\033[H\033[2J");
			                        System.out.println("\n");
					        break;    			
                     			  //Verifica se a opção escolhida pelo usuário é válida
                     			  default:
                                	        System.out.println("Op\u00e7\u00e3o Inv\u00e1lida. Leia novamente o menu.");
                     			        break;
					}
                		   }while(op != 5);
				  }
				  else
                		  {
                		      cont++;
                		  }
      				}//fim do ciclo FOR
				//Verifica se o número e senha digitados pelo usuário existem no vetor
				//Caso não, mostra na tela a mensagem abaixo e volta ao MENU PRINCIPAL
                		if(cont == contas_cad)
                		{
                			cont=0;
                			System.out.println("Conta n\u00e3o cadastrada ou erro de autentica\u00e7\u00e3o.");
                		}			
            			break;
			     //Imprime na tela todas as contas cadastradas no vetor
                	     case 3:
				System.out.print("\033[H\033[2J");
                    		imprimeConta(c, contas_cad);
				break;
			     //Encerra o programa
                	     case 4:
				System.out.print("\033[H\033[2J");
                  		System.out.println("Encerrado.");
				break;
            		     //Verifica a escolha do usuário
			     default:
				System.out.println("Op\u00e7\u00e3o Inv\u00e1lida. Leia novamente o menu.");
			}
          	 }while(opcao != 4);
      }
}