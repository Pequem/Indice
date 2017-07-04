#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"
#include "hash.h"

#define MAXALFABETO 255
#define TRUE 1
#define FALSE 0

typedef short TipoAlfabeto[MAXALFABETO + 1];
FILE *ArqTxt, *ArqAlf;
TipoAlfabeto Alfabeto;
char Palavra[256];
char Linha[256];
int i;
short aux;

void DefineAlfabeto(short *Alfabeto) {
    char Simbolos[MAXALFABETO + 1];
    int i;
    int CompSimbolos;
    char *TEMP;

    for (i = 0; i <= MAXALFABETO; i++) {
        Alfabeto[i] = FALSE;
    }

    fgets(Simbolos, MAXALFABETO + 1, ArqAlf);
    TEMP = strchr(Simbolos, '\n');

    if (TEMP != NULL) *TEMP = 0;
    {
        CompSimbolos = strlen(Simbolos);
    }

    for (i = 0; i < CompSimbolos; i++) {
        Alfabeto[Simbolos[i] + 127] = TRUE;
    }

    Alfabeto[0] = FALSE; /* caractere de codigo zero: separador */
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Modelo: %s teste.txt alfabeto.txt\n", argv[0]);
        return 1;
    }

    ArqTxt = fopen(argv[1], "r");
    ArqAlf = fopen(argv[2], "r");

    DefineAlfabeto(Alfabeto); /* Le alfabeto definido em arquivo */
    aux = FALSE;

    while (fgets(Linha, 256, ArqTxt) != NULL) {
        for (i = 1; i <= strlen(Linha); i++) {
            if (Alfabeto[Linha[i - 1] + 127]) {
                sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
                aux = TRUE;
            } else if (aux) {
                puts(Palavra);
                *Palavra = '\0';
                aux = FALSE;
            }
        }
    }
    
    TipoDicionario keywords = Inicializa(keywords);
    TipoItem palavra;
    
    FILE *keywords = fopen("key.txt", "r+");

    if (aux) {
        puts(Palavra);
        InicializaTipoItem(palavra);
        *Palavra = '\0';
    }
    
    
    
    
    
    while (fscanf(keywords, "%s", &palavra))
    {
        InicializaTipoItem(palavra);
        
    }

    fclose(ArqTxt);
    fclose(ArqAlf);
    return 0;
}
