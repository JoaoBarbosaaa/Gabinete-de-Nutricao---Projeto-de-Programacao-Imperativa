/**

    @file      GestaoFicheiros.h
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

#pragma region Pacientes
int ImportarPacientes(char nomeFiceiro[], Paciente pacientes[], int maximoPacientes);
bool ConverterPacienteBinario(char nomeFicheiroBinario[], Paciente pacientes[], int n);

#pragma endregion

#pragma region Dieta
int ImportarInfoDieta(char nomeFicheiro[], Paciente dieta[], int tamanho);
bool ConverterInfoDietaBinario(char nomeFicheiroBinario[], Dieta dieta[], int tamanho);

#pragma endregion

#pragma region Plano
int ImportarPlanoNutricional(char nomeFicheiro[], Paciente plano[], int tamanho);
bool ConverterPlanoNutricionalBinario(char nomeFicheiroBinario[], PlanoNutricional plano[], int tamanho);

#pragma endregion