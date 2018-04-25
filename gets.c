#include <stdio.h>
#include <stdlib.h>
int getInt(int* numero, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
int getFloat(float* numero, char *mensaje, char *mensajeError, int maximo, int minimo, int reintento);
float calcularPromedio(int numeros[], int cantidad);
int calcularSumaInt(int numeros[], int cantidad);
int calcularSumaFloat(float numeros[], int cantidad);
int calcularPromedioV2(int numeros[], int cantidad, float* pResultado);
int calcularPromedioPreviaSuma(float resultadoSuma, int cantidad, float* pResultado)


/** \brief
 *
 * \param numero int* INGRESO NUMERO A VALIDAR
 * \param mensaje char* MUESTRO MENSAJE "INGRESAR NUMERO"
 * \param mensajeError char* MUESTRO MENSAJE "ERROR(NUMERO INVALIDO)"
 * \param maximo int MAXIMO VALOR DE INT PERMITIDO
 * \param minimo int MINIMO VALOR DE INT PERMITIDO
 * \param reintento int CANTIDAD DE REINTENTOS RESTANTES
 * \return int
 *
 */
int getInt( int* numero, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    long numeroAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%ld", &numeroAuxiliar);
        if (numeroAuxiliar < maximo && numeroAuxiliar > minimo)
        {
            *numero = (int)numeroAuxiliar;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s , le quedan %d reintentos\n",mensajeError , reintento);
            reintento--;
        }
    }while(reintento >= 0);

    return retorno;
}


/** \brief
 *
 * \param numero float* INGRESO NUMERO A VALIDAR
 * \param mensaje char* MUESTRO MENSAJE "INGRESAR NUMERO"
 * \param mensajeError char* MUESTRO MENSAJE "ERROR(NUMERO INVALIDO)"
 * \param maximo int MAXIMO VALOR DE FLOAT PERMITIDO
 * \param minimo int MINIMO VALOR DE FLOAT PERMITIDO
 * \param reintento int CANTIDAD DE REINTENTOS RESTANTES
 * \return int
 *
 */
int getFloat( float* numero, char* mensaje, char* mensajeError, int maximo, int minimo, int reintento)
{
    float numeroAuxiliar;
    int retorno = -1;
    do
    {
        fflush(stdin);
        printf("%s", mensaje);
        scanf("%f", &numeroAuxiliar);
        if (numeroAuxiliar < maximo && numeroAuxiliar > minimo)
        {
            *numero = (float)numeroAuxiliar;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s , le quedan %d reintentos\n",mensajeError , reintento);
            reintento--;
        }
    }while(reintento >= 0);

    return retorno;
}

/** \brief FUNCION PARA SUMAR VALORES DEL ARRAY
 *
 * \param numeros[] int ARRAY DE NUMEROS
 * \param cantidad int TAMAÑO DEL ARRAY (SE UTILIZA PARA ITERAR)
 * \return int DEVUELVE ACUMULADOR ( SUMA DE ARRAYS )
 *
 */
int calcularSumaInt(int numeros[], int cantidad)
{
    int acumulador=0;
    int i=0;
    for (i=0; i < cantidad; i++)
    {
        acumulador = acumulador + numeros[i];

    }
    return acumulador;
}

/** \brief
 *
 * \param numeros[] float ARRAY DE FLOAT
 * \param cantidad int TAMAÑO DEL ARRAY (SE UTILIZA PARA ITERAR)
 * \return int DEVUELVE ACUMULADOR ( SUMA DE ARRAYS )
 *
 */
int calcularSumaFloat(float numeros[], int cantidad)
{
    float acumulador=0;
    int i=0;
    for (i=0; i < cantidad; i++)
    {
        acumulador = acumulador + numeros[i];

    }
    return acumulador;
}

/** \brief
 *
 * \param numeros int INGRESO RESULTADO SUMA, CALCULADO ANTERIORMENTE
 * \param cantidad int
 * \param pResultado float*
 * \return int
 *
 */
int calcularPromedioV2(int numeros[], int cantidad, float* pResultado)
{
    int suma = calcularSuma(numeros, cantidad);
    int retorno;
    if (cantidad == 0|| pResultado ==NULL)
    {
        retorno = -1;
    }
    else
    {
        *pResultado = (float)suma / cantidad;
        retorno = 0;
    }

    return retorno;
}


/** \brief REALIZA PROMEDIO SI YA SE REALIZO LA SUMA
 *
 * \param resultadoSuma float PASO RESULTADO SUMA
 * \param cantidad int CANTIDAD NUMEROS CARGADOS
 * \param pResultado float* POR PUNTERO ENVIO RESULTADO PROMEDIO
 * \return int RETORNO
 *
 */
int calcularPromedioPreviaSuma(float resultadoSuma, int cantidad, float* pResultado)
{
    //int suma = calcularSuma(numeros, cantidad);
    int retorno;
    if (cantidad == 0|| pResultado ==NULL)
    {
        retorno = -1;
    }
    else
    {
        *pResultado = resultadoSuma / cantidad;
        retorno = 0;
    }

    return retorno;
}


