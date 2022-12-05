#include "gmock/gmock.h"
#include "Funciones.h"

namespace foobar::tests {

	//Testear conversion, fecha, buscar medico y buscar contacto


	TEST(leer_pacientes_T1, test1) {
		
		string nombre = "IRI_Pacientes.csv";

		int tam = 0;

		Paciente* array_pacientes = new Paciente[tam];

		*array_pacientes = NULL;


        ASSERT_THAT(leer_pacientes(nombre, array_pacientes, tam) * array_pacientes != NULL); // leer google test , el null debe ser null pointer

		delete[]array_pacientes;
	}

	TEST(leer_consultas_T1, test1) {

		string nombre = "IRI_Consultas.csv";

		int tam = 0;

		Consulta* array_consultas = new Consulta[tam];

		*array_consultas = NULL;


		ASSERT_THAT(leer_consultas(nombre, array_consultas, tam), *array_consultas != NULL);

		delete[]array_consultas;

	}

	TEST(leer_medicos_T1, test1) {

		string nombre = "IRI_Pacientes.csv";

		int tam = 0;

		Medico* array_medicos = new Medico[tam];

		*array_medicos = NULL;


		ASSERT_THAT(leer_medicos(nombre, array_medicos, tam), *array_medicos != NULL);

		delete[]array_medicos;
	}

	TEST(leer_Contactos_T1, test1) {

		string nombre = "IRI_Contactos.csv";

		int tam = 0;

		Contacto* leer_Contactos = new Contacto[tam];

		*leer_Contactos = NULL;


		ASSERT_THAT(leer_medicos(nombre, leer_Contactos, tam), *leer_Contactos != NULL);

		delete[]leer_Contactos;
	}
}