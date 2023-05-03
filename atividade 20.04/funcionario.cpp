#include <iostream>
#include <stdlib.h>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;
};

Funcionario* init()
{
	return NULL;
}

Funcionario* incluir(Funcionario* funcionario)
{
	Funcionario* novo = new Funcionario;
	
	cout << "Prontuario: ";
	cin >> novo->prontuario;
	cout << "Nome: ";
	cin >> novo->nome;
	cout << "Salario: ";
	cin >> novo->salario;
	novo->prox = funcionario;
	return novo;
}

Funcionario* excluir(Funcionario* funcionario)
{
	Funcionario *ant = NULL;
	Funcionario *aux;
	
	int i;
	
	cout << "Digite o prontuario do funcionario a ser excluido: ";
	cin >> i;
	
	aux = funcionario;
	while (aux != NULL && aux->prontuario != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		return funcionario;
	}
	if (ant == NULL) 
	{
		funcionario = aux->prox;
	}
	else 
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return funcionario;
}

Funcionario* pesquisar(Funcionario* funcionario)
{
	Funcionario* aux;
	aux = funcionario;
	
	int i;
	
	cout << "Digite o prontuario do funcionario desejado: ";
	cin >> i;
	
	while(aux != NULL && aux->prontuario !=i)
	{
		aux = aux->prox;
			
	}
	if(aux == NULL)
	{		
		cout <<"Nao encontrado" << endl;
	}
	else
	{
		cout << "Resultado da busca: " << endl;
		cout << "Prontuario: " << aux->prontuario << "/ Nome: " << aux->nome << "/ Salario: " << aux->salario << endl;
	}
	
	return aux;
}

void listar(Funcionario* funcionario)
{
	Funcionario* aux;
	aux = funcionario;
	while(aux != NULL)
	{
		cout << "Prontuario: " << aux->prontuario << "/ Nome: " << aux->nome << "/ Salario: " << aux->salario << endl;
		
		aux = aux->prox;
	}
}

void freeList(Funcionario* funcionario)
{
	Funcionario *aux;
	aux = funcionario;
	while (aux != NULL)
	{
		Funcionario *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	Funcionario *meufuncionario;
	meufuncionario = init();
	
	int opcao;	
	while(opcao != 0)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
	
		cin >> opcao;
		
		switch(opcao)
		{
		case 0:
			freeList(meufuncionario);
			break;
		case 1:
			meufuncionario = incluir(meufuncionario);
			break;
		case 2:
			excluir(meufuncionario);
			break;
		case 3:
			pesquisar(meufuncionario);
			break;
		case 4:
			listar(meufuncionario);
			break;
		default:
			cout << "OPCAO NAO DISPONIVEL" << endl;
			break;
		}	
	}
		
	return 0;