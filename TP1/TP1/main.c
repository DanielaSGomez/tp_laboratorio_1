#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"//BIBLIOTECA DE MIS FUNCIONES

int main()//FUNCION PRINCIPAL DE LA CALCULADORA
{
//DECLARACION DE VARIABLES
    int opcion;
    float primerNumero = 0;//VARIABLES INCIALIZADAS PARA QUE SI SE ELIGE OTRA OPCION PARA INICIAR QUE NO SEA LA DE INGRESAR NUMEROS, DE ERROR.
    float segundoNumero = 0;//
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialA;
    float factorialB;




//PLANTEO DENTRO DEL BUCLE DO WHILE PARA QUE SE EJECUTE EL PROGRAMA POR LO MENOS UNA VEZ.

    do
    {
        system("cls");//FUNCION QUE LIMPIA LA PANTALLA
        printf("<----------MENU---------->");
        printf("\nIngrese la opcion que corresponda: ");
        printf("\n1-Ingresar operando A.\n2-Ingresar operando B.\n3-Realizar operaciones.\n4-Resultados.\n5-Salir\n");

        scanf("%d",&opcion);//TOMO LA OPCION ELEGIDA


        switch(opcion)//PLANTEO LOS CASOS SEGUN LA OPCION ELEGIDA
        {
            case 1:
                printf("Ingrese el primer numero");
                scanf("%f",&primerNumero);
                break;

            case 2:

               printf("Ingrese el segundo numero");
                   scanf("%f",&segundoNumero);
                break;

            case 3:

                if(primerNumero==0&&segundoNumero==0)//SI SE ELIGE LA OPCION DE CALCULAR LOS RESULTADOS SIN HABER INGRESADO NINGUN NUMERO.
                {
                    printf("Debe ingresar numeros");

                }
                else//SI INGRESO LOS NUMEROS, SE REALIZAN LAS ASIGNACIONES DE RESULTADOS LLAMANDO A LAS FUNCIONES DE LA BIBLIOTECA.
                {
                    suma = sumarNumeros(primerNumero,segundoNumero);
                    resta = restarNumeros(primerNumero,segundoNumero);
                    division = dividirNumeros(primerNumero,segundoNumero);
                    multiplicacion = multiplicarNumeros(primerNumero,segundoNumero);
                    factorialA = calcularFactorialA(primerNumero);
                    factorialB = calcularFactorialB(segundoNumero);
                }
                break;

            case 4:
                printf("\nEl resultado de la suma es: %f",suma);
                printf("\nEl resultado de la resta es: %f",resta);
                printf("\nEl resultado de la division es: %f",division);
                printf("\nEl resultado de la multiplicacion es: %f",multiplicacion);
                printf("\nEl resultado del factorial A es: %f",factorialA);
                printf("\nEl resultado del factorial B es: %f",factorialB);
                break;

            case 5:
                printf("La calculadora se cerrara... :( ");
                break;

            default:
                printf("Opcion incorrecta");
        }
        system("pause");


    }while(opcion!=5);//SI EL USUARIO INGRESA LA OPCION 5 SE CIERRA EL PROGRAMA.

return 0;

}
