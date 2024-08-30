## Ads-Bank V1

Aluno: Guilherme Alves Da Silva  
Professor: Felipe Gonçalves dos Santos  
Disciplina: Alogoritmos e progração

**OBSERVAÇÃO!!**  
## PARA ACESSAR o sistema gerente
- **Nome do gerente: Guilherme**
- **Senha do gerente: 1458**

Repositorio dedicado a exposição do codigo Ads Bank. Turma do Modulo 1 de ads, Disciplina Algoritimos e programação.

# AdsBank - Sistema Bancário

**AdsBank** é um sistema bancário básico desenvolvido em C que permite a gestão de clientes e suas contas. O sistema tem dois módulos principais: **Sistema Cliente** e **Sistema Gerente**.

## Funcionalidades

### Sistema Cliente
- **Visualizar saldo**: Exibe o saldo atual da conta do cliente.
- **Depositar valor**: Permite ao cliente adicionar um valor ao saldo da sua conta.
- **Sacar valor**: Permite ao cliente retirar um valor da sua conta, desde que haja saldo suficiente.
- **Transferir valor**: Permite ao cliente transferir um valor para outra conta, identificada pelo CPF.
- **Sair do sistema cliente**: Sai do módulo cliente e retorna ao menu principal.

### Sistema Gerente
- **Cadastrar cliente**: Permite ao gerente adicionar novos clientes ao sistema.
- **Listar clientes**: Exibe uma lista de todos os clientes cadastrados, incluindo nome, CPF e saldo.
- **Alterar clientes**: Permite ao gerente modificar informações de um cliente existente, como nome, CPF, saldo ou senha.
- **Excluir cliente**: Permite ao gerente remover um cliente do sistema.
- **Sair do sistema gerente**: Sai do módulo gerente e retorna ao menu principal.

## Estrutura do Código

### Funções do Programa

#### `main()`
O ponto de entrada do programa. Exibe um menu principal com três opções:
1. Sistema Cliente
2. Sistema Gerente
3. Encerrar Sistema

Dependendo da escolha do usuário, chama as funções apropriadas (`sistemacliente` ou `sistemagerente`) ou encerra o programa.

#### `sistemacliente()`
Esta função é chamada quando um cliente faz login com sucesso. Exibe um menu de opções para o cliente e chama a função correspondente (`versaldo`, `depositar`, `sacar`, `transferir`) ou sai do sistema cliente.

#### `versaldo()`
Mostra o saldo atual da conta do cliente logado, utilizando a variável global `indice_cliente` para acessar o saldo correto.

#### `depositar()`
Solicita um valor para depósito e adiciona esse valor ao saldo da conta do cliente. Exibe o saldo atualizado após o depósito.

#### `sacar()`
Solicita um valor para saque e verifica se há saldo suficiente. Se sim, decrementa o valor do saldo e exibe o saldo atualizado. Caso contrário, informa que o saldo é insuficiente.

#### `transferir()`
Solicita o CPF da conta de destino e o valor a ser transferido. Verifica se o saldo da conta de origem é suficiente e procura a conta de destino pelo CPF. Realiza a transferência se a conta for encontrada e atualiza os saldos.

#### `sistemagerente()`
Chamada quando o gerente faz login com sucesso. Exibe um menu de opções para o gerente e chama a função correspondente (`cadastrarcliente`, `listarclientes`, `alterarclientes`, `excluircliente`) ou sai do sistema gerente.

#### `cadastrarcliente()`
Solicita informações para cadastrar um novo cliente, incluindo nome, CPF, saldo inicial e senha de acesso. Adiciona essas informações ao banco de dados global e incrementa o número de clientes (`num_clientes`).

#### `listarclientes()`
Exibe uma lista de todos os clientes cadastrados, mostrando nome, CPF e saldo de cada um.

#### `alterarclientes()`
Permite ao gerente alterar informações de um cliente existente. Solicita o CPF do cliente, exibe suas informações e oferece opções para alterar nome, CPF, saldo ou senha.

#### `excluircliente()`
Permite ao gerente excluir um cliente do sistema. Solicita o CPF do cliente e, se encontrado, exibe suas informações e confirma a exclusão. Move os clientes subsequentes para preencher o espaço vazio e reduz o número de clientes (`num_clientes`).

## Observações Gerais

- **Controle de Fluxo**: Utiliza estruturas de controle como `if`, `for`, e `switch` para decisões e repetições.
- **Validação e Manipulação de Strings**: Utiliza funções como `fgets`, `strcspn`, e `strcasecmp` para leitura e manipulação de strings.
- **Uso de Arrays Globais**: Armazena informações sobre clientes em arrays globais, acessadas e modificadas pelas funções conforme necessário.


## Como Compilar e Executar

1. **Compilar**: Use um compilador C ou um editor de codigo com compilador embarcado como Devc++ ou Vscode e tambem `gcc`, para compilar o código.
   ```sh
   gcc -o adsbank adsbank.c

