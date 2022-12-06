#include "gmock/gmock.h"
#include "Funciones.h"

namespace foobar::tests {

	//Testear conversion, fecha, buscar medico y buscar contacto

	TEST(Test_BuscarMedico, Test_Caso1)
	{
		int tam_med = 1;
		int tam_cons = 1;
		Consulta* testeo = new Consulta[tam_cons];
		Medico* prueba = new Medico[tam_med];
		string DNI = "10242587";
		testeo[0].dni_1= "10242587";
		testeo[0].matricula = "12-566-1323";
		prueba[0].matricula = "03-912-2018";
		prueba[0].nombre = "Gonzalo";
		prueba[0].apellido = "Martinez";
		prueba[0].teldoc = "+54(014)44587898";
		prueba[0].actividad = "1";
		prueba[0].especialidad = "Cardiologia";

		int Retorno = BuscarMedico(DNI,prueba,tam_med,testeo,tam_cons);

		ASSERT_THAT(prueba[0].matricula, Retorno);//retorna -1 ya que no lo encuentra
	}
	TEST(Test_BuscarMedico, Test_Caso2)
	{
		int tam_med = 1;
		int tam_cons = 1;
		Consulta* testeo = new Consulta[tam_cons];
		Medico* prueba = new Medico[tam_med];
		string DNI = "10242587";
		testeo[0].dni_1 = "10242587";
		testeo[0].matricula = "12-566-1323";
		prueba[0].matricula = "12-566-1323";
		prueba[0].nombre = "Kathi";
		prueba[0].apellido = "Bernard";
		prueba[0].teldoc = "+54(313)88809965";
		prueba[0].actividad = "1";
		prueba[0].especialidad = "oncologia_medica";

		int Retorno = BuscarMedico(DNI, prueba, tam_med, testeo, tam_cons);

		ASSERT_THAT(prueba[0].matricula, Retorno);//retorna la posicion en la lista donde esta el medico

	}
	
	TEST(Test_Buscarcontacto, Test_Caso1)
	{
		int tam_cont = 1;
		Contacto* testeo = new Contacto[tam_cont];
		string DNI = "10242587";
		testeo[0].dni = "10242587";

		int Retorno = BuscarContacto(DNI, testeo, tam_cont);

		ASSERT_THAT(testeo[0].dni, Retorno);//retorna la posicion en la lista donde esta el contacto

	}
	TEST(Test_Buscarcontacto, Test_Caso2)
	{
		int tam_cont = 1;
		Contacto* testeo = new Contacto[tam_cont];
		string DNI = "41689256";
		testeo[0].dni = "10242587";

		int Retorno = BuscarContacto(DNI, testeo, tam_cont);

		ASSERT_THAT(testeo[0].dni, Retorno);//retorna -1 ya que no lo encuentra

	}
	TEST(Test_conversion, Test_Caso1)
	{
		
		string fecha = "09/12/2018";
		
		tm Retorno = conversion(fecha);

		ASSERT_THAT(fecha, Retorno);//retorna la fecha en tm

	}
	TEST(Test_conversion, Test_Caso2)
	{

		string fecha = "009/012/2018";

		tm Retorno = conversion(fecha);

		ASSERT_THAT(fecha, -1);//retorna -1 ya que deberia fallar

	}
	TEST(Test_fecha, Test_Caso1)
	{

		string Fecha = "09/12/2018";

		float Retorno = fecha(Fecha);

		ASSERT_THAT(Fecha, Retorno);//retorna la diferencia en años hasta la fecha actual

	}
	TEST(Test_fecha, Test_Caso2)
	{

		string Fecha = "09/12/2024";

		float Retorno = fecha(Fecha);   

		ASSERT_THAT(Fecha, -1);//retorna -1 ya que deberia fallar



	}
}
