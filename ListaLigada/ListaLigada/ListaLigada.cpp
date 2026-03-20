
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o valor a excluir: ";// o usuario digita o valor que quer excluir
	cin >> numero;//guarda na variavel

	// verifica se a lista esta vazia
	if (primeiro == NULL) {
		cout << "Lista vazia\n";
		return;// nao tem nada pra excluir
	}

	NO* alvo = posicaoElemento(numero); // procura o numero

	//  se nao encontrou encontrou
	if (alvo == NULL) {
		cout << "Elemento nao encontrado\n";
		return;
	}

	// caso 1: se for o primeiro elemento
	if (primeiro == alvo) {
		primeiro = primeiro->prox; // primeiro agora aponta para o proximo
		free(alvo);  // libera memoria do no
	}
	else {
		NO* anterior = primeiro; // começa do primeiro
		NO* atual = primeiro->prox;// começa do segundo


		// percorre a lista ate achar o elemento
		while (atual != NULL) {
			if (atual == alvo) { // encontrou o elemento
				anterior->prox = atual->prox; // faz o anterior pular o atual
				free(atual);// remove da memoria
				break;// sai do loop
			}
			anterior = atual;//anda o anterior 
			atual = atual->prox;// anda atual
		}
	}

	cout << "Elemento excluido\n";
}


void buscarElemento()
{
	int numero;
	cout << "Digite o valor a buscar: ";
	cin >> numero;
	// procura o valor na lista
	NO* resultado = posicaoElemento(numero);

	if (resultado != NULL)
		cout << "Encontrado\n";// se encontrou
	else
		cout << "Elemento nao encontrado\n";//se nao tiver encontrado
}





