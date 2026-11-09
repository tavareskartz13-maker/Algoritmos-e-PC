# Aula 10.1 - Desafio: Monitoramento de consumo de energia de laboratórios

## Enunciado

Uma universidade deseja acompanhar o consumo de energia elétrica de seus laboratórios de informática. Durante uma semana foi registrado o consumo diário, em kWh, de quatro laboratórios (Lab A, Lab B, Lab C e Lab D), armazenado em uma matriz (linhas = laboratórios, colunas = dias da semana).

O programa deve determinar:

1. o consumo total geral da semana;
2. o consumo médio de cada laboratório;
3. o dia com maior consumo total (considerando todos os laboratórios);
4. o laboratório com maior consumo total na semana;
5. quantos registros ficaram acima de 100 kWh.

## Objetivo

Praticar a modularização de um programa em C, dividindo as responsabilidades em funções e percorrendo matrizes (por linha, por coluna e por todos os elementos).

## Descrição da solução

| Função | Responsabilidade |
|---|---|
| `calcular_total` | Soma todos os elementos da matriz |
| `calcular_media_laboratorio` | Média de uma linha (um laboratório) |
| `total_do_dia` | Soma de uma coluna (um dia) |
| `buscar_dia_maior_consumo` | Retorna o índice do dia com maior total |
| `buscar_laboratorio_maior_consumo` | Retorna o índice do laboratório com maior total |
| `contar_acima_limite` | Conta registros estritamente acima de um limite |
| `gerar_relatorio` | Coordena as funções e imprime o relatório |

A `main()` apenas declara a matriz e chama `gerar_relatorio()`. As constantes `LABS` e `DIAS` (`#define`) evitam valores fixos nas funções, e os vetores `dias[]` e `laboratorios[]` identificam os nomes nos resultados.

## Como compilar e executar

```bash
gcc -Wall -o consumo_energia consumo_energia.c
./consumo_energia
```

## Saída obtida

```
===== RELATORIO DE CONSUMO =====

Consumo total geral: 2725.00 kWh

Media do Lab A: 97.14 kWh
Media do Lab B: 92.14 kWh
Media do Lab C: 115.00 kWh
Media do Lab D: 85.00 kWh

Dia com maior consumo total:
sex - 460.00 kWh

Laboratorio com maior consumo semanal:
Lab C - 805.00 kWh

Registros acima de 100 kWh: 10
```

## Observações importantes

- Na saída esperada do enunciado consta **9** registros acima de 100 kWh, mas a contagem correta para os dados de teste é **10**: Lab A tem 2 (110 e 120), Lab B tem 2 (105 e 115), Lab C tem 6 (110, 120, 130, 125, 115 e 105) e Lab D tem 0. Valores iguais a 100 não são contados, pois o critério é "acima de 100 kWh".
- Os demais resultados coincidem com a saída esperada.
- O desafio extra (constantes `LABS`/`DIAS` e a função `gerar_relatorio`) foi implementado.
