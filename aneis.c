#include <stdio.h>

int main(){
	int tamanho;
	scanf("%d",&tamanho);
	int vetor[19];
	int var;
	for(int i = 0;i<20;i++){
		vetor[i]=0;
	}
	int maior = 0;
	for (int i = 0;i<tamanho;i++){
		scanf("%d",&var);
		vetor[var-11]+=1;
		if(vetor[var-11] > maior){
			maior = vetor[var-11];
		}
	}
	printf("%d\n",maior);



	return 0;
}
