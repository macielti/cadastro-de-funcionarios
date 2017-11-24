#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct data{
	int dia;
	int mes;
	int ano;
}DATA;
	
typedef struct funcionario{
	int matricula;
	char nome[100];
	char estadoCivil[20];
	char endereco[300];
	char cargo[100];
	float salario;
	DATA nascimento;
}FUNCIONARIO;


int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	FUNCIONARIO trabalhador[20];
	int fim=0;
	//Exclusao
	int posicaoExcluir;
	int i;
	FUNCIONARIO	aux;
	//alteracao
	int positionAlter;
	//buscar
	char var[100];
	int retorno, tamanho, valor;
	
	int option;
	while(1){
		printf("-----------Menu-----------\n\a");
		printf("\t1.Cadastrar Funcionario\n");
		printf("\t2.Excluir Funcinario\n");
		printf("\t3.Alterar Funcionario\n");
		printf("\t4.Buscar Funcionario\n");
		printf("\t5.Listar Todos os Funcionarios\n");
		printf("\t6.Sair\n");
		printf("Opcao: ");
		scanf("%d", &option);
		
		if(option==6){
			break;
		}
		
		switch(option){
			
			case 1:
				if(fim<20){
					printf("Digite a matricula do novo funcionario: ");
					scanf("%d", &trabalhador[fim].matricula);
					
					printf("Digite o nome do novo funcionario:");
					fflush(stdin);
					fgets(trabalhador[fim].nome, 100, stdin);
					trabalhador[fim].nome[strlen(trabalhador[fim].nome) - 1] = '\0';
					
					printf("Digite o estado civil do novo funcionario: ");
					fgets(trabalhador[fim].estadoCivil, 20, stdin);
					
					printf("Digite o endereco do novo funcionario: ");
					fgets(trabalhador[fim].endereco, 300, stdin);
					
					printf("Digite o cargo do novo funcionario: ");
					fgets(trabalhador[fim].cargo, 100, stdin);
					
					printf("Digite o salario do novo funcionario: ");
					scanf("%f", &trabalhador[fim].salario);
					
					printf("Agora vamos para a data de nascimento do novo funcionario.\n\tDigite o numero do dia de nascimento: ");
					scanf("%d", &trabalhador[fim].nascimento.dia);
					printf("\tDigite o numero do mes de nascimento: ");
					scanf("%d", &trabalhador[fim].nascimento.mes);
					printf("\tDigite o numero ano do nascimento: ");
					scanf("%d", &trabalhador[fim].nascimento.ano);
					printf("Funcionario cadastrado com sucesso na posicao %d!!!\n\n", fim);
					fim +=1;
				}
				else{
					printf("\nImpossivel cadastrar. Vetor cheio.\n");
				}
			break;
			
			case 2:
				printf("Qual posicao voce deseja excluir? ");
				scanf("%d", &posicaoExcluir);
				
				if(trabalhador[posicaoExcluir].matricula > 0){
					trabalhador[posicaoExcluir].matricula;
					trabalhador[posicaoExcluir].nome[100];
					trabalhador[posicaoExcluir].estadoCivil[20];
					trabalhador[posicaoExcluir].endereco[300];
					trabalhador[posicaoExcluir].cargo[100];
					trabalhador[posicaoExcluir].salario;
					
					trabalhador[posicaoExcluir].nascimento.dia=0;
					trabalhador[posicaoExcluir].nascimento.mes=0;
					trabalhador[posicaoExcluir].nascimento.ano=0;
					
						for(i=posicaoExcluir; i<19; i++){
							aux = trabalhador[i];
							trabalhador[i]=trabalhador[i+1];
							trabalhador[i+1]=aux;
						}
					
					printf("\nO FUNCIONARIO FOI EXCLUIDO COM SUCESSO\n");
					
					fim -=1;
						
				}
				else{
					printf("\nImpossivel excluir. Posicao invalida\n");
				}
			break;
			
			case 3:
				printf("\nEscolha a posicao a ser alterada: ");
				scanf("%d", &positionAlter);
				
				if(trabalhador[positionAlter].matricula>0){
					printf("\n----Dados Atuais---\n");
					printf("Matricula: %d\n", trabalhador[positionAlter].matricula);
					printf("Nome: %s\n", trabalhador[positionAlter].nome);
					printf("Estado Civil: %s\n", trabalhador[positionAlter].estadoCivil);
					printf("Endereco: %s\n", trabalhador[positionAlter].endereco);
					printf("Cargo: %s\n", trabalhador[positionAlter].cargo);
					printf("Salario: %.2f\n", trabalhador[positionAlter].salario);
					printf("Data de Nascimento: %d/%d/%d\n", trabalhador[positionAlter].nascimento.dia, trabalhador[positionAlter].nascimento.mes,trabalhador[positionAlter].nascimento.ano);
					printf("\nEntre com os novos dados: \n");
					
					printf("Digite a matricula: ");
					scanf("%d", &trabalhador[positionAlter].matricula);
					
					printf("Digite o nome:");
					fflush(stdin);
					fgets(trabalhador[positionAlter].nome, 100, stdin);
					
					printf("Digite o estado civil: ");
					fgets(trabalhador[positionAlter].estadoCivil, 20, stdin);
					
					printf("Digite o endereco: ");
					fgets(trabalhador[positionAlter].endereco, 300, stdin);
					
					printf("Digite o cargo: ");
					fgets(trabalhador[positionAlter].cargo, 100, stdin);
					
					printf("Digite o salario: ");
					scanf("%f", &trabalhador[positionAlter].salario);
					
					printf("Agora vamos para a data de nascimento.\n\tDigite o numero do dia de nascimento: ");
					scanf("%d", &trabalhador[positionAlter].nascimento.dia);
					printf("\tDigite o numero do mes de nascimento: ");
					scanf("%d", &trabalhador[positionAlter].nascimento.mes);
					printf("\tDigite o numero ano do nascimento: ");
					scanf("%d", &trabalhador[positionAlter].nascimento.ano);
					
					printf("DADOS ALTERADOS COM SUCESSO!!!\n");
				}	
				else{
					printf("\nImpossivel alterar. Posicao nao preenchida\n");
				}
			break;
			
			case 4:
				
				fflush(stdin);
				printf("\nDigite um nome a ser buscado: ");
				gets(var);
				
				for(i=0; i<=fim; i++){
					tamanho=strlen(var);
					retorno= strncmp(trabalhador[i].nome, var, tamanho);
					
					if(retorno==0){
						valor=1;
						break;
						
					} else {
						valor =0;
						
					}
					
					
					
				}
				if(valor==1){
						//exibir dados de i
						printf("\n----Nome encontrado na Posicao %d---\n", i);
						printf("Matricula: %d\n", trabalhador[i].matricula);
						printf("Nome: %s\n", trabalhador[i].nome);
						printf("Estado Civil: %s\n", trabalhador[i].estadoCivil);
						printf("Endereco: %s\n", trabalhador[i].endereco);
						printf("Cargo: %s\n", trabalhador[i].cargo);
						printf("Salario: %.2f\n", trabalhador[i].salario);
						printf("Data de Nascimento: %d/%d/%d\n", trabalhador[i].nascimento.dia, trabalhador[i].nascimento.mes,trabalhador[i].nascimento.ano);
						
				} else{
						
					printf("\nFuncionario nao encontrado\n");
						
				}
				
				

			break;
			
			case 5:
				if(trabalhador[0].matricula>0){
					
					for(i=0; i<fim; i++){
						
						printf("\n----Posicao %d---\n", i);
						printf("Matricula: %d\n", trabalhador[i].matricula);
						printf("Nome: %s\n", trabalhador[i].nome);
						printf("Estado Civil: %s\n", trabalhador[i].estadoCivil);
						printf("Endereco: %s\n", trabalhador[i].endereco);
						printf("Cargo: %s\n", trabalhador[i].cargo);
						printf("Salario: %.2f\n", trabalhador[i].salario);
						printf("Data de Nascimento: %d/%d/%d\n", trabalhador[i].nascimento.dia, trabalhador[i].nascimento.mes,trabalhador[i].nascimento.ano);
						printf("-----------------------------------------\n\n");
						
					}
					
				}
				else{
					printf("\nNenhum funcionario cadastrado\n");
				}
			break;
			
			default:
				printf("\nOPCAO INVALIDA!!\n");
				
		}
		
	}
	
	system("pause");
}
