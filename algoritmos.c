#include "algoritmos.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM 10

void bubble_sort(int vetor[TAM]){

    //Auxiliares
    int x, y, aux;

    //Valor da esquerda sendo analisado
    for(x = 0; x < TAM; x++){

        //Valor da direita sendo analisado
        for(y = x + 1; y < TAM; y++){

            //Confere se precisa fazer a troca
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }

        }

    }

}
void insertion_sort(int vetor[TAM]){


    int i, j, atual;

    for(i = 1; i < TAM; i++){

        //Elemento atual em análise
        atual = vetor[i];

        //Elemento anterior ao analisado
        j = i - 1;

        //Analisando membros anteriores
        while( (j >=0) && (atual < vetor[j])){

            //Posiciona os elmeentos uma posição para frente
            vetor[j + 1] = vetor[j];

            //Faz o j andar para trás
            j = j - 1;

        }

        //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
        vetor[j + 1] = atual;

        //Mostra a lista atualizada
        //imprimeVetor(vetor);

    }

}
void selection_sort(int vetor[TAM]){

    int posicaoDoMenorValor, aux, i, j;

    for(i = 0; i < TAM; i++){

        //Recebe a posicao inicial para o menor valor
        posicaoDoMenorValor = i;

        //Analisa os elementos na frente
        for(j = i + 1; j < TAM; j++){

            //Caso encontre um valor menor na frente dos analisados
            if(vetor[j] < vetor[posicaoDoMenorValor]){
                posicaoDoMenorValor = j;
            }

        }

        //Verifica se houve mudança e troca os valores
        if(posicaoDoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }

        //imprimeVetor(vetor);

    }

}
void shell_sort(int vetor[TAM]){
    int i, j, atual;
    int h = 1;

    //De quantos em quantos será o pulo entre análises
    while(h < TAM){
        h = 3*h+1;
    }

    while(h > 1){

        //Reduz a distância entre as análises
        h = h / 3;

        for(i = h; i < TAM; i++){

            //Elemento atual em análise
            atual = vetor[i];

            //Elemento anterior ao analisado
            j = i - h;

            //Analisando membros anteriores
            while( (j >=0) && (atual < vetor[j])){

                //Posiciona os elmeentos uma posição para frente
                vetor[j + h] = vetor[j];

                //Faz o j andar para trás
                j = j - h;

            }

            //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
            vetor[j + h] = atual;

            //imprimeVetor(vetor);

        }

    }




}
void merge(int vetor[TAM], int indiceEsquerdo, int meio, int indiceDireito){

    int i, j, k;                        //Auxiliares contadoras
    int n1 = meio - indiceEsquerdo + 1; //Tamanho do primeiro vetor auxiliar
    int n2 = indiceDireito - meio;      //Tamanho do segundo vetor auxiliar

    //Cria dois Arrays temporários
    int vetorEsquerdo[n1], vetorDireito[n2];

    //Passa os elementos do vetor principal para o primeiro vetor auxiliar (Esquerda)
    for(i = 0; i < n1; i++){
        vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
    }

    //Passa os elementos do vetor principal para o primeiro vetor auxiliar (Direito)
    for(j = 0; j < n2; j++){
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    //Reseta as variáveis
    i = 0;
    j = 0;
    k = indiceEsquerdo;

    while((i < n1) && ( j < n2)){
        //Caso o valor na esquerda seja menor
        if(vetorEsquerdo[i] <= vetorDireito[j]){
            //Passo para o meu vetor principal o valor meno
            vetor[k] = vetorEsquerdo[i];

            //Incrementa
            i++;
        }else{
            //Passo para o meu vetor principal o valor menor
            vetor[k] = vetorDireito[j];

            //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
            j++;
        }

        //Aumenta o índice de posicionamento no vetor
        k++;
    }

    //Se faltarem alguns elementos do array ESQUERDO, passa eles para o array principal
    while(i < n1){
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    //Se faltarem alguns elementos do array DIREITO, passa eles para o array principal
    while(j < n2){
        vetor[k] = vetorDireito[j];
        j++;
        k++;
    }

}
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito){
    if(indiceEsquerdo < indiceDireito){

        //Encontra o meio
        int meio = indiceEsquerdo + (indiceDireito-indiceEsquerdo)/2;

        //Da metade para trás
        merge_sort(vetor, indiceEsquerdo, meio);

        //Da metade para frente
        merge_sort(vetor, meio+1, indiceDireito);

        // Imprimindo
        //imprimeVetor(vetor);


        //Une os dois subarrava que foram criados
        merge(vetor, indiceEsquerdo, meio, indiceDireito);

    }

}
void quickSort(int *vetor, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vetor, inicio, fim); //separa os dados em duas partições.
        quickSort(vetor, inicio, pivo-1); //chama a função para as duas metades
        quickSort(vetor, pivo+1, fim);    //por RECURSÃO.
    }
}
int particiona(int *vetor, int inicio, int fim){
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vetor[inicio]; //o pivo recebe o valor do início do vetor.

    while(esq < dir){
        while(vetor[esq] <= pivo){//enquanto o elemento for menor ou igual ao pivo
            esq++; //avança posição da esquerda.
        }
        while(vetor[dir] > pivo){//enquanto o elemento for maior ou igual ao pivo
            dir--; //recua posição da direita.
        }
        if(esq < dir){ // troca esq e dir.
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}
void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}
void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}
/* A utility function to print array of size n */
int menuPrincipal(){ //Menu principal
    int opcao;
    printf("\n\n---------------- Escolha um algoritmo para testar ----------------\n\n");
    printf("1 - BubbleSort\n");
    printf("2 - InsertionSort\n");
    printf("3 - SelectionSort\n");
    printf("4 - ShellSort\n");
    printf("5 - MergeSort\n");
    printf("6 - QuickSort\n");
    printf("7 - HeapSort\n");
    printf("Digite a opção:  ");
    scanf("%d", &opcao);
    return opcao;
}
void limpaTela(){ //limpa tela com o system CLS
    system("CLS");
}
int * numerosAleatorios(){
    static int numerosAleatorios[10];
    int i = 0;

    for(i = 0; i <= 10; i++){
        numerosAleatorios[i] = rand();
    }
    return numerosAleatorios;
}
int subMenu(){ //Menu principal
    int escolha;
    int contagem;
    printf("\n\n---------------- Escolha quantas vezes testar ----------------\n\n");
    printf("1 - 1.000\n");
    printf("2 - 5.000\n");
    printf("3 - 10.000\n");
    printf("4 - 20.000\n");
    printf("5 - 50.000\n");
    printf("6 - 100.000\n");
    printf("Digite qualquer outro número diferente das opções para voltar para o menu:  \n");
    printf("Digite a opção:  ");
    scanf("%d", &escolha);

    if(escolha == 1){
        contagem = 1000;
    }else if(escolha == 2){
        contagem = 5000;
    }
    else if(escolha == 3){
        contagem = 10000;
    }else if(escolha == 4){
        contagem = 20000;
    }else if(escolha == 5){
        contagem = 50000;
    }else if(escolha == 6){
        contagem = 10000;
    }else{
        contagem = 7;
    }

    return contagem;
}


