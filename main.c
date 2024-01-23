#include <stdio.h>

void realizarSaque(int valor, int* cedulas, int tam){
    //inicializando vetor quant[]
    int quant[tam];
    for(int i=0; i<tam; i++)quant[i]=0;

    //Verificando se é um valor válido
    if(valor<=0){
        printf("Informe um valor maior que 0");
        return;
    }else if(valor>1){
        for(int i=0; i<tam; i++){
            if(valor<44 && valor>=40 && (valor%2)!=0){
                quant[3] += 1;
                valor = valor - cedulas[3];
            }else if(valor<24 && valor>=cedulas[3] && (valor%2)!=0){
                quant[4] += 1;
                valor = valor - cedulas[4];
            }else if(valor<14 && valor>=cedulas[4] && (valor%2)!=0){
                quant[5] += 1;
                valor = valor - cedulas[5];
            }else if(valor<10 && valor>=cedulas[i] && (valor%2)!=0){
                quant[i] = valor / cedulas[i];
                valor = valor - cedulas[5];
            }else if(valor<10 && valor>=cedulas[5] && (valor%2)==0){
                quant[6] = valor / cedulas[6];
                valor = valor % cedulas[6];
            }else if(valor>=cedulas[i]){
               quant[i] = valor / cedulas[i];
               valor = valor % cedulas[i];
            }
        }
    }
    
    if(valor!=0){
        printf("Nao e possivel sacar o valor solicitado\n");
        return;
    }

    //Imprimindo resultado
    for(int i=0; i<tam; i++)printf("%d cedula(s) de %d.00\n", quant[i], cedulas[i]);
}

int main(int argc, char* argv[]) {
    int valor=0, tam=7;
    int cedulas[]={200, 100, 50, 20, 10, 5, 2};
    scanf("%d", &valor);
    realizarSaque(valor, &cedulas[0], tam);
    return 0;
}


