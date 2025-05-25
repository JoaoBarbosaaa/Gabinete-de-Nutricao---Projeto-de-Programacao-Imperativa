/**

	@file      GestaoFicheiros.c
	@brief
	@details   ~
	@author    Joao Barbosa
	@date      21.12.2023
	@copyright Joao Barbosa, 2023. All right reserved.

**/
#include "global.h"
#include <stdio.h>
#pragma warning (disable: 4996)

#pragma region Paciente
/**
 * @brief Importa informacoes de pacientes a partir de um arquivo.
 *
 * Esta funcao le informacoes de pacientes de um arquivo CSV e popula um array de pacientes
 * com os dados lidos.
 *
 * @param nomeFicheiro O nome do arquivo CSV contendo as informacoes dos pacientes.
 * @param pacientes Um array de pacientes a ser preenchido com as informacoes do arquivo.
 * @param maximoPacientes O numero maximo de pacientes que podem ser lidos do arquivo.
 *
 * @return Retorna o numero de pacientes importados com sucesso.
 *         Retorna 0 se houver um erro ao abrir o arquivo ou se nao houver pacientes a serem lidos.
 */

int ImportarPacientes(char nomeFicheiro[], Paciente pacientes[], int maximoPacientes) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeFicheiro);
		return 0;
	}
	// Ignora a primeira linha
	int c;
	while ((c = fgetc(fp)) != EOF && c != '\n');

	int i = 0;
	while (i < maximoPacientes) {
		if (fscanf(fp, "%d;%[^;];%s", &pacientes[i].numPaciente, pacientes[i].nome, pacientes[i].telemovel) != 3) {
			break;
		}
		//printf("%d;%s;%s\n", pacientes[i].numPaciente, pacientes[i].nome, pacientes[i].telemovel); //verificar se esta a funcionar....
		i++;
	}

	fclose(fp);
	return i;
}

/**
 * @brief Converte dados da estrutura Paciente para um arquivo binario.
 *
 * Esta funcao recebe um array de pacientes e o numero total de pacientes (n).
 * Em seguida, ela cria um arquivo binario e escreve os dados da estrutura Paciente
 * no formato binario. O arquivo resultante e util para armazenar dados de pacientes
 * de forma compacta e eficiente.
 *
 * @param nomeFicheiroBinario Nome do arquivo binario a ser criado.
 * @param pacientes Array de estruturas Paciente contendo os dados a serem convertidos.
 * @param n Numero total de pacientes no array.
 * @return true se a conversao foi bem-sucedida, false em caso de erro.
 */
bool ConverterPacienteBinario(char nomeFicheiroBinario[], Paciente pacientes[], int n) {
	// Abre o arquivo binário para escrita em modo binário
	FILE* fp = fopen(nomeFicheiroBinario, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo binário %s\n", nomeFicheiroBinario);
		return false;
	}

	for (int i = 0; i < n; i++) {
		fwrite(&pacientes[i], sizeof(Paciente), 1, fp);
	}

	// Fecha o arquivo binário
	fclose(fp);

	return true;
}
#pragma endregion

#pragma region Dieta
/**
 * @brief Importa informacoes de dieta a partir de um arquivo.
 *
 * Esta funcao le informacoes de dieta de um arquivo CSV e popula um array de dietas
 * com os dados lidos.
 *
 * @param nomeFicheiro O nome do arquivo CSV contendo as informacoes das dietas.
 * @param dieta Um array de dietas a ser preenchido com as informacoes do arquivo.
 * @param tamanho O numero maximo de dietas que podem ser lidas do arquivo.
 *
 * @return Retorna o numero de dietas importadas com sucesso.
 *         Retorna 0 se houver um erro ao abrir o arquivo ou se nao houver dietas a serem lidas.
 */
int ImportarInfoDieta(char nomeFicheiro[], Dieta dieta[], int tamanho) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeFicheiro);
		return 0;
	}

	// Ignora a primeira linha
	int c;
	while ((c = fgetc(fp)) != EOF && c != '\n');



	int i = 0;
	while (i < tamanho) {
		if (fscanf(fp, "%d;%[^;];%[^;];%[^;];%d\n", &dieta[i].numPaciente, dieta[i].data, dieta[i].refeicao, dieta[i].alimento, &dieta[i].calorias) != 5) {
			break;
		}
		//printf("%d;%s;%s;%s;%d \n", dieta[i].numPaciente, dieta[i].data, dieta[i].refeicao, dieta[i].alimento, dieta[i].calorias); //verificar se esta a funcionar....
		i++;
	}
	fclose(fp);
	return i;
}

/**
 * @brief Converte dados de dieta para um arquivo binario.
 *
 * Esta funcao recebe um array de estruturas Dieta e o numero total de elementos (tamanho).
 * Em seguida, ela cria um arquivo binario e escreve os dados da estrutura Dieta
 * no formato binario. O arquivo resultante e util para armazenar dados de dieta
 * de forma compacta e eficiente.
 *
 * @param nomeFicheiroBinario Nome do arquivo binario a ser criado.
 * @param dieta Array de estruturas Dieta contendo os dados a serem convertidos.
 * @param tamanho Numero total de elementos no array.
 * @return true se a conversao foi bem-sucedida, false em caso de erro.
 */
bool ConverterInfoDietaBinario(char nomeFicheiroBinario[], Dieta dieta[], int tamanho) {
	FILE* fp = fopen(nomeFicheiroBinario, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo binario %s\n", nomeFicheiroBinario);
		return false;
	}

	for (int i = 0; i < tamanho; i++) {
		fwrite(&dieta[i], sizeof(Dieta), 1, fp);
	}
	fclose(fp);

	return true;
}

#pragma endregion

#pragma region Plano
/**
 * @brief Importa informacoes de plano nutricional a partir de um arquivo.
 *
 * Esta funcao le informacoes de plano nutricional de um arquivo CSV e popula um array de planos nutricionais
 * com os dados lidos.
 *
 * @param nomeFicheiro O nome do arquivo CSV contendo as informacoes dos planos nutricionais.
 * @param plano Um array de planos nutricionais a ser preenchido com as informacoes do arquivo.
 * @param tamanho O numero maximo de planos nutricionais que podem ser lidos do arquivo.
 *
 * @return Retorna o numero de planos nutricionais importados com sucesso.
 *         Retorna 0 se houver um erro ao abrir o arquivo ou se nao houver planos nutricionais a serem lidos.
 */

int ImportarPlanoNutricional(char nomeFicheiro[], PlanoNutricional plano[], int tamanho) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeFicheiro);
		return 0;
	}

	// Ignora a primeira linha
	int c;
	while ((c = fgetc(fp)) != EOF && c != '\n');



	int i = 0;
	while (i < tamanho) {
		if (fscanf(fp, "%d;%[^;];%[^;];%d;%d\n", &plano[i].numPaciente, plano[i].data, plano[i].refeicao, &plano[i].calMIN, &plano[i].calMAX) != 5) {
			break;
		}
		//printf("%d;%s;%s;%d;%d cal \n", plano[i].numPaciente, plano[i].data, plano[i].refeicao, plano[i].calMIN, plano[i].calMAX); //verificar se esta a funcionar....
		i++;
	}

	fclose(fp);
	return i;
}

/**
 * @brief Converte dados do PlanoNutricional para um arquivo binario.
 *
 * Esta funcao recebe um array de estruturas PlanoNutricional e o numero total de elementos (tamanho).
 * Em seguida, ela cria um arquivo binario e escreve os dados da estrutura PlanoNutricional
 * no formato binario. O arquivo resultante e util para armazenar dados do plano nutricional
 * de forma compacta e eficiente.
 *
 * @param nomeFicheiroBinario Nome do arquivo binario a ser criado.
 * @param plano Array de estruturas PlanoNutricional contendo os dados a serem convertidos.
 * @param tamanho Numero total de elementos no array.
 * @return true se a conversao foi bem-sucedida, false em caso de erro.
 */

bool ConverterPlanoNutricionalBinario(char nomeFicheiroBinario[], PlanoNutricional plano[], int tamanho) {

	FILE* fp = fopen(nomeFicheiroBinario, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo binario %s\n", nomeFicheiroBinario);
		return false;
	}

	for (int i = 0; i < tamanho; i++) {
		fwrite(&plano[i], sizeof(PlanoNutricional), 1, fp);
	}

	fclose(fp);

	return true;
}


#pragma endregion