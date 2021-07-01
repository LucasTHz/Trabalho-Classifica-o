#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define count 100000

void bubbleSort(int vet[], int vecSize) {
    int j, aux;

    for(int i = vecSize - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(vet[j] > vet[j+1])
            {
                int temp;
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
    printf("\nBubble Sort\n");

}

void selectionSort(int vet[]){
    int min, temp;

    for (int i=1; i<=count; i++){
        min = i;
        for (int j=i+1; j<=count; j++){
                if (vet[j] < vet[min])
                    min = j;
        }
        if (vet[i] != vet[min])
        {
            temp = vet[min];
            vet[min] = vet[i];
            vet[i] = temp;
        }
    }
}

void insertionSort(int vet[])
{
    int temp, j;

    for (int i=1; i<count; i++){
        temp = vet[i];
        j = i -1;
        while (j>=0 && temp < vet[j])
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = temp;
    }
}

void quickSort(int vet[], int esq, int dir){
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
        quickSort(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quickSort(vet,pivo+1,dir);      
    }
 }

void merge(int vec[], int vecSize) {
    int mid;
    int i, j, k;
    int* tmp;
    tmp = (int*) malloc(vecSize * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }
    mid = vecSize / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize) {
        if (vec[i] < vec[j]) {
          tmp[k] = vec[i];
          ++i;
        }
        else {
          tmp[k] = vec[j];
          ++j;
        }
        ++k;
    }
    if (i == mid) {
        while (j < vecSize) {
          tmp[k] = vec[j];
          ++j;
          ++k;
        }
    }
    else {
        while (i < mid) {
          tmp[k] = vec[i];
          ++i;
          ++k;
        }
    }
    for (i = 0; i < vecSize; ++i) {
        vec[i] = tmp[i];
    } 
    free(tmp);
}

void mergeSort(int vec[], int vecSize) {
    int mid;

    if (vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
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

void heapSort(int v[], int vecSize){
    int i;
    int aux;
    for(i=(vecSize-1)/2;i>=0;i--){// cria heap
        criarHeap(v,i,vecSize-1);
    }
    for(i=vecSize-1;i>=1;i--){//pega o maior elemento e coloca na posicao o array
        aux = v[0];
        v[0]=v[i];
        v[i]=aux;
        criarHeap(v,0,i-1);//cria o heap sem o maior elemento anterior
    }
}

void inicializarAleatoriamente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = rand () % 100000;
}

void inicializarOrdemCrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i;
}

void inicializarOrdemDecrescente(int v[], int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = n-i;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int v[count];
    
    inicializarOrdemDecrescente(v, count);

    for (int i=0; i < count; i++)
        printf("%d  ", v[i]);

    double start, stop, elapsed; // variaveis para medir o tempo

    start = (double) clock() / CLOCKS_PER_SEC;

    quickSort(v,0, count);

    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    for (int i=0; i < count; i++)
        printf("%d  ", v[i]);

    printf("\nTempo total em segundos: %f\n", elapsed);

    return 0;
}
