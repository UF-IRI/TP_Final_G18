#define _CRT_SECURE_NO_WARNINGS 

#include "Funciones.h"



void resize_P(Paciente* &array_pacientes, int &tam_P) 
{
    tam_P++; //Incrementamos en 1 la variable que tiene la diemension de la lista

    Paciente *array_paciente_aux = new Paciente [tam_P];  //Utilizamos una lista del tipo como auxiliar con 1 espacio 
                                                         // que la anterior

    for (int i = 0; i < tam_P-1; i++)      //Copiamos componente a componente los datos de la lista 
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    delete[] array_pacientes;             //Libramos la memoria de la lista vieja 

    array_pacientes = array_paciente_aux;  //Asignamos la direccion de memoria de la lista auxiliar a nuesta lista

    

}   

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

    
} 

void resize_c(Contacto *&array_contactos, int &tam_cont) {

    tam_cont++;

    Contacto* array_contacto_aux = new Contacto[tam_cont];

    for (int i = 0; i < tam_cont-1; i++) 
    {
        array_contacto_aux[i] = array_contactos[i];
    }

    delete[] array_contactos;
    
    array_contactos = array_contacto_aux;

}

void resize_M(Medico *&array_medicos, int &tam_med) {

    tam_med++;
    
    Medico* array_medicos_aux = new Medico[tam_med]; 

    for (int i = 0; i < tam_med-1; i++)
    {
        array_medicos_aux[i] = array_medicos[i];
    }

    delete[] array_medicos;
    
    array_medicos = array_medicos_aux;

}

void resize_PF(paciente_full *&array_pacientes, int &tam_Pf) 
{
    tam_Pf++;
    
    paciente_full* array_paciente_aux = new paciente_full[tam_Pf];  

    for (int i = 0; i < tam_Pf-1; i++) 
    {
        array_paciente_aux[i] = array_pacientes[i];
    }

    delete[] array_pacientes;
    
    array_pacientes = array_paciente_aux;

    

}  


tm conversion(string consulta)
{
    int Dia = 0;
    int Mes = 0;
    int Año = 0;
    int i = 0;
    int cont = 0;
    int cant = consulta.length();   //La cantidad de caracteres que tiene la fecha
    int aux1;
    int aux2;



    for (i = 0; i < consulta.length(); i++) {         //Recorremos 1 a 1 los caraceteres de la fecha

        if (consulta[i] == '/' && cont == 0) {       //Reconocemos el dia por la primera vez que encontramos la barra

            if (i == 2) {                            //Nos fijamos cuantas cifras tiene el dia

                aux1 = consulta[0] - 48;             //Como es un string se toma el valor ASCII por lo que le restamos 48
                aux2 = consulta[1] - 48;             //Para que tome el valor del numero

                Dia = (aux1 * 10) + aux2;           //En este caso como es de 2 cifras la primera la multiplicamos x10
                                                    //Para sumarla y que quede igual
            }

            if (i == 1) {                          //Mismo procedimiento para una cifra
                Dia = (consulta[0] - 48);
            }
            i++;
            cont++;
        }
        if (consulta[i] == '/' && cont == 1) {     //Con la segunda barra detectamos que es un mes

            if (consulta[i - 3] == '/') {        //Vamos hacia atras buscando la primera barra para ver cuantas cifras 
                                                // tiene el mes
                aux1 = consulta[i - 2] - 48;
                aux2 = consulta[i - 1] - 48;

                Mes = (aux1 * 10) + aux2;


            }

            if (consulta[i - 2] == '/')Mes = consulta[i - 1] - 48;   
            cont++;

        }
        if (consulta[i] == '/' && cont == 2) {                  //Cuando detectamos la tercera barra ya sabemos 
                                                               //Que los proximos 4 digitos son el año
            aux1 = consulta[i + 1] - 48;
            aux1 = consulta[i + 2] - 48;
            aux1 = consulta[i + 3] - 48;
            aux1 = consulta[i + 4] - 48;

            Año = ((consulta[i + 1] - 48) * 1000) + ((consulta[i + 2] - 48) * 100) + ((consulta[i + 3] - 48) * 10) + (consulta[i + 4] - 48);

            break; //Ya tenemos los el dia mes y año asignado por lo que dejamos de leer
        }

    }
    



    tm Fecha_tm;             //Declaramos una fecha de tipo tm

    Fecha_tm.tm_mday = Dia;  //Le asignamos los datos que recopilamos del string
    Fecha_tm.tm_mon = Mes;
    Fecha_tm.tm_year = Año;

    return Fecha_tm;           //retornamos la fecha en tm

}


void CopyArray_Paciente(Paciente *&Lista1, int Tam, Paciente *Lista2, int Pos) {

    Paciente* Aux = new Paciente[Tam];         //Utilizamos una lista de tipo como axuliar

    int i = 0;

    for (i = 0; i < Tam ; i++) {           //copiamos las listas componente a componente

        Aux[i] = Lista1[i];

    }

    Aux[Tam-1] = Lista2[Pos];           //Copiamos hasta la posicion del array que necesitabamos y dejamos el ultimo 
                                        //espacio de memoria libre
    delete[] Lista1;                   //Liberamos la memoria del la lista a la que queremos copiar

    Lista1 = Aux;                     //Asignamos la memoria de la lista auxiliar a la lista que queriamos copiar

}


float fecha(string fecha)
{
    tm Fecha = conversion(fecha);             //Convertimos la fecha de string a tm

    time_t auxiliar_fecha = time(nullptr);   //Inicializamos una fecha axiliar

    tm* hoy = localtime(&auxiliar_fecha);    //Tomamos la fecha actual en el auxiliar


    tm fecha_hoy;

    fecha_hoy.tm_mday = 28;            //Seteamos la fecha actual a mano porque lee mal la de windows
    fecha_hoy.tm_mon = 11;
    fecha_hoy.tm_year = 2022;

    int dif = 0;



    dif = fecha_hoy.tm_year - Fecha.tm_year;          //restamos los años

    return dif; // retorna la diferencia ( en años) 

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
                    

                    resize_P(Lista_menos10, tam_menos10);

                    CopyArray_Paciente(Lista_menos10, tam_menos10, array_pacientes, i);

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

                    resize_P(Lista_mas10, tam_mas10);

                    CopyArray_Paciente(Lista_mas10, tam_mas10, array_pacientes, i);


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

    if (Tam_P_Inactivo > 0 && Tam_P_Inactivo < 3)Imprimir_P(Paciente_Inactivo, Tam_P_Inactivo);

    if(Tam_P_Inactivo > 0)Imprimir_P(Paciente_Inactivo, 3);

    else  cout << "NO HAY PACIENTES." << endl;;

    cout << "----- LISTA DE PACIENTES ACTIVOS -----" << endl;
    cout << endl;
    cout << endl;

    if (Tam_P_Activo > 0 && Tam_P_Activo < 3)Imprimir_P(Paciente_Activo, 3);

    if (Tam_P_Activo > 0)Imprimir_P(Paciente_Activo, 3);

    else  cout << "NO HAY PACIENTES." << endl;;
    
    delete[] Paciente_Inactivo;
    delete[] Paciente_Activo;
}


void Escribir_Archivados(Paciente *Lista_mas10, int tam_mas10, Paciente* Lista_menos10, int tam_menos10) {


    int i = 0;

    string dummy;

    char coma = ',';

    int cont = 0;

    Paciente* array_archivados = new Paciente[cont];

    for (i = 0; i < tam_mas10; i++) {

        resize_P(array_archivados, cont);

        CopyArray_Paciente(array_archivados, cont, Lista_mas10, i);

    }
    for (i = 0; i < tam_menos10; i++) {


        if(Lista_menos10[i].estado == "fallecido"){

            resize_P(array_archivados, cont);

            CopyArray_Paciente(array_archivados, cont, Lista_menos10, i);
        
        }
    }

    cout << "Inicio de protocolo de archivamiento de pacientes..." << endl;

    cout << "Se archivaran: " << cont << " pacientes." << endl;


    ofstream Outdata1;

    if (cont > 0) {

        Outdata1.open("ARCHIVADOS.csv", ios::out);

        Outdata1 << "DNI , Nombre , Apellido , Sexo , Nacimiento , Estado , ObraSocial" << endl;

        for (i = 0; i < cont; i++) {

            Outdata1 << array_archivados[i].dni << coma << array_archivados[i].Nombre << coma
                << array_archivados[i].Apellido << coma << array_archivados[i].sexo << coma <<
                array_archivados[i].Nacimiento << coma << array_archivados[i].estado << coma
                << array_archivados[i].os << "\n";
        }

        delete[] array_archivados;

        Outdata1.close();

        cout << "Los pacientes fueron archivados correctamente." << endl;
    }
    else cout << "Cantidad de pacientes para archivar invalida." << endl;
}


void Retornan(Paciente *lista_menos10, int tam_menos10, Medico *array_medicos, int tam_med, Contacto *array_contacto,  int tam_cont, Consulta* array_consultas, int tam_cons) {


    int i = 0;
    int Doc = -1;
    int Phone = -1;

    char coma = ',';

    int cont = 0;
    int cont2 = 0;
    int opcion = 0;
    int opcion2 = 0;

    paciente_full* array_retornan = new paciente_full[cont];

    ofstream Outdata2;

    for (i = 0; i < tam_menos10; i++) {

        opcion = rand() % 2;  //Emulamos el momento en que llaman para preguntarle si vuelve

        opcion2 = rand() % 6;  //Y si la obra social

        //Hacer un swicht case con a cual de las 6 obras social se cambio y implementar ese cambio aca abajo

        if (lista_menos10[i].estado == "n/c" && opcion == 1) {

            Doc = BuscarMedico(lista_menos10[i].dni, array_medicos, tam_med, array_consultas, tam_cons);

            //Hacer una funcion que si el medico no esta en actividad encuentre otro de la misma especialidad para 
            //Asignarle
            //Tambien agregarle un filtro para que si los buscadores retornan -1 avisen que lo que se esta buscando no existe

            Phone = BuscarContacto(lista_menos10[i].dni, array_contacto, tam_cont);

            resize_PF(array_retornan, cont);

            paciente_full* Aux = new paciente_full[cont];

            array_retornan[cont - 1].dni = lista_menos10[i].dni;
            array_retornan[cont - 1].Nombre = lista_menos10[i].Nombre;
            array_retornan[cont - 1].Apellido = lista_menos10[i].Apellido;
            array_retornan[cont - 1].Telefono = array_contacto[Phone].celular;
            array_retornan[cont - 1].medico.matricula = array_medicos[Doc].matricula;
            array_retornan[cont - 1].medico.teldoc = array_medicos[Doc].teldoc;
            array_retornan[cont - 1].medico.nombre = array_medicos[Doc].nombre;
            array_retornan[cont - 1].medico.apellido = array_medicos[Doc].apellido;
            array_retornan[cont - 1].medico.especialidad = array_medicos[Doc].especialidad;
            array_retornan[cont - 1].medico.actividad = array_medicos[Doc].actividad;
            array_retornan[cont - 1].os = lista_menos10[i].os;
            array_retornan[cont - 1].retorna = "Si";


        }
        if (lista_menos10[i].estado == "n/c" && opcion == 0) {

            cont2++;
        }




    }

    cout << "\nEsperando a que administracion se comunique con los pacientes..." << endl;
    cout << "Nueva lista de pacientes recibida." << endl;
    cout << "Catalogando pacientes...\n" << endl;
    cout << "La cantidad de pacientes que no asistiran es de: " << cont2 << endl;
    cout << "La cantidad de pacientes que volveran es de: " << cont << endl;

    if (cont > 0) {

        Outdata2.open("RETORNAN.csv", ios::out);

        Outdata2 << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Telefono" << coma << "Matricula_Medico" << coma
            << "Telefono_Medico" << coma << "Nombre_Medico" << coma << "Apellido_Medico" << coma << "Especialidad_Medico" << coma
            << "Actividad_Medico" << coma << "ObraSocial" << coma << "Retornan" << endl;




        for (i = 0; i < cont; i++) {

            Outdata2 << array_retornan[i].dni << coma << array_retornan[i].Nombre << coma << array_retornan[i].Apellido << coma << array_retornan[i].Telefono
                << coma << array_retornan[i].medico.matricula << coma << array_retornan[i].medico.teldoc << coma << array_retornan[i].medico.nombre
                << coma << array_retornan[i].medico.apellido << coma << array_retornan[i].medico.especialidad << coma
                << array_retornan[i].medico.actividad << coma << array_retornan[i].os << coma << array_retornan[i].retorna << endl;

        }

        Outdata2.close();
    }
    else cout << "No hay pacientes que vuelvan, por lo tanto no se generara ningun archivo." << endl;

    delete[] array_retornan;

}


int BuscarMedico(string DNI, Medico* array_medicos, int tam_med, Consulta* array_consultas, int tam_cons) {

    int i = 0;
    int j = 0;

    for(i=0;i<tam_cons;i++){                      //Recorremos la lista de consultas

        if (DNI == array_consultas[i].dni_1) {    //Buscamos la consulta del paciente filtrando por dni

            for (j = 0; j < tam_med; j++) {      //Recorremos la lista de medicos

                if (array_consultas[i].matricula == array_medicos[j].matricula) {  //Buscamos al medico por matricula

                    return j;         //Retornamos la posicion de la lista donde esta el medico que queremos
                }
            }

        }
    
    }
    return -1;                          //Si no lo encontramos retornamos -1
}


int BuscarContacto(string DNI, Contacto* array_contacto, int tam_cont) {

    int i = 0;
    int j = 0;

    for (i = 0; i < tam_cont; i++) {

        if (DNI == array_contacto[i].dni) return i;       //Recorremos la lista de contacto y filtramos por dni

    }
    return -1; //-1 si no encontro el dni que le pasamos
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
