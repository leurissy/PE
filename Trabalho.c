/*
	Probability and Statistics work developed by Larissa Cristina
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int QNT = 100, i, k = 5;

/*Função pra gerar numeros, esccrever no arquivo e lê-los do arquivos*/
int generate_values(int *values){
    FILE *arq_values;
    int temp = 0;
    srand(time(NULL));
	//abrindo o arquivo
	arq_values = fopen("values.txt", "w");
	if(arq_values == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 1;
	}else{
		// escrever os valores no txt /
		for (i = 0; i < QNT; i++){
	        fprintf(arq_values, " %d", rand()%10);
		}
	}
	fclose(arq_values);

	//abrindo o arquivo com tipo de abertura r
	arq_values = fopen("values.txt", "r");

	/* Ler os valores do txt e preencher o vetor*/
	for (i = 0; i < QNT; i++){
        fscanf(arq_values, " %d", &values[i]);
	}
	fclose(arq_values);
	return 0;
}

/*Função Immprimir os values*/
void values_print(int *values){
    puts("\t\t\t\tNUMEROS: \n");
    printf("    ");
	for (i = 0; i<QNT; i++){
		if(i%10==0){
			puts(" ");
		}else{
			if(i == QNT-1){
				printf("\t%d", values[i]);
			}else{
				printf("\t%d, ", values[i]);
			}
		}
	}
	puts(" ");
}

/*Função para ordenar o vetor*/
void order_values(int* values){
	int ord = QNT, aux;
	while (ord>1){
		for (i = 0; i<QNT-1; i++){
			if (values[i]>values[i+1]){
				aux=values[i];
				values[i] = values[i+1];
				values[i+1] = aux;
			}
		}
		ord=ord-1;
	}

}

/* Função para calcular a moda*/
void calculate_Mode(int* values, int *mode){
	int j, count = 0, countM = 0;

	for (i = 0; i < QNT; i++){
		count = 0;
		for (j = 0; j < QNT; j++){
			if(values[i]==values[j]){
				count++;
			}
			if(count > countM){
				*mode = values[i];
				countM = count;
			}else if(count == countM){
				*mode = values[i];
			}
		}
	}

	if(countM == 1){
		printf("AMODAL\n");
	}else{
		printf("\t\t\t\tMODA %d\n", *mode);
	}
}

/* Função para calcular da média */
void calculate_Average(int* values, float *media){
	float soma = 0.0;
	for (i = 0; i < QNT; i++)
        soma += values[i];
	*media = soma/QNT;
	printf("\t\t\t\tMEDIA: %.2f \n",*media);

}
/* Função para calcular a média ponderada*/
void calculate_WeightedAverage(int* values, float *weightedAverage){
	float soma = 0.0;
	int pesos = 0;
	for (i = 0; i < QNT; i++){
        soma += (values[i] * i);
        pesos += i;
	}
	*weightedAverage = soma/pesos;
	printf("\t\t\t\tMEDIA PONDERADA: %.2f \n",*weightedAverage);

}

/*Função para calcula mediana*/
void calculate_Median(int* values, float *median){
    int temp = QNT/2;
	if((QNT%2) == 0){
        *median = (values[temp-1] + values[temp])/2;
	}else{
        *median = values[temp-1];
	}
	printf("\t\t\t\tMEDIANA: %.2f \n",*median);
}

/*Função para calcular a amplitude*/
void calculate_Extent(int* values, int *extent){
	i = 0;
	*extent = values[99] - values[0];
	printf("\t\t\t\tAMPLITUDE: %d \n",*extent);
}

/* Função para calcular a variância */
void calculate_Variance(int* values, float media, float *variance){
	float soma = 0.0;
	for (i = 0; i < QNT; i++){
        soma += pow((values[i] - media), 2);
	}
	*variance = soma/(QNT-1);
	printf("\t\t\t\tVARIANCIA: %.2f \n",*variance);
}

/*Função para calcular Desvio Padrão*/
void calculate_StandardDeviation(int* values, float variance, float *standardDeviation){
	*standardDeviation = sqrt(variance);
	printf("\t\t\t\tDESVIO PADRAO: %.2f \n",*standardDeviation);
}

/*Função para frequencia*/
void calculate_Frequency(int* values, int* frequencyAbs){
    int frequencyRel=0; int frequencyRelAc=0;

    for( i=0; i<k; i++){
        frequencyAbs[i] = 0;
	}

	for (i = 0; i < QNT; i++){
		if(values[i]>=0 && values[i]<2){
			frequencyAbs[0] = frequencyAbs[0] + 1;
		}else if(values[i]>=2 && values[i]<4){
			frequencyAbs[1] = frequencyAbs[1] + 1;
		}else if(values[i]>=4 && values[i]<6){
			frequencyAbs[2] = frequencyAbs[2] + 1;
		}else if(values[i]>=6 && values[i]<8){
			frequencyAbs[3] = frequencyAbs[3] + 1;
		}else if(values[i]>=8 && values[i]<10){
			frequencyAbs[4] = frequencyAbs[4] + 1;
		}
	}

	printf("\t\t______________________________________________________________________\n");
	printf("\t\t| CLASSES | FREQ. ABSOLUTA |FREQ. RELATIVA |FREQ. RELATIVA ACUMULADA |\n");
	printf("\t\t|_________|________________|_______________|_________________________|\n");

	for (i = 0; i < k; ++i){
		frequencyRel = (frequencyAbs[i]);
		frequencyRelAc += frequencyRel;
		switch(i){
			case 0:
				printf("\t\t| 0 |- 2  |       %d       |       %d %%    |            %d %%         |\n",frequencyAbs[i], frequencyRel, frequencyRelAc);
			break;
			case 1:
				printf("\t\t| 2 |- 4  |       %d       |       %d %%    |            %d %%         |\n",frequencyAbs[i], frequencyRel, frequencyRelAc);
			break;
			case 2:
				printf("\t\t| 4 |- 6  |       %d       |       %d %%    |            %d %%         |\n",frequencyAbs[i], frequencyRel, frequencyRelAc);
			break;
			case 3:
				printf("\t\t| 6 |- 8  |       %d       |       %d %%    |            %d %%         |\n",frequencyAbs[i], frequencyRel, frequencyRelAc);
			break;
			case 4:
				printf("\t\t| 8 |- 9  |       %d       |       %d %%    |            %d %%        |\n",frequencyAbs[i], frequencyRel, frequencyRelAc);
			break;
		}
		printf("\t\t|_________|________________|_______________|_________________________|\n");
	}
}
/*funcao pra os graficos*/
void generate_Graphics(int* values, int* frequencyAbs){
    int i, j, maior = 0;

	printf("\t\t\t\t\tHISTOGRAMA\n\n");

	for (i = 0; i < 5; ++i){
		if(frequencyAbs[i]>maior){
			maior = frequencyAbs[i];
		}
	}

	int temp = maior;

	for (j=0; j < maior ; j++){
        if(temp<10){
            printf("%d  |", temp);
        }else{
            printf("%d |", temp);
        }

		for (i = 0; i < 5; i++){
			if((frequencyAbs[i])<(maior-j)){
                printf("\t   \t");
			}else{
                printf("\t%c%c%c%c\t",219, 219, 219, 219);
			}
		}
		temp--;
        printf("\n");
	}

	printf("    ____________________________________________________________________________\n\n");
    for (i = 0; i < 5; i++){
        switch(i){
			case 0:
				printf("      [0 |- 2]      ",frequencyAbs[i]);
			break;
			case 1:
				printf("   [2 |- 4]     ",frequencyAbs[i]);
			break;
			case 2:
				printf("   [4 |- 6]     ",frequencyAbs[i]);
			break;
			case 3:
				printf("   [6 |- 8]     ",frequencyAbs[i]);
			break;
			case 4:
				printf("   [8 |- 9]     ",frequencyAbs[i]);
			break;
		}
    }
    printf("\n");
}
/*função para calcular assimetria*/
void calculate_Asymmetry(float *asymmetry, float media, float median, float standardDeviation){
	*asymmetry = (3*(media-median))/standardDeviation;

	printf("\t\t\t\tASSIMETRIA: %.2f \n",*asymmetry);
}

/*função para calcular percentil*/
float calculate_Percentile(int* values, int z){
	//printf("PERCENTIL: %d \n",values[k]);
	return values[z];
}

void calculate_Curtose(int* values, float *curtose){

	*curtose = (calculate_Percentile(values, 75) - calculate_Percentile(values, 25))/((calculate_Percentile(values, 90) - calculate_Percentile(values, 10)) * 2);
	printf("\t\t\t\tCURTOSE: %f \n",*curtose);
}

int main(){

	int i;
	int *values, extent, mode, test = 0, frequencyAbs, test2 = 0, test3 = 0;
	float media = 0, variance, weightedAverage, median, standardDeviation, asymmetry, curtose;

	/* alocação dinâmica */
	values = (int*) malloc(QNT*sizeof(int));
	if (values==NULL) {	//testando se a memoria é suficiente
		printf("Memoria insuficiente.\n");
		return 1;
	}

	/* alocação dinâmica */
	frequencyAbs = (int*) malloc(5*sizeof(int));
	if (frequencyAbs==NULL) {	//testando se a memoria é suficiente
		printf("Memoria insuficiente.\n");
		return 1;
	}

    int option = 0;

	do{
        puts("\n\n\n\n\n");
		printf("\t\t\t\t\t\t\tMENU\n");
		puts(" ");
		printf("\t\t\t\t[0] - Gerar os numeros\n");
		printf("\t\t\t\t[1] - Mostrar os numeros\n");
		printf("\t\t\t\t[2] - Cacular Medidas de Centralidade\n");
		printf("\t\t\t\t[3] - Calcular Medidas de Dispersao \n");
		printf("\t\t\t\t[4] - Calcular Frequencias \n");
		printf("\t\t\t\t[5] - Calcular Medidas de Assimetria e Curtose\n");
		printf("\t\t\t\t[6] - Gerar Graficos\n");
		printf("\t\t\t\t[7] - Sair\n");
        puts(" ");
		scanf("%d", &option);
		switch(option){
			case 0:
				generate_values(values);
				puts("\n\t\t\tNumeros gerados com sucesso\n");
				test++;
				puts("\n");
                getchar();
                getchar();
                system("cls");
				break;
			case 1:
				if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
				    order_values(values);
					values_print(values);
					puts(" ");
				}
				puts("\n");
                getchar();
                getchar();
                system("cls");
				break;
			case 2:
				if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
					calculate_Average(values, &media);
					calculate_WeightedAverage(values, &weightedAverage);
					calculate_Median(values, &median);
					calculate_Mode(values, &mode);
				}
				puts("\n");
                getchar();
                getchar();
                system("cls");
				break;
			case 3:
				if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
					if(media == 0){
						printf("\nGere a media primeiro\n");
					}else{
						calculate_Extent(values, &extent);
						calculate_Variance(values, media, &variance);
						calculate_StandardDeviation(values, variance, &standardDeviation);
						test3++;
					}
				}
				puts("\n");
                getchar();
                getchar();
                system("cls");
				break;
            case 4:
            	if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
                	calculate_Frequency(values, frequencyAbs);
                	test2++;
                }
                puts("\n");
                getchar();
                getchar();
                system("cls");
                break;
            case 5:
            	if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
					if(test3==0){
						printf("\nCalcule as outras medidas primeiro\n");
					}else{
						calculate_Asymmetry(&asymmetry, median, media, standardDeviation);
						calculate_Curtose(values, &curtose);
					}
                }
                puts("\n");
                getchar();
                getchar();
                system("cls");
                break;
            case 6:
                if(test==0){
					printf("\nGere os numeros primeiro\n");
				}else{
				    if(test2==0){
                        printf("\nCalcule a frequencia primeiro\n");
                    }else{
                        generate_Graphics(values, frequencyAbs);
                    }
                }
                puts("\n");
                getchar();
                getchar();
                system("cls");
                break;
			case 7:
				exit(0);
				break;
			default:
				printf("\nOpcao Invalida!\n");
				puts("\n");
                getchar();
                getchar();
                system("cls");
		}
	}while(option!=-1);

	/* libera memória */
	free(values);

	return 0;
}
