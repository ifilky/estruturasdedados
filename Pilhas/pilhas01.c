#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    char nome[50];
    Data data;
}Pessoa;

typedef struct no {
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa (){
    Pessoa p;
    
    printf("Digite o nome da pessoa e a data de nascimento (dd mm aaaa):\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa (Pessoa p){
    printf("\nNome: %s\nData: %2.d/%2.d/%4.d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// função para a operação push (empilhar)
No* push(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }else {
        printf("\nA memória não foi alocada!\n");
        return NULL;
    }
}

// função para a operação POP (desempilhar)
No* pop(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else {
        printf("\nA pilha está vazia!\n");
        return NULL;
    }
}


int main() {

    No *remover, *topo = NULL;
    int opcao;

    do {
        printf("\n0 - SAIR\n1 - PUSH\n2 - POP\n3 - IMPRIMIR\n");
        scanf("%d", &opcao);
        getchar();
        printf("\nOpção: %d\n", opcao);

        switch (opcao) {
        case 1:
            topo = push(topo);
            break;
        case 2:
            remover = pop(&topo);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);
            }
            else {
                printf("\nSem nó para remover.\n");
            }
            break;
        case 3:

            break; 
        default:
            if(opcao != 0) {
                printf("\nOpção Inválida!\n");
            }
        }

    } while (opcao != 0);

    return 0;
}