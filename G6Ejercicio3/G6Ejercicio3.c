#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
        nuevo->sig = raiz;
        raiz=nuevo;
    }   
}


void imprimir(){
    struct nodo *reco=raiz;
    while(reco!=NULL){
        
        printf("%i ", reco->info);
        reco=reco->sig; 
    }
    
    printf("\n");
}


void reemplazar(struct nodo *pila, int viejo, int nuevo ){
    if(pila != NULL){
        
        while(pila!=NULL){
        if(pila->info == viejo){
            pila->info = nuevo;
        }
        pila = pila->sig;
        }
        
    }else{
        printf("No se ha encontrado coincidencia\n");
    }
}

int main(){
    int viejo,nuevo;
    insertar(5);
    insertar(20);
    insertar(7);
    insertar(9);
    insertar(4);

    printf("\nLista inicial de pila :\n");
    imprimir();
    printf("Ingresar el numero viejo:\n");
    scanf("%d", &viejo);
    printf("Ingresar el numero nuevo:\n");
    scanf("%d", &nuevo);
    reemplazar(raiz,viejo, nuevo);
    printf("\nSe cambio el valor viejo = %d por el valor nuevo ingresado = %d",viejo,nuevo);
    printf("\nLa lista:\n");
    printf("\nLista final\n");
    imprimir();
    
  return 0;
}