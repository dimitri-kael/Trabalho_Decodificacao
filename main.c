#include <stdio.h>
#include <stdlib.h>

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

// Função para converter a string hexadecimal em valores ASCII e ignorar caracteres inválidos
void decodificar_mensagem(char mensagem_hex[100]) {
    int i = 0; // Índice para percorrer a string hexadecimal

    while (mensagem_hex[i] != '\0' && mensagem_hex[i + 1] != '\0') {
        // Converte dois caracteres hexadecimais em um valor decimal
        int primeiro_digito = hex_to_decimal(mensagem_hex[i]);
        int segundo_digito = hex_to_decimal(mensagem_hex[i + 1]);

        // Verifica se ambos os caracteres são válidos
        if (primeiro_digito == -1 || segundo_digito == -1) {
            // Ignora caracteres inválidos e avança para o próximo par
            i++;
            continue;
        }

        // Calcula o valor ASCII
        int valor_ascii = primeiro_digito * 16 + segundo_digito;

        // Se o valor for 0x00 (caractere nulo), interrompe o loop
        if (valor_ascii == 0) {
            break;
        }

        // Verifica se o caractere está na tabela ASCII imprimível ou é um caractere acentuado comum
        if ((valor_ascii >= 32 && valor_ascii <= 126) || 
            (valor_ascii == 128 || valor_ascii == 131 || valor_ascii == 135 || valor_ascii == 136 || valor_ascii == 145 ||
             valor_ascii == 146 || valor_ascii == 157 || valor_ascii == 160 || valor_ascii == 162 || valor_ascii == 163 ||
             valor_ascii == 167 || valor_ascii == 198 || valor_ascii == 199 || valor_ascii == 200 || valor_ascii == 201 ||
             valor_ascii == 202 || valor_ascii == 203 || valor_ascii == 205 || valor_ascii == 213 || valor_ascii == 214 ||
             valor_ascii == 217 || valor_ascii == 225 || valor_ascii == 227 || valor_ascii == 228 || valor_ascii == 229 ||
             valor_ascii == 231 || valor_ascii == 233 || valor_ascii == 234 || valor_ascii == 235 || valor_ascii == 237 ||
             valor_ascii == 243 || valor_ascii == 245 || valor_ascii == 246 || valor_ascii == 250 || valor_ascii == 253)) {
            printf("%c", valor_ascii); // Imprime caracteres válidos
        }

        // Avança para o próximo par de caracteres hexadecimais
        i += 2;
    }
    printf("\n");
}

int main() {
    // Mensagem interceptada em hexadecimal (a que você forneceu)
    char mensagem_hex[100] = "566F6388732073C66F2076656E6365646F867265732C00566F6388732073C66F2076656E6365646F867265732C00332C2C2C";

    // Decodificar a mensagem
    decodificar_mensagem(mensagem_hex);

    return 0;
}
