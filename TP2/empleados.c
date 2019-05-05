#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"
#include "empleados.h"
#define LIBRE 1
#define OCUPADO 0


/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int harcodearData(empleado lista[], int tam)
{
    int i;
    int id[]= {1,3,22,8,6,9};
    char nombre[][51] = {"Daniela","Fabian","Alicia","Enrique","Constanza","Matias"};
    char apellido[][51] = {"Gomez","Gamarra", "Acosta","Gomez","Atencio","Perez"};
    int sector[] = {2,9,25,4,2,4};
    float sueldo[] = {15000,22222,15500,17000,30000,27000};

    for(i=0;i<tam;i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].apellido,apellido[i]);
        lista[i].sector=sector[i];
        lista[i].sueldo = sueldo[i];
        lista[i].isEmpty = OCUPADO;

    }

    return 0;
}



/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int initEmpleado(empleado lista[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        lista[i].isEmpty = LIBRE;
        retorno = 0;
    }

    return retorno;
}


/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int buscarLugarLibre(empleado lista[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty== LIBRE)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarExisteId(empleado lista[], int tam, int id)
{
    int i;

    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO && (lista[i].id== id))
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \param id int
 * \param nombre[] char
 * \param apellido[] char
 * \param sueldo float
 * \param sector int
 * \return int
 *
 */
int anadirEmpleado(empleado lista[], int tam, int id, char nombre[], char apellido[], float sueldo, int sector)
{

    int hayLugar;
    int idOcupado;
    int retorno = -1;

    hayLugar = buscarLugarLibre(lista,tam);

    if(hayLugar == -1)
    {
        printf("\nNo hay lugar!!");

    }
    else
    {
        id = getValidInt("\nIngrese el ID: ","Debe ingresar numeros",0,1001);
        idOcupado = buscarExisteId(lista,tam,id);

        if(idOcupado != -1)
        {
            printf("\nId ya esta en uso...");
        }
        else
        {
               lista[hayLugar].id = id;

               getValidString("Ingrese el nombre: ","Debe ser un nombre de solo letras", nombre);
               strcpy(lista[hayLugar].nombre,nombre);

               getValidString("Ingrese el apellido: ", "Debe ser un apellido solo letras", apellido);
               strcpy(lista[hayLugar].apellido,apellido);

               sueldo = getValidFloat("Ingrese el sueldo: ","Debe ser un sueldo valido",0,9999999);
               lista[hayLugar].sueldo = sueldo;

               sector = getValidInt("Ingrese el sector (0 a 50): ", "Debe ser un numero.",0,50);
               lista[hayLugar].sector = sector;

               lista[hayLugar].isEmpty = OCUPADO;

               retorno = 0;
        }

    }

    return retorno;
}

/** \brief
 *
 * \param unEmpleado empleado
 * \return int
 *
 */
int mostrarUnEmpleado(empleado unEmpleado)
{
    printf("\n---------------------------------------------------------------------------------------------");
    printf("\n ID |       NOMBRE       |       APELLIDO     |       SECTOR       |      SALARIO            |");
    printf("\n---------------------------------------------------------------------------------------------");
    printf("\n%4d|%20s|%20s|%20d|%25f|\n",unEmpleado.id,unEmpleado.nombre,unEmpleado.apellido,unEmpleado.sector,unEmpleado.sueldo);
    printf("\n---------------------------------------------------------------------------------------------");
    return 0;
}

/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int mostrarListaEmpleados(empleado lista[], int tam)
{
    int i;
    printf("\n---------------------------------------------------------------------------------------------");
    printf("\n ID |       NOMBRE       |       APELLIDO     |       SECTOR       |      SALARIO            |");
    printf("\n---------------------------------------------------------------------------------------------");

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
             printf("\n%4d|%20s|%20s|%20d|%25f|\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].sector,lista[i].sueldo);
        }

    }
    printf("\n---------------------------------------------------------------------------------------------");
    return 0;
}


/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \param id int
 * \return int
 *
 */
int bajaEmpleado(empleado lista[], int tam, int id)
{
    char respuesta;
    int existeId;
    int retorno = -1;

    id = getValidInt("\nIngrese el id a buscar\n", "\ndebe ingresar un nuero de id",0,1001);
    existeId = buscarExisteId(lista,tam,id);


            if(existeId != -1)
            {
               mostrarUnEmpleado(lista[existeId]);
                respuesta = getChar("\nEsta seguro que desea elminar el empleado: (s/n)\n");

                if(respuesta == 's' || respuesta == 'S')
                {
                    lista[existeId].isEmpty = LIBRE;
                    retorno =  0;
                    printf("\nEmpleado eliminado!\n");
                }
                else
                {
                    printf("\nSe cancelo la baja\n");
                }

            }

            else
            { printf("\nEl id ingresado no existe\n");

            }

    return retorno;
}


/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \param id int
 * \return int
 *
 */
int modificarEmpleado(empleado lista[], int tam, int id)
{
    char respuesta;
    int existeId;
    int retorno = -1;
    int opcionMenuModificar;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int nuevoSector;
    float nuevoSueldo;
    //danielagomez

    id = getValidInt("\nIngrese el id a modificar\n", "\ndebe ingresar un numero de id",0,1001);
    existeId = buscarExisteId(lista,tam,id);


            if(existeId != -1 && lista[existeId].isEmpty != LIBRE)
            {
                mostrarUnEmpleado(lista[existeId]);
                respuesta = getChar("\nEsta seguro que desea modificar el empleado: (s/n)\n");

                if(respuesta == 's' || respuesta == 'S')
                {
                    printf("\t\t\t\tSUBMENU DE MODIFICACIONES");

                    do
                    {
                        opcionMenuModificar = mostrarMenu("\nDigite una opcion:\n1-Modificar nombre: \n2-Modificar Apellido: \n3-Modificar Salario: \n4-Modificar Sector\n5-Salir del Submenu","Debe ingresar un numero",0,6);

                        switch(opcionMenuModificar)
                        {
                            case 1:
                                getValidString("\nIngrese el nuevo nombre: ","\nDebe contener solo letras\n",nuevoNombre);
                                strcpy(lista[existeId].nombre , nuevoNombre);
                                break;
                            case 2:
                                getValidString("\nIngrese el nuevo apellido: ","\nDebe contener solo letras", nuevoApellido);
                                strcpy(lista[existeId].apellido , nuevoApellido);
                                break;
                            case 3:
                                nuevoSueldo = getValidFloat("\nIngrese el nuevo sueldo: ", "\nDebe contener solo numeros",0,999999999);
                                lista[existeId].sueldo = nuevoSueldo;
                                break;
                            case 4:
                                nuevoSector = getValidInt("\nIngrese el nuevo sector (0 a 50): ", "\nDebe ser un numero entero (0 a 50)",0,51);
                                lista[existeId].sector = nuevoSector;
                                break;
                            case 5:
                                printf("\nVolviendo al menu principal...\n");
                                break;

                        }

                    }while(opcionMenuModificar != 5);

                    retorno = 0;
                }

                else
                {
                    printf("Se cancelo la modificacion!");
                }

            }

            else
            {
                printf("\nEl id ingresado no existe\n");

            }

            return retorno;
}

/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int ordenarEmpleados(empleado lista[], int tam)
{
    int ordenarSegun;
    int i;
    int j;
    empleado aux;

    printf("\n\t\t\t\tMENU DE ORDENAMIENTO DE EMPLEADOS\n");

    ordenarSegun = getValidInt("\nIngrese en que orden quiere mostrar la lista: \n1-Ascendente\n2-Descendente\n","Debe ser una opcion valida",0,3);

        if(ordenarSegun == 1)
        {
            printf("\nSe organizo la lista en orden ascendente:\n");
              //ORDEN ASCENDENTE
            for(i=0;i<tam-1;i++)
            {
                for(j = i+1;j<tam;j++)
                {
                    if(strcmp(lista[j].apellido,lista[i].apellido)<0)//ORDENA DE MENOR A MAYOR LOS APELLIDOS
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[j].apellido,lista[i].apellido)==0 && lista[i].sector>lista[j].sector)//SI ESTAN ORDENADOS LOS APELLIDOS Y HAY DOS IGUALES LOS ORDENA POR SECTOR
                        {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nSe organizo la lista en orden descendente\n");
             //ORDEN DESCENDENTE
            for(i=0;i<tam-1;i++)
            {
                for(j = i+1;j<tam;j++)
                {
                    if(strcmp(lista[j].apellido,lista[i].apellido)>0)//ORDENA DE MAYOR A MENOR LOS APELLIDOS
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[j].apellido,lista[i].apellido)==0 && lista[i].sector<lista[j].sector)//SI ESTAN ORDENADOS LOS APELLIDOS Y HAY DOS IGUALES LOS ORDENA POR SECTOR
                        {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                        }
                    }
                }
            }
        }


    mostrarListaEmpleados(lista,tam);
    return 0;
}

//danielagomez

/** \brief
 *
 * \param lista[] empleado
 * \param tam int
 * \return int
 *
 */
int informesSueldos(empleado lista[], int tam)
{
    float totalSueldos = 0;
    int cantidadSueldos = 0;
    float promedioSueldos;
    int cantidadEmpleadosMasPromedio = 0;
    int i;

    printf("\n\t\t\t\tINFORMES DE SUELDOS\n");

    for(i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            totalSueldos = totalSueldos + lista[i].sueldo;
            cantidadSueldos++;
        }
    }

    promedioSueldos = totalSueldos/cantidadSueldos;


    for(i = 0;i<tam;i++)
    {
        if(lista[i].isEmpty == OCUPADO && lista[i].sueldo>promedioSueldos)
        {
            cantidadEmpleadosMasPromedio++;
        }
    }

    printf("\n--------------------------------------------------------------------------------------");
    printf("\n   TOTAL SUELDOS    |     PROMEDIO DE SUELDOS    | EMPLEADOS QUE SUPERAN EL PROMEDIO |");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n%17f %20f %20d",totalSueldos,promedioSueldos,cantidadEmpleadosMasPromedio);


    return 0;
}


