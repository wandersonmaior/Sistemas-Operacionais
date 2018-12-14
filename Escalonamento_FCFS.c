#include <stdio.h>

int main()
{
    int n, tempo_estouro[20],tempo_espera[20],tempo_resposta[20],tme=0,tmm=0,i,j;
    printf("Digite o numero total de processos (maximo 20):\n");  //Entrada de numero de processos
    scanf("%d", &n);
    printf("\nInsira o tempo de interrupcao do processo\n");

    for(i=0; i<n; i++)
    {
        printf("P[%d]:", i+1);
        scanf("%d",&tempo_estouro[i]);
    }

    tempo_espera[0]=0;

    for(i=1; i<n; i++)
    {
        tempo_espera[i]=0;
        for(j=0; j<i; j++)
        {
            tempo_espera[i]+=tempo_estouro[j];
        }
    }

    printf("\nProcesso\tTempo Estouro\tTempo de espera\tTempo de resposta");
    for(i=0; i<n; i++)
    {
        tempo_resposta[i]=tempo_estouro[i]+tempo_espera[i];
        tme+=tempo_espera[i];
        tmm+=tempo_resposta[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i+1,tempo_estouro[i],tempo_espera[i],tempo_resposta[i]);
    }

    tme/=i;
    tmm/=i;
    printf("\n\nTempo Medio de Espera: %d", tme);
    printf("\n\nTempo Medio de Retorno: %d\n", tmm);
    return 0;
}
