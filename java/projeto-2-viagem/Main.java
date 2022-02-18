//Bibliotecas para receber os dados do teclado e utilizar lista dinâmica
import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	//Método para limpar a tela
	public static void limpaTerminal(){
		System.out.print("\033[H\033[2J");
	}
	//Início da Função principal
	public static void main(String[] args){
		//Declaração do Scanner
		Scanner sc = new Scanner(System.in);

		//Variáveis para receber o nome completo para CADASTRO
		String nome, sobrenome, nome_completo, space= " ";

		//Declaração da lista 
		ArrayList<Pessoa> listaPessoa = new ArrayList<Pessoa>();
		
		//Variáveis para receber informações do usuário e informar o total geral e por idade;
		int total_idosos=0, total_idosos_p=0, total_adultos=0, total_menores=0, total_passageiros=0;
		int op, idd, c, f, fil=4, cad=21, i, choice = 0;

		//Criação de uma matriz com assentos preferenciais (pref) e outra (a) apenas com assentos normais.
		Assento [][]a = new Assento[fil][cad];
		Assento [][]pref = new Assento [fil+1][cad];
		Transporte t = new Transporte(a);

		//Construção das matrizes declaradas acima. O primeiro loop contrói a matriz de assentos normais, indicados por 0.
		//A segunda, os assentos preferenciais, indicados por 4.
		for(i=1;i<fil;i++){
				for(int j=1;j<cad;j++){
					Assento h = new Assento(0,0);
					a[i][j] = h;
				}
		}
		for(i=1;i<fil+1;i++){
				for(int j=1;j<cad;j++){
					Assento h = new Assento(4,4);
					pref[i][j] = h;
				}
		}
		//Menu de interação
			do{
				//Variável para armazenar o tamanho da lista
				int size = listaPessoa.size();
				System.out.println("\n******INGRESSOS P.O.O AIRLINES******\n\n1 - Consultar total de passageiros\n2 - Consultar total de Idosos, Adultos e Menores");
				System.out.println("3 - Consultar dados de um assento\n4 - Consultar Assentos Livres\n5 - Cadastrar+Reservar um Assento\n6 - Sair\n");
				System.out.println("************************************");
				op = sc.nextInt();
				switch(op){
				        //Opção 1: consulta o total de passageiros no voo
					case 1: 
						limpaTerminal();
						System.out.println("CONSULTA TOTAL\n");
						System.out.println("Total de passageiros no voo: "+total_passageiros+"\n");
						break;
		
					//Opção 2: consulta o total por idade (idosos, menores e adultos)
					case 2:
						limpaTerminal();
						System.out.println("CONSULTA POR IDADE\n");
						System.out.println("Total de IDOSOS no voo: "+(total_idosos+total_idosos_p)+"\nTotal de ADULTOS no voo: "+total_adultos);
						System.out.println("Total de MENORES no voo: "+total_menores+"\n");
						break;
				
					//Opção 3: consulta a pessoa que está em determinado assento
					case 3:
						limpaTerminal();
						System.out.println("CONSULTA POR ASSENTO\n");
						//Se a lista estiver vazia
						if(size == 0){	
							System.out.println("Ainda nao ha pessoas cadastradas.");
							break;
						}
						System.out.println("ASSENTO\n");
						System.out.print("Fileira: ");
						f = sc.nextInt();
						System.out.print("Cadeira: ");
						c = sc.nextInt();
						//Verifica se a fileira e a cadeira digitadas estão corretas
						if((f > 4 || f < 1) || (c < 1 || c > 20)){
							System.out.print("Fileira e/ou cadeira invalida. Tente novamente.\n");
						}
						else{
							Assento assento = new Assento(f, c);
							int k=0;
							for(i=0;i<size;i++){								
								Pessoa pessoa = listaPessoa.get(i);
								if(pessoa.pesquisa().equals(f+""+c)){
									System.out.print("\nOcupado por: "+pessoa.getNome()+", "+pessoa.getIdade()+" anos.\n");
								}
								else{
									k++;
								}
							}
							if(k == size){
								System.out.println("\nAssento livre.\n");
							}
						}		
						break;
					//Opção 4: mostra ao usuário os assentos livres
					case 4:
						//Caso ainda existam assentos livres (80 no total)
						if(total_passageiros <= ((fil)*(cad-1))){
							limpaTerminal();
							System.out.println("CONSULTAR ASSENTOS LIVRES\n");
							System.out.println("00 -> Assento normal disponivel.");
							System.out.println("11 -> Assento ocupado.");
							System.out.println("44 -> Assento preferencial disponivel.\n");
							for(i=1;i<fil;i++){
								System.out.print("\n");
								for(int j=1;j<cad;j++){
									System.out.print(a[i][j].getFileira());
									System.out.print(a[i][j].getCadeira()+" ");
								}
							}
							for(i=4;i<fil+1;i++){
								System.out.print("\n");
								for(int j=1;j<cad;j++){		
									System.out.print(pref[i][j].getFileira());
									System.out.print(pref[i][j].getCadeira()+" ");
								}
							}
							System.out.println("");
						}
						//Caso o voo esteja lotado, o usuário não pode mais ver os assentos livres
						else{
							System.out.println("Voo LOTADO. Nao existem assentos livres.\n");
						}
						break;
				
					//Opção 5: cadastra e reserva o assento de um usuário
					case 5:
						if(total_passageiros <= ((fil)*(cad-1))){
							int m=0;
							limpaTerminal();
							System.out.println("CADASTRAR E RESERVAR\n");
							System.out.print("PRIMEIRO NOME: ");
							nome = sc.next();
							System.out.print("SEGUNDO NOME: ");
							sobrenome = sc.next();
							//Une o primeiro ao segundo nome
							nome_completo = nome.concat(space);
							nome_completo = nome_completo.concat(sobrenome);
							//Verifica se o nome já esta cadastrado
							for(i=0;i<size;i++){
								Pessoa pessoa = listaPessoa.get(i);
								if(pessoa.getNome().equals(nome_completo)){
									System.out.print("\nNome ja cadastrado.\n");
									m = m+1;	
								}
							}
							//Caso o nome ainda não tenha sido cadastrado, continua a reserva
							if(m == 0){
								System.out.print("IDADE: ");
								idd = sc.nextInt();
								//Verifica se a idade é valida
								if(idd<0){ 
                  							System.out.print("Idade invalida.\n"); 
                  							break;
                						}
								//Caso a idade seja maior ou igual a 60 anos, é aberta a opção de assento preferencial.
								//Caso o usuário opte pelo assento preferecial, a variável np aumenta, alterando, mais abaixo,
								//O modo como será reservado este assento.
								int np = 3;
								if(idd>=60){
									System.out.print("Assento normal<1> ou preferencial<2>?: ");
									choice = sc.nextInt();
									//Verifica se a escolha feita é <1> ou <2>
									if(choice <1 || choice >2){
										System.out.println("Opcao Invalida. Tente novamente.");
										break;
									}		
									if(choice == 2){
										np++;
									}
								}
								System.out.print("ASSENTO\n");
								//Caso o idoso escolha o assento preferencial, sua fileira automaticamente é a 4, definida como de assentos preferenciais
								if(np == 4){
									f = 4;
								}
								else{
									System.out.print("Fileira (1 a 3): ");
									f = sc.nextInt();
								}
								System.out.print("Cadeira (1 a 20): ");
								c = sc.nextInt();
								//Verifica se a cadeira ou a fileira escolhida são válidas 
								if((f > 4 || f < 1) || (c < 1 || c > 20) || (idd < 60 && f == 4) || (idd>= 60 && choice == 1 && f == 4)){
									System.out.print("Fileira e/ou cadeira invalida. Tente novamente.\n");
									break;
								}
								//Verifica se ainda podem ser reservados assentos normais
								if((total_idosos+total_adultos+total_menores >60)){
									System.out.println("Assentos normais lotados.\n");
									break;
								}
								//Caso hajam pessoas cadastradas, o programa irá conferir se o assento já está ocupado.
								//Variável g para parar a execução caso o assento não esteja disponível
								int g = 0; 
								if(size != 0){
									for(i=0;i<size;i++){
										Pessoa pessoa = listaPessoa.get(i);
										if(pessoa.pesquisa().equals(f+""+c)){
											System.out.print("\nAssento indisponivel. Escolha <4> para verificar os assentos livres.\n");
											np = 0;
											g++;
										}
									}
								}
								if(g >0){
									break;
								}
								Assento sit = new Assento(f, c);
								//Caso a idade do usuário o enquadre como menor, ele deve possuir autorização
								if(idd<18){
									String autorizacao = "";
									System.out.print("Possui autorizacao dos responsaveis? <1>sim <2>nao: ");
									int aut = sc.nextInt();
									if(aut <1 || aut >2){
										System.out.println("Opcao Invalida. Tente novamente.");
									}
									else if(aut == 1){
										System.out.print("--> Autorizacao: ");
										autorizacao = sc.next();
										MenordeIdade menor = new MenordeIdade(nome_completo, idd, sit, autorizacao);
										listaPessoa.add(menor);
										menor.Reservar(a, listaPessoa, sit);
										total_menores++;
										total_passageiros++;
									}
									//Caso não tenha autorização, ele não poderá fazer a reserva
									else{
										break;
									}
								}
								//Caso a idade do usuário se enquadre como adulto
								else if(idd<60){
									Adulto adult = new Adulto(nome_completo, idd, sit);
									listaPessoa.add(adult);
									adult.Reservar(a, listaPessoa, sit);
									total_adultos++;
									total_passageiros++;
								}
								//Caso o passageiro seja idoso
								else{
								//Caso, no cadastro, o usuário tenha escolhido o assento normal, np == 3 e é reservado um assento
								//Através do reservar presente na classe Pessoa.
									if(np == 3){
										Idoso idoso = new Idoso(nome_completo, idd, sit);
										listaPessoa.add(idoso);
										for(i=0;i<listaPessoa.size();i++){
											Pessoa p = listaPessoa.get(i);
											if(nome_completo.equals(p.getNome())){
												p.Reservar(a, listaPessoa, sit);
												total_idosos++;
												total_passageiros++;
											}
										}
									}
									//Caso, no cadastro, o usuário tenha escolhido o assento preferencial, np == 4 e é reservado um assento
									//Através do reservar presente na classe Idoso.
									else if(np == 4){
										if(total_idosos_p <= 20){
											Idoso velho = new Idoso(nome_completo, idd, sit);
											listaPessoa.add(velho);
											for(i=0;i<listaPessoa.size();i++){
												Pessoa p = listaPessoa.get(i);
												if(nome_completo.equals(p.getNome())){
													p.Reservar(pref, listaPessoa, sit);
													total_idosos_p++;
													total_passageiros++;
												}
											}
										}
										else{
											System.out.println("Assentos preferenciais lotados.");
											break;
										}
									}
								}
						    	}
            					}
						else{
							System.out.println("Voo LOTADO. Nao e possivel realizar mais reservas.\n");
						}
						break;
					//Opção 6: encerra o programa
					case 6:
						limpaTerminal();
						System.out.println("Obrigada por voar conosco!! Tenha uma otima viagem!!");
						break;
					//Verifica o que foi digitado
					default:
						limpaTerminal();
						System.out.println("Leia novamente o MENU. Opcao Invalida.");
						break;

					}
			}while(op != 6);
		}
}