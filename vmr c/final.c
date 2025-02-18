#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100
#define MAX_ENTREGAS 100
#define MAX_FUNCIONARIOS 100
#define MAX_CLIENTES 100
#define TAM_NOME 100
#define TAM_ENDERECO 200
#define TAM_SERVICO 50

// Definição das structs
typedef struct {
    int id;
    char tipo[20];
    float capacidade;
    char status[10]; // "livre" ou "ocupado"
} Veiculo;

typedef struct {
    int id;
    char origem[TAM_NOME];
    char destino[TAM_NOME];
    float tempoEstimado; // em horas
} Entrega;

typedef struct {
    int id;
    char nome[TAM_NOME];
} Funcionario;

typedef struct {
    int id;
    char nome[TAM_NOME];
    char endereco[TAM_ENDERECO];
    char tipo_servico[TAM_SERVICO]; // "economico", "padrao", "premium"
} Cliente;

// Variáveis globais
Veiculo veiculos[MAX_VEICULOS];
Entrega entregas[MAX_ENTREGAS];
Funcionario funcionarios[MAX_FUNCIONARIOS];
Cliente clientes[MAX_CLIENTES];

int numVeiculos = 0, numEntregas = 0, numFuncionarios = 0, numClientes = 0;

// Funções para manipulação de veículos
void adicionarVeiculo();
void removerVeiculo();
void listarVeiculos();
void salvarVeiculos();
void carregarVeiculos();
int g_veiculos();

// Funções para manipulação de entregas
void id_criar_entregas();
void id_deletar_entregas();
void id_modificar_entregas();
void entrega_visualizar();
void salvarEntregas();
void carregarEntregas();
int g_entregas();

// Funções para manipulação de funcionários
void id_criar_funcionarios();
void id_deletar_funcionarios();
void id_modificar_funcionarios();
void funcionarios_visualizar();
void salvarFuncionarios();
void carregarFuncionarios();
int g_funcionarios();

// Funções para manipulação de clientes
void adicionar_cliente();
void visualizar_clientes();
void editar_cliente();
void excluir_cliente();
void salvar_clientes();
void carregar_clientes();
int g_clientes();

// Função principal
int main() {
    // Carregar dados dos arquivos ao iniciar o programa
    carregarVeiculos();
    carregarEntregas();
    carregarFuncionarios();
    carregar_clientes();

    int escolha;

    do {
        printf("\n=== Sistema de Gestão ===\n");
        printf("1. Gestao de Veiculos\n");
        printf("2. Gestao de Entregas\n");
        printf("3. Gestao de Funcionarios\n");
        printf("4. Gestao de Clientes\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                g_veiculos();
                break;
            case 2:
                g_entregas();
                break;
            case 3:
                g_funcionarios();
                break;
            case 4:
                g_clientes();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}

// =======================================================================================VEÍCULOS======================================================================================================================

void salvarVeiculos() {
    FILE *arquivo = fopen("veiculos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    for (int i = 0; i < numVeiculos; i++) {
        fprintf(arquivo, "%d|%s|%.2f|%s\n", veiculos[i].id, veiculos[i].tipo, veiculos[i].capacidade, veiculos[i].status);
    }

    fclose(arquivo);
}

void carregarVeiculos() {
    FILE *arquivo = fopen("veiculos.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de veículos não encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d|%[^|]|%f|%[^\n]\n", &veiculos[numVeiculos].id, veiculos[numVeiculos].tipo, &veiculos[numVeiculos].capacidade, veiculos[numVeiculos].status) != EOF) {
        numVeiculos++;
    }

    fclose(arquivo);
}

void adicionarVeiculo() {
    if (numVeiculos >= MAX_VEICULOS) {
        printf("Limite de veículos atingido!\n");
        return;
    }

    Veiculo v;
    v.id = numVeiculos + 1; // ID sequencial e único

    printf("Tipo do veículo: ");
    scanf("%s", v.tipo);
    printf("Capacidade de carga (kg): ");
    scanf("%f", &v.capacidade);
    printf("Status (Livre/Ocupado): ");
    scanf("%s", v.status);

    veiculos[numVeiculos++] = v;
    salvarVeiculos();
    printf("Veículo adicionado com sucesso! ID: %d\n", v.id);
}

void removerVeiculo() {
    int id, i, encontrado = 0;
    printf("Digite o ID do veículo a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == id) {
            encontrado = 1;
            for (int j = i; j < numVeiculos - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }
            numVeiculos--;
            salvarVeiculos();
            printf("Veículo removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Veículo não encontrado!\n");
    }
}

void listarVeiculos() {
    if (numVeiculos == 0) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    printf("\nLista de veículos:\n");
    for (int i = 0; i < numVeiculos; i++) {
        printf("ID: %d | Tipo: %s | Capacidade: %.2f kg | Status: %s\n",
               veiculos[i].id, veiculos[i].tipo, veiculos[i].capacidade, veiculos[i].status);
    }
}

int g_veiculos() {
    int opcao;

    do {
        printf("\n=== Gestao de Veiculos ===\n");
        printf("1. Adicionar veiculo\n");
        printf("2. Remover veiculo\n");
        printf("3. Listar veiculos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVeiculo();
                break;
            case 2:
                removerVeiculo();
                break;
            case 3:
                listarVeiculos();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}

// =======================================================================================ENTREGAS=======================================================================================================================

void salvarEntregas() {
    FILE *arquivo = fopen("entregas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entregas.\n");
        return;
    }

    for (int i = 0; i < numEntregas; i++) {
        fprintf(arquivo, "%d|%s|%s|%.2f\n", entregas[i].id, entregas[i].origem, entregas[i].destino, entregas[i].tempoEstimado);
    }

    fclose(arquivo);
}

void carregarEntregas() {
    FILE *arquivo = fopen("entregas.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de entregas não encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%f\n", &entregas[numEntregas].id, entregas[numEntregas].origem, entregas[numEntregas].destino, &entregas[numEntregas].tempoEstimado) != EOF) {
        numEntregas++;
    }

    fclose(arquivo);
}

void id_criar_entregas() {
    if (numEntregas >= MAX_ENTREGAS) {
        printf("Limite de entregas atingido!\n");
        return;
    }

    Entrega novo;
    novo.id = numEntregas + 1; // ID sequencial e único

    printf("Insira a origem da entrega: ");
    getchar();
    fgets(novo.origem, TAM_NOME, stdin);
    novo.origem[strcspn(novo.origem, "\n")] = 0;

    printf("Insira o destino da entrega: ");
    fgets(novo.destino, TAM_NOME, stdin);
    novo.destino[strcspn(novo.destino, "\n")] = 0;

    printf("Insira o tempo estimado (em horas): ");
    scanf("%f", &novo.tempoEstimado);

    entregas[numEntregas++] = novo;
    salvarEntregas();
    printf("Entrega adicionada com sucesso! ID: %d\n", novo.id);
}

void id_deletar_entregas() {
    int id_procurado;
    printf("Insira o ID que queira remover: ");
    scanf("%d", &id_procurado);

    int encontrado = 0;
    for (int i = 0; i < numEntregas; i++) {
        if (entregas[i].id == id_procurado) {
            encontrado = 1;
            for (int j = i; j < numEntregas - 1; j++) {
                entregas[j] = entregas[j + 1];
            }
            numEntregas--;
            salvarEntregas();
            printf("Entrega removida com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Entrega com ID %d não encontrada.\n", id_procurado);
    }
}

void id_modificar_entregas() {
    int id;
    printf("Insira o ID que queira editar: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numEntregas; i++) {
        if (entregas[i].id == id) {
            encontrado = 1;
            printf("Origem atual: %s\n", entregas[i].origem);
            printf("Novo local de origem: ");
            getchar();
            fgets(entregas[i].origem, TAM_NOME, stdin);
            entregas[i].origem[strcspn(entregas[i].origem, "\n")] = 0;

            printf("Destino atual: %s\n", entregas[i].destino);
            printf("Novo local de destino: ");
            fgets(entregas[i].destino, TAM_NOME, stdin);
            entregas[i].destino[strcspn(entregas[i].destino, "\n")] = 0;

            printf("Tempo estimado atual: %.2f horas\n", entregas[i].tempoEstimado);
            printf("Novo tempo estimado: ");
            scanf("%f", &entregas[i].tempoEstimado);

            salvarEntregas();
            printf("Entrega atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Entrega com ID %d não encontrada.\n", id);
    }
}

void entrega_visualizar() {
    if (numEntregas == 0) {
        printf("Nenhuma entrega cadastrada.\n");
        return;
    }

    printf("\nLista de entregas:\n");
    for (int i = 0; i < numEntregas; i++) {
        printf("ID: %d | Origem: %s | Destino: %s | Tempo estimado: %.2f horas\n",
               entregas[i].id, entregas[i].origem, entregas[i].destino, entregas[i].tempoEstimado);
    }
}

int g_entregas() {
    int escolha;

    do {
        printf("\n=== Gestao de Entregas ===\n");
        printf("1. Criar entrega\n");
        printf("2. Deletar entrega\n");
        printf("3. Modificar entrega\n");
        printf("4. Visualizar entregas\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                id_criar_entregas();
                break;
            case 2:
                id_deletar_entregas();
                break;
            case 3:
                id_modificar_entregas();
                break;
            case 4:
                entrega_visualizar();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 5);

    return 0;
}

// =======================================================================================FUNCIONARIOS=================================================================================================================

void salvarFuncionarios() {
    FILE *arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        fprintf(arquivo, "%d|%s\n", funcionarios[i].id, funcionarios[i].nome);
    }

    fclose(arquivo);
}

void carregarFuncionarios() {
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de funcionários não encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d|%[^\n]\n", &funcionarios[numFuncionarios].id, funcionarios[numFuncionarios].nome) != EOF) {
        numFuncionarios++;
    }

    fclose(arquivo);
}

void id_criar_funcionarios() {
    if (numFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    Funcionario novo;
    novo.id = numFuncionarios + 1; // ID sequencial e único

    printf("Insira o nome do funcionario: ");
    getchar();
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    funcionarios[numFuncionarios++] = novo;
    salvarFuncionarios();
    printf("Funcionario adicionado com sucesso! ID: %d\n", novo.id);
}

void id_deletar_funcionarios() {
    int id_procurado;
    printf("Insira o ID que queira remover: ");
    scanf("%d", &id_procurado);

    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].id == id_procurado) {
            encontrado = 1;
            for (int j = i; j < numFuncionarios - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            numFuncionarios--;
            salvarFuncionarios();
            printf("Funcionario removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario com ID %d não encontrado.\n", id_procurado);
    }
}

void id_modificar_funcionarios() {
    int id;
    printf("Insira o ID que queira editar: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            encontrado = 1;
            printf("Nome atual: %s\n", funcionarios[i].nome);
            printf("Novo nome: ");
            getchar();
            fgets(funcionarios[i].nome, TAM_NOME, stdin);
            funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = 0;

            salvarFuncionarios();
            printf("Funcionario atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario com ID %d não encontrado.\n", id);
    }
}

void funcionarios_visualizar() {
    if (numFuncionarios == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    printf("\nLista de funcionarios:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("ID: %d | Nome: %s\n", funcionarios[i].id, funcionarios[i].nome);
    }
}

int g_funcionarios() {
    int escolha;

    do {
        printf("\n=== Gestao de Funcionarios ===\n");
        printf("1. Criar funcionario\n");
        printf("2. Deletar funcionario\n");
        printf("3. Modificar funcionario\n");
        printf("4. Visualizar funcionarios\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                id_criar_funcionarios();
                break;
            case 2:
                id_deletar_funcionarios();
                break;
            case 3:
                id_modificar_funcionarios();
                break;
            case 4:
                funcionarios_visualizar();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 5);

    return 0;
}

// =======================================================================================CLIENTES=======================================================================================================================

void salvar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(arquivo, "%d|%s|%s|%s\n", clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].tipo_servico);
    }

    fclose(arquivo);
}

void carregar_clientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de clientes não encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%[^\n]\n", &clientes[numClientes].id, clientes[numClientes].nome, clientes[numClientes].endereco, clientes[numClientes].tipo_servico) != EOF) {
        numClientes++;
    }

    fclose(arquivo);
}

void adicionar_cliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo_cliente;
    novo_cliente.id = numClientes + 1; // ID sequencial e único

    printf("Nome completo: ");
    getchar();
    fgets(novo_cliente.nome, TAM_NOME, stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = 0;

    printf("Endereço completo: ");
    fgets(novo_cliente.endereco, TAM_ENDERECO, stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = 0;

    printf("Tipo de serviço (economico, padrao, premium): ");
    fgets(novo_cliente.tipo_servico, TAM_SERVICO, stdin);
    novo_cliente.tipo_servico[strcspn(novo_cliente.tipo_servico, "\n")] = 0;

    clientes[numClientes++] = novo_cliente;
    salvar_clientes();
    printf("Cliente adicionado com sucesso! ID: %d\n", novo_cliente.id);
}

void visualizar_clientes() {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\nLista de clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("ID: %d | Nome: %s | Endereço: %s | Serviço: %s\n",
               clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].tipo_servico);
    }
}

void editar_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].id == id) {
            encontrado = 1;
            printf("Nome atual: %s\n", clientes[i].nome);
            printf("Novo nome: ");
            getchar();
            fgets(clientes[i].nome, TAM_NOME, stdin);
            clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

            printf("Endereço atual: %s\n", clientes[i].endereco);
            printf("Novo endereço: ");
            fgets(clientes[i].endereco, TAM_ENDERECO, stdin);
            clientes[i].endereco[strcspn(clientes[i].endereco, "\n")] = 0;

            printf("Tipo de serviço atual: %s\n", clientes[i].tipo_servico);
            printf("Novo tipo de serviço: ");
            fgets(clientes[i].tipo_servico, TAM_SERVICO, stdin);
            clientes[i].tipo_servico[strcspn(clientes[i].tipo_servico, "\n")] = 0;

            salvar_clientes();
            printf("Cliente editado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", id);
    }
}

void excluir_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].id == id) {
            encontrado = 1;
            for (int j = i; j < numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            numClientes--;
            salvar_clientes();
            printf("Cliente excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d não encontrado.\n", id);
    }
}

int g_clientes() {
    carregar_clientes();

    int opcao;
    do {
        printf("\n=== Gestao de Clientes ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Visualizar Clientes\n");
        printf("3. Editar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_cliente();
                break;
            case 2:
                visualizar_clientes();
                break;
            case 3:
                editar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}