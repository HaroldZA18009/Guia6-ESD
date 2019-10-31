#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int num;
    struct nodo *sig;
};

struct nodo2{
    int num2;
    struct nodo2 *sig;
};

struct nodo *raiz=NULL;
struct nodo2 *raiz2=NULL;

void insertar(int n){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->num=n;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}
void insertar2(int x){
    struct nodo2 *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->num2=x;
    if(raiz2==NULL){
        raiz2=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz2;
        raiz2=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    printf("Pila original.\n");
    while (reco!=NULL){
        printf("%i\n",reco->num);
        reco=reco->sig;
    }
    printf("\n");
}

int invertir(){
    if(raiz!=NULL){
        while (raiz!=NULL){
            struct nodo *bor=raiz;
            insertar2(bor->num);
            raiz=raiz->sig;
            free(bor);
        }
    } else{
        return -1;
    }
}

void imprimirInvertido(){
    struct nodo2 *reco=raiz2;
    printf("Pila invertida.\n");
    while (reco!=NULL){
        printf("%i\n",reco->num2);
        reco=reco->sig;
    }
    printf("\n");
}

int main() {
    insertar(1);
    insertar(2);
    insertar(3);
    imprimir();
    invertir();
    imprimirInvertido();
    return 0;
}