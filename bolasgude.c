#include <stdio.h>
#include <stdlib.h>



void Quick(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}
int Search(int vetor[],int quest,int pos){
	int resp;
	//printf("quest: %d||vetor[%d]:%d\n",quest,pos,vetor[pos] );
	for(int i = vetor[pos];vetor[pos] == quest && pos>=0;pos--){
		resp = pos;
	}
	//printf("pos return:%d\n",pos );
	return resp;

}
int binSearch( int vetor[], int quest,int N){
    int pos,meio;
    int inicio = 0;
    int fim = N-1;
    while(inicio<=fim){
        meio = (inicio+fim)/2;
        //printf("vetor[meio]:%d\n",vetor[meio] );
        //printf("quest%d\n",quest);

        if(vetor[meio]==quest){
        	pos = Search(vetor,quest,meio);
        	//printf("return:%d\n",pos+1 );
            return pos+1;
        }
        if(quest<vetor[meio]){
            fim = meio-1;
            
        }else if(quest>vetor[meio]){
            inicio = meio+1;
        }
    }
    return -1;
    
}


int main(){
	int vetor[10001];
	int N,Q,aux,count,quest,pos,caso;
	caso = 1;
	do{
		scanf("%d %d",&N,&Q);
		aux = N;
		count = 0;
		while(aux){
			scanf("%d",&vetor[count]);
			count++;
			aux--;
		}
		Quick(vetor,0,N-1);
		/*
		for (int i = 0;i<N;i++){
			printf("%d\n",vetor[i]);
		}
		*/
		aux = Q;
		
		while(aux){	
			scanf("%d",&quest);
			
			pos = binSearch(vetor,quest,N);
			if(aux == Q){
				printf("CASE %d:\n",caso );
			}
			if(pos >= 0){
				printf("%d found at %d\n",quest,pos );
			}
			else{
				printf("%d not found\n",quest);
			}
			aux--;
		}

		caso++;
	}while(N>0 || Q>0);

	return 0;

}
