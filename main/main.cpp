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

    string Archivo_P = "..\\..\\..\\..\\data_files\\input\\IRI_Pacientes.csv";
    string Archivo_C = "..\\..\\..\\..\\data_files\\input\\IRI_Consultas.csv";
    string Archivo_M = "..\\..\\..\\..\\data_files\\input\\IRI_Medicos.csv";
    string Archivo_c = "..\\..\\..\\..\\data_files\\input\\IRI_Contactos.csv";

    Paciente* array_pacientes = new Paciente[tam_P];

    Paciente* lista_mas10 = new Paciente[tam_mas10];

    Paciente* lista_menos10 = new Paciente[tam_menos10];

    Paciente* array_perdidos = new Paciente[tam_per];

    Paciente* array_fallecidos = new Paciente[tam_fall];

    array_pacientes = NULL;
    lista_mas10 = NULL;
    lista_menos10 = NULL;
    array_perdidos = NULL;
    array_fallecidos = NULL;

    /*
    Listas de tipo consulta:
    Declaramos en memoria la lista que utilizamos para leer los datos de las consultas de los pacientes
    */

    Consulta* array_consultas = new Consulta[tam_cons];

    array_fallecidos = NULL;


    /*
    Listas de tipo Medico:
    Declaramos en memoria la lista que utilizamos para leer los datos de los medicos
    */

    Medico* array_medicos = new Medico[tam_med];

    array_medicos = NULL;


    /*
   Listas de tipo Contacto:
   Declaramos en memoria la lista que utilizamos para leer los datos de contacto los pacientes
   */

    Contacto* array_contacto = new Contacto[tam_cont];

    array_contacto = NULL;


                                        //Lectura de archivos\\

    //Herramientas para hacer la lectura

    int i = 0;

    string dummy;

    char coma = ',';
    
//Lectura de pacientes:


    ifstream IndataP;

    IndataP.open(Archivo_P, ios::in);  

    IndataP >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma;

    while (!IndataP.eof()) // reviso que el archivo sea distinto de end of file
    {

        resize_P(array_pacientes, tam_P);
        // hago el resize ya que no se la cantidad de personas en la lista

        IndataP >> array_pacientes[i].dni >> coma >> array_pacientes[i].Nombre >> coma
            >> array_pacientes[i].Apellido >> array_pacientes[i].sexo >> coma >>
            array_pacientes[i].Nacimiento >> coma >> array_pacientes[i].os >> coma
            >> array_pacientes[i].estado;
        // guardo a medida que voy leyendo en mi lista 


        i++; // incremento las iteraciones ! 

    }
    IndataP.close(); // cierro el archivo 

    for (i = 0; i < tam_P; i++) {

        cout << "---------------------------------------------------------------------------" << endl;

        cout << "\nDNI: " << array_pacientes[i].dni << "\nNombre: " << array_pacientes[i].Nombre << "\nApellido: "
            << array_pacientes[i].Apellido << "\nSexo: " << array_pacientes[i].sexo << "\nNacimiento: " <<
            array_pacientes[i].Nacimiento << "\nObra social: " << array_pacientes[i].os << "\nEstado: "
            << array_pacientes[i].estado << endl;
    }
    

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