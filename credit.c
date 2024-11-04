#include <stdio.h>
#include <math.h>
#include "../libs/getInputs/getInputs.h" // Biblioteca personalizada 


int main(void) {
    long long numero = get_long_long("Numero: ");
    long long numeroOriginal = numero;
    int soma = 0, multiplicar = 0, digito;

    do {
        // Extrair o último dígito
        digito = numero % 10;

        // Se for um dígito em posição de multiplicação, multiplique-o por 2
        if (multiplicar) {
            digito *= 2;
            // Se o resultado for maior que 9, some os dígitos (exemplo: 12 -> 1 + 2 = 3)
            if (digito > 9) {
                digito = (digito % 10) + 1; // Soma os dígitos do produto
            }
        }

        // Adiciona o dígito (modificado ou não) à soma total
        soma += digito;

        // Remove o último dígito e alternar a posição de multiplicação
        numero /= 10;
        multiplicar = !multiplicar;

    } while (numero > 0);

    // Verifica se o total é divisível por 10
    if (soma % 10 == 0) {
        // Verifica o tipo de cartão
        int num_digitos = 0;
        long long digitoCartao = numeroOriginal;

        while (digitoCartao > 0) {
            digitoCartao /= 10;
            num_digitos++;
        }
        // Identifica o tipo do cartão
        if ((num_digitos == 13 || num_digitos == 16) && (numeroOriginal / (long long)pow(10, num_digitos - 1) == 4))  {
            printf("Numero valido!\n Tipo: Visa\n");
        }else if (num_digitos == 16 && (numeroOriginal / (long long)pow(10, num_digitos - 2) >= 51 && numeroOriginal / (long long)pow(10, num_digitos - 2) <= 55)) {
            printf("Numero valido!\n Tipo: MasterCard\n");
        } else if ((num_digitos == 15 && (numeroOriginal / (long long)pow(10, num_digitos - 2) == 34 || numeroOriginal / (long long)pow(10, num_digitos - 2) == 37))) {
            printf("Numero valido!\n Tipo: American Express\n");
        } else {
            printf("Numero invalido!\n");
        }
    } else {
        printf("Numero invalido!\n");
    }
    return 0;
}
