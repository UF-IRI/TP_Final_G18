#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"


using namespace std;

int main() {

    //Declaramos todas las variables que utilizaremos para almacenar las dimensiones de cada lista.

    int tam_P = 0;
    int tam_mas10 = 0;
    int tam_menos10 = 0;
    int tam_cons = 0;
    int tam_per = 0;
    int tam_fall = 0;
    int tam_med = 0;
    int tam_obr = 0;
    int tam_cont = 0;
    int tam_Pf = 0;

                                       //Declaracion de Listas en memoria\\

/*
Listas de tipos Paciente :
Declaramos la lista que usamos para leer a los parcientes de los archivos y las listas para clasificarlos
segun su ultima consulta(+10/-10 y si asistio).
Tambien declaramos listas para clasificarlos segun su estado.
*/

    string Archivo_P = "Pacientes.csv";
    string Archivo_C = "Consultas.csv";
    string Archivo_M = "Medicos.csv";
    string Archivo_c = "Contactos.csv";

    Paciente* array_pacientes = new Paciente[tam_P];

    Paciente* lista_mas10 = new Paciente[tam_mas10];

    Paciente* lista_menos10 = new Paciente[tam_menos10];


    /*
    Listas de tipo consulta:
    Declaramos en memoria la lista que utilizamos para leer los datos de las consultas de los pacientes
    */

    Consulta* array_consultas = new Consulta[tam_cons];


    /*
    Listas de tipo Medico:
    Declaramos en memoria la lista que utilizamos para leer los datos de los medicos
    */

    Medico* array_medicos = new Medico[tam_med];


    /*
   Listas de tipo Contacto:
   Declaramos en memoria la lista que utilizamos para leer los datos de contacto los pacientes
   */

    Contacto* array_contacto = new Contacto[tam_cont];


                                        //Lectura de archivos\\

    //Herramientas para hacer la lectura

    int i = 0;

    string dummy;

    char coma = ',';

    ifstream IndataP;
    ifstream IndataC;
    ifstream Indatac;
    ifstream IndataM;

#pragma region Lectura Paciente 

    //Lectura de pacientes:

    //Abrimos el Archivo de pacientes y salteamos el encabezado

    IndataP.open(Archivo_P, ios::in);

    IndataP >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

    while (IndataP) //Recorremos todo el archivo fila a fila y guardamos los datos de cada una donde corresponde
    {

        resize_P(array_pacientes, tam_P); //Por cada nuevo elemento redimensionamos la lista en 1


        IndataP >> array_pacientes[i].dni >> coma >> array_pacientes[i].Nombre >> coma
            >> array_pacientes[i].Apellido >> coma >> array_pacientes[i].sexo >> coma >>
            array_pacientes[i].Nacimiento >> coma >> array_pacientes[i].estado >> coma
            >> array_pacientes[i].os; 

        i++;

    }
    IndataP.close(); // cierramos el archivo 

#pragma endregion


#pragma region Lectura Contacto
//Lectura de datos de contacto:

    Indatac.open(Archivo_c, ios::in);  

    Indatac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

    i = 0;

    while (Indatac) 
    {

        resize_c(array_contacto, tam_cont);
        
        Indatac >> array_contacto[i].dni >> coma >> array_contacto[i].Telefono >> coma >> array_contacto[i].celular >> coma >> array_contacto[i].Direccion >> coma >> array_contacto[i].Mail;
        

        i++; 

    }
    Indatac.close(); 

#pragma endregion


#pragma region Lectura Consultas
 //Lectura de Consultas:

    IndataC.open(Archivo_C, ios::in);

    i = 0;

    while (IndataC) 
    {
        IndataC >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; 

        resize_C(array_consultas, tam_cons);

        

        IndataC >> array_consultas[i].dni_1 >> coma >> array_consultas[i].fecha_solicitado >> coma
            >> array_consultas[i].fecha_consulta >> coma >> array_consultas[i].Asistencia >> coma >> array_consultas[i].matricula;

        i++;

    }
    IndataC.close();  

#pragma endregion


#pragma region Lectura Medicos
//Leemos datos de los medicos:

    IndataM.open(Archivo_M, ios::in); 

    i = 0;

    while (IndataM) 
    {
        IndataM >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy; 

        resize_M(array_medicos, tam_med);

        

        IndataM >> array_medicos[i].matricula >> coma >> array_medicos[i].nombre >> coma
            >> array_medicos[i].apellido >> coma >> array_medicos[i].teldoc >> coma >> array_medicos[i].especialidad >> coma
            >> array_medicos[i].actividad;

        i++;

    } 
    IndataM.close(); 

#pragma endregion

                                               //Inicio de Desarrollo\\

    //Separamos los pacientes por +/- 10 años e imprimimos los pacientes activos e inactivos:
    
    separar_pacientes(array_pacientes, array_consultas, tam_P, tam_cons, lista_mas10, tam_mas10, lista_menos10, tam_menos10);

    //Creamos el archivo donde se encuentran todos los pacientes archivados:
    
    Escribir_Archivados( lista_mas10, tam_mas10, lista_menos10, tam_menos10);

    // Creamos un reporte de todos los paciente potenciales a ser recuperados, simulamos el contacto con ellos e imprimos
    // un reporte con todos los que si vuelven: 

    Retornan(lista_menos10, tam_menos10, array_medicos, tam_med, array_contacto, tam_cont, array_consultas, tam_cons);

    //Liberamos toda la memoria que utilizamos:

    delete[] array_pacientes;
    delete[] lista_mas10;
    delete[] lista_menos10;
    delete[] array_consultas;
    delete[] array_medicos;
    delete[]array_contacto;

                                                      //Fin del codigo\\

    getchar();

    return 0;
}