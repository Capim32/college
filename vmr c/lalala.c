#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TAM_PAD 100
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
    char funcionario[TAM_PAD];
    int id_veiculo; // ID do veículo associado
    char cliente[TAM_PAD];
    char origem[TAM_PAD];
    char destino[TAM_PAD];
    float tempoEstimado; // em horas
    int concluida; // 0 = pendente, 1 = concluída
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

// Variáveis globais
Veiculo veiculos[MAX];
Entrega entregas[MAX];
Funcionario funcionarios[MAX];
Cliente clientes[MAX];

int numVeiculos = 0, numEntregas = 0, numFuncionarios = 0, numClientes = 0;
int ultimo_id_vei = 0, ultimo_id_ent = 0, ultimo_id_fun = 0, ultimo_id_cli = 0;

// Protótipos das funções
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

void gerarRelatorioEntregas();
void finalizarEntrega();

// Função principal
int main() {
    // Carregar dados dos arquivos ao iniciar o programa
    carregarVeiculos();
    carregarEntregas();
    carregarFuncionarios();
    carregar_clientes();

    int escolha;

    do {
        printf("\n=== Sistema de Gestao ===\n");
        printf("1. Gestao de Veiculos\n");
        printf("2. Gestao de Entregas\n");
        printf("3. Gestao de Funcionarios\n");
        printf("4. Gestao de Clientes\n");
        printf("5. Relatorio de Entregas\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
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
                gerarRelatorioEntregas();
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

// =======================================================================================VEÍCULOS======================================================================================================================
void salvarVeiculos() {
    FILE *arquivo_vei = fopen("veiculos.txt", "w");
    if (arquivo_vei == NULL) {
        printf("Erro ao abrir o arquivo de veículos.\n");
        return;
    }

    for (int i = 0; i < numVeiculos; i++) {
        fprintf(arquivo_vei, "%d|%s|%.2f|%s\n", veiculos[i].id, veiculos[i].tipo, veiculos[i].capacidade, veiculos[i].status);
    }

    fclose(arquivo_vei);
}

void carregarVeiculos() {
    FILE *arquivo_vei = fopen("veiculos.txt", "r");
    if (arquivo_vei == NULL) {
        printf("Arquivo de veículos não encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(arquivo_vei, "%d|%[^|]|%f|%[^\n]\n", &veiculos[numVeiculos].id, veiculos[numVeiculos].tipo, &veiculos[numVeiculos].capacidade, veiculos[numVeiculos].status) == 4) {
        if (veiculos[numVeiculos].id > ultimo_id_vei) {
            ultimo_id_vei = veiculos[numVeiculos].id;
        }
        numVeiculos++;
    }

    fclose(arquivo_vei);
}

void adicionarVeiculo() {
    if (numVeiculos >= MAX) {
        printf("Limite de veículos atingido!\n");
        return;
    }

    Veiculo v;
    v.id = ++ultimo_id_vei;

    printf("Tipo do veiculo: ");
    scanf("%s", v.tipo);
    printf("Capacidade de carga (kg): ");
    scanf("%f", &v.capacidade);
    strcpy(v.status, "livre"); // Novo veículo começa como "livre"

    veiculos[numVeiculos++] = v;
    salvarVeiculos();
    printf("Veiculo adicionado com sucesso! ID: %d\n", v.id);
}

void removerVeiculo() {
    int id, i, encontrado = 0;
    printf("Digite o ID do veículo a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == id) {
            if (strcmp(veiculos[i].status, "ocupado") == 0) {
                printf("Veículo está ocupado e não pode ser removido!\n");
                return;
            }
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
    FILE *arquivo_ent = fopen("entregas.txt", "w");
    if (arquivo_ent == NULL) {
        printf("Erro ao abrir o arquivo de entregas.\n");
        return;
    }

    for (int i = 0; i < numEntregas; i++) {
        fprintf(arquivo_ent, "%d|%s|%d|%s|%s|%s|%.2f|%d\n", entregas[i].id, entregas[i].funcionario, entregas[i].id_veiculo, entregas[i].cliente, entregas[i].origem, entregas[i].destino, entregas[i].tempoEstimado, entregas[i].concluida);
    }

    fclose(arquivo_ent);
}

void carregarEntregas() {
    FILE *arquivo_ent = fopen("entregas.txt", "r");
    if (arquivo_ent == NULL) {
        printf("Arquivo de entregas nao encontrado.\n");
        return;
    }

    while (fscanf(arquivo_ent, "%d|%[^|]|%d|%[^|]|%[^|]|%[^|]|%f|%d\n", &entregas[numEntregas].id, entregas[numEntregas].funcionario, &entregas[numEntregas].id_veiculo, entregas[numEntregas].cliente, entregas[numEntregas].origem, entregas[numEntregas].destino, &entregas[numEntregas].tempoEstimado, &entregas[numEntregas].concluida) == 8) {
        if (entregas[numEntregas].id > ultimo_id_ent) {
            ultimo_id_ent = entregas[numEntregas].id;
        }
        numEntregas++;
    }

    fclose(arquivo_ent);
}

void id_criar_entregas() {
    if (numEntregas >= MAX) {
        printf("Limite de entregas atingido!\n");
        return;
    }

    Entrega ent;
    ent.id = ++ultimo_id_ent;

    printf("Insira o nome do funcionario responsavel: ");
    getchar();
    fgets(ent.funcionario, TAM_PAD, stdin);
    ent.funcionario[strcspn(ent.funcionario, "\n")] = 0;

    printf("Insira o ID do veiculo: ");
    scanf("%d", &ent.id_veiculo);

    // Verifica se o veículo existe e está livre
    int veiculo_encontrado = 0;
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == ent.id_veiculo) {
            if (strcmp(veiculos[i].status, "ocupado") == 0) {
                printf("Veículo já está ocupado!\n");
                return;
            }
            veiculo_encontrado = 1;
            strcpy(veiculos[i].status, "ocupado"); // Marca o veículo como ocupado
            salvarVeiculos();
            break;
        }
    }

    if (!veiculo_encontrado) {
        printf("Veículo com ID %d não encontrado!\n", ent.id_veiculo);
        return;
    }

    printf("Insira o nome do cliente: ");
    getchar();
    fgets(ent.cliente, TAM_PAD, stdin);
    ent.cliente[strcspn(ent.cliente, "\n")] = 0;

    printf("Insira a origem da entrega: ");
    fgets(ent.origem, TAM_PAD, stdin);
    ent.origem[strcspn(ent.origem, "\n")] = 0;

    printf("Insira o destino da entrega: ");
    fgets(ent.destino, TAM_PAD, stdin);
    ent.destino[strcspn(ent.destino, "\n")] = 0;

    printf("Insira o tempo estimado (em horas): ");
    scanf("%f", &ent.tempoEstimado);

    ent.concluida = 0; // Entrega começa como pendente

    entregas[numEntregas++] = ent;
    salvarEntregas();
    printf("Entrega adicionada com sucesso! ID: %d\n", ent.id);
}

void id_deletar_entregas() {
    int id_procurado;
    printf("Insira o ID que queira remover: ");
    scanf("%d", &id_procurado);

    int encontrado = 0;
    for (int i = 0; i < numEntregas; i++) {
        if (entregas[i].id == id_procurado) {
            encontrado = 1;
            if (entregas[i].concluida == 0) {
                printf("Entrega ainda está pendente e não pode ser removida!\n");
                return;
            }
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
            if (entregas[i].concluida == 1) {
                printf("Entrega já foi concluída e não pode ser modificada!\n");
                return;
            }
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
        printf("ID: %d | Funcionario: %s | Veiculo ID: %d | Cliente: %s | Origem: %s | Destino: %s | Tempo estimado: %.2f horas | Status: %s\n",
               entregas[i].id, entregas[i].funcionario, entregas[i].id_veiculo, entregas[i].cliente, entregas[i].origem, entregas[i].destino, entregas[i].tempoEstimado, entregas[i].concluida ? "Concluída" : "Pendente");
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

// =======================================================================================FUNCIONÁRIOS=======================================================================================================================
void id_criar_funcionarios() {
    if (numFuncionarios >= MAX) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    Funcionario fun;
    fun.id = ++ultimo_id_fun;

    printf("Nome do funcionário: ");
    getchar();
    fgets(fun.nome, TAM_PAD, stdin);
    fun.nome[strcspn(fun.nome, "\n")] = 0;

    funcionarios[numFuncionarios++] = fun;
    salvarFuncionarios();
    printf("Funcionário adicionado com sucesso! ID: %d\n", fun.id);
}

void id_deletar_funcionarios() {
    int id;
    printf("Digite o ID do funcionário que deseja excluir: ");
    scanf("%d", &id);

    int i, encontrado = 0;
    for (i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            encontrado = 1;
            for (int j = i; j < numFuncionarios - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            numFuncionarios--;
            salvarFuncionarios();
            printf("Funcionário excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
    }
}

void id_modificar_funcionarios() {
    int id;
    printf("Digite o ID do funcionário que deseja editar: ");
    scanf("%d", &id);

    int i, encontrado = 0;
    for (i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            encontrado = 1;
            printf("Nome atual: %s\n", funcionarios[i].nome);
            printf("Novo nome: ");
            getchar();
            fgets(funcionarios[i].nome, TAM_PAD, stdin);
            funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = 0;
            salvarFuncionarios();
            printf("Funcionário atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
    }
}

void funcionarios_visualizar() {
    if (numFuncionarios == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    printf("\nLista de funcionários:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("ID: %d | Nome: %s\n", funcionarios[i].id, funcionarios[i].nome);
    }
}

int g_funcionarios() {
    int opcao;

    do {
        printf("\n=== Gestao de Funcionarios ===\n");
        printf("1. Adicionar funcionario\n");
        printf("2. Excluir funcionario\n");
        printf("3. Modificar funcionario\n");
        printf("4. Listar funcionarios\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
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
    } while (opcao != 5);

    return 0;
}

// =======================================================================================CLIENTES=======================================================================================================================
void adicionar_cliente() {
    if (numClientes >= MAX) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente cli;
    cli.id = ++ultimo_id_cli;

    printf("Nome do cliente: ");
    getchar();
    fgets(cli.nome, TAM_PAD, stdin);
    cli.nome[strcspn(cli.nome, "\n")] = 0;

    printf("Endereco do cliente: ");
    fgets(cli.endereco, TAM_ENDERECO, stdin);
    cli.endereco[strcspn(cli.endereco, "\n")] = 0;

    printf("Tipo de servico (economico, padrao, premium): ");
    fgets(cli.tipo_servico, TAM_SERVICO, stdin);
    cli.tipo_servico[strcspn(cli.tipo_servico, "\n")] = 0;

    clientes[numClientes++] = cli;
    salvar_clientes();
    printf("Cliente adicionado com sucesso! ID: %d\n", cli.id);
}

void visualizar_clientes() {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\nLista de clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("ID: %d | Nome: %s | Endereco: %s | Tipo de servico: %s\n",
               clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].tipo_servico);
    }
}

void editar_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &id);

    int i, encontrado = 0;
    for (i = 0; i < numClientes; i++) {
        if (clientes[i].id == id) {
            encontrado = 1;
            printf("Nome atual: %s\n", clientes[i].nome);
            printf("Novo nome: ");
            getchar();
            fgets(clientes[i].nome, TAM_PAD, stdin);
            clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

            printf("Endereco atual: %s\n", clientes[i].endereco);
            printf("Novo endereco: ");
            fgets(clientes[i].endereco, TAM_ENDERECO, stdin);
            clientes[i].endereco[strcspn(clientes[i].endereco, "\n")] = 0;

            printf("Tipo de servico atual: %s\n", clientes[i].tipo_servico);
            printf("Novo tipo de servico: ");
            fgets(clientes[i].tipo_servico, TAM_SERVICO, stdin);
            clientes[i].tipo_servico[strcspn(clientes[i].tipo_servico, "\n")] = 0;

            salvar_clientes();
            printf("Cliente atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    }
}

void excluir_cliente() {
    int id;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &id);

    int i, encontrado = 0;
    for (i = 0; i < numClientes; i++) {
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
        printf("Cliente não encontrado.\n");
    }
}

void salvar_clientes() {
    FILE *arquivo_cli = fopen("clientes.txt", "w");
    if (arquivo_cli == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(arquivo_cli, "%d|%s|%s|%s\n", clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].tipo_servico);
    }

    fclose(arquivo_cli);
}

void carregar_clientes() {
    FILE *arquivo_cli = fopen("clientes.txt", "r");
    if (arquivo_cli == NULL) {
        printf("Arquivo de clientes nao encontrado.\n");
        return;
    }

    while (fscanf(arquivo_cli, "%d|%[^|]|%[^|]|%[^\n]\n", &clientes[numClientes].id, clientes[numClientes].nome, clientes[numClientes].endereco, clientes[numClientes].tipo_servico) == 4) {
        if (clientes[numClientes].id > ultimo_id_cli) {
            ultimo_id_cli = clientes[numClientes].id;
        }
        numClientes++;
    }

    fclose(arquivo_cli);
}

int g_clientes() {
    int opcao;

    do {
        printf("\n=== Gestao de Clientes ===\n");
        printf("1. Adicionar cliente\n");
        printf("2. Excluir cliente\n");
        printf("3. Editar cliente\n");
        printf("4. Visualizar clientes\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_cliente();
                break;
            case 2:
                excluir_cliente();
                break;
            case 3:
                editar_cliente();
                break;
            case 4:
                visualizar_clientes();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
