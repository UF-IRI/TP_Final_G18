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

    Paciente* array_perdidos = new Paciente[tam_per];

    Paciente* array_fallecidos = new Paciente[tam_fall];

    array_pacientes = NULL;
    //lista_mas10 = NULL;
    //lista_menos10 = NULL;
    //array_perdidos = NULL;
    //array_fallecidos = NULL;

    /*
    Listas de tipo consulta:
    Declaramos en memoria la lista que utilizamos para leer los datos de las consultas de los pacientes
    */

    Consulta* array_consultas = new Consulta[tam_cons];

    //array_fallecidos = NULL;


    /*
    Listas de tipo Medico:
    Declaramos en memoria la lista que utilizamos para leer los datos de los medicos
    */

    Medico* array_medicos = new Medico[tam_med];

    //array_medicos = NULL;


    /*
   Listas de tipo Contacto:
   Declaramos en memoria la lista que utilizamos para leer los datos de contacto los pacientes
   */

    Contacto* array_contacto = new Contacto[tam_cont];

    //array_contacto = NULL;


                                        //Lectura de archivos\\

    //Herramientas para hacer la lectura

    int i = 0;

    string dummy;

    char coma = ',';

    ifstream IndataP;
    ifstream IndataC;
    ifstream Indatac;
    ifstream IndataM;

    //Lectura de pacientes:

    IndataP.open(Archivo_P, ios::in);

    IndataP >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma;

    cout << dummy << endl;

    while (IndataP) // reviso que el archivo sea distinto de end of file
    {

        resize_P(array_pacientes, tam_P);
        // hago el resize ya que no se la cantidad de personas en la lista
        tam_P++;
        IndataP >> array_pacientes[i].dni >> coma >> array_pacientes[i].Nombre >> coma
            >> array_pacientes[i].Apellido >> array_pacientes[i].sexo >> coma >>
            array_pacientes[i].Nacimiento >> coma >> array_pacientes[i].os >> coma
            >> array_pacientes[i].estado;
        // guardo a medida que voy leyendo en mi lista 
        

        i++; // incremento las iteraciones ! 

    }
    IndataP.close(); // cierro el archivo 

//Lectura de datos de contacto:

    Indatac.open(Archivo_C, ios::in);  // abro el archivo en modo lectura

    Indatac >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma;

    while (Indatac) // reviso que el archivo sea distinto de end of file
    {

        resize_c(array_contacto, tam_cont);
        // hago el resize ya que no se la cantidad de personas en la lista

        Indatac >> array_contacto[i].celular >> coma >> array_contacto[i].Direccion >> coma >> array_contacto[i].dni >> coma >> array_contacto[i].Mail >> coma >> array_contacto[i].Telefono >> coma;
        // guardo a medida que voy leyendo en mi lista 

        i++; // incremento las iteraciones ! 

    }
    Indatac.close(); // cierro el archivo 

 //Lectura de Consultas:

    IndataC.open(Archivo_C, ios::in); // abro el archivo de consultas en modo lectura 

    while (IndataC) // mientras que el archivo sea distinto del final 
    {
        IndataC >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado

        resize_C(array_consultas, tam_cons);

        // hago el resize ya que no se la cantidad de personas en la lista 

        IndataC >> array_consultas[i].dni_1 >> coma >> array_consultas[i].fecha_solicitado >> coma
            >> array_consultas[i].fecha_consulta >> array_consultas[i].Asistencia >> coma >> array_consultas[i].matricula >> coma;

        i++;

    }
    IndataC.close(); // cierro el archivo 

//Leemos datos de los medicos:

    IndataM.open(Archivo_M, ios::in); // abro el archivo de consultas en modo lectura 

    while (IndataM) // mientras que el archivo sea distinto del final 
    {
        IndataM >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma; // salteo encabezado

        resize_M(array_medicos, tam_med);

        // hago el resize ya que no se la cantidad de docs en la lista 

        IndataM >> array_medicos[i].matricula >> coma >> array_medicos[i].nombre >> coma
            >> array_medicos[i].apellido >> array_medicos[i].teldoc >> coma >> array_medicos[i].especialidad >> coma
            >> array_medicos[i].actividad;

        i++;

    } // ya tengo mi lista de doctores cargada 
    IndataM.close(); // cierro el archivo 

    

    separar_pacientes(array_pacientes, array_consultas, tam_P, tam_cons, lista_mas10, tam_mas10, lista_menos10, tam_menos10);

    Escribir_Archivados( lista_mas10, tam_mas10, lista_menos10, tam_menos10);

    Retornan(lista_menos10, tam_menos10);

    //Liberamos toda la memoria que utilizamos.

    delete[] array_pacientes;
    delete[] lista_mas10;
    delete[] lista_menos10;
    delete[] array_consultas;
    delete[] array_fallecidos;
    delete[] array_perdidos;

    //Fin del codigo

    getchar();

    return 0;
}