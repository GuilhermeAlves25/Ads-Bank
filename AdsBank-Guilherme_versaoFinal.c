#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100
#define TAM_NOME 50

// Definições globais
char nomes[MAX_NOMES][TAM_NOME];
char cpf[MAX_NOMES][15]; // CPF tem 14 dígitos + 1 para '\0'
double saldo[MAX_NOMES];
int senhas[MAX_NOMES];
int num_clientes = 0; //número de clientes para futuros laços de repetição
int indice_cliente = -1; // Índice do cliente atual
void cadastrarcliente();//função responsavel por cadastrar o cliente no sistema
void listarclientes();//Função para listar os clientes cadastrados
void alterarclientes();//Função para alterar dados dos clientes
void sistemagerente();//Sistema com funções do gerente
void excluircliente();//Função para excluir um cliente do sistema
void versaldo();//Funcao para ver saldo do cliente
void depositar();//Função para depositar valor na conta do cliente
void sacar();//Função para sacar valor da conta cliente
void transferir();//Funçao para trasnferir valor de uma conta para outra 
int i,j;
int x = 1;

int main() {
    int escolha; //Variavel usada para armazenar a escolha do usuario
    char cpf_cliente[15];//Array usado para armazenar o CPF digitado
    int senha;//Variavel usada para armazenar uma senha digitada
    const char gerente[] = "Guilherme";//Constante usada para armazenar o nome do gerente
    int result;//Variavel usada para armazenar o resultado da comparar
	
    while (x) {
        printf("~~~~~~~~ Bem-vindo ao AdsBank! ~~~~~~~~\n");
        printf("\nDigite o numero da opcao abaixo:\n\n");
        printf("--------------------------------\n");
        printf("1. Sistema cliente\n");
        printf("2. Sistema gerente\n");
        printf("3. Encerrar sistema\n");
        printf("--------------------------------\n");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
            	//Recebe o CPF para comparar com CPFs cadastrados
                printf("Digite o CPF do cliente: ");
                fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
                cpf_cliente[strcspn(cpf_cliente, "\n")] = '\0'; // Remove o newline no final do CPF
				
				//Compara o CPF digitado com os CPFs cadastrados
                for ( i = 0; i < num_clientes; i++) {
                    if (strcasecmp(cpf[i], cpf_cliente) == 0) {
                        printf("======Bem-vindo %s=======\n", nomes[i]);
                        
                        //Solicita a senha de acesso do cliente
                        printf("Digite sua senha de acesso:\n\n");
                        scanf("%d", &senha);
                        getchar();
						
						//Compara a senha digitada com a senha do cliente
                        if (senha == senhas[i]) {
                            indice_cliente = i; // Atualiza o índice do cliente atual
                            printf("\n\n=====Acesso concedido=====\n\n");
                            sistemacliente();//Leva o usuario para o sistema cliente caso o CPF e senha estejam corretos
                        } else {
                            printf("!!Senha incorreta.!!\n\n");
                        }
                        break;
                    }
                }
                //Caso nenhum cliente seja encontrado printa a mensagem abaixo
                if (indice_cliente == -1) {
                    printf("!!Cliente nao encontrado.!!\n\n");
                }
                break;

            case 2:
            	//Solicita o nome do gerente
                printf("Digite o nome do gerente:\n");
                fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
                cpf_cliente[strcspn(cpf_cliente, "\n")] = '\0'; // Remove o newline no final do nome
				
				//compara o nome digitado com o nome do gerente armazenado
                result = strcasecmp(gerente, cpf_cliente);
				
				//Solicita a senha do gerente
                printf("Digite a senha do gerente:\n");
                scanf("%d", &senha);
                getchar();
				
				//Verifica se a senha digitada é igual a armazenada
                if (result == 0 && senha == 1458) {
                    printf("\n!!Acesso concedido!!\n\n");
                    sistemagerente();//Caso a senha e nome do gerente esteja correto leva o usuario para o sistema cliente
                } else {
                    printf("!!Usuario ou senha incorretos!!\n\n");
                }
                break;
            //Encerra o sistema
			case 3: printf("\n\n=====Sistema encerrado=====\n\n"); 
			x = 0;
			break;
			
            default:
                printf("!!Opçao invalida!!\n\n");
                break;
        }
    }
    return 0;
}

void sistemacliente() {
    int op;//Variavel que recebe a escolha do usuario

    while (1) {
        printf("~~~~~~Voce esta no sistema cliente~~~~~~\n\n");
        printf("Digite o numero da opcao abaixo correspondente a acao que deseja realizar:\n");
        printf("------------------------------------\n");
        printf("1. Visualizar saldo\n");
        printf("2. Depositar valor na conta\n");
        printf("3. Sacar valor da conta\n");
        printf("4. Transferir valor para outra conta\n");
        printf("5. Sair do sistema cliente\n\n");
        printf("------------------------------------\n\n");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
            	//Leva o cliente para visualizar o saldo
                versaldo();
                break;
            case 2:
            	//Leva o cliente para depositar um valor na conta
                depositar();
                break;
            case 3:
            	//Leva o cliente para sacar um valor da conta
                sacar();
                break;
            case 4:
            	//Leva o cliente para tranferir um valor pra uma determinada conta 
                transferir();
                break;
            case 5:
            	//Retorna o usuario para o menu inicial
                printf("!!Voce saiu do sistema cliente!!\n\n");
                return;
            default:
                printf("!!Opçao invalida.!!\n\n");
        }
    }
}

void versaldo() {
	//Imprime o saldo do cliente
    printf("Saldo de %s: %.2lf\n\n", nomes[indice_cliente], saldo[indice_cliente]);
}

void depositar() {
    double valor;//Variavel para receber o valor a ser depositado
    
    //Recebe o valor a ser depositado
    printf("Digite o valor que deseja depositar:\n\n");
    scanf("%lf", &valor);
    getchar();
    
    //Incrementa o saldo do cliente com o valor desejado
    saldo[indice_cliente] += valor;
    printf("!!Deposito de %.2lf realizado com sucesso!!\n", valor);
    printf("Valor atualizado: %.2lf\n\n", saldo[indice_cliente]);
    return;
}

void sacar() {
    double valor;//Variavel usada para receber o valor do saque
    
    printf("Digite o valor que deseja sacar da conta:\n\n");
    scanf("%lf", &valor);
    getchar();
    
    //Verifica se o valor é maior que o saldo disponivel
    if (valor > saldo[indice_cliente]) {
        printf("!!Saldo insuficiente para o saque!!.\n\n");
        return;
    }
    //Decrementa o valor sacado do saldo da conta do cliente
    saldo[indice_cliente] -= valor;
    printf("!!Saque no valor de %.2lf realizado com sucesso!!\n", valor);
    printf("Valor atualizado: %.2lf\n\n", saldo[indice_cliente]);
    return;
}

void transferir() {
    char cpfDestino[15]; // Buffer para armazenar o CPF de destino
    double valor;
    int encontrado = 0; // Inicializa a flag como não encontrado

    // Solicita o CPF da conta destino
    printf("Digite o CPF da conta destino:\n\n");
    fgets(cpfDestino, sizeof(cpfDestino), stdin);
    cpfDestino[strcspn(cpfDestino, "\n")] = '\0'; // Remove o newline no final do buffer

    // Solicita o valor a ser transferido
    printf("Digite o valor que deseja transferir:\n\n");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer de entrada após a leitura do valor

    // Verifica se o saldo da conta de origem é suficiente
    if (valor > saldo[indice_cliente]) {
        printf("Saldo insuficiente para a transferencia.\n\n");
        return;
    }

    // Procura a conta de destino
    for ( i = 0; i < num_clientes; i++) {
        if (strcasecmp(cpf[i], cpfDestino) == 0) {
            // Atualiza os saldos
            saldo[indice_cliente] -= valor;
            saldo[i] += valor;
            printf("!!Transferencia de %.2lf realizada com sucesso!!\n", valor);
            printf("Novo saldo: %.2lf\n", saldo[indice_cliente]);
            printf("Saldo da conta destino: %.2lf\n\n", saldo[i]);
            encontrado = 1; // Marca como encontrado
            break; // Encerra o loop após encontrar e atualizar a conta destino
        }
    }

    if (!encontrado) {
        printf("!!CPF nao encontrado!!\n\n");
    }
}

void sistemagerente() {
    while (1) {
        int opcao;//Variavel para armazenar a escolha do usuario
        
        printf("~~~~~~Voce esta no sistema gerente!~~~~~~\n");
        printf("\nDigite o numero da opcao abaixo correspondente a acao que deseja realizar:\n");
        printf("--------------------------\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Alterar clientes\n");
        printf("4. Excluir cliente\n");
        printf("5. Sair do sistema gerente\n");
        printf("--------------------------\n\n");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer após a leitura do inteiro

        switch (opcao) {
            case 1:
            	//Leva o gerente para cadastrar um cliente no sistema
                cadastrarcliente();
                break;
            case 2:
            	//Leva o gerente para listar os clientes cadastrados no sistema
                listarclientes();
                break;
            case 3:
            	//Leva o gerente para alterar informações de um determinado cliente
                alterarclientes();
                break;
            case 4:
            	//Leva o gerente para excluir um determinado cliente do sistema
                excluircliente();
                break;
            case 5:
            	//Leva o usuario de volta para escolher entre o sistema gerente ou cliente
                printf("!!Voce saiu do sistema gerente!\n\n");
                return;
            default:
                printf("!!Opcao invalida.!!\n\n");
        }
    }
}

void cadastrarcliente() {
	
	//Verifica se a quantidade de clientes ja foi excedida
    if (num_clientes >= MAX_NOMES) {
        printf("Numero maximo de clientes atingido.\n\n");
        return;
    }
	//recebe o nome do cliente
    printf("Digite o nome do cliente %d: ", num_clientes + 1);
    fgets(nomes[num_clientes], TAM_NOME, stdin);						
    nomes[num_clientes][strcspn(nomes[num_clientes], "\n")] = '\0'; 
	
	//recebe o cpf do cliente
    printf("Digite o CPF do cliente %d: ", num_clientes + 1);
    fgets(cpf[num_clientes], 15, stdin);								
    cpf[num_clientes][strcspn(cpf[num_clientes], "\n")] = '\0'; 
	
	//recebe o saldo do cliente
    printf("Digite o saldo do cliente %d: ", num_clientes + 1);
    scanf("%lf", &saldo[num_clientes]);									
    getchar(); 
	
	//recebe a senha de acesso do cliente
    printf("Digite a senha de acesso do cliente:\n");
    scanf("%d", &senhas[num_clientes]); 								
    getchar(); 

    num_clientes++; // Atualiza o número de clientes

    printf("\n\n!!!!Cliente cadastrado com sucesso!!!!\n\n");
}

void listarclientes() {
  
   //verifica se tem clientes cadastrados no sistema
    if (num_clientes == 0) {
        printf("Nenhum cliente cadastrado.\n");				
        return;
    }
   
    //lista os clientes cadastrados no sistema
	printf("~~~~~~Lista de clientes~~~~~~\n");
	
    for ( i = 0; i < num_clientes; i++) {
	printf("\n-----------------------------\n");
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", nomes[i]);						
        printf("CPF: %s\n", cpf[i]);
        printf("Saldo: %.2f\n", saldo[i]);
		printf("-----------------------------\n\n");
    }
    
}

void alterarclientes() {
	
	//Verifica se há clientes cadastrados no sistema
    if (num_clientes < 1) {
        printf("!!Nenhum cliente cadastrado!!\n\n");
        return;
    }

    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    
    //Recebe o CPF para conparar com os CPFs cadastrados no sistema
    printf("\nDigite o CPF do cliente que deseja alterar:\n ");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF

    // Procura o cliente com o CPF fornecido
    for ( i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("\n\n!!!Cliente encontrado!!!\n\n");
            printf("Nome: %s\n", nomes[i]);
            printf("CPF: %s\n", cpf[i]);
            printf("Saldo: %.2f\n", saldo[i]);
			printf("\n-----------------------------------------\n");
            printf("Qual dado do cliente voce deseja alterar?\n");
            printf("1.Nome\n2.CPF\n3.Saldo                   \n");
            printf("-----------------------------------------\n\n");
            int escolha;
            scanf("%d", &escolha);
            getchar(); // Limpa o buffer após a leitura da opção

            switch (escolha) {
                case 1:
                	//altera o nome do cliente
                    printf("Digite o novo nome para o cliente: ");
                    fgets(nomes[i], TAM_NOME, stdin);
                    nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o newline no final do nome
                    printf("\n!!Nome atualizado com sucesso!!\n");
                    return;
                case 2:
                	//altera o CPF do cliente
                    printf("Digite o novo CPF para o cliente: ");
                    fgets(cpf[i], 15, stdin);
                    cpf[i][strcspn(cpf[i], "\n")] = '\0'; // Remove o newline no final do CPF
                    printf("\n!!Cpf atualizado com sucesso!!\n");
                    return;
                case 3:
                	//altera o saldo do cliente
                    printf("Digite o novo saldo para o cliente: ");
                    scanf("%lf", &saldo[i]);
                    getchar(); // Limpa o buffer após a leitura do saldo
                    printf("\n!!Saldo atualizado com sucesso!!\n");
                    return;
                case 4:
                	//altera a senha de acesso do cliente 
                	printf("Digite uma nova senha e acesso para o cliente:\n");
                	scanf("%d",senhas[i]);
                	printf("\n!!Senha atualizada com sucesso!!\n");
                	return;
                default:
                    printf("!!Opção inválida.!!\n\n");
                    return;
            }
        }
    }

    printf("!!!Cliente com CPF %s nao encontrado!!!.\n\n", cpfD);
}

void excluircliente() {
	//verifica se o sistema possui clientes cadastrados
    if (num_clientes < 1) {
        printf("!!Nenhum cliente cadastrado!!\n\n");
        return;
    }

    char cpfD[15]; // Array para armazenar o CPF digitado pelo usuário
    printf("Digite o CPF do cliente que deseja excluir: ");
    fgets(cpfD, 15, stdin);
    cpfD[strcspn(cpfD, "\n")] = '\0'; // Remove o newline no final do CPF

    int encontrado = 0; // Flag para verificar se o cliente foi encontrado
    
	//verifica se o cliente esta cadastrado e exibe as informações sobre ele
    for ( i = 0; i < num_clientes; i++) {
        if (strcmp(cpf[i], cpfD) == 0) {
            printf("!!Cliente encontrado!!\n");
            printf("----------------------\n");
            printf("Nome: %s\n", nomes[i]);
            printf("CPF: %s\n", cpf[i]);
            printf("Saldo: %.2f\n", saldo[i]);
            printf("----------------------\n\n");
			
			//pergunta se deseja excluir o cliente
            printf("Deseja excluir %s? (S/N):\n", nomes[i]);
            char op;
            scanf("%c", &op);
            getchar(); // Limpa o buffer após a leitura da opção

            if (op == 'S' || op == 's') {
                // Move todos os elementos após o índice para a esquerda e apaga o cliente do indice desejado
                for ( j = i; j < num_clientes - 1; j++) {
                    strcpy(nomes[j], nomes[j + 1]);
                    strcpy(cpf[j], cpf[j + 1]);
                    saldo[j] = saldo[j + 1];
                    senhas[j] = senhas[j + 1];
                }

                num_clientes--; // Reduz o número de clientes
                printf("----Cliente excluido com sucesso!----\n\n");
                encontrado = 1; // Marca como encontrado
                break; // Sai do loop após excluir o cliente 
            } else {
                printf("-----Açao cancelada!-----\n\n");
                return;
            }
        }
    }
	//caso o CPF não estiver cadastrado exibe a mensagem abaixo
    if (!encontrado) {
        printf("!!!Cliente com CPF %s nao encontrado.!!!\n\n", cpfD);
    }
}
