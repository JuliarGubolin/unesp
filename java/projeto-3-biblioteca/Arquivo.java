//Bibliotecas para se comunicar com os pacotes, além de poder manipular arquivos
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import usuario.*;
import biblioteca.*;
public class Arquivo{
	//Método para ler e salvar na lista de Editoras seus nomes e respectivos endereços
	public static void loadTemp(String nome) throws IOException{
       	 	try{
          		BufferedReader arqTemp = new BufferedReader(new FileReader(nome)); 
        	}
        	catch(FileNotFoundException e){
            		BufferedWriter arqTemp = new BufferedWriter(new FileWriter(nome, true));
            		arqTemp.close();
        	}
        	BufferedReader arqTemp = new BufferedReader(new FileReader(nome));
    	}
	public static void loadEdit(String nome, ArrayList<Editora> listEditora) throws IOException{
		
		//Tenta abrir um arquivo para leitura com o nome "nome". Caso ele ainda não exista, ele é criado. 
		try{
			BufferedReader word = new BufferedReader(new FileReader(nome));
		}
		catch(FileNotFoundException e){
			BufferedWriter search = new BufferedWriter(new FileWriter(nome, true));
			search.close();	
		}
		//Abre o arquivo para leitura e carregamento das informações, as quais estão separadas por um '+'
		//Para diferencia-las
		BufferedReader word = new BufferedReader(new FileReader(nome));
		//Variáveis auxiliares para salvar as informações
		int i=0, j=0;
		String line = null;
		//Este while irá percorrer cada caractere da linha individualmente, até o final do arquivo
		//Quando encontrar um '+', já tera salvo todos os caracteres anteriores em uma unica
		//Variável do tipo String, a qual será usada para criar o objeto da classe Editora e salvar na lista
		while((line = word.readLine())!=null){
			String name = "", address = "";
			for(i=0;i<line.length();i++){
				//Como a linha está sendo lida caractere à caractere, transformamos o conjunto de caracteres en uma String
				if(line.charAt(i) == '+'){
					j++;
					if(j == 3){
						j=0;
					}
				} 
				else if(j == 0){
					//Neste ponto, todos os caracteres anteriores ao primeiro '+' encontrado serão salvos em "name" 
					//O qual representa o nome da editora
					//Como a linha está sendo lida caractere à caractere, transformamos o conjunto de caracteres em uma String
					name = name.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 1){
					//Neste ponto, todos os caracteres anteriores ao segundo '+' e posteriores ao primeiro  serão salvos em "address" 
					//O qual representa o endereço da editora
					address = address.concat(Character.toString(line.charAt(i)));
					//Como o fim da linha possui um '+' e um '\n', quando chegamos na última informação
					//Ele pula estes caracteres, salva estes dados (name e address) como sendo um elemento da lista de editora
					//E segue até acabarem as linhas 
					if(i+2 == line.length()){
						j++;
					}
				}
				if(j == 2){
					//Salvando os dados na lista após encontrar o final da linha
					Editora editoras = new Editora(name, address);
					listEditora.add(editoras);
				}
			}	
		}
		//Fecha o arquivo após a conclusão
		word.close();
	}
	//Método para ler e salvar na lista de Livros seus títulos, autores e respectivas editoras
	public static void loadLivro(String nome, ArrayList<Livro> listLivro) throws IOException{

		try{
			BufferedReader word = new BufferedReader(new FileReader(nome));
		}
		catch(FileNotFoundException e){
			BufferedWriter search = new BufferedWriter(new FileWriter(nome, true));
			search.close();	
		}
		BufferedReader word = new BufferedReader(new FileReader(nome));
		int i=0, j=0;
		String line = null;
		//Este while irá percorrer cada caractere da linha individualmente, até o final do arquivo
		//Quando encontrar um '+', já tera salvo todos os caracteres anteriores em uma unica
		//Variável do tipo String, a qual será usada para criar o objeto da classe Livro e salvar na lista
		while((line = word.readLine())!=null){
			String name = "", address = "", tit = "", autor = "";
			for(i=0;i<line.length();i++){
				if(line.charAt(i) == '+'){
					j++;
					if(j == 5){
						j=0;
					}
				} 
				else if(j == 0){
					//Neste ponto, todos os caracteres anteriores ao primeiro '+' encontrado serão salvos em "tit" 
					//O qual representa o título do livro
					tit = tit.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 1){
					//Neste ponto, todos os caracteres anteriores ao segundo '+' e posteriores ao primeiro serão salvos em "autor" 
					//O qual representa o autor do livro
					autor = autor.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 2){
					//Neste ponto, todos os caracteres anteriores ao terceiro '+' e posteriores ao segundo serão salvos em "name" 
					//O qual representa o nome da editora
					name = name.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 3){
					//Neste ponto, todos os caracteres anteriores ao quarto '+' e posteriores ao terceiro serão salvos em "address" 
					//O qual representa o endereço da editora
					address = address.concat(Character.toString(line.charAt(i)));
					if(i+2 == line.length()){
						j++;
					}
				}
				if(j == 4){
					//Salva os dados recolhidos em um tipo Livro e o adiciona na lista de livros
					Editora editoras = new Editora(name, address);
					Livro livros = new Livro(tit, autor, editoras);
					listLivro.add(livros);
				}

			}	
		}
		//Fecha o arquivo após a conclusão
		word.close();
	}
	public static void loadPessoa(String nome, ArrayList<Pessoa> listPessoa) throws IOException{

		try{
			BufferedReader word = new BufferedReader(new FileReader(nome));
		}
		catch(FileNotFoundException e){
			BufferedWriter search = new BufferedWriter(new FileWriter(nome, true));
			search.close();	
		}
		BufferedReader word = new BufferedReader(new FileReader(nome));
		int i=0, j=0;
		String line = null;
		//Este while irá percorrer cada caractere da linha individualmente, até o final do arquivo
		//Quando encontrar um '+', já tera salvo todos os caracteres anteriores em uma unica
		//Variável do tipo String, a qual será usada para criar o objeto da classe Livro e salvar na lista
		while((line = word.readLine())!=null){
			String name = "", email = "", senha = "", info = "", cat = "";
			ArrayList<Livro> livros = new ArrayList<Livro>();
			for(i=0;i<line.length();i++){
				if(line.charAt(i) == '+'){
					j++;
					if(j == 6){
						j=0;
					}
				} 
				else if(j == 0){
					//Neste ponto, todos os caracteres anteriores ao primeiro '+' encontrado serão salvos em "name" 
					//O qual representa o nome da pessoa
					name = name.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 1){
					//Neste ponto, todos os caracteres anteriores ao segundo '+' e posteriores ao primeiro serão salvos em "email" 
					//O qual representa o email da pessoa
					email = email.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 2){
					//Neste ponto, todos os caracteres anteriores ao terceiro '+' e posteriores ao segundo serão salvos em "info" 
					//O qual representa o ra ou cco da pessoa
					info = info.concat(Character.toString(line.charAt(i)));
					
				}
				else if(j == 3){
					//Neste ponto, todos os caracteres anteriores ao quarto '+' e posteriores ao terceiro serão salvos em "senha" 
					//O qual representa a senha da conta da pessoa
					senha = senha.concat(Character.toString(line.charAt(i)));
					
				}
				else if(j == 4){
					//Neste ponto, todos os caracteres anteriores ao terceiro '+' e posteriores ao segundo serão salvos em "cat" 
					//O qual representa a categoria
					cat = cat.concat(Character.toString(line.charAt(i)));
					if(i+2 == line.length()){
						j++;
					}
				}
				if(j == 5){
					//Verifica qual a categoria para salvar no tipo correto
					if(cat.equals("1")){
						Graduacao grad = new Graduacao(name, email, livros, info, senha, cat);
						listPessoa.add(grad);
					}
					else{
						Posgraduacao posgrad = new Posgraduacao(name, email, livros, info, senha, cat);
						listPessoa.add(posgrad);
					}
				}
			}	
		}
		//Fecha o arquivo após a conclusão
		word.close();
	}
	public static void loadReservados(String nome, ArrayList<Pessoa> listPessoa) throws IOException{
		try{
			BufferedReader word = new BufferedReader(new FileReader(nome));
		}
		catch(FileNotFoundException e){
			BufferedWriter search = new BufferedWriter(new FileWriter(nome, true));
			search.close();	
		}
		BufferedReader word = new BufferedReader(new FileReader(nome));
		int i=0, j=0, x;
		String line = null;
		//Este while irá percorrer cada caractere da linha individualmente, até o final do arquivo
		//Quando encontrar um '+', já tera salvo todos os caracteres anteriores em uma unica
		//Variável do tipo String, a qual será usada para criar o objeto da classe Livro e salvar na lista
		while((line = word.readLine())!=null){
			String email = "", tit = "", autor = "", name = "", end = "";
			ArrayList<Livro> livros = new ArrayList<Livro>();
			for(i=0;i<line.length();i++){
				if(line.charAt(i) == '+'){
					j++;
					if(j == 6){
						j=0;
					}
				} 
				else if(j == 0){
					email = email.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 1){
					tit = tit.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 2){
					autor = autor.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 3){
					name = name.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 4){
					end = end.concat(Character.toString(line.charAt(i)));
					if(i+2 == line.length()){
						j++;
					}
				}
				if(j == 5){
					Editora edit= new Editora(name, end);
					Livro l = new Livro(tit, autor, edit);
					for(x=0;x<listPessoa.size();x++){
						if(listPessoa.get(x).getEmail().equals(email)){
							listPessoa.get(x).getLivros().add(l);
						}
					}
				}
			}	
		}
		//Fecha o arquivo após a conclusão
		word.close();
	}
	public static void devolverLivros(String nome, String ad, Livro book) throws IOException{
		int i=0, j=0, x, bandeira=0;
		String line = null;
		//Abre o arquivo com o nome "nome" para leitura
		BufferedReader bat = new BufferedReader(new FileReader(nome));
		//Este while irá percorrer cada caractere da linha individualmente, até o final do arquivo
		//Quando encontrar um '+', já tera salvo todos os caracteres anteriores em uma unica
		//Variável do tipo String.
		while((line = bat.readLine())!=null){
			String email = "", tit = "", autor = "", name = "", end = "";
			ArrayList<Livro> livros = new ArrayList<Livro>();
			for(i=0;i<line.length();i++){
				if(line.charAt(i) == '+'){
					j++;
					if(j == 6){
						j=0;
					}
				} 
				else if(j == 0){
					email = email.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 1){
					tit = tit.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 2){
					autor = autor.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 3){
					name = name.concat(Character.toString(line.charAt(i)));
				}
				else if(j == 4){
					end = end.concat(Character.toString(line.charAt(i)));
					if(i+2 == line.length()){
						j++;
					}
				}
				if(j == 5){
					//A variável bandeira controla se existem livros repetidos da mesma pessoa, pulando o
					//dado que não deve ser escrito, já que o livro que não deve ser escrito (que irá ser devolvido)
					//não entrará nem no if(bandeira == 1) nem no else.
					if(ad.equals(email) && book.getTitulo().equals(tit)){
						if(bandeira == 1){
							BufferedWriter escrever = new BufferedWriter(new FileWriter("temp.txt", true));
        						escrever.append(line + "\n");
        						escrever.close();	
						}
						bandeira = 1;
					}
					else{
						BufferedWriter escrever = new BufferedWriter(new FileWriter("temp.txt", true));
        					escrever.append(line + "\n");
        					escrever.close();
					}
				}
			}	
		}
		//É criado um arquivo temporário com os livros que ainda estão sendo reservados, para que depois os 
		//dados do temporário sejam escritos no lugar dos arquivos de Reservados, retirando o livro devolvido
		bandeira = 0;
		line = null;
		//Fecha o arquivo após a conclusão
		BufferedReader transf = new BufferedReader(new FileReader("temp.txt"));
		BufferedWriter b = new BufferedWriter(new FileWriter("Reservados.txt"));
		b.close();
		while((line = transf.readLine())!=null){
			BufferedWriter bc = new BufferedWriter(new FileWriter("Reservados.txt", true));
			bc.append(line + "\n");
			bc.close();
		}
		BufferedWriter anul = new BufferedWriter(new FileWriter("temp.txt"));
		anul.append(null);
		bat.close();
	}
	//Escreve no arquivo desejado uma linha (Variável linha)
	public static void escrever(String arq, String linha) throws IOException{
        	BufferedWriter escrever = new BufferedWriter(new FileWriter(arq, true));
        	escrever.append(linha + "\n");
        	escrever.close();
    	}
	//Atualiza a lista de livros disponíveis para serem reservados cada vez que uma reserva/devolução é feita
	public static void atualizar(String arq, ArrayList<Livro> listLivro) throws IOException{
		int i;
        	BufferedWriter atualizar = new BufferedWriter(new FileWriter(arq));
		for(i=0;i<listLivro.size();i++){
			//Adiciona com a mesma formatação de como é lido, com um '+' entre os dados
			Livro l = listLivro.get(i);
			atualizar.append(l.getTitulo() + "+");
			atualizar.append(l.getAutor() + "+");
			atualizar.append(l.getEditora().getNome() + "+");
			atualizar.append(l.getEditora().getEndereco() + "+");
			atualizar.append("\n");
		}
		atualizar.close();	
    	}
}