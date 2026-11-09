#include <stdio.h>

#define LABS 4
#define DIAS 7

const char *dias[DIAS] = {"seg", "ter", "qua", "qui", "sex", "sab", "dom"};
const char *laboratorios[LABS] = {"Lab A", "Lab B", "Lab C", "Lab D"};

/* Consumo total de todos os laboratorios na semana */
float calcular_total(float consumo[][DIAS], int laboratorios_qtd)
{
    float total = 0;
    for (int i = 0; i < laboratorios_qtd; i++)
        for (int j = 0; j < DIAS; j++)
            total += consumo[i][j];
    return total;
}

/* Media semanal de um laboratorio (percorre uma LINHA) */
float calcular_media_laboratorio(float consumo[][DIAS], int laboratorio)
{
    float soma = 0;
    for (int j = 0; j < DIAS; j++)
        soma += consumo[laboratorio][j];
    return soma / DIAS;
}

/* Soma de um dia considerando todos os laboratorios (percorre uma COLUNA) */
float total_do_dia(float consumo[][DIAS], int laboratorios_qtd, int dia)
{
    float soma = 0;
    for (int i = 0; i < laboratorios_qtd; i++)
        soma += consumo[i][dia];
    return soma;
}

/* Retorna o indice do dia com maior consumo total */
int buscar_dia_maior_consumo(float consumo[][DIAS], int laboratorios_qtd)
{
    int melhor = 0;
    float maior = total_do_dia(consumo, laboratorios_qtd, 0);
    for (int j = 1; j < DIAS; j++)
    {
        float t = total_do_dia(consumo, laboratorios_qtd, j);
        if (t > maior)
        {
            maior = t;
            melhor = j;
        }
    }
    return melhor;
}

/* Retorna o indice do laboratorio com maior consumo semanal */
int buscar_laboratorio_maior_consumo(float consumo[][DIAS], int laboratorios_qtd)
{
    int melhor = 0;
    float maior = -1;
    for (int i = 0; i < laboratorios_qtd; i++)
    {
        float soma = 0;
        for (int j = 0; j < DIAS; j++)
            soma += consumo[i][j];
        if (soma > maior)
        {
            maior = soma;
            melhor = i;
        }
    }
    return melhor;
}

/* Conta registros estritamente acima do limite */
int contar_acima_limite(float consumo[][DIAS], int laboratorios_qtd, float limite)
{
    int contador = 0;
    for (int i = 0; i < laboratorios_qtd; i++)
        for (int j = 0; j < DIAS; j++)
            if (consumo[i][j] > limite)
                contador++;
    return contador;
}

/* Coordena todos os calculos e exibe o relatorio */
void gerar_relatorio(float consumo[][DIAS], const char *labs[],
                     const char *dias_semana[], int quantidade_laboratorios)
{
    printf("===== RELATORIO DE CONSUMO =====\n\n");

    printf("Consumo total geral: %.2f kWh\n\n",
           calcular_total(consumo, quantidade_laboratorios));

    for (int i = 0; i < quantidade_laboratorios; i++)
        printf("Media do %s: %.2f kWh\n", labs[i],
               calcular_media_laboratorio(consumo, i));

    int dia = buscar_dia_maior_consumo(consumo, quantidade_laboratorios);
    printf("\nDia com maior consumo total:\n");
    printf("%s - %.2f kWh\n", dias_semana[dia],
           total_do_dia(consumo, quantidade_laboratorios, dia));

    int lab = buscar_laboratorio_maior_consumo(consumo, quantidade_laboratorios);
    printf("\nLaboratorio com maior consumo semanal:\n");
    printf("%s - %.2f kWh\n", labs[lab],
           calcular_media_laboratorio(consumo, lab) * DIAS);

    printf("\nRegistros acima de 100 kWh: %d\n",
           contar_acima_limite(consumo, quantidade_laboratorios, 100));
}

int main(void)
{
    float consumo[LABS][DIAS] = {
        {80, 90, 95, 110, 120, 100, 85},
        {75, 85, 90, 105, 115, 95, 80},
        {100, 110, 120, 130, 125, 115, 105},
        {70, 80, 85, 90, 100, 95, 75}};

    gerar_relatorio(consumo, laboratorios, dias, LABS);
    return 0;
}
