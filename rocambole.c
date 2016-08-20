#include<stdio.h>
#include<stdlib.h>

void main(){

	int totalLinha, totalColuna, linha, coluna, i, j, x;

	printf("\nDigite o numero de linhas: ");
	scanf("%d", &totalLinha);

	printf("\nDigite o numero de colunas: ");
	scanf("%d", &totalColuna);

	int matriz[totalLinha][totalColuna];

	printf("\nDigite a matriz.\n");
	
	for(i=0;i<totalLinha;i++){
		for(j=0;j<totalColuna;j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	i=0;
	linha=totalLinha-1;
	coluna=totalColuna-1;

	for(j=0;j<totalColuna;j++){
		printf("[%d][%d]: %d \n", i, j, matriz[i][j]);
	}
	j--;
	while(1){
		x=i+1;
		for(i=i+1;i<(x+linha);i++){
			printf("[%d][%d]: %d \n", i, j, matriz[i][j]);
		}
		i--; 
		linha--;
		if(coluna == 0)
			break;
		x=j-1;
		for(j=j-1;j>(x-coluna);j--){
			printf("[%d][%d]: %d \n", i, j, matriz[i][j]);
		}
		j++;
		coluna--;
		if(linha == 0)
			break;
		x=i-1;
		for(i=i-1;i>(x-linha);i--){
			printf("[%d][%d]: %d \n", i, j, matriz[i][j]);
		}
		i++;
		linha--;
		if(coluna == 0)
			break;
		x=j+1;
		for(j=j+1;j<(x+coluna);j++){
			printf("[%d][%d]: %d \n", i, j, matriz[i][j]);
		}
		j--;
		coluna--;
		if(linha == 0)
			break;
	}

	printf("\n");

}
