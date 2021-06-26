#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selecao (int vet, int tam){
    int i, j, min, x;
    for (i=1; i<=n-1; i++){
        min = i;
	for (j=i+1; j<=n; j++){
            if (vet[j] < vet[min])
	        min = j;
	}
	x = vet[min];
	vet[min] = vet[i];
	vet[i] = x;
    }
}

void insercao (int vet, int tam){
int i, j, x;
for (i=2; i<=tam; i++){
	x = vet[i];
	j=i-1;
	vet[0] = x; 
	while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void criarHeap(int v[], int inicio, int final){
    int aux = v[inicio];//v[pai]//inicio=pai
    int filho = (inicio * 2)+1;//i=filho
while(filho<=final){
    if(filho<final && (filho+1)<final){
        if(v[filho]<v[filho+1]){//pai tem 2 filhos ? se sim, qual o maior
            filho++;
        }
    }
    if(aux<v[filho]){//troca o filho com o pai se o filho for maior
        v[inicio]=v[filho];
        inicio=filho;
        filho=(2*inicio)+1;
    }
    else{
        filho=final+1;
    }
}
    v[inicio] = aux;//pai troca com filho mais profundo mais a direita
}

void heapSort(int v[], int tam){
    int i;
    int aux;
    for(i=(tam-1)/2;i>=0;i--){// cria heap
        criarHeap(v,i,tam-1);
    }
    for(i=tam-1;i>=1;i--){//pega o maior elemento e coloca na posicao o array
        aux = v[0];
        v[0]=v[i];
        v[i]=aux;
        criarHeap(v,0,i-1);//cria o heap sem o maior elemento anterior
    }
}

int main {
   
    return 0;
}
