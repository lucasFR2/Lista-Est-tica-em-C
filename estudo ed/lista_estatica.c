#include <stdio.h>
#include <stdlib.h>
#define max 5
 
typedef struct aluno{
    int matricula;
    int nota;
}aluno;

typedef struct lista{
    aluno dados[max];
    int qtd;
}lista;

lista* ini_lista(){
    lista *li = (lista*) malloc(sizeof(lista));
    li->qtd = 0;
    return li;
}

int in_ini(lista *li, aluno al){
    if (li->qtd == 0){
        li->dados[0] = al;
        li->qtd++;
        return 1;
    }
    if(li->qtd == max){
        printf("Lista cheia!");
        return 1;
    }
    for(int i = li->qtd; i>=0; i--){
        li->dados[i] = li->dados[i-1];
    }
    li->dados[0] = al;
    li->qtd++;
}

int in_fim(lista *li, aluno al){
    if(li->qtd == max){
        printf("Lista Cheia");
        return 1;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
}

void imprimir(lista *li){
    if (li->qtd == 0){
        printf("Lista vazia!");
        return;
    }
    for(int i = 0; i < li->qtd; i++){
        printf("Matricula: %d \nNota: %d \n", li->dados[i].matricula, li->dados[i].nota);
    }
}

int main(){
    int opc;
    lista *li;
    li = ini_lista();
    aluno al;

    do{
        printf("\nO que deseja fazer? \n[0] - Sair \n[1] - Inserir no Inicio\n[2] - Inserir no Fim\n[3] - Imprimir Lista\n");
        scanf(" %d",&opc);

        switch(opc){
            case 1:
                printf("Digite a matricula: ");
                scanf(" %d", &al.matricula);
                printf("Digite a nota: ");
                scanf(" %d", &al.nota);
                in_ini(li, al);
                break;
            case 2:
                printf("Digite a matricula: ");
                scanf(" %d", &al.matricula);
                printf("Digite a nota: ");
                scanf(" %d", &al.nota);
                in_fim(li, al);
                break;
            case 3:
                imprimir(li);
                break;
            default:
                if(opc != 0){
                    printf("Numero invalido!");
                }
                break;
        }
    } while(opc!=0);

}