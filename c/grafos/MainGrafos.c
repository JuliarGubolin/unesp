#include <stdio.h>
#include"Grafos.h"

int main(void){
	grafo* g;
	g = criaGrafo(5);

	criaAresta(g, 0, 1, 2);
	criaAresta(g, 1, 2, 4);
	criaAresta(g, 2, 0, 12);
	criaAresta(g, 2, 4, 40);
	criaAresta(g, 3, 1, 3);
	criaAresta(g, 4, 3, 8);

	imprime(g);
	printf("\nBUSCA EM LARGURA\n");
	//A função busca em largura recebe o grafo g e a posição do vértice de início.
	buscaLargura(g, 0);
	return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln