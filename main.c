#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função auxiliar para converter um caractere hexadecimal para decimal
int hex_to_decimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1; // Retorna -1 caso o caractere não seja hexadecimal válido
    }
}

// Função para converter a string hexadecimal em valores ASCII
void decodificar_mensagem(char mensagem_hex[100]) {
    int i = 0; // Índice para percorrer a string hexadecimal

    while (mensagem_hex[i] != '\0' && mensagem_hex[i + 1] != '\0') {
        // Converte dois caracteres hexadecimais em um valor decimal
        int primeiro_digito = hex_to_decimal(mensagem_hex[i]);
        int segundo_digito = hex_to_decimal(mensagem_hex[i + 1]);

        // Verifica se os caracteres são válidos
        if (primeiro_digito == -1 || segundo_digito == -1) {
            break; // Se encontrar caracteres inválidos, interrompe
        }

        // Calcula o valor ASCII
        int valor_ascii = primeiro_digito * 16 + segundo_digito;

        // Se o valor for 0x00 (caractere nulo), interrompe o loop
        if (valor_ascii == 0) {
            break;
        }

        // Imprime o caractere correspondente
        printf("%c", valor_ascii);

        // Avança para o próximo par de caracteres hexadecimais
        i += 2;
    }
    printf("\n");
}

int main() {
    
    // Exemplo de mensagem interceptada em hexadecimal (substitua conforme necessário)
    char mensagem_hex[100] = "566F6388732073C66F2076656E6365646F867265732C20766F63C3887320636FBE6E73656775656D2E002DC6C921B7B87FCF";  // "Hello World" em hexadecimal, seguido de 00 para encerrar

    // Decodificar a mensagem
    decodificar_mensagem(mensagem_hex);

    return 0;
}
