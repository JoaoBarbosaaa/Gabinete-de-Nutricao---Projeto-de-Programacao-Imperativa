/**

    @file      main.c
    @brief     
    @details   ~
    @author    Joao Barbosa
    @date      21.12.2023
    @copyright Joao Barbosa, 2023. All right reserved.

*/

#include "global.h"
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("-----------------------------Trabalho Prático ----------------------------- \n");
#pragma region Pacientes
    /**
   * @brief Array de objetos Paciente.
   *
   * Este array armazena objetos Paciente para representar informacoes sobre pacientes.
   * O tamanho do array e definido por K.
   */
    Paciente pacientes[K];
    
    /**
 * @brief Importa dados de pacientes de um arquivo CSV.
 *
 * A funcao ImportarPacientes e utilizada para ler dados de pacientes de um arquivo CSV
 * e armazena-los no array de objetos Paciente.
 *
 * @param arquivoCSV Nome do arquivo CSV contendo os dados dos pacientes.
 * @param pacientes Array de objetos Paciente para armazenar os dados importados.
 * @param tamanhoPacientes Tamanho do array de pacientes.
 * @return Numero de pacientes importados com sucesso.
 */
    int dados = ImportarPacientes("dadosPacientes.csv", pacientes, K);
   
    /**
 * @brief Converte dados de pacientes para formato binario e salva em um arquivo.
 *
 * A funcao ConverterPacienteBinario e utilizada para converter os dados dos pacientes
 * para um formato binario e salvar o resultado em um arquivo mais seguro.
 *
 * @param nomeArquivo Nome do arquivo binario de destino.
 * @param pacientes Array de objetos Paciente contendo os dados a serem convertidos.
 * @param tamanhoPacientes Tamanho do array de pacientes.
 */
    ConverterPacienteBinario("dadosPacientes.bin", pacientes, K);


#pragma endregion 

#pragma region Dieta
    /**
 * @brief Array de objetos Dieta.
 *
 * Este array armazena objetos Dieta para representar informacoes sobre a dieta dos pacientes.
 * O tamanho do array e definido por K.
 */
    Dieta dieta[K];
   
    /**
 * @brief Importa informacoes da dieta de um arquivo CSV.
 *
 * A funcao ImportarInfoDieta e utilizada para ler informacoes da dieta de um arquivo CSV
 * e armazena-las no array de objetos Dieta.
 *
 * @param arquivoCSV Nome do arquivo CSV contendo as informacoes da dieta.
 * @param dieta Array de objetos Dieta para armazenar as informacoes importadas.
 * @param tamanhoDieta Tamanho do array de dietas.
 */
    ImportarInfoDieta("dieta.csv", dieta, K);
    /**
  * @brief Converte informacoes da dieta para formato binario e salva em um arquivo.
  *
  * A funcao ConverterInfoDietaBinario e utilizada para converter as informacoes da dieta
  * para um formato binario e salvar o resultado em um arquivo.
  *
  * @param nomeArquivo Nome do arquivo binario de destino.
  * @param dieta Array de objetos Dieta contendo as informacoes a serem convertidas.
  * @param tamanhoDieta Tamanho do array de dietas.
  */
    ConverterInfoDietaBinario("dieta.bin", dieta, K);

#pragma endregion

#pragma region Plano
    /**
 * @brief Array de objetos PlanoNutricional.
 *
 * Este array armazena objetos PlanoNutricional para representar informacoes sobre os planos nutricionais.
 * O tamanho do array e definido por K.
 */
    PlanoNutricional plano[K];
   
    /**
 * @brief Importa informacoes do plano nutricional de um arquivo CSV.
 *
 * A funcao ImportarPlanoNutricional e utilizada para ler informacoes do plano nutricional de um arquivo CSV
 * e armazena-las no array de objetos PlanoNutricional.
 *
 * @param arquivoCSV Nome do arquivo CSV contendo as informacoes do plano nutricional.
 * @param plano Array de objetos PlanoNutricional para armazenar as informacoes importadas.
 * @param tamanhoPlano Tamanho do array de planos nutricionais.
 */
    ImportarPlanoNutricional("plano.csv", plano, K);
    
    /**
 * @brief Converte informacoes do plano nutricional para formato binario e salva em um arquivo.
 *
 * A funcao ConverterPlanoNutricionalBinario e utilizada para converter as informacoes do plano nutricional
 * para um formato binario e salvar o resultado em um arquivo.
 *
 * @param nomeArquivo Nome do arquivo binario de destino.
 * @param plano Array de objetos PlanoNutricional contendo as informacoes a serem convertidas.
 * @param tamanhoPlano Tamanho do array de planos nutricionais.
 */
    ConverterPlanoNutricionalBinario("plano.bin", plano, K);

#pragma endregion

#pragma region sizeof
    /**
 * @brief Calcula o tamanho do array de dietas.
 *
 * Esta linha de codigo determina o tamanho do array de dietas dividindo o tamanho
 * total do array pelo tamanho de um elemento do array.
 *
 * @param dieta Array de objetos Dieta.
 * @return Tamanho do array de dietas.
 */
    int tamanhoDieta = sizeof(dieta) / sizeof(dieta[0]); 
    /**
 * @brief Calcula o tamanho do array de planos nutricionais.
 *
 * Esta linha de codigo determina o tamanho do array de planos nutricionais dividindo o tamanho
 * total do array pelo tamanho de um elemento do array.
 *
 * @param plano Array de objetos PlanoNutricional.
 * @return Tamanho do array de planos nutricionais.
 */
    int tamanhoPlano = sizeof(plano) / sizeof(plano[0]); 

    /**
 * @brief Calcula o tamanho do array de pacientes.
 *
 * Esta linha de codigo determina o tamanho do array de pacientes dividindo o tamanho
 * total do array pelo tamanho de um elemento do array.
 *
 * @param pacientes Array de objetos Paciente.
 * @return Tamanho do array de pacientes.
 */
    int tamanhoPacientes = sizeof(pacientes) / sizeof(pacientes[0]); 

#pragma endregion 

#pragma region Pacientes que ultrapassam n calorias
    /**
  * @brief Calcula o numero de pacientes que ultrapassaram um limite de calorias em um periodo especifico.
  *
  * @param dieta Array de objetos Dieta contendo as informacoes sobre as calorias consumidas.
  * @param tamanhoDieta Tamanho do array de dietas.
  * @param valorUltrapassar Limite de calorias a ser ultrapassado.
  * @param dataInicio Data de inicio do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
  * @param dataFim Data de fim do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
  * @return O numero de pacientes que ultrapassaram o limite de calorias.
  */

    int ultrapassar = 1000;
    int Ultrapassa = numPacientesUltrapassaram(dieta, tamanhoDieta, ultrapassar, "01/01/2023", "02/01/2023");
    printf("O número de pacientes que ultrapassaram o número de calorias é:%d\n", Ultrapassa);


#pragma endregion

#pragma region Listagem Fora Limites
    /**
   * @brief Verifica e lista pacientes fora dos limites de calorias durante um periodo especifico.
   *
   * @param plano Array de objetos PlanoNutricional contendo as informacoes sobre os planos nutricionais.
   * @param tamanhoPlano Tamanho do array de planos nutricionais.
   * @param dieta Array de objetos Dieta contendo as informacoes sobre as calorias consumidas.
   * @param tamanhoDieta Tamanho do array de dietas.
   * @param dataInicio Data de inicio do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
   * @param dataFim Data de fim do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
   */
    PacientesForaLimites(plano,  tamanhoPlano, dieta, tamanhoDieta, "01/01/2023", "02/01/2023");

#pragma endregion

#pragma region Listagem plano 
    /**
 * @brief Lista informacoes do plano nutricional para um paciente durante um periodo especifico.
 *
 * @param numPaciente Numero do paciente associado ao plano nutricional.
 * @param plano Array de objetos PlanoNutricional contendo as informacoes sobre os planos nutricionais.
 * @param tamanhoPlano Tamanho do array de planos nutricionais.
 * @param dataInicio Data de inicio do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 * @param dataFim Data de fim do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 */
    listarPlano(1, plano, tamanhoPlano, "01/01/2023", "02/01/2023");

#pragma endregion

#pragma region Média calorias
    /**
 * @brief Calcula a media de calorias consumidas por um paciente em uma refeicao durante um periodo especifico.
 *

 * @param numPaciente Numero do paciente associado as dietas.
 * @param dieta Array de objetos Dieta contendo as informacoes sobre as calorias consumidas.
 * @param tamanhoDieta Tamanho do array de dietas.
 * @param refeicao Tipo de refeicao para calcular a media de calorias.
 * @param dataInicio Data de inicio do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 * @param dataFim Data de fim do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 * @return A media de calorias consumidas pelo paciente na refeicao durante o periodo especificado.
 */
    
    int numPaciente = 2;
    char refeicao[] = "jantar";
    char dataInicio[] = "01/01/2023";
    char dataFim[] = "02/01/2023";

    float MEDIA = MediaCalorias(2, dieta, tamanhoDieta, refeicao, dataInicio, dataFim);
    printf("A média de calorias que o paciente %d consumiu à refeição %s entre os dias %s e %s foi de:%.1f\n\n", numPaciente, refeicao,
        dataInicio, dataFim, MEDIA); // %.1f significa que arredonda a uma casa decimal

#pragma endregion 

#pragma region Tabela
    /**
 * @brief Mostra uma tabela com informacoes de dieta, plano nutricional e pacientes durante um periodo especifico.
 *

 * @param dieta Array de objetos Dieta contendo as informacoes sobre as calorias consumidas.
 * @param tamanhoDieta Tamanho do array de dietas.
 * @param plano Array de objetos PlanoNutricional contendo as informacoes sobre os planos nutricionais.
 * @param tamanhoPlano Tamanho do array de planos nutricionais.
 * @param pacientes Array de objetos Paciente contendo as informacoes dos pacientes.
 * @param tamanhoPacientes Tamanho do array de pacientes.
 * @param dataInicio Data de inicio do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 * @param dataFim Data de fim do periodo, a data de ser apresentada no formato "DD/MM/AAAA".
 */
    MostrarTabela(dieta, tamanhoDieta, plano, tamanhoPlano, pacientes, tamanhoPacientes, "01/01/2023", "02/01/2023");

#pragma endregion

    return 0;
}