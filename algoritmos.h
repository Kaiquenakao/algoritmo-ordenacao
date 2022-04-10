#define TAM 10
void bubble_sort(int vetor[TAM]);
void insertion_sort(int vetor[TAM]);
void selection_sort(int vetor[TAM]);
void shell_sort(int vetor[TAM]);
void merge(int vetor[TAM], int indiceEsquerdo, int meio, int indiceDireito);
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito);
void quickSort(int *vetor, int inicio, int fim);
int particiona(int *vetor, int inicio, int fim);
void heapsort(int *vet, int n);
void peneira(int *vet, int raiz, int fundo);
int menuPrincipal();
void limpaTela();
int *numerosAleatorios();
int subMenu();
