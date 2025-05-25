/**

	@file      funcoes.c
	@brief
	@details   ~
	@author    Joao Barbosa
	@date      21.12.2023
	@copyright Joao Barbosa, 2023. All right reserved.

**/
#include "global.h"
#include <stdio.h>
#pragma warning (disable: 4996)


#pragma region Pacientes que ultrapassam determinadas calorias 

/**
 * @brief Conta o numero de pacientes cujas dietas ultrapassaram um valor especifico de calorias em um intervalo de datas.
 *
 * Esta funcao percorre um array de dietas e conta o numero de pacientes cujas dietas ultrapassaram um determinado valor de calorias
 * dentro de um intervalo de datas especifico.
 *
 * @param dieta Um array de dietas contendo as informacoes caloricas.
 * @param tamanhoDieta O numero de elementos no array de dietas.
 * @param valorUltrapassar O valor de calorias a ser comparado para determinar a ultrapassagem.
 * @param dataInicio A data de inicio do intervalo desejado no formato "DD-MM-AAAA".
 * @param dataFim A data de fim do intervalo desejado no formato "DD-MM-AAAA".
 *
 * Caso pelo menos uma das datas nao esteja dentro do intervalo a funcao retorna -1.
 * 
 * @return Retorna o numero de pacientes cujas dietas ultrapassaram o valor especificado no intervalo de datas.
 */

int numPacientesUltrapassaram(Dieta dieta[], int tamanhoDieta, int valorUltrapassar, char dataInicio[], char dataFim[]) {

	bool encontrouDataInicio = false;
	bool encontrouDataFim = false;

	for (int j = 0; j < tamanhoDieta; j++) {
		if (strcmp(dieta[j].data, dataInicio) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
			encontrouDataInicio = true;
		}
		if (strcmp(dieta[j].data, dataFim) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
			encontrouDataFim = true;
		}
	}
	if (!(encontrouDataInicio && encontrouDataFim)) {
		return -1; 
	}

	int contador = 0;
	bool pacientesContados[MAX_PACIENTES] = { false };

	for (int i = 0; i < tamanhoDieta; i++) {
		if (strcmp(dieta[i].data, dataInicio) >= 0 && strcmp(dieta[i].data, dataFim) <= 0 &&
			dieta[i].calorias > valorUltrapassar && !pacientesContados[dieta[i].numPaciente - 1]) {
			contador++;
			pacientesContados[dieta[i].numPaciente - 1] = true;
		}
	}
	return contador;
}


#pragma endregion


#pragma region Pacientes fora do limite 

/**
 * @brief Identifica e exibe os numeros dos pacientes cujas dietas estao fora dos limites do plano nutricional em um intervalo de datas.
 *
 * Esta funcao compara as informacoes de plano nutricional com as informacoes de dieta e identifica os pacientes cujas dietas
 * ultrapassam os limites especificados no plano nutricional dentro de um intervalo de datas especifico. Em seguida, exibe os numeros
 * desses pacientes em ordem decrescente.
 *
 * @param plano Um array de planos nutricionais contendo os limites caloricos.
 * @param tamanhoPlano O numero de elementos no array de planos nutricionais.
 * @param dieta Um array de dietas contendo as informacoes caloricas.
 * @param tamanhoDieta O numero de elementos no array de dietas.
 * @param dataInicio A data de inicio do intervalo desejado no formato "DD-MM-AAAA".
 * @param dataFim A data de fim do intervalo desejado no formato "DD-MM-AAAA".
 *
 * @return Retorna true se a operacao for bem-sucedida e false se o tamanho de dieta ou plano for nao positivo.
 */


void PacientesForaLimites(PlanoNutricional plano[], int tamanhoPlano, Dieta dieta[], int tamanhoDieta, char dataInicio[], char dataFim[]) {
	printf("\n\n");
	if (tamanhoDieta <= 0 || tamanhoPlano <= 0) {
		printf("Erro: Arrays vazios.\n\n");
	}

	int numerosForaDeLimites[MAX_PACIENTES];
	int contador = 0;
	bool encontrouDataInicio = false;
	bool encontrouDataFim = false;

	for (int i = 0; i < tamanhoPlano; i++) {
		for (int j = 0; j < tamanhoDieta; j++) {
			if (dieta[j].numPaciente == plano[i].numPaciente) {
				if (strcmp(dieta[j].data, dataInicio) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
					encontrouDataInicio = true;
				}
				if (strcmp(dieta[j].data, dataFim) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
					encontrouDataFim = true;
				}
			}
		}

		if (encontrouDataInicio && encontrouDataFim) {
			bool pacienteForaDosLimites = false;

			for (int j = 0; j < tamanhoDieta; j++) {
				if (strcmp(plano[i].data, dataInicio) >= 0 && strcmp(plano[i].data, dataFim) <= 0 &&
					strcmp(dieta[j].data, plano[i].data) == 0) {

					if (plano[i].numPaciente == dieta[j].numPaciente &&
						strcmp(plano[i].refeicao, dieta[j].refeicao) == 0 &&
						(plano[i].calMAX < dieta[j].calorias || plano[i].calMIN > dieta[j].calorias)) {
						pacienteForaDosLimites = true;
						break;
					}
				}
			}

			if (pacienteForaDosLimites) {
				numerosForaDeLimites[contador] = plano[i].numPaciente;
				contador++;
			}
		}
		encontrouDataInicio = false;
		encontrouDataFim = false;
	}

	if (contador > 0) {
		for (int i = 0; i < contador - 1; i++) {
			for (int j = i + 1; j < contador; j++) {
				if (numerosForaDeLimites[i] < numerosForaDeLimites[j]) {
					int k = numerosForaDeLimites[i];
					numerosForaDeLimites[i] = numerosForaDeLimites[j];
					numerosForaDeLimites[j] = k;
				}
			}
		}

		printf("Números de paciente fora de limites (ordenados por ordem decrescente):\n");
		for (int i = 0; i < contador; i++) {
			printf("%d\n", numerosForaDeLimites[i]);
		}
	}
	else {
		printf("Erro: Pelo menos uma datas não foi encontrada no intervalo especificado.\n");
	}

	printf("\n\n");
}






#pragma endregion


#pragma region Listar plano
/**
 * @brief Lista o plano nutricional de um paciente para um intervalo de datas especifico.
 *
 * Esta funcao percorre um array de planos nutricionais e exibe as informacoes de refeicao, maximo e minimo de calorias
 * para um paciente especifico durante um intervalo de datas especificado.
 *
 * @param numPaciente O numero do paciente para o qual o plano nutricional sera listado.
 * @param plano Um array de planos nutricionais contendo as informacoes caloricas.
 * @param tamanhoPlano O numero de elementos no array de planos nutricionais.
 * @param dataInicio A data de inicio do intervalo desejado no formato "DD-MM-AAAA".
 * @param dataFim A data de fim do intervalo desejado no formato "DD-MM-AAAA".
 */
void listarPlano(int numPaciente, PlanoNutricional plano[], int tamanhoPlano, char dataInicio[], char dataFim[]) {
	int encontrouDataInicio = 0;
	int encontrouDataFim = 0;

	printf("----------------------------Plano Nutricional----------------------------\n");
	printf("Plano nutricional para o paciente %d no período de %s a %s:\n", numPaciente, dataInicio, dataFim);

	for (int i = 0; i < tamanhoPlano; i++) {
		if (plano[i].numPaciente == numPaciente) {
			if (strcmp(plano[i].data, dataInicio) >= 0 && strcmp(plano[i].data, dataFim) <= 0) {
				encontrouDataInicio = 1;
			}
		}
	}

	for (int j = 0; j < tamanhoPlano; j++) {
		if (plano[j].numPaciente == numPaciente) {
			if (strcmp(plano[j].data, dataFim) >= 0 && strcmp(plano[j].data, dataFim) <= 0) {
				encontrouDataFim = 1;
			}
		}
	}

	if (encontrouDataInicio && encontrouDataFim) {
		for (int i = 0; i < tamanhoPlano; i++) {
			if (plano[i].numPaciente == numPaciente &&
				strcmp(plano[i].data, dataInicio) >= 0 && strcmp(plano[i].data, dataFim) <= 0) {
				printf("Refeição:%s; Máximo calorias:%d; Minimo calorias:%d\n", plano[i].refeicao, plano[i].calMAX, plano[i].calMIN);
			}
		}
	}
	else {
		printf("Não foi possível encontrar dados acerca do plano nutricional para o período especificado.\n");
	}

	printf("\n\n");
}

#pragma endregion


#pragma region Media de calorias consumidas por Paciente em determinada refeicao 
/**
 * @brief Calcula a media de calorias consumidas por refeicao por um paciente durante um periodo especifico.
 *
 * @param numPaciente Numero do paciente para o qual a media e calculada.
 * @param dieta Array de estruturas Dieta contendo informacoes sobre as dietas dos pacientes.
 * @param tamanhoDieta Tamanho do array de estruturas Dieta.
 * @param refeicao Tipo de refeicao para a qual a media e calculada.
 * @param dataInicio Data de inicio do periodo para o calculo da media.
 * @param dataFim Data de termino do periodo para o calculo da media.
 * @return A media de calorias consumidas por refeicao pelo paciente durante o periodo especificado.
 *
 * Esta funcao calcula a media de calorias consumidas por refeicao por um paciente especifico durante um periodo
 * determinado. Se as datas de inicio e termino nao estiverem no intervalo das datas presentes no array de dietas,
 * a funcao retorna 0. Caso contrario, ela calcula a media corretamente.
 */
float MediaCalorias(int numPaciente, Dieta dieta[], int tamanhoDieta, char refeicao[], char dataInicio[], char dataFim[]) {
	int soma = 0;
	int contador = 0;
	float media = 0;
	int encontrouDataInicio = 0;
	int encontrouDataFim = 0;

	for (int i = 0; i < tamanhoDieta; i++) {
		if (dieta[i].numPaciente == numPaciente && strcmp(dieta[i].refeicao, refeicao) == 0) {
			if (strcmp(dieta[i].data, dataInicio) >= 0 && strcmp(dieta[i].data, dataFim) <= 0) {
				soma += dieta[i].calorias;
				contador++;
			}
		}
	}

	for (int j = 0; j < tamanhoDieta; j++) {
		if (dieta[j].numPaciente == numPaciente) {
			if (strcmp(dieta[j].data, dataInicio) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
				encontrouDataInicio = 1;
			}
			if (strcmp(dieta[j].data, dataFim) >= 0 && strcmp(dieta[j].data, dataFim) <= 0) {
				encontrouDataFim = 1;
			}
		}
	}

	if (encontrouDataInicio && encontrouDataFim) {
		media = (float)soma / contador;
	}
	else {
		media = 0;
	}

	return media;
}




#pragma endregion


#pragma region Tabela
/**
 * @brief Calcula a media de calorias para um paciente e uma refeicao especificos.
 *
 * Esta funcao percorre um array de dietas, calcula a media de calorias consumidas em uma refeicao especifica
 * para um paciente especifico.
 *
 * @param dieta Um array de dietas contendo as informacoes caloricas.
 * @param tamanhoDieta O numero de elementos no array de dietas.
 * @param numPaciente O numero do paciente para o qual a media de calorias sera calculada.
 * @param refeicao A refeicao especifica para a qual a media de calorias sera calculada.
 *
 * @return Retorna a media de calorias consumidas na refeicao especificada para o paciente.
 *         Retorna 0 se nao houver dados de dieta correspondentes ao criterio especificado.
 */

float calcularMediaCalorias(Dieta dieta[], int tamanhoDieta, int numPaciente, char refeicao[]) {
	int totalCalorias = 0;
	int contador = 0;
	int mediaCalorias = 0;
	
	for (int i = 0; i < tamanhoDieta; i++) {
		if (dieta[i].numPaciente == numPaciente && strcmp(dieta[i].refeicao, refeicao) == 0) {
			totalCalorias += dieta[i].calorias;
			contador++;
		}
	}
	mediaCalorias = (float)totalCalorias / contador;
	return mediaCalorias;
}

/**
 * @brief Calcula a media de calorias maximas para um paciente e uma refeicao especificos.
 *
 * Esta funcao percorre um array de planos nutricionais, calcula a media de calorias maximas permitidas em uma refeicao especifica
 * para um paciente especifico.
 *
 * @param plano Um array de planos nutricionais contendo as informacoes caloricas maximas.
 * @param tamanhoPlano O numero de elementos no array de planos nutricionais.
 * @param numPaciente O numero do paciente para o qual a media de calorias maximas sera calculada.
 * @param refeicao A refeicao especifica para a qual a media de calorias maximas sera calculada.
 *
 * @return Retorna a media de calorias maximas permitidas na refeicao especificada para o paciente.
 *         Retorna 0 se nao houver dados de plano nutricional correspondentes ao criterio especificado.
 */

float calcularMediaCalMax(PlanoNutricional plano[], int tamanhoPlano, int numPaciente, char refeicao[]) {
	int totalCalMax = 0;
	int contador = 0;
	int mediaCaloriasMAX = 0;
	for (int i = 0; i < tamanhoPlano; i++) {
		if (plano[i].numPaciente == numPaciente && strcmp(plano[i].refeicao, refeicao) == 0) {
			totalCalMax += plano[i].calMAX;
			contador++;
		}
	}
	mediaCaloriasMAX = (float)totalCalMax / contador;
	return mediaCaloriasMAX;
}

/**
 * @brief Calcula a media de calorias minimas para um paciente e uma refeicao especificos.
 *
 * Esta funcao percorre um array de planos nutricionais, calcula a media de calorias minimas permitidas em uma refeicao especifica
 * para um paciente especifico.
 *
 * @param plano Um array de planos nutricionais contendo as informacoes caloricas minimas.
 * @param tamanhoPlano O numero de elementos no array de planos nutricionais.
 * @param numPaciente O numero do paciente para o qual a media de calorias minimas sera calculada.
 * @param refeicao A refeicao especifica para a qual a media de calorias minimas sera calculada.
 *
 * @return Retorna a media de calorias minimas permitidas na refeicao especificada para o paciente.
 *         Retorna 0 se nao houver dados de plano nutricional correspondentes ao criterio especificado.
 */
float calcularMediaCalMin(PlanoNutricional plano[], int tamanhoPlano, int numPaciente, char refeicao[]) {
	int totalCalMin = 0;
	int contador = 0;
	int mediaCaloriasMIN = 0;
	for (int i = 0; i < tamanhoPlano; i++) {
		if (plano[i].numPaciente == numPaciente && strcmp(plano[i].refeicao, refeicao) == 0) {
			totalCalMin += plano[i].calMIN;
			contador++;
		}
	}
	mediaCaloriasMIN = (float)totalCalMin / contador;
	return  mediaCaloriasMIN;
}


/**
 * @brief Mostra uma tabela com informacoes sobre a dieta e o plano nutricional dos pacientes em um determinado intervalo de datas.
 *
 * Esta funcao exibe uma tabela que contem informacoes sobre a dieta e o plano nutricional de cada paciente durante um intervalo
 * de datas especifico. A tabela inclui o numero do paciente, nome, tipo de refeicao, inicio e fim do intervalo, minimo (media) e maximo(media)
 * de calorias permitidas, e o consumo medio de calorias.
 *
 * @param dieta Um array de dietas contendo as informacoes caloricas.
 * @param tamanhoDieta O numero de elementos no array de dietas.
 * @param plano Um array de planos nutricionais contendo as informacoes caloricas.
 * @param tamanhoPlano O numero de elementos no array de planos nutricionais.
 * @param pacientes Um array de pacientes contendo informacoes pessoais.
 * @param tamanhoPacientes O numero de elementos no array de pacientes.
 * @param inicio A data de inicio do intervalo desejado no formato "DD-MM-AAAA".
 * @param fim A data de fim do intervalo desejado no formato "DD-MM-AAAA".
 */
void MostrarTabela(Dieta dieta[], int tamanhoDieta, PlanoNutricional plano[], int tamanhoPlano, Paciente pacientes[], int tamanhoPacientes, char inicio[], char fim[]) {
	
	if (tamanhoDieta <= 0 || tamanhoPlano <= 0 || tamanhoPacientes <= 0) {
		printf("Erro: Tamanhos inválidos dos arrays.\n");
		return;
	}

	if (strcmp(inicio, fim) > 0) {
		printf("Erro: A data de início é posterior à data de fim.\n");
		return;
	}

	printf("=================================== Tabela de refeições ======================================\n");
	printf(" _____________________________________________________________________________________________\n");
	printf("| Num |  Nome   | Tipo Refeição  |   Inicio   |   Fim      |   Mínimo   | Máximo  |  Consumo  |\n");
	printf("|-----+---------+----------------+------------+------------+------------+---------+-----------|\n");

	int encontrouDatas = 0; 

	for (int i = 0; i < tamanhoPacientes; i++) {
		int numPaciente = pacientes[i].numPaciente;
		int encontrouDataInicio = 0;
		int encontrouDataFim = 0;

		for (int j = 0; j < tamanhoDieta; j++) {
			if (dieta[j].numPaciente == numPaciente) {
				if (strcmp(dieta[j].data, inicio) >= 0 && strcmp(dieta[j].data, fim) <= 0) {
					encontrouDataInicio = 1;
				}
				if (strcmp(dieta[j].data, fim) >= 0 && strcmp(dieta[j].data, fim) <= 0) {
					encontrouDataFim = 1;
				}
			}
		}

		if (encontrouDataInicio && encontrouDataFim) {
			encontrouDatas = 1;

			int jaMostrouPequenoAlmoco = 0, jaMostrouAlmoco = 0, jaMostrouJantar = 0;

			for (int j = 0; j < tamanhoDieta; j++) {
				if (dieta[j].numPaciente == numPaciente && strcmp(dieta[j].data, inicio) >= 0 && strcmp(dieta[j].data, fim) <= 0) {
					int jaMostrouRefeicao = 0;

					if (strcmp(dieta[j].refeicao, "pequeno almoço") == 0 && !jaMostrouPequenoAlmoco) {
						jaMostrouRefeicao = 1;
						jaMostrouPequenoAlmoco = 1;
					}
					else if (strcmp(dieta[j].refeicao, "almoço") == 0 && !jaMostrouAlmoco) {
						jaMostrouRefeicao = 1;
						jaMostrouAlmoco = 1;
					}
					else if (strcmp(dieta[j].refeicao, "jantar") == 0 && !jaMostrouJantar) {
						jaMostrouRefeicao = 1;
						jaMostrouJantar = 1;
					}

					if (jaMostrouRefeicao) {
						float mediaCalMin = calcularMediaCalMin(plano, tamanhoPlano, numPaciente, dieta[j].refeicao);
						float mediaCalMax = calcularMediaCalMax(plano, tamanhoPlano, numPaciente, dieta[j].refeicao);
						float mediaCal = calcularMediaCalorias(dieta, tamanhoDieta, numPaciente, dieta[j].refeicao);

						printf("|  %-2d | %-7s | %-14s | %-6s | %-4s | %-10.2f | %-7.2f | %-8.2f  |\n",
							numPaciente, pacientes[i].nome, dieta[j].refeicao, inicio, fim, mediaCalMin, mediaCalMax, mediaCal);
					}
				}
			}
		}
	}

	if (!encontrouDatas) {
		printf("Nenhuma data no intervalo especificado para pelo menos um paciente.\n");
	}

	printf("|---------------------------------------------------------------------------------------------|\n");
}


#pragma endregion 