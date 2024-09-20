#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função que calcula f(x, b) de acordo com os coeficientes fornecidos
double f_x_b(int x, double b) {
    // Coeficientes fornecidos
    double a0 = 186752;
    double a1 = -148235;
    double a2 = 34504.9;
    double a3 = -3509.1;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    // Calculando f(x, b)
    double f = a0 +
               (a1 + b) * x +
               a2 * pow(x, 2) +
               a3 * pow(x, 3) +
               a4 * pow(x, 4) +
               a5 * pow(x, 5) +
               a6 * pow(x, 6) +
               a7 * pow(x, 7);

    return f;
}

// Função para converter a string hexadecimal em valores ASCII de acordo com a tabela CP437
void decodificar_mensagem(const char *mensagem_hex, double b) {
    int x = 1; // Posição do caractere (inicia em 1)
    int i = 0; // Índice para percorrer a string hexadecimal

    while (mensagem_hex[i] != '\0' && mensagem_hex[i + 1] != '\0') {
        // Pega os dois caracteres hexadecimais e converte para um valor decimal
        char hex_char[3] = {mensagem_hex[i], mensagem_hex[i + 1], '\0'};
        int valor_ascii = (int)strtol(hex_char, NULL, 16);

        // Se o valor for 0x00 (caractere nulo), interrompe o loop
        if (valor_ascii == 0) {
            break;
        }

        // Verifica se o caractere na posição x é válido
        double resultado_funcao = f_x_b(x, b);

        // Se o resultado da função for positivo, consideramos o caractere como válido
        if (resultado_funcao > 0) {
            printf("%c", valor_ascii); // Imprime o caractere correspondente
        }

        // Avança para o próximo par de caracteres hexadecimais
        i += 2;
        x++; // Incrementa a posição do caractere
    }
    printf("\n");
}

int main() {
    // Exemplo de mensagem interceptada em hexadecimal (substitua conforme necessário)
    const char *mensagem_hex = "48656c6c6f20576f726c6400";  // "Hello World" em hexadecimal, seguido de 00 para encerrar
    double b = 10; // Exemplo de valor de b fornecido pelo agente

    // Decodificar a mensagem
    decodificar_mensagem(mensagem_hex, b);

    return 0;
}
