/**

    @file      Pacientes.h
    @brief
    @details   ~
    @author    Joao Barbosa
    @date      21.12.2023
    @copyright Joao Barbosa, 2023. All right reserved.

*/
#pragma once
#include "global.h"
#include <stdbool.h>
#define N 20

/**
 * @brief Estrutura que representa um paciente.
 *
 * Esta estrutura armazena informacoes sobre um paciente, incluindo um identificador unico,
 * nome e numero de telefone.
 */

typedef struct Paciente {
    int numPaciente; /**< Identificador unico do paciente. */
    char nome[N]; /**< Nome do paciente. O tamanho maximo e definido por N. */
    char telemovel[N]; /**< Numero de telefone do paciente. O tamanho maximo e definido por N. */
} Paciente;

/**
 * @brief Estrutura que representa informacoes sobre a dieta de um paciente.
 *
 * Esta estrutura armazena dados sobre a dieta de um paciente, incluindo o numero do paciente,
 * a data da dieta, o tipo de refeicao, o alimento consumido e a quantidade de calorias.
 */
typedef struct Dieta {
    int numPaciente; /**< Numero do paciente associado a dieta. */
    char data[N]; /**< Data da dieta. O tamanho maximo e definido por N. */
    char refeicao[N]; /**< Tipo de refeicao associado a dieta. O tamanho maximo e definido por N. */
    char alimento[N]; /**< Alimento consumido na dieta. O tamanho maximo e definido por N. */
    int calorias; /**< Quantidade de calorias do alimento consumido na dieta. */
} Dieta;


/**
 * @brief Estrutura que representa um plano nutricional para um paciente.
 *
 * Esta estrutura armazena informacoes sobre um plano nutricional para um paciente,
 * incluindo o numero do paciente, a data do plano, o tipo de refeicao, e os valores
 * maximo e minimo de calorias permitidas na refeicao.
 */

typedef struct PlanoNutricional {
    int numPaciente; /**< Numero do paciente associado ao plano nutricional. */
    char data[N]; /**< Data do plano nutricional. O tamanho maximo e definido por N. */
    char refeicao[N]; /**< Tipo de refeicao associado ao plano nutricional. O tamanho maximo e definido por N. */
    int calMAX; /**< Valor maximo de calorias permitidas na refeicao do plano. */
    int calMIN; /**< Valor minimo de calorias permitidas na refeicao do plano. */
} PlanoNutricional;



#pragma region Pacientes que ultrapassam determinadas calorias 
int numPacientesUltrapassaram(Dieta dieta[], int tamanhoDieta, int valorUltrapassar, char dataInicio[], char dataFim[]);

#pragma endregion

#pragma region Pacientes fora do limite 
void PacientesForaLimites(PlanoNutricional plano[], int tamanhoPlano, Dieta dieta[], int tamanhoDieta, char dataInicio[], char dataFim[]);

#pragma endregion

#pragma region Listar plano
void listarPlano(int numPaciente, PlanoNutricional plano[], int tamanhoPlano, char dataInicio[], char dataFim[]);

#pragma endregion

#pragma region Media de calorias consumidas por Paciente em determinada refeicao
float MediaCalorias(int numPaciente, Dieta dieta[], int tamanhoDieta, char refeicao[], char dataInicio[], char dataFim[]);

#pragma endregion

#pragma region Tabela
void MostrarTabela(Dieta dieta[], int tamanhoDieta, PlanoNutricional plano[], int tamanhoPlano, Paciente pacientes[], int tamanhoPacientes, char inicio[], char fim[]);

#pragma endregion


