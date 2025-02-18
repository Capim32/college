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

// Funcao principal
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
        printf("5. Sair\n");
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
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}

// =======================================================================================VEiCULOS======================================================================================================================

void salvarVeiculos() {
    FILE *arquivo_vei = fopen("veiculos.txt", "w");
    if (arquivo_vei == NULL) {
        printf("Erro ao abrir o arquivo de veiculos.\n");
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
        printf("Arquivo de veiculos nao encontrado.\n");
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
        printf("Limite de veiculos atingido!\n");
        return;
    }

    Veiculo v;
    v.id = ++ultimo_id_vei;

    printf("Tipo do veiculo(Carro/ Moto/ Caminhao/ Aviao): ");
    scanf("%s", v.tipo);
    printf("Capacidade de carga (kg): ");
    scanf("%f", &v.capacidade);
    printf("Status (Livre/Ocupado): ");
    scanf("%s", v.status);

    veiculos[numVeiculos++] = v;
    salvarVeiculos();
    printf("Veiculo adicionado com sucesso! ID: %d\n", v.id);
}

void removerVeiculo() {
    int id, i, encontrado = 0;
    printf("Digite o ID do veiculo a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == id) {
            encontrado = 1;
            for (int j = i; j < numVeiculos - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }
            numVeiculos--;
            salvarVeiculos();
            printf("Veiculo removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Veiculo nao encontrado!\n");
    }
}

void listarVeiculos() {
    if (numVeiculos == 0) {
        printf("Nenhum veiculo cadastrado.\n");
        return;
    }

    printf("\nLista de veiculos:\n");
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
        fprintf(arquivo_ent, "%d|%s|%s|%.2f\n", entregas[i].id, entregas[i].origem, entregas[i].destino, entregas[i].tempoEstimado);
    }

    fclose(arquivo_ent);
}

void carregarEntregas() {
    FILE *arquivo_ent = fopen("entregas.txt", "r");
    if (arquivo_ent == NULL) {
        printf("Arquivo de entregas nao encontrado.\n");
        return;
    }

    while (fscanf(arquivo_ent, "%d|%[^|]|%[^|]|%f\n", &entregas[numEntregas].id, entregas[numEntregas].origem, entregas[numEntregas].destino, &entregas[numEntregas].tempoEstimado) == 4) {
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

    printf("Insira a origem da entrega: ");
    getchar();
    fgets(ent.origem, TAM_PAD, stdin);
    ent.origem[strcspn(ent.origem, "\n")] = 0;

    printf("Insira o destino da entrega: ");
    fgets(ent.destino, TAM_PAD, stdin);
    ent.destino[strcspn(ent.destino, "\n")] = 0;

    printf("Insira o tempo estimado (em horas): ");
    scanf("%f", &ent.tempoEstimado);

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
        printf("Entrega com ID %d nao encontrada.\n", id_procurado);
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
        printf("Entrega com ID %d nao encontrada.\n", id);
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
//==============================================================================================

void adicionarEntregaPendente() {
    FILE *arquivo_ent_pen = fopen("entregas_pendentes.txt", "a");
    if (!arquivo_ent_pen) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Entrega e;
    printf("ID da entrega: "); scanf("%d", &e.id);
    printf("Funcionario responsavel: "); scanf(" %[^\n]", e.funcionario);
    printf("Veiculo: "); scanf(" %[^\n]", e.veiculo);
    printf("Cliente: "); scanf(" %[^\n]", e.cliente);
    
    fprintf(arquivo_ent_pen, "%d;%s;%s;%s\n", e.id, e.funcionario, e.veiculo, e.cliente);
    fclose(arquivo_ent_pen);
    printf("Entrega adicionada com sucesso!\n");
}

void concluirEntrega() {
    FILE *pendentes = fopen("entregas_pendentes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *concluidas = fopen("entregas_concluidas.txt", "a");
    if (!pendentes || !temp || !concluidas)
    {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    int idBusca;
    printf("ID da entrega concluida: ");
    scanf("%d", &idBusca);

    Entrega e;
    int encontrada = 0;
    while (fscanf(pendentes, "%d;%[^;];%[^;];%[^\n]\n", &e.id, e.funcionario, e.veiculo, e.cliente) != EOF) {
        if (e.id == idBusca) {
            encontrada = 1;
            printf("Origem: "); scanf(" %[^\n]", e.origem);
            printf("Destino: "); scanf(" %[^\n]", e.destino);
            printf("Tempo total de entrega (hrs): "); scanf("%f", &e.tempoEstimado);
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
        printf("Entrega concluida com sucesso!\n");
    else
        printf("Entrega nao encontrada!\n");
}

void gerarRelatorio() {
    FILE *file = fopen("entregas_concluidas.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Entrega e;
    printf("\n=== RELATÓRIO DE ENTREGAS CONCLUiDAS ===\n");
    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", &e.id, e.funcionario, e.veiculo, e.cliente, e.origem, e.destino, &e.tempoEstimado) == 7) {
        printf("ID: %d\nFuncionario: %s\nVeiculo: %s\nCliente: %s\nOrigem: %s\nDestino: %s\nTempo total: %.2f h\n\n",
               e.id, e.funcionario, e.veiculo, e.cliente, e.origem, e.destino, e.tempoEstimado);
    }
    fclose(file);
}

int realizar_entregas() {
    int opcao;
    do {
        printf("\n1. Adicionar entrega pendente\n");
        printf("2. Concluir entrega\n");
        printf("3. relatório de entregas concluidas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}


//================================================================================================

// =======================================================================================FUNCIONARIOS=================================================================================================================

void salvarFuncionarios() {
    FILE *arquivo_fun = fopen("funcionarios.txt", "w");
    if (arquivo_fun == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        return;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        fprintf(arquivo_fun, "%d|%s\n", funcionarios[i].id, funcionarios[i].nome);
    }

    fclose(arquivo_fun);
}

void carregarFuncionarios() {
    FILE *arquivo_fun = fopen("funcionarios.txt", "r");
    if (arquivo_fun == NULL) {
        printf("Arquivo de funcionarios nao encontrado.\n");
        return;
    }

    while (fscanf(arquivo_fun, "%d|%[^\n]\n", &funcionarios[numFuncionarios].id, funcionarios[numFuncionarios].nome) == 2) {
        if (funcionarios[numFuncionarios].id > ultimo_id_fun) {
            ultimo_id_fun = funcionarios[numFuncionarios].id;
        }
        numFuncionarios++;
    }

    fclose(arquivo_fun);
}

void id_criar_funcionarios() {
    if (numFuncionarios >= MAX) {
        printf("Limite de funcionarios atingido!\n");
        return;
    }

    Funcionario novo;
    novo.id = ++ultimo_id_fun;

    printf("Insira o nome do funcionario: ");
    getchar();
    fgets(novo.nome, TAM_PAD, stdin);
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
        printf("Funcionario com ID %d nao encontrado.\n", id_procurado);
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
            fgets(funcionarios[i].nome, TAM_PAD, stdin);
            funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = 0;

            salvarFuncionarios();
            printf("Funcionario atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario com ID %d nao encontrado.\n", id);
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
        printf("Arquivo de clientes nao encontrado. Criando novo arquivo.\n");
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

void adicionar_cliente() {
    if (numClientes >= MAX) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    Cliente novo_cliente;
    novo_cliente.id = ++ultimo_id_cli;

    printf("Nome completo: ");
    getchar();
    fgets(novo_cliente.nome, TAM_PAD, stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = 0;

    printf("Endereco completo: ");
    fgets(novo_cliente.endereco, TAM_ENDERECO, stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = 0;

    printf("Tipo de servico (economico, padrao, premium): ");
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
        printf("ID: %d | Nome: %s | Endereco: %s | Servico: %s\n",
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
            printf("Cliente editado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d nao encontrado.\n", id);
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
            printf("Cliente excluido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com ID %d nao encontrado.\n", id);
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
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
