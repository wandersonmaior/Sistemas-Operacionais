#include <stdio.h>

int main(){
    int n, tempo_estouro[20],tempo_espera[20],tempo_resposta[20],tme=0,tmm=0,i,j;
    int lista_bt_ord[20],aux = 0,k=0,procura_processo=0;
    printf("Digite o numero total de processos (maximo 20):");  //Entrada de numero de processos
    scanf("%d", &n);
    printf("\nInsira o tempo de interrupcao do processo \n");

    for(i=0;i<n;i++){
        printf("P[%d]:", i+1);
        scanf("%d",&tempo_estouro[i]);
    }

    lista_bt_ord[0] = tempo_estouro[0];
    for(i=1; i<n; i++){
        for(j=0; j<=i; j++){
            if(tempo_estouro[i] < lista_bt_ord[j]){
                for(k=i; k>j; k--){
                    lista_bt_ord[k] = lista_bt_ord[k-1];
                }
                lista_bt_ord[j] = tempo_estouro[i];
                break;
            }else if(j==i){
                lista_bt_ord[j] = tempo_estouro[i];
                break;
            }
        }
    }

    tempo_espera[0]=0;

    for(i=1;i<n;i++){
        tempo_espera[i]=0;
        for(j=0;j<i;j++){
            tempo_espera[i]+=lista_bt_ord[j];
        }
    }



    printf("\nProcesso\tTempo Estouro\tTempo de espera\tTempo de resposta");

    for(i=0;i<n;i++){
       tempo_resposta[i]=lista_bt_ord[i]+tempo_espera[i];
        tme+=tempo_espera[i];
        tmm+=tempo_resposta[i];
        procura_processo = lista_bt_ord[i];
        for(j=0; j<n; j++){
            if(procura_processo == tempo_estouro[j]){
                procura_processo = j;
                break;
            }
        }
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", procura_processo+1,lista_bt_ord[i],tempo_espera[i],tempo_resposta[i]);
    }

    tme/=i;
    tmm/=i;
    printf("\n\nTempo Medio de Espera: %d", tme);
    printf("\nTempo Medio de Retorno: %d\n\n", tmm);
    return 0;
}
