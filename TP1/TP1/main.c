#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"//BIBLIOTECA DE MIS FUNCIONES

int main()//FUNCION PRINCIPAL DE LA CALCULADORA

{
//DECLARACION DE VARIABLES
    int opcion;
    float primerNumero;
    float segundoNumero;
    float suma = 0;
    float resta = 0;
    float division = 0;
    float multiplicacion = 0;
    float factorialA = 0;
    float factorialB = 0;
    int flagPrimerNumero = 0;
    int flagSegundoNumero = 0;

//PLANTEO DENTRO DEL BUCLE DO WHILE PARA QUE SE EJECUTE EL PROGRAMA POR LO MENOS UNA VEZ.

    do
    {

        printf("<----------MENU---------->\n");
        printf("\nIngrese la opcion que corresponda: \n");
        printf("\n1-Ingresar 1er operando.\n2-Ingresar 2do operando.\n3-Calcular todas las operaciones:\n\t>>Calcular la suma (A+B)\n\t>>Calcular la Resta (A-B)\n\t>>Calcular la Multiplicacion (A*B)\n\t>>Calcular la Division (A/B)\n\t>>Calcular el Factorial de A\n\t>>Calcular el Factorial de B.\n4-Resultados.\n5-Salir\n");
        if(flagPrimerNumero==1)
        {
            printf("\nA = %.2f\n",primerNumero);
        }

        if(flagSegundoNumero==1)
        {
            printf("\nB = %.2f\n",segundoNumero);
        }

        scanf("%d",&opcion);//TOMO LA OPCION ELEGIDA

        switch(opcion)//PLANTEO LOS CASOS SEGUN LA OPCION ELEGIDA
        {
            case 1:
                printf("Ingrese el primer numero: \n");
                scanf("%f",&primerNumero);
                flagPrimerNumero = 1;
                break;

            case 2:

                printf("\nIngrese el segundo numero: \n");
                scanf("%f",&segundoNumero);
                flagSegundoNumero =1;
                break;

            case 3:
                    if(flagPrimerNumero==0&&flagSegundoNumero==0)
                    {
                        printf("Ingrese operandos para calcular...");
                    }
                    else
                    {

                    suma = sumarNumeros(primerNumero,segundoNumero);
                    resta = restarNumeros(primerNumero,segundoNumero);
                    if(segundoNumero!=0)
                    {
                        division = dividirNumeros(primerNumero,segundoNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No se puede dividir por 0\n");
                    }

                    multiplicacion = multiplicarNumeros(primerNumero,segundoNumero);

                    if(primerNumero>=0)
                    {
                        factorialA = calcularFactorialA(primerNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No existen factoriales de numeros negativos\n");
                    }

                    if(segundoNumero>=0)
                    {
                         factorialB = calcularFactorialB(segundoNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No existen factoriales de numeros negativos\n");
                    }

                        printf("\t\t\tCalculos realizados!\n");

                    }


                break;

            case 4:
                printf("\n<-------RESULTADOS------->\nEl resultado de A+B es: %.2f",suma);
                printf("\nEl resultado de A-B es: %.2f",resta);
                printf("\nEl resultado de A*B es: %.2f",multiplicacion);
                if(segundoNumero!=0)
                {
                    printf("\nEl resultado de A/B es: %.2f",division);

                }
                else
                {
                   printf("\nEl resultado de A/B es: no se puede realizar la division por 0");
                }



                if(primerNumero<0)
                {
                    printf("\nEl factorial de A es: No se pueden calcular factoriales de numeros negativos");
                }
                else
                {
                  printf("\nEl factorial de A es: %.2f",factorialA);
                }

                if(segundoNumero<0)
                {
                    printf("\nEl factorial de B es: No se pueden calcular factoriales de numeros negativos");
                }
                else
                {
                    printf("\nEl factorial de B es: %.2f\n",factorialB);
                }

                break;

            case 5:
                printf("La calculadora se cerrara... :( \n");
                break;

            default:
                printf("\nOpcion incorrecta");
        }
        system("pause");
        system("cls");


    }while(opcion!=5);//SI EL USUARIO INGRESA LA OPCION 5 SE CIERRA EL PROGRAMA.

return 0;

}
