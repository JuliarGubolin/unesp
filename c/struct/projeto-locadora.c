#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

/*Declaração do ponteiro para o arquivo*/
FILE *ptr;

/*Struct datas de reserva*/
typedef struct data
{
  int dia;
  int mes;
  int ano;

}reservas;
/*Struct dados do carro*/
typedef struct cad_car
{
  int ID_c, km, categ, num_ocu;
  char placa[8], fabricante[20], model[15]; 
  char ar[3], disp;
  reservas i, f;

}cad;
/*Salva o vetor no arquivo*/
void fprint(cad cli[], int n){
	
  int i;
  ptr=fopen("listacarros.dat","w");

  for(i=0;i<n;i++)
  {

  fprintf(ptr, "%d %s %c %d %s %s %s %d %d %d %d %d %d %d %d", cli[i].ID_c, cli[i].placa, cli[i].disp, cli[i].categ, 
    cli[i].fabricante, cli[i].model, cli[i].ar, cli[i].num_ocu, cli[i].km, cli[i].i.dia, cli[i].i.mes, cli[i].i.ano, cli[i].f.dia, 
    cli[i].f.mes, cli[i].f.ano);
  }
      fclose(ptr);
}
/*Salvar o que esta no arquivo dentro do vetor:*/
void lerarq(cad cli[],int lim_car)
{
  int var=0;
  if((ptr=fopen("listacarros.dat","r"))==NULL)
    printf("\nERRO!!\n");
  else{
      while (!feof(ptr))
	  {
      fscanf(ptr,"%d %s %c %d %s %s %s %d %d %d %d %d %d %d %d",&cli[var].ID_c,&*cli[var].placa, &cli[var].disp, &cli[var].categ,
	  &*cli[var].fabricante,&*cli[var].model,&*cli[var].ar, &cli[var].num_ocu, &cli[var].km, &cli[var].i.dia,&cli[var].i.mes,&cli[var].i.ano, 
	  &cli[var].f.dia, &cli[var].f.mes,&cli[var].f.ano);
      var++;
	 }
  }

  fclose(ptr);
  
}
/*OPÇÃO 1:*/
cad cadastro()
{
  printf("\33[H\33[2J");
  printf("REGISTRAR NOVO CARRO\n");
  cad cli;
  printf("\nID: ");
  scanf("%d",&cli.ID_c);
  setbuf(stdin,NULL);
  printf("\nPlaca : ");
  setbuf(stdin,NULL);
  scanf("%s",cli.placa);
  setbuf(stdin,NULL);
  printf("\nFabricante: ");
  scanf("%s",cli.fabricante);
  setbuf(stdin,NULL);
  printf("\nModelo: ");
  scanf("%s",cli.model);
  setbuf(stdin,NULL);
  printf("\nCategoria: \n");
  printf("1-Compacto\n2-Médio\n3-Grande\n4-SUV\n5-Minivan\n");
  scanf("%d",  &cli.categ);
  setbuf(stdin,NULL);
  printf("\nDisponibilidade (S/N): ");
  scanf("%c",&cli.disp);
  setbuf(stdin,NULL);
  printf("\nQuilometragem: ");
  scanf("%d",&cli.km);
  printf("\nAr condicionado (S/N): ");
  scanf("%s", cli.ar);
  printf("\nNúmero de ocupantes: ");
  scanf("%d", &cli.num_ocu);
  setbuf(stdin,NULL);
  cli.i.dia=cli.i.mes=cli.i.ano=0;
  cli.f.dia=cli.f.mes=cli.f.ano=0;
  printf("\nConcluído.\n");
  return cli;
}
/*OPÇÃO 2:*/
void removeCar(cad cli[], int *lim_car){
	
	int id, n, i;
    printf("\33[H\33[2J");
	printf("REMOVER CARRO \n");
	printf("ID do carro que será REMOVIDO: ");
	scanf("%d", &id);
	for(i=0;i<*lim_car;i++)
	{
      if(cli[i].ID_c == id)
	  {
	    while(cli[i].ID_c != 0)
	    {
		      cli[i].ID_c = cli[i+1].ID_c;
		      strcpy(cli[i].placa,cli[i+1].placa);
		      strcpy(cli[i].fabricante,cli[i+1].fabricante);
		      strcpy(cli[i].model,cli[i+1].model);
		      strcpy(cli[i].ar,cli[i+1].ar);
		      cli[i].disp=cli[i+1].disp;
		      cli[i].num_ocu=cli[i+1].num_ocu;
		      cli[i].km=cli[i+1].km;
		      cli[i].categ=cli[i+1].categ;
		      cli[i].i.dia=cli[i+1].i.dia;
		      cli[i].i.mes=cli[i+1].i.mes;
		      cli[i].i.ano=cli[i+1].i.ano;
		      cli[i].f.dia=cli[i+1].f.dia;
		      cli[i].f.mes=cli[i+1].f.mes;
		      cli[i].f.ano=cli[i+1].f.ano;
		      i++;
		}
			*lim_car=*lim_car-1;
      n=1;
    }
  }
  printf("Concluído.\n");
  if(n==0){
    printf("Id não encontrado.\n");
  }
}
/*OPÇÃO 3:*/
void listar(cad cli[], int lim_car){
	
	int c, y, i;
	int dia, diaf, mes, mesf, ano, anof;
    printf("\33[H\33[2J");
	printf("LISTAR CARROS DISPONÍVEIS\n");
	printf("\nCategoria: ");
	printf("\n1-Compacto\n2-Médio\n3-Grande\n4-SUV\n5-Minivan\n");
	scanf("%d", &c);
	printf("Data da ÍNICIO da reserva\n");
    printf("Digite o dia/mês/ano: ");
    scanf("%d %d %d", &dia, &mes, &ano);
	printf("Data FINAL da reserva\n");
    printf("Digite o dia/mês/ano: ");
    scanf("%d %d %d", &diaf, &mesf, &anof);
	
	y=0;
    printf("\33[H\33[2J");
	for(i=0;i<lim_car;i++)
	{
		if(cli[i].categ == c)
		{
			if(cli[i].f.dia<dia || cli[i].disp=='S' || cli[i].i.dia==0)
			{
				if(cli[i].f.mes<mes || cli[i].f.mes==mes)
				{
					printf("\n\nID do carro: %d",cli[i].ID_c);
					printf("\nPlaca (ex: AAA0000): %s",cli[i].placa);
					printf("\nFabricante: %s",cli[i].fabricante);
					printf("\nModelo: %s",cli[i].model);
					printf("\nDisponibilidade: %c",cli[i].disp);
					printf("\nQuilometrage: %d", cli[i].km);
					printf("\nAr condicionado: %s",cli[i].ar);
					printf("\nNúmero de ocupantes: %d\n", cli[i].num_ocu);
					y=1;
				}
			}
		}	
	}
	if(y==0){
		printf("Nenhum carro desta categoria disponível para esta data.\n");
	}

}
/*OPÇÃO 4*/
void verificar(cad cli[], int lim_car){
	
	int id, y, i;
    printf("\33[H\33[2J");
    printf("VERIFICAR DEVOLUÇÃO\n");
	printf("Digite o ID do carro a ser verificado: ");
	scanf("%d", &id);
	y=0;
	for(i=0;i<lim_car;i++){
		if(cli[i].ID_c==id){
			if(cli[i].f.ano == 0)
			{
				printf("Carro não foi retirado.\n");
			}			
			else
			{
				printf("Devolução: %d/%d/%d\n", cli[i].f.dia, cli[i].f.mes, cli[i].f.ano);	
			}
			y=1;
		}
	}
	if(y==0){
		printf("Id não encontrado.\n\n");
	}
	
}
/*OPÇÃO 5*/
void reservar(cad cli[], int lim_car){

  int categ, y, id, z, i;
  printf("\33[H\33[2J");
  printf("FAZER RESERVA\n");
  printf("Categoria: ");
  scanf("%d", &categ);
  y=0;
  for(i=0;i<lim_car;i++){
    if(cli[i].categ == categ && cli[i].disp == 'S'){
    	
		printf("\n\nID do carro: %d",cli[i].ID_c);
		printf("\nPlaca (ex: AAA0000): %s",cli[i].placa);
		printf("\nFabricante: %s",cli[i].fabricante);
		printf("\nModelo: %s",cli[i].model);
		printf("\nQuilometrage: %d", cli[i].km);
		printf("\nAr condicionado: %s",cli[i].ar);
		printf("\nNúmero de ocupantes: %d\n", cli[i].num_ocu);
	    y=1;
    }
  }
	if(y==0){
		printf("Não há nenhum carro desta categoria disponível.\n");
	}
	printf("Das opções acima, qual o ID do carro a ser reservado: ");
	scanf("%d", &id);
	
	z=0;
	for(i=0;i<lim_car;i++)
	{
    	if(cli[i].ID_c == id)
		{
    		printf("Data da ÍNICIO da reserva\n");
    		printf("Digite o dia/mês/ano: ");
    		scanf("%d %d %d", &cli[i].i.dia, &cli[i].i.mes, &cli[i].i.ano);
			printf("Data FINAL da reserva\n");
    		printf("Digite o dia/mês/ano: ");
    		scanf("%d %d %d", &cli[i].f.dia, &cli[i].f.mes, &cli[i].f.ano);
        cli[i].disp='N';
	    	z=1;
        }
    }
  printf("Concluído.\n");
	if(z==0){
		printf("Id não encontrado.\n");
	}
	

}
/*OPÇÃO 6:*/
void liberar(cad cli[], int lim_car){

  int id, y, i;
  printf("\33[H\33[2J");
  printf("LIBERAR RESERVA\n");
  printf("Digite o id do carro: ");
  scanf("%d", &id);
  y=0;
  for(i=0;i<lim_car;i++)
  {
    if(cli[i].ID_c == id)
	{
      cli[i].i.dia = 0;
      cli[i].i.mes = 0;
      cli[i].i.ano = 0;
      cli[i].f.dia = 0;
      cli[i].f.mes = 0;
      cli[i].f.ano = 0;
      cli[i].disp='S';
      y=1;
    }
  }
  
  if(y==0){
    printf("Id não encontrado.\n");
  }
  printf("Concluído.\n");
}
/*OPÇÃO 7:*/
void attRetorno(cad cli[], int lim_car){

  int id, y, i;
  printf("\33[H\33[2J");
  printf("RETORNO\n");
  printf("Digite o id do carro: ");
  scanf("%d", &id);
  for(i=0;i<lim_car;i++)
  {
    if(cli[i].ID_c == id)
	{
      setbuf(stdin,NULL);
	  cli[i].disp='S';
      setbuf(stdin,NULL);
      printf("\nAtualizar a quilometragem: ");
      scanf("%d",&cli[i].km);
      setbuf(stdin,NULL);
      cli[i].i.dia=cli[i].i.mes=cli[i].i.ano=0;
      cli[i].f.dia=cli[i].f.mes=cli[i].f.ano=0;
      y=1;
    }
  }
  
  if(y==0){
    printf("Id não encontrado.\n");
  }
  printf("Concluído.\n");

}
/*MENU:*/
void menu()
{
	
	printf("\nLOCADORA DE CARROS\n");
	printf("1- Inserir um novo carro no cadastro\n");
	printf("2- Remover um carro do cadastro\n");
	printf("3- Listar carros de uma determinada categoria que estejam disponiveis em uma determinada data\n");
	printf("4- Verificar quando um determinado carro deve ser devolvido\n");
	printf("5- Fazer a reserva de um carro de uma determinada categoria para um certo periodo\n");
	printf("6- Liberar a reserva de um carro quando nao ocorrer sua retirada no dia reservado\n");
	printf("7- Atualizar os dados de um veiculo no seu retorno\n");
	printf("8- Fechar e atualizar\n");
	
}
/*PRINCIPAL:*/
int main ()
{
  
  	setlocale(LC_ALL,"portuguese");
  	
	cad cli[150];
	int cli_num=0, i, j=0, k=0, z=0, car=0;
	char qtd, cad, opcao;
	
	ptr = fopen ("listacarros.dat","r");
    
	if(ptr == NULL)
	{
		ptr = fopen ("listacarros.dat","a");
    	car=0;
	}
 	else
  	{
        ptr = fopen ("listacarros.dat","r");
        do     
        {
        qtd = getc(ptr);
        if(qtd == '\n')
          car++;
        
        }while (qtd != EOF);
        
        fclose(ptr);
    	lerarq(&cli[0], car);
 	}
	do
	{
     setbuf(stdin,NULL);
	 menu();	
	 scanf("%c",&opcao);
     setbuf(stdin,NULL);
	
		if(opcao=='1')
		{
			cli[car]=cadastro();
			car++;
		}
		else if(opcao=='2')
		{
			removeCar(&cli[0], &car);
		}
		else if(opcao=='3')
		{
			listar(&cli[0], car);
		}
		else if(opcao=='4')
		{
			verificar(&cli[0], car);
		}
        else if(opcao=='5')
		{
           reservar(&cli[0], car);
        }
        else if(opcao=='6')
		{
           liberar(&cli[0], car);
        }
        else if(opcao=='7')
		{
        	attRetorno(&cli[0], car);
		}
		else if(opcao=='8')
		{
      		fprint(&cli[0], car);
      		printf("Programa encerrado.\n");
		}
		else
		{
			printf("Leia novamente o MENU de opções.\n");
		}
	}while (opcao!='8');
	
	return 0;
}
