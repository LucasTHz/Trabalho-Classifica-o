# **Implementação dos algoritmos de ordenação**

## **Disciplina de Classificação e pesquisa de dados do curso de Engenharia de Computação CEFET-MG Campus Leopoldina-Minas Gerais.**

Bubble sort, Selection sort, Insertion sort, Quicksort, Mergesort e Heapsort. Criar um relatório contendo:

1) Introdução: descrever cada algoritmo de ordenação (Complexidade,
funcionamento, ...)
2) Executar cada um dos algoritmos para um vetor preenchido com números
aleatórios
3) Executar cada um dos algoritmos para um vetor ordenado (em ordem
crescente)
4) Executar cada um dos algoritmos para um vetor ordenado (em ordem
decrescente)
5) Conclusão do trabalho.

Para os itens 2, 3 e 4, crie uma tabela indicando o nome do algoritmo e o
tempo de execução do mesmo para a entrada selecionada. Faça uma
discussão sobre os resultados de cada tabela, apontando o porquê do pior e
melhor desempenho frente as características do algoritmo utilizado. A tabela
também deverá informar tamanho da entrada dos algoritmos (tamanho
sugerido: 100.000).

## Introdução

1. **Bubble Sort** \
É um algoritmo de ordenação simples que consiste em comparações em um vetor. Seu funcionamento e conforme o se o valor da posição atual é maior ou menor que o próximo valor na posição seguinte, caso o valor atual seja maior que o seguinte, ocorre a “flutuação” mudança na posição dos dois valores comparados ate chegar ao fim do vetor. Sua complexidade é O(n²) mostrando que não é um algoritmo eficiente.

2. **Select Sort** \
Na sua primeira passagem pelo vetor, o primeiro elemento é comparado com o restante dos valores no vetor, procurando um valor menor do que ele de modo a fazer a troca de posição entre os elementos onde o menor valor vai para o início do vetor e o maior para o final do vetor. Em seguida procurar o segundo menor valor nas n-1 posições restantes e deslocá-lo para a segunda posição e assim sucessivamente. A cada passagem pelo vetor o número de trocas diminui. Sua complexidade é O(n²).
3. **Insertion Sort** \
Uma maneira de se imaginar como é feita a ordenação você pode pensar que está com várias cartas na mão, e elas estão ordenadas. Você recebe uma nova carta. Você deve colocá-la na posição correta, de forma que as cartas na sua mão continuem ordenadas. Percorra as posições do vetor, começando com o índice 1. Cada nova posição é como a nova carta que você recebeu, e você precisa inseri-la no lugar correto no subvetor ordenado à esquerda daquela posição. Sua complexidade e O(n²).
4. **QuickSort** \
É um método baseado em divisão e conquista. Onde um elemento é escolhido como pivô onde todos os elementos antes dele sera menor e todos os elementos depois dele serão maiores. Sua complexidade no médio caso é de ϴ(nlogn) e seu pior caso O(n²).
5. **Merge Sort** \
Como o “Quick Sort”, o “merge sort” também é um algoritmo de divisão e conquista. É um método recursivo onde o vetor é dividido ao meio e às duas metades são ordenadas uma de cada vez e por fim ocorre a união das duas metades já fazendo as comparações entre às duas metades e deixando todo o vetor ordenado. Sua complexidade de tempo é θ (nLogn) em todos os 3 casos (pior, médio e melhor), pois o “merge sort” sempre divide o vetor em duas metades e leva tempo linear para unir às duas metades.

6. **Heap Sort** \
O heap sort utiliza uma estrutura de dados chamada heap para ordenar os elementos a medida que os insere na estrutura. Essa estrutura pode ser vista como uma árvore binaria quase completa. Onde temos pais e filhos, com o primeiro elemento sendo a raiz. Um heap decrescente de tamanho n  é implementado utilizando-se uma árvore binaria quase completa representada sequencialmente, com a característica de que todo nó possui um valor maior ou igual aos valores armazenados em seus filhos, caso estes existam. Sua complexidade é O(nlogn).

## **Discussão sobre os resultados dos testes**

### Tabela de tempo de execucao dos algoritmos

| Algoritmo          | Entrada | Vetor Aleatorio | Vetor Crescente | Vetor Decrescente |
|--------------------|---------|:---------------:|:---------------:|:-------------------:|
| **Bubble sort**    | 100000  | 55.3            | 23.25           |       51.39       |
| **Selection sort** | 100000  | 20.8            | 20.56           |       22.07       |
| **Insertion sort** | 100000  | 14.3            | 0.000987        |       28.80       |
| **Quicksort**      | 100000  | 10.6            | 28.65           |       71.91       |
| **Mergesort**      | 100000  | 0.03            | 0.033           |        0.02       |
| **Heapsort**       | 100000  | 0.04            | 0.03            |       0.034       |

* **Bubble Sort**
No bubble sort vimos o seu melhor caso foi com o vetor ordenado de forma crescente seu caso médio com o vetor ordenado em forma decrescente  é o pior caso com o vetor aleatório. Seu melhor caso seria O(n), pois só ocorreria uma passagem pelo vetor fazendo as comparações como tudo já está ordenado não a troca de posição. O pior caso seria com o vetor com valores aleatórios, pois a cada posição percorrida haverá troca na posição.

* **Selection Sort**
Observamos poucas variações de tempo no selection, seu melhor caso também é com o vetor ordenado, pois, só ocorreria n comparações e nenhuma troca de posição. O pior caso seria O(n²), pois além de fazer n comparações ao longo do vetor também fará n  trocas, pois a cada comparação deverá fazer trocas nas posições.

* **Insert Sort**
No melhor caso se porque serão feitas n comparações e nenhuma troca de posição apenas a comparação do elemento anterior com o atual. Seu pior caso se dá com o vetor ordenado de forma decrescente, pois ao achar um elemento menor, deverá passar por todas as posições anteriores, comparando se é menor até chegar na primeira posição.
* **Quick Sort**
Pior caso é com o vetor em forma decrescente, pois, seu pivô esta sendo o início do vetor, como os elementos estão em forma decrescente então a cada comparação devera ser feita a troca dos elementos, colocando todos os elementos a direita vai para a esquerda do pivô e assim recursivamente ate o vetor estar ordenado. Seu melhor caso é com o vetor preenchido de forma aleatória,

* **Merge Sort**
No caso do merge sort que sua complexidade é a mesma para todos os casos que é O(nlogn) a variação pode se dar conta de variáveis desprezíveis e pela questão de processamento. A variação de tempo foi muito pequena, diferença de milissegundos.

* **Heap Sort**
O heap sort tem o mesmo caso do merge sort sua complexidade tambem é O(nlogn) em todos os casos, mas com o fato que suas constantes de proporcionalidade são maiores.
