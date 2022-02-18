//Importando os pacotes de usuario e biblioteca, além das bibliotecas para utilizar arquivos, listas dinâmicas e dados do teclado
import usuario.*;
import biblioteca.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.IOException;
public class Principal{

	//Método para limpar a tela
	public static void limpaTerminal(){
		System.out.print("\033[H\033[2J");
	}
	//Inicio do método Main
	public static void main(String []args) throws IOException{

		//Declaração de variáveis para receber informações do usuário
		int op, opcao, i, info=0, u=0, j=0, senha_biblio, var = 0;
		String senha, nome, end, titulo, autor, email, ra, cco, cat;

		//Criação das listas dinâmicas para editora, livro e pessoa
		ArrayList<Editora> listEditora = new ArrayList<Editora>();
		ArrayList<Livro> listLivro = new ArrayList<Livro>();
		ArrayList<Pessoa> listPessoa = new ArrayList<Pessoa>(); 
		ArrayList<Livro> livros = new ArrayList<Livro>();
		
		//Carregando os dados dos arquivos txt para dentro das respectivas listas
		Arquivo.loadEdit("Editoras.txt", listEditora);
		Arquivo.loadLivro("LivrosDisp.txt", listLivro);
		Arquivo.loadPessoa("Pessoa.txt", listPessoa);
		Arquivo.loadReservados("Reservados.txt", listPessoa);
		Arquivo.loadTemp("temp.txt");

		//Declaração do Scanner
		Scanner sc = new Scanner(System.in);
		
		//Início do menu PRINCIPAL
		do{
			System.out.println("\n**********SISTEMA GERAL**********\n\n1 - Login Aluno\n2 - Login Biblioteca");
			System.out.println("3 - Cadastrar Aluno\n4 - Sair\n");
			System.out.println("*********************************");
			opcao = sc.nextInt();
			switch(opcao){
				//Opção 1: faz login na conta do aluno para reservae e/ou devolver livros
				case 1:
					//Verificação: se existem pessoas na lista
					if(listPessoa.size() == 0){
						System.out.println("Ainda nao existem cadastros");
						break;
					}
					System.out.println("LOGIN ALUNO\n");	
					System.out.print("E-mail: ");
					email = sc.next();
					System.out.print("Senha: ");
					senha = sc.next();
					int tam = listPessoa.size();
					//Verificação: se o email e a senha são correspondentes a algum usuário cadastrado
					for(i=0;i<tam;i++){
						Pessoa pessoa = listPessoa.get(i);
						if(pessoa.getEmail().equals(email) && pessoa.getSenha().equals(senha)){
							var = i;
						}
						else{
							j++;
						}
					}
					//Verificação: caso o cadastro tenha sido encontrado
					if(j != tam){
						j=0;
						do{
							//Menu do usuario cadastrado
						        System.out.println("\n******SISTEMA ALUNO******\n\n1 - Reservar Livro\n2 - Devolver Livro");
							System.out.println("3 - Logout\n");
							System.out.println("*************************");
							op = sc.nextInt();
							switch(op){
								//Opção 1: reserva um livro cadastrado na biblioteca
								case 1:
									//Verificação: caso ainda não existam livros cadastrados. Sai da opção de reserva
									if(listLivro.size() == 0){
										System.out.println("Nao existem livros disponiveis para reserva.");
										break;
									}
									//Verificação: verifica se o limite de livros de cada categoria, 1 ou 2, foi atingido
									if(listPessoa.get(var).getCategoria().equals("1")){
										if(listPessoa.get(var).getLivros().size() == 5){
											System.out.println("Limite de reservas atingido.");
											break;
										}
									}
									else{
										if(listPessoa.get(var).getLivros().size() == 10){
											System.out.println("Limite de reservas atingido.");
											break;
										}
									}
									//Mostra para o usuário os livros disponíveis para reserva
									System.out.println("DADOS DOS LIVROS DA BIBLIOTECA");
									for(i=0;i<listLivro.size();i++){
										System.out.println("\n<"+(i)+"> Titulo: "+listLivro.get(i).getTitulo()+" Autor: "+listLivro.get(i).getAutor());	
									}
									System.out.print("\n-> ");
									info = sc.nextInt();
									//Verificação: verifica se info está valendo 1 ou 2. Caso não, o usuário volta ao menu 
									if(info < 0 || info >= listLivro.size()){
										System.out.println("Erro. Opcao Invalida.");
										break;
									}
									//Cria um objeto de Editora, um objeto de Livro, adiciona o livro na lista do usuário
									//Remove da lista de livros disponíveis (listLivro) e atualiza o arquivo retirando o livro reservado
									Editora ed = new Editora(listLivro.get(info).getEditora().getNome(), listLivro.get(info).getEditora().getEndereco());
									Livro book = new Livro(listLivro.get(info).getTitulo(), listLivro.get(info).getAutor(), ed);
									listPessoa.get(var).reservarLivro(livros, book);
									String juntandinho = listPessoa.get(var).getEmail().concat("+").concat(listLivro.get(info).getTitulo()).concat("+").concat(listLivro.get(info).getAutor()).concat("+").concat(listLivro.get(info).getEditora().getNome()).concat("+").concat(listLivro.get(info).getEditora().getEndereco()).concat("+");
									Arquivo.escrever("Reservados.txt", juntandinho);
									listLivro.remove(info);
									Arquivo.atualizar("LivrosDisp.txt", listLivro);
									break;
								//Opção 2: devolve um livro reservado pelo usuário
								case 2:
									//Verificação: verifica se o usuário reservou algum livro
									if(listPessoa.get(var).getLivros().size() == 0){
										System.out.println("Voce nao possui livros para devolver.\n");
										break;
									}
									//Mostra a lista de livros reservados para que ele escolha qual quer devolver
									System.out.println("LIVROS RESERVADOS POR VOCE");
									for(i=0;i<listPessoa.get(var).getLivros().size();i++){
										System.out.println("\n<"+(i)+"> Titulo: "+listPessoa.get(var).getLivros().get(i).getTitulo()+" Autor: "+listPessoa.get(var).getLivros().get(i).getAutor());
									}
									info = sc.nextInt();
									//Verificação: verifica se info está valendo 1 ou 2. Caso não, o usuário volta ao menu 
									if(info < 0 || info >= listPessoa.get(var).getLivros().size()){
										System.out.println("Erro. Opcao invalida.");
										break;
									}
									//Cria um objeto do tipo Editora, um do tipo Livro, remove ele da lista pessoal do usuário, adiciona
									//Na lista de livros disponíveis e atualiza o arquivo de livros disponíveis
									Editora edi_tora = new Editora(listPessoa.get(var).getLivros().get(info).getEditora().getNome(), listPessoa.get(var).getLivros().get(info).getEditora().getEndereco());
									Livro book_1 = new Livro(listPessoa.get(var).getLivros().get(info).getTitulo(), listPessoa.get(var).getLivros().get(info).getAutor(), edi_tora);
									listLivro.add(book_1);
									Arquivo.devolverLivros("Reservados.txt", email, book_1);
									listPessoa.get(var).devolverLivro(listPessoa.get(var).getLivros(), info);
									Arquivo.atualizar("LivrosDisp.txt", listLivro);
									System.out.println("Devolvido.\n");
									break;
								//Opção 3: caso o usuário queira voltar ao menu principal
								case 3:
									limpaTerminal();
									System.out.println("Logout Concluido.\n");
									break;
								//Default: verifica se a opção escolhida pelo usuário é válida
								default:
									System.out.println("Opcao invalida. Leia novamente o menu.\n");
									break;

							}//Fim switch

						}while(op != 3);
					}
					//Verificação: caso o cadastro não tenha sido encontrado
					else{
						j=0;
						System.out.println("Cadastro nao encontrado. Senha e/ou nome invalido(s).");
						break;
					}
					break;
				//Opção 2: Entra na área da biblioteca para cadastrar livros, editoras e verificá-los
				case 2:
					limpaTerminal();
					System.out.println("LOGIN BIBLIOTECA\n");
					System.out.println("Login Biblioteca_Ibilce1976");
					System.out.print("Senha (1946): ");
					senha_biblio = sc.nextInt();
					//Verificação: caso a senha esteja correta, entra para o menu da bibloteca
					if(senha_biblio == 1946){
						limpaTerminal();
						do{
							//Menu da BIBLIOTECA
							System.out.println("\n******SISTEMA BIBLIOTECA******\n\n1 - Cadastrar livro\n2 - Cadastrar Editora");
							System.out.println("3 - Mostrar editoras\n4 - Logout\n");
							System.out.println("******************************");
							op = sc.nextInt();
							switch(op){
								//Opção 2: cadastra um livro novo 
								case 1:
									//Verificação: um livro só pode ser cadastrado se houverem editoras cadastradas.
									//Portanto se o tamanho da lista de editoras for 0, não é possível cadastrar
									if(listEditora.size() == 0){
										System.out.println("Nenhuma editora cadastrada.\n");
										break;
									}
									limpaTerminal();
									//Pede os dados do livro ao usuário
									System.out.println("DADOS DO LIVRO\n");
									System.out.print("Titulo: ");
									sc = new Scanner(System.in);
									titulo = sc.nextLine();
									System.out.print("Autor: ");
									sc = new Scanner(System.in);
									autor = sc.nextLine();
									for(i=0;i<listEditora.size();i++){
										System.out.println("<"+i+"> Nome: "+listEditora.get(i).getNome()+" Endereco: "+listEditora.get(i).getEndereco());
									}
									info = sc.nextInt();
									//Verificação: verifica se info está valendo 1 ou 2. Caso não, o usuário volta ao menu 
									if(info < 0 || info >= listEditora.size()){
										System.out.println("Erro. Opcao invalida.");
										break;
									}
									//No arquivo, as informações são separadas por um '+', então para escreve-las no arquivo
									//Concatenamos as informações com um '+' entre elas
									String juntar = titulo.concat("+").concat(autor).concat("+").concat(listEditora.get(info).getNome()).concat("+").concat(listEditora.get(info).getEndereco()).concat("+");
									//Escreve a nova linha no arquivo de livros disponíveis
									Arquivo.escrever("LivrosDisp.txt", juntar);
									Editora editor = new Editora(listEditora.get(info).getNome(), listEditora.get(info).getEndereco());
									Livro livrinho = new Livro(titulo, autor, editor);
									//Escreve a nova linha no arquivo de livros disponíveis
									listLivro.add(livrinho);
									break;
								//Opção 2: cadastrar uma nova editora
								case 2:
									limpaTerminal();
									System.out.println("DADOS DA EDITORA\n");
									sc = new Scanner(System.in);
									System.out.print("Nome: ");
									nome = sc.next();
									sc = new Scanner(System.in);
									System.out.print("Endereco: ");
									end = sc.next();
									//Verificação: caso a lista de editoras tenha cadastros, varifica se não está endo cadastrada uma mesma
									//editora novamente
									if(listEditora.size() > 0){
										for(i=0;i<listEditora.size();i++){
											Editora edit = listEditora.get(i);
											if(edit.getNome().equals(nome) && edit.getEndereco().equals(end)){
												u++;
											}
										}
                  							}
									//Verificação: caso a editora já exista na lista
									if(u > 0){
										limpaTerminal();
										System.out.println("Editora ja cadastrada.");
										break;
									}
									//Verificação: caso a editora não esteja na lista ainda, ela é cadastrada
									else{
										//Escreve a linha armazenada em "concatena" no arquivo e salva a nova editora na lista
										String concatena = nome.concat("+").concat(end).concat("+");
										Arquivo.escrever("Editoras.txt",concatena);	
										Editora editora = new Editora(nome, end);
										listEditora.add(editora);
									}
									break;
								//Opção 3: Mostra as editoras cadastradas
								case 3:
									limpaTerminal();
									System.out.println("--EDITORAS--");
									if(listEditora.size() > 0){
										for(i=0;i<listEditora.size();i++){
											System.out.println("\nNome: "+listEditora.get(i).getNome()+" Endereco: "+listEditora.get(i).getEndereco());
										}
									}
									else{
										System.out.println("Nao existem editoras cadastradas.");
									}
									break;
								//Opção 4: Volta para o menu principal 
								case 4:
									limpaTerminal();
									System.out.println("Logout concluido.");
									break;
								//Default: verifica se a opção digitada pelo usuário é valida
								default:
									limpaTerminal();
									System.out.println("Opcao Invalida. Leia novamente o menu.");
									break;
							}
						}while(op != 4);
					
					}
					else{
						limpaTerminal();
						System.out.println("Senha invalida.");
						break;
					}
					break;
					//Opção 3: Cadastra o aluno para que possa reservar e devolver livros
					case 3:
						limpaTerminal();
						System.out.println("CADASTRO ALUNO\n");
						sc = new Scanner(System.in);
						System.out.print("Nome: ");
						sc = new Scanner(System.in);
						nome = sc.nextLine();
						sc = new Scanner(System.in);
						System.out.print("E-mail: ");
						sc = new Scanner(System.in);
						email = sc.nextLine();
						sc = new Scanner(System.in);
						System.out.print("Digite uma senha: ");
						senha = sc.next();
						System.out.print("<1> Graduacao <2> PosGraduacao: ");
						cat = sc.next();
						//Verifica qual a categoria o aluno se encontra e se digitou corretamente
						if(cat.equals("1")){
							System.out.print("RA: ");
							ra = sc.next();
							Graduacao grad = new Graduacao(nome, email, livros, ra, senha, cat);
							listPessoa.add(grad);
							String juntando = nome.concat("+").concat(email).concat("+").concat(ra).concat("+").concat(senha).concat("+").concat(cat).concat("+");
							Arquivo.escrever("Pessoa.txt", juntando);
						}
						else if(cat.equals("2")){
							System.out.print("CCO: ");
							cco = sc.next();
							Posgraduacao posgrad = new Posgraduacao(nome, email, livros, cco, senha, cat);
							listPessoa.add(posgrad);
							String juntando_2 = nome.concat("+").concat(email).concat("+").concat(cco).concat("+").concat(senha).concat("+").concat(cat).concat("+");
							Arquivo.escrever("Pessoa.txt", juntando_2);
						}
						else{
							System.out.print("Opcao invalida.");
						}
						break;
					//Opção 4: Encerra o programa
					case 4:
						sc.close();
						System.exit(0);
						break;
					//Default: Verifica se a opção digitada pelo usuário é valida
					default:
						limpaTerminal();
						System.out.println("Opcao Invalida. Leia novamente o menu.");
						break;
      				}//Fim do switch
		}while(true);//Fim do menu principal
  	}//Fim do método Main
}//Fim do programa
