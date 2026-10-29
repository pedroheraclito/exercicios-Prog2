#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int tamanhoString(char *str);

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void copiaString(char *src, char *dest);

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void converteMaisculaString(char *str);

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void converteMinusculoString(char *str);

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void inverteString(char *str);

#endif