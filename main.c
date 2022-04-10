#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"
#include <locale.h>
#include <time.h>



int main(){
    setlocale(LC_ALL, "portuguese");
    int opcao = 0, i;
    int cont, contagem;
    time_t antes, depois;

    while(opcao >= 0 && opcao <= 7){
        opcao = menuPrincipal();
        limpaTela();

        switch(opcao){
        case 1:
            printf("Bubble sorte escolhido!\n");
            contagem = subMenu();
            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    bubble_sort(recebeNumeros);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }


        break;

        case 2:
            printf("InsertionSort escolhido!\n");
            contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    insertion_sort(recebeNumeros);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        case 3:
            printf("SelectionSort escolhido!\n");
            contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    selection_sort(recebeNumeros);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        case 4:
            printf("ShellSort escolhido!\n");
           contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    shell_sort(recebeNumeros);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        case 5:
            printf("MergeSort escolhido!\n");
           contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    merge_sort(recebeNumeros, 0, TAM - 1);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        case 6:
            printf("QuickSort escolhido!\n");
           contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    quickSort(recebeNumeros, 0, 6);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        case 7:
            printf("HeapSort escolhido!\n");
           contagem = subMenu();

            if(contagem != 7){
                antes = time(0);
                for(cont = 0; cont < contagem; cont++){
                    int *recebeNumeros = numerosAleatorios();
                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n");
                    heapsort(recebeNumeros, 10);

                    for(i = 0; i < 10; i++){
                        printf("%d - ", recebeNumeros[i]);
                    }
                    printf("\n\n");
                }
                depois = time(0);
                printf("Entre %d e %d se passaram %f segundos\n",antes, depois, difftime(depois, antes));
            }else{
                system("cls");
                printf("Voltando para o menu principal...");
            }
        break;

        default:
            printf("Erro opção invalida"); // Caso o usuário digita uma opção invalida ocorre esse erro
            exit(1);
        break;
        }
}

    system("pause");
    return 0;
}
