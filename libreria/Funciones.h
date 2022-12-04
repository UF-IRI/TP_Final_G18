#include <iostream>
#include <string.h>
#include <ctime>
#include <fstream>
#include <stdlib.h>

using namespace std;

//Declaramos las estructuras de datos

typedef struct
{

    string dni;
    string Telefono;
    string celular;
    string Direccion;
    string Mail;
}
Contacto;

typedef struct
{
    string dni_1;
    string fecha_consulta;
    string fecha_solicitado;
    string matricula;
    string Asistencia;
}
Consulta;

typedef struct
{
    string dni;
    string Nombre;
    string Apellido;
    string sexo;
    string Nacimiento;
    string estado; 
    string os; 
}
Paciente;               

typedef struct
{
    string ID;
    string Nombre;
}
Obrasoc;

typedef struct
{
    string matricula;
    string teldoc;
    string nombre;
    string apellido;
    string especialidad;
    string actividad;

}
Medico;

//Estructura de paciente con los datos que se piden para generar el archivo

typedef struct
{
    string dni;
    string Nombre;
    string Apellido;
    string Telefono;
    Medico medico;
    string os; 
    string retorna;  

}
paciente_full;



                               //Declaracion de las funciones\\

//Impresion de archivos:

void Escribir_Archivados(Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10);

void Retornan(Paciente* lista_menos10, int tam_menos10, Medico* array_medicos, int tam_med, Contacto* array_contacto, int tam_cont, Consulta* array_consultas, int tam_cons);


//Clasificaciones por lista de los pacientes:

//Organiza los pacientes en listas segun su ultima consulta (+10años/-10años)
void separar_pacientes(Paciente *array_pacientes, Consulta *array_consultas, int tam, int tam_cons, Paciente *&Lista_mas10, int &tam_mas10, Paciente *&Lista_menos10, int &tam_menos10);


//Herramientas de apoyo:

tm conversion(string consulta);                               //Convierte una variable de tipo string a tm

float fecha(string fecha);                                   //Retorna en años la diferencia entre 2 fechas

void CopyArray_Paciente(Paciente *&Lista1, int Tam, Paciente *Lista2, int Pos);//copia dos listas dinamicas de tipo paciente

void resize_P(Paciente *&array_pacientes, int &tam_P);                      //Incrementa la dimension de la lista para tipos Paciente

void resize_C(Consulta *&array_consultas, int &tam_cons);    //Incrementa la dimension de la lista para tipos Consulta

void resize_M(Medico *&array_medicos, int &tam_med);           //Incrementa la dimension de la lista para tipos Medico

void resize_c(Contacto *&array_contactos, int &tam_cont);      //Incrementa la dimension de la lista para tipos contacto

void resize_PF(paciente_full *&array_pacientes, int &tam_P);   //Incrementa la dimension de la lista para tipos paciente full

int BuscarMedico(string DNI, Medico* array_medicos, int tam_med, Consulta* array_consultas, int tam_cons);  //Busca al medico que atendo a un paciente en su ultima consulta

int BuscarContacto(string DNI, Contacto* array_contacto, int tam_cont);  //Busca los datos de contacto de un paciente

//Funciones para imprimir tipos de listas (es un extra para hacer pruebas y chekeos)

void Imprimir_P(Paciente *array_pacientes, int tam_P);

void Imprimir_c(Contacto* array_contacto, int tam_cont);

void Imprimir_C(Consulta* array_consulta, int tam_cons);

void Imprimir_M(Medico* array_Medicos, int tam_M);