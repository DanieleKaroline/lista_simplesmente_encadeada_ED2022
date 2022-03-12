#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int dia, mes, ano;
};
typedef struct data Data;

struct aluno{
    char matricula[10];
    char nome[40];
    Data data_nasc;
    float nota;
    struct aluno *prox;
};
typedef struct aluno Aluno;


Aluno* insert_aluno(Aluno *Lista, Aluno *novo_aluno){

    Aluno *aux;

    if (Lista  == NULL){
        return novo_aluno;
    }

    aux = Lista;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo_aluno;

    return Lista;
}

void exibe_ordem(Aluno* Lista){
    Aluno *aux = Lista;
    if(Lista == NULL){
        printf("\nLista vazia\n");
    } else{
         while (aux != NULL){
            printf("\n%s, ", aux->matricula);
            printf("%s, ", aux->nome);
            printf("%d/%d/%d, ", aux->data_nasc.dia, aux->data_nasc.mes, aux->data_nasc.ano);
            printf("%.2f\n", aux->nota);
            aux=aux->prox;
        }
    }    
}
void exibe_inverso(Aluno* Lista){
    Aluno *aux;
    aux = Lista;

    if(Lista == NULL){
        return;
    }
    else{
        exibe_inverso(aux->prox);
        printf("\n%s, ", aux->matricula);
        printf("%s, ", aux->nome);
        printf("%d/%d/%d, ", aux->data_nasc.dia, aux->data_nasc.mes, aux->data_nasc.ano);
        printf("%.2f\n", aux->nota);	

    }
	
}

int tam_lista(Aluno *p){
   int c = 0;
	Aluno *aux;
	for(aux = p; aux!=NULL; aux = aux->prox){
		c ++;
	}
    if(p == NULL){
        printf("Lista vazia");
    } else{
        printf("%d", c);
    }  
}

Aluno *del_aluno(Aluno *Lista, char *mat_del){

    Aluno *aux, *prev = Lista;
    for (aux = Lista; aux != NULL; aux = aux->prox)
    {
        if (strcmp(aux->matricula, mat_del) == 0)
        {

            if (aux == Lista)
            {
                Lista = Lista->prox;
                free(prev);
                return Lista;
            }

            prev->prox = aux->prox;
            free(aux);
            return Lista;
        }
        prev = aux;
    }
    return Lista;
}

void saida(Aluno *Lista)
{
    Aluno *aux;
    aux = Lista;
    while (aux != NULL)
    {
        Aluno *prox = aux->prox;
        free(aux);
        printf("-\n");
        aux = prox;
    }
}

/*void menu(){
    printf("\nOpcao 1: Incluir elemento na lista\n");
    printf("Opcao 2: Excluir elemento da lista\n");
    printf("Opcao 3: Listar todos os elementos da lista na ordem de inclusao\n");
    printf("Opcao 4: Listar todos os elementos da lista na ordem inversa a inclusao\n");    
    printf("Opcao 5: Apresentar quantos elementos existem na lista\n");   
    printf("Opcao 0: Sair\n"); 
    printf("\nDigite a opcao:  ");
}*/

int main(){

    Aluno *Lista = NULL, *novo_aluno;  
    char mat_del[10];
    int i = 1;

    while (i == 1)
    {
        //menu();
        int opcao;
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            novo_aluno = malloc(sizeof(Aluno));
            scanf("%s", &novo_aluno->matricula);
            scanf("%s", &novo_aluno->nome);
            scanf("%d/%d/%d", &novo_aluno->data_nasc.dia, &novo_aluno->data_nasc.mes, &novo_aluno->data_nasc.ano);
            scanf("%f", &novo_aluno->nota);
            novo_aluno->prox = NULL;
            Lista = insert_aluno(Lista, novo_aluno);
            break;
        case 2:
            scanf("%s", mat_del);
            del_aluno(Lista, mat_del);
            break;
        case 3: exibe_ordem(Lista); break;
        case 4: exibe_inverso(Lista); break;
        case 5: tam_lista(Lista); break;
        case 0: saida(Lista); i = 0; break;
        }
    }

    return 0;
}