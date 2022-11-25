#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize_P(Paciente* array_pacientes, int tam_P) // incrementa la dimension de 1 en 1 del array
{
    Paciente* array_paciente_aux = new Paciente[tam_P + 1];  // icremento de a 1

    for (int i = 0; i < tam_P; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    array_pacientes = array_paciente_aux;

    delete[] array_paciente_aux; // libero memoria 

} // aumenta dimension de pacientes  

void resize_C(Consulta* array_consultas, int tam_cons)
{
    Consulta* array_consultas_aux = new Consulta[tam_cons + 1];

    for (int i = 0; i < tam_cons; i++)
    {
        array_consultas_aux[i] = array_consultas[i];
    }


    array_consultas = array_consultas_aux;

    delete[] array_consultas;
} // aumenta dimension de consultas

void resize_c(Contacto* array_contactos, int tam_cont) {

    Contacto* array_contacto_aux = new Contacto[tam_cont + 1];  // icremento de a 1

    for (int i = 0; i < tam_cont; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_contacto_aux[i] = array_contactos[i];
    }

    array_contactos = array_contacto_aux;

    delete[] array_contacto_aux; // libero memoria 

}

void resize_M(Medico* array_medicos, int tam_med) {

    Medico* array_medicos_aux = new Medico[tam_med + 1];  // icremento de a 1

    for (int i = 0; i < tam_med; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_medicos_aux[i] = array_medicos[i];
    }

    array_medicos = array_medicos_aux;

    delete[] array_medicos_aux; // libero memoria 

}

void resize_PF(paciente_full* array_pacientes, int tam_P) // incrementa la dimension de 1 en 1 del array
{
    paciente_full* array_paciente_aux = new paciente_full[tam_P + 1];  // icremento de a 1

    for (int i = 0; i < tam_P; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    array_pacientes = array_paciente_aux;

    delete[] array_paciente_aux; // libero memoria 

} // aumenta dimension de pacientes  


tm conversion(string consulta)
{
    fstream Fecha_str(consulta);

    int Dia = 0;
    int Mes = 0;
    int Año = 0;

    string separador = "/";

    Fecha_str >> Dia >> separador >> Mes >> separador >> Año;

    tm Fecha_tm;

    Fecha_tm.tm_mday = Dia;
    Fecha_tm.tm_mon = Mes;
    Fecha_tm.tm_year = Año;

    return Fecha_tm;

}


float fecha(string fecha)
{
    tm Fecha = conversion(fecha); // primero convierto de string a tm 
    time_t auxiliar_fecha = time(0);

    tm* hoy = localtime(&auxiliar_fecha);

    tm fecha_hoy;

    fecha_hoy.tm_mday = hoy->tm_mday;
    fecha_hoy.tm_mon = hoy->tm_mon;
    fecha_hoy.tm_year = hoy->tm_year;

    int dif = 0;

    time_t aux_fin = mktime(&fecha_hoy);
    time_t aux_inicio = mktime(&Fecha);
    dif = difftime(aux_fin, aux_inicio) / (3153600);

    return dif; // retorna la diferencia ( en anios) 

}


void separar_pacientes(Paciente* array_pacientes, Consulta* array_consultas, int tam_P, int tam_cons, Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10)
{

    // le paso las listas de los pacientes y de las consultas 
   // y las listas vacias donde voy separar 

    int n1 = 0; // para falso_Archivado
    int n2 = 0; // para si_fue_menos10 

    Paciente* falso_archivado = new Paciente[n1]; // listas donde voy a guardar los parcientes que SI fueron 
    Paciente* si_fue_menos10 = new Paciente[n2]; // los separo tambien + 10 años  y - 10 años, // null pointer

    tam_mas10 = 0;  //Para +10 años
    tam_menos10 = 0;  //Para -10 años 

    string aux;


    for (int i = 0; i < tam_P; i++)

    {
        for (int j = 0; j < tam_cons; j++)
        {
            if (array_consultas[j].dni_1 == array_pacientes[i].dni)
            {

                aux = array_consultas[j].fecha_consulta;

                float diferencia = fecha(aux); // se le pasa direccion de memoria

                if (diferencia < 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que no asistieron
                    //Para intentar recuperarlos posteriormente
                {
                    if (tam_mas10 == 0) Lista_menos10[tam_mas10] = array_pacientes[i];

                    resize_P(Lista_menos10, tam_mas10);

                    Lista_menos10[tam_mas10] = array_pacientes[i];

                }

                if (diferencia < 10 && array_consultas[j].Asistencia == true)  //Solo guardamos los pacientes que SI asistieron
                    //Para tenerlos catalogados tambien 
                {
                    if (n1 == 0) falso_archivado[n1] = array_pacientes[i];

                    resize_P(falso_archivado, n1);

                    falso_archivado[n1] = array_pacientes[i];

                }


                if (diferencia > 10 && array_consultas[j].Asistencia)  //Solo guardamos los pacientes que no asistieron
                    //Para intentar recuperarlos posteriormente
                {
                    if (tam_mas10 == 0) Lista_mas10[tam_menos10] = array_pacientes[i];

                    resize_P(Lista_mas10, tam_menos10);

                    Lista_mas10[tam_menos10] = array_pacientes[i];

                    Lista_mas10[tam_menos10].estado = "Archivado";

                }

                if (diferencia > 10 && array_consultas[j].Asistencia == false)  //Solo guardamos los pacientes que si asistieron
                    //Para llevar control, no hacer nada con estos pacientes no es opcion ;) 
                {
                    if (n2 == 0) si_fue_menos10[tam_menos10] = array_pacientes[i];


                    resize_P(si_fue_menos10, n2);

                    Lista_mas10[tam_menos10] = array_pacientes[i];


                }

                
            }
        }

    }

    cout << "----- LISTA DE PACIENTES INACTIVOS -----" << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < n1; i++)
    {
        cout << "Paciente : " << falso_archivado[i].Apellido << "  DNI: " << falso_archivado[i].dni << endl;
        cout << endl;
    }

    cout << "----- LISTA DE PACIENTES RESPONSABLES QUE ASISTEN A SUS CONSULTAS -----" << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < n2; i++)
    {
        cout << "Paciente :  " << si_fue_menos10[i].Apellido << "  DNI : " << si_fue_menos10[i].dni << endl;
        cout << endl;
    }

    delete[] si_fue_menos10;
    delete[] falso_archivado;
}


void Escribir_Archivados(Paciente* Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10) {


    int i = 0;

    string dummy;

    char coma = ',';

    int cont = 0;

    Paciente* array_archivados = new Paciente[cont];

    for (i = 0; i < tam_mas10; i++) {


        if (Lista_mas10[i].estado == "Archivado") {

            resize_P(array_archivados, cont);

            array_archivados[cont] = Lista_mas10[i];

            cont++;

        }
        if (Lista_menos10[i].estado == "fallecido") {

            resize_P(array_archivados, cont);

            array_archivados[cont] = Lista_menos10[i];

            cont++;

        }
    }



    ofstream Outdata1;

    Outdata1.open("ARCHIVADOS.csv", ios::out);

    Outdata1 << "dni , nombre , apellido , sexo , natalicio , estado , id_os" << endl;

    for (i = 0; i < cont; i++) {

        Outdata1 << array_archivados[i].Apellido << coma << array_archivados[i].dni << coma <<
            array_archivados[i].estado << coma << array_archivados[i].Nacimiento << coma <<
            array_archivados[i].Nombre << coma << array_archivados[i].os << coma <<
            array_archivados[i].sexo << coma << "(Archivado)";
    }

    delete[] array_archivados;

    Outdata1.close();
}


void Retornan(Paciente* lista_menos10, int tam_menos10) {


    int i = 0;

    char coma = ',';

    int cont = 0;
    int opcion = 0;

    paciente_full* array_retornan = new paciente_full[cont];

    ofstream Outdata2;

    Outdata2.open("RETORNAN.csv", ios::out);

    for (i = 0; i < tam_menos10; i++) {

        opcion = rand() % 2;  //Emulamos el momento en que llaman para preguntarle si vuelve

        if (lista_menos10[i].estado == "n/c" && opcion == 1) {

            resize_PF(array_retornan, cont);

            array_retornan[cont].Apellido = lista_menos10[i].Apellido;
            array_retornan[cont].dni = lista_menos10[i].dni;
            array_retornan[cont].Nombre = lista_menos10[i].Nombre;
            array_retornan[cont].os = lista_menos10[i].os;
            array_retornan[cont].retorna = true;


        }
        if (lista_menos10[i].estado == "n/c" && opcion == 0) {

            array_retornan[cont].Apellido = lista_menos10[i].Apellido;
            array_retornan[cont].dni = lista_menos10[i].dni;
            array_retornan[cont].Nombre = lista_menos10[i].Nombre;
            array_retornan[cont].os = lista_menos10[i].os;
            array_retornan[cont].retorna = false;
        }




    }

    for (i = 0; i < cont; i++) {

        Outdata2 << array_retornan[i].Apellido << coma << array_retornan[i].dni << coma <<
            array_retornan[i].medico << coma << array_retornan[i].Nombre << coma <<
            array_retornan[i].os << coma << array_retornan[i].retorna << coma;
    }

    delete[] array_retornan;

    Outdata2.close();

}


void Imprimir_P(Paciente *array_pacientes, int tam_P) {

    int i = 0;

    for (i = 0; i < tam_P; i++) {

        cout << "---------------------------------------------------------------------------" << endl;

        cout << "\nDNI: " << array_pacientes[i].dni << "\nNombre: " << array_pacientes[i].Nombre << "\nApellido: "
            << array_pacientes[i].Apellido << "\nSexo: " << array_pacientes[i].sexo << "\nNacimiento: " <<
            array_pacientes[i].Nacimiento << "\nObra social: " << array_pacientes[i].os << "\nEstado: "
            << array_pacientes[i].estado << endl;
    }
}
