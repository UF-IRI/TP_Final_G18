#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize_P(Paciente* &array_pacientes, int &tam_P) // incrementa la dimension de 1 en 1 del array
{
    tam_P++;

    Paciente *array_paciente_aux = new Paciente [tam_P];  // icremento de a 1

    //array_paci

    for (int i = 0; i < tam_P-1; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    delete[] array_pacientes;

    array_pacientes = array_paciente_aux;

    

} // aumenta dimension de pacientes  

void resize_C(Consulta *&array_consultas, int &tam_cons)
{

    tam_cons++;

    Consulta* array_consultas_aux = new Consulta[tam_cons];

    for (int i = 0; i < tam_cons-1; i++)
    {
        array_consultas_aux[i] = array_consultas[i];
    }

    delete[] array_consultas;
    
    array_consultas = array_consultas_aux;

    
} // aumenta dimension de consultas

void resize_c(Contacto *&array_contactos, int &tam_cont) {

    tam_cont++;

    Contacto* array_contacto_aux = new Contacto[tam_cont];  // icremento de a 1

    for (int i = 0; i < tam_cont-1; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_contacto_aux[i] = array_contactos[i];
    }

    delete[] array_contactos;
    
    array_contactos = array_contacto_aux;

}

void resize_M(Medico *&array_medicos, int &tam_med) {

    tam_med++;
    
    Medico* array_medicos_aux = new Medico[tam_med];  // icremento de a 1

    for (int i = 0; i < tam_med-1; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_medicos_aux[i] = array_medicos[i];
    }

    delete[] array_medicos;
    
    array_medicos = array_medicos_aux;

    

}

void resize_PF(paciente_full *&array_pacientes, int &tam_Pf) // incrementa la dimension de 1 en 1 del array
{
    tam_Pf++;
    
    paciente_full* array_paciente_aux = new paciente_full[tam_Pf];  // icremento de a 1

    for (int i = 0; i < tam_Pf-1; i++) // en la ultima posicion se agrega una mas, se redimensiona
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    delete[] array_pacientes;
    
    array_pacientes = array_paciente_aux;

    

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


void CopyArray_Paciente(Paciente *&Lista1, int Tam, Paciente *Lista2, int Pos) {

    Paciente* Aux = new Paciente[Tam];

    int i = 0;

    for (i = 0; i < Tam ; i++) {

        Aux[i] = Lista1[i];

    }

    Aux[Tam-1] = Lista2[Pos];

    delete[] Lista1;

    Lista1 = Aux;

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

    float dif = 0;

    time_t aux_fin = mktime(&fecha_hoy);
    time_t aux_inicio = mktime(&Fecha);
    dif = difftime(aux_fin, aux_inicio) / (3153600);

    return dif; // retorna la diferencia ( en anios) 

}


void separar_pacientes(Paciente* array_pacientes, Consulta* array_consultas, int tam_P, int tam_cons, Paciente *&Lista_mas10, int &tam_mas10, Paciente *&Lista_menos10, int &tam_menos10)
{

    // le paso las listas de los pacientes y de las consultas 
   // y las listas vacias donde voy separar 

    int Tam_P_Activo = 0; // para falso_Archivado
    int Tam_P_Inactivo = 0; // para si_fue_menos10 

    Paciente* Paciente_Activo = new Paciente[Tam_P_Activo]; // listas donde voy a guardar los parcientes que SI fueron 
    Paciente* Paciente_Inactivo = new Paciente[Tam_P_Inactivo]; // los separo tambien + 10 años  y - 10 años, // null pointer

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

                if (diferencia < 10 && array_consultas[j].Asistencia == "0")  //Solo guardamos los pacientes que no asistieron
                    //Para intentar recuperarlos posteriormente
                {
                    

                    resize_P(Lista_menos10, tam_mas10);

                    CopyArray_Paciente(Lista_menos10, tam_mas10, array_pacientes, i);

                }

                if (diferencia < 10 && array_consultas[j].Asistencia == "1")  //Solo guardamos los pacientes que SI asistieron
                    //Para tenerlos catalogados tambien 
                {
                    

                    resize_P(Paciente_Activo, Tam_P_Activo);

                    CopyArray_Paciente(Paciente_Activo, Tam_P_Activo, array_pacientes, i);

                }


                if (diferencia > 10 && array_consultas[j].Asistencia == "0")  //Solo guardamos los pacientes que no asistieron
                    //Para intentar recuperarlos posteriormente
                {

                    resize_P(Lista_mas10, tam_menos10);

                    CopyArray_Paciente(Lista_mas10, tam_menos10, array_pacientes, i);

                    Lista_mas10[tam_menos10-1].estado = "Archivado";

                }

                if (diferencia > 10 && array_consultas[j].Asistencia == "1")  //Solo guardamos los pacientes que si asistieron
                                                                             //Para llevar control, no hacer nada con estos pacientes no es opcion ;) 
                {

                    resize_P(Paciente_Inactivo, Tam_P_Inactivo);

                    
                    CopyArray_Paciente(Paciente_Inactivo, Tam_P_Inactivo, array_pacientes, i);

                }

                
            }
        }

    }

    //Reduje esto a 3 porque sino imprime demasiados

    cout << "----- LISTA DE PACIENTES INACTIVOS -----" << endl;
    cout << endl;
    cout << endl;

    if (n1 > 0 && n1 < 3)Imprimir_P(falso_archivado, n1);

    if(n1 > 0)Imprimir_P(falso_archivado, 3);

    else  cout << "NO HAY PACIENTES." << endl;;

    cout << "----- LISTA DE PACIENTES RESPONSABLES QUE ASISTEN A SUS CONSULTAS -----" << endl;
    cout << endl;
    cout << endl;

    if (n2 > 0 && n2 < 3)Imprimir_P(si_fue_menos10, 3);

    if (n2 > 0)Imprimir_P(si_fue_menos10, 3);

    else  cout << "NO HAY PACIENTES." << endl;;
    
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
            array_retornan[cont].retorna = "true";


        }
        if (lista_menos10[i].estado == "n/c" && opcion == 0) {

            array_retornan[cont].Apellido = lista_menos10[i].Apellido;
            array_retornan[cont].dni = lista_menos10[i].dni;
            array_retornan[cont].Nombre = lista_menos10[i].Nombre;
            array_retornan[cont].os = lista_menos10[i].os;
            array_retornan[cont].retorna = "false";
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

        cout << "--------------------------------------------" << endl;
        cout << "DNI: " << array_pacientes[i].dni << endl;
        cout << "Nombre: " << array_pacientes[i].Nombre << endl;
        cout << "Apellido: " << array_pacientes[i].Apellido << endl;
        cout << "Sexo: " << array_pacientes[i].sexo << endl;
        cout << "Nacimiento: " << array_pacientes[i].Nacimiento << endl;
        cout << "Obra social: " << array_pacientes[i].os << endl;
        cout << "Estado: " << array_pacientes[i].estado << endl;
    }
}


void Imprimir_c(Contacto *array_contacto, int tam_cont) {


    int i = 0;

    for (i = 0; i < tam_cont; i++) {

        cout << "--------------------------------------------" << endl;
        cout << "DNI: " << array_contacto[i].dni << endl;
        cout << "Nombre: " << array_contacto[i].Telefono << endl;
        cout << "Apellido: " << array_contacto[i].celular << endl;
        cout << "Sexo: " << array_contacto[i].Direccion << endl;
        cout << "Nacimiento: " << array_contacto[i].Mail << endl;
    }
}


void Imprimir_C(Consulta* array_consulta, int tam_cons) {


    int i = 0;

    for (i = 0; i < tam_cons; i++) {

        cout << "--------------------------------------------" << endl;
        cout << "DNI: " << array_consulta[i].dni_1 << endl;
        cout << "Fecha en que se solicita el turno: " << array_consulta[i].fecha_solicitado << endl;
        cout << "Fecha del turno: " << array_consulta[i].fecha_consulta << endl;
        cout << "Asistencia: " << array_consulta[i].Asistencia << endl;
        cout << "Matricula del medico: " << array_consulta[i].matricula << endl;
    }
}


void Imprimir_M(Medico* array_Medicos, int tam_M) {


    int i = 0;

    for (i = 0; i < tam_M; i++) {

        cout << "--------------------------------------------" << endl;
        cout << "Matricula: " << array_Medicos[i].matricula << endl;
        cout << "Nombre: " << array_Medicos[i].nombre << endl;
        cout << "Apellido: " << array_Medicos[i].apellido << endl;
        cout << "Telefono: " << array_Medicos[i].teldoc << endl;
        cout << "En ejercicio: " << array_Medicos[i].actividad << endl;
    }
}
