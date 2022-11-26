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
    string Nombre;
    string Apellido;
    string dni;
    string Nacimiento;
    string sexo;
    string os; // obra social
    string estado; // internado, fallecido, nc
}
Paciente;               //Estructura para leer los pacientes

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

typedef struct
{
    string Nombre;
    string Apellido;
    string dni;
    string os; // obra social
    string retorna; // si el paciente retorna o no. 
    string medico;  // datos del ultimo medico q atendio 

}
paciente_full;          // Estructura para guardar todos los datos del paciente



                               //Declaracion de las funciones\\

//Impresion de archivos:

void Escribir_Archivados(Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10);

void Retornan(Paciente* lista_menos10, int tam_menos10);

//void Escribir_Retornan(Paciente* Lista_mas10, int tam_mas10);

//Clasificaciones por lista de los pacientes:

//Organiza los pacientes en listas segun su ultima consulta (+10a�os/-10a�os)
void separar_pacientes(Paciente* array_pacientes, Consulta* array_consultas, int tam, int tam_cons, Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10);


//Herramientas de apoyo:

tm conversion(string consulta);                               //Convierte una variable de tipo string a tm

float fecha(string fecha);                                   //Retorna en a�os la diferencia entre 2 fechas

void resize_P(Paciente* &array_pacientes, int &tam_P);                      //Incrementa la dimension de la lista para tipos Paciente

void resize_C(Consulta* array_consultas, int tam_cons);    //Incrementa la dimension de la lista para tipos Consulta

void resize_M(Medico* array_medicos, int tam_med);           //Incrementa la dimension de la lista para tipos Medico

void resize_c(Contacto* array_contactos, int tam_cont);

void resize_PF(paciente_full* array_pacientes, int tam_P);

void Imprimir_P(Paciente array_pacientes, int tam_P);