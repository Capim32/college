#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TAM_PAD 100
#define TAM_ENDERECO 200
#define TAM_SERVICO 100

// Definicao das structs
typedef struct {
    int id;
    char tipo[20];
    float capacidade;
    char status[10]; // "livre" ou "ocupado"
} Veiculo;

typedef struct {
    int id;
    char funcionario[TAM_PAD];
    char veiculo[TAM_PAD];
    char cliente[TAM_PAD];
    char origem[TAM_PAD];
    char destino[TAM_PAD];
    float tempoEstimado; // em horas
} Entrega;

typedef struct {
    int id;
    char nome[TAM_PAD];
} Funcionario;

typedef struct {
    int id;
    char nome[TAM_PAD];
    char endereco[TAM_ENDERECO];
    char tipo_servico[TAM_SERVICO]; // "economico", "padrao", "premium"
} Cliente;

// Variaveis globais
Veiculo veiculos[MAX];
Entrega entregas[MAX];
Funcionario funcionarios[MAX];
Cliente clientes[MAX];

int numVeiculos = 0, numEntregas = 0, numFuncionarios = 0, numClientes = 0;
int ultimo_id_vei = 0, ultimo_id_ent = 0, ultimo_id_fun = 0, ultimo_id_cli = 0;

// Declararação das funcões
void adicionarVeiculo();
void removerVeiculo();
void listarVeiculos();
void salvarVeiculos();
void carregarVeiculos();
int g_veiculos();

void id_criar_entregas();
void id_deletar_entregas();
void id_modificar_entregas();
void entrega_visualizar();
void salvarEntregas();
void carregarEntregas();
int realizar_entregas();
int g_entregas();

void id_criar_funcionarios();
void id_deletar_funcionarios();
void id_modificar_funcionarios();
void funcionarios_visualizar();
void salvarFuncionarios();
void carregarFuncionarios();
int g_funcionarios();

void adicionar_cliente();
void visualizar_clientes();
void editar_cliente();
void excluir_cliente();
void salvar_clientes();
void carregar_clientes();
int g_clientes();



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
    if (numVeiculos >= MAX) {
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

  while (numEntregas < MAX &&
       fscanf(arquivo, "%d|%[^|]|%[^|]|%f\n",
              &entregas[numEntregas].id,
              entregas[numEntregas].origem,
              entregas[numEntregas].destino,
              &entregas[numEntregas].tempoEstimado) == 4) { 
    numEntregas++;
}

    fclose(arquivo);
}

void id_criar_entregas() {
    if (numEntregas >= MAX) {
        printf("Limite de entregas atingido!\n");
        return;
    }

    Entrega novo;
    novo.id = numEntregas + 1; // ID sequencial e único

    printf("Insira a origem da entrega: ");
    getchar();
    fgets(novo.origem, TAM_PAD, stdin);
    novo.origem[strcspn(novo.origem, "\n")] = 0;

    printf("Insira o destino da entrega: ");
    fgets(novo.destino, TAM_PAD, stdin);
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
            fgets(entregas[i].origem, TAM_PAD, stdin);
            entregas[i].origem[strcspn(entregas[i].origem, "\n")] = 0;

            printf("Destino atual: %s\n", entregas[i].destino);
            printf("Novo local de destino: ");
            fgets(entregas[i].destino, TAM_PAD, stdin);
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
        printf("5. realizar entregas\n");
        printf("6. Sair\n");
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
                realizar_entregas();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 5);

    return 0;
}
void adicionarEntregaPendente() {
    FILE *file = fopen("entregas_pendentes.txt", "a");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Entrega e;
    printf("ID da entrega: "); scanf("%d", &e.id);
    printf("Funcionário responsável: "); scanf(" %[^\n]", e.funcionario);
    printf("Veículo: "); scanf(" %[^\n]", e.veiculo);
    printf("Cliente: "); scanf(" %[^\n]", e.cliente);
    
    fprintf(file, "%d;%s;%s;%s\n", e.id, e.funcionario, e.veiculo, e.cliente);
    fclose(file);
    printf("Entrega adicionada com sucesso!\n");
}

void concluirEntrega() {
    FILE *pendentes = fopen("entregas_pendentes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *concluidas = fopen("entregas_concluidas.txt", "a");
    if (!pendentes || !temp || !concluidas) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    int idBusca;
    printf("ID da entrega concluída: ");
    scanf("%d", &idBusca);

    Entrega e;
    int encontrada = 0;
    while (fscanf(pendentes, "%d;%[^;];%[^;];%[^\n]\n", &e.id, e.funcionario, e.veiculo, e.cliente) != EOF) {
        if (e.id == idBusca) {
            encontrada = 1;
            printf("Origem: "); scanf(" %[^\n]", e.origem);
            printf("Destino: "); scanf(" %[^\n]", e.destino);
            printf("Tempo total de entrega (horas): "); scanf("%f", &e.tempoEstimado);
            fprintf(concluidas, "%d;%s;%s;%s;%s;%s;%.2f\n", e.id, e.funcionario, e.veiculo, e.cliente, e.origem, e.destino, e.tempoEstimado);
        } else {
            fprintf(temp, "%d;%s;%s;%s\n", e.id, e.funcionario, e.veiculo, e.cliente);
        }
    }
    fclose(pendentes);
    fclose(temp);
    fclose(concluidas);

    remove("entregas_pendentes.txt");
    rename("temp.txt", "entregas_pendentes.txt");

    if (encontrada)
        printf("Entrega concluída com sucesso!\n");
    else
        printf("Entrega não encontrada!\n");
}

void gerarRelatorio() {
    FILE *file = fopen("entregas_concluidas.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Entrega e;
    printf("\n=== RELATÓRIO DE ENTREGAS CONCLUÍDAS ===\n");
    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", &e.id, e.funcionario, e.veiculo, e.cliente, e.origem, e.destino, &e.tempoEstimado) == 7) {
        printf("ID: %d\nFuncionário: %s\nVeículo: %s\nCliente: %s\nOrigem: %s\nDestino: %s\nTempo total: %.2f h\n\n",
               e.id, e.funcionario, e.veiculo, e.cliente, e.origem, e.destino, e.tempoEstimado);
    }
    fclose(file);
}

int main ( ) {
    realizar_entregas();
    int opcao;
    do {
        printf("\n1. Adicionar entrega pendente\n");
        printf("2. Concluir entrega\n");
        printf("3. Gerar relatório de entregas concluídas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarEntregaPendente();
                break;
            case 2:
                concluirEntrega();
                break;
            case 3:
                gerarRelatorio();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
