#include "MainMenu.h"

MainMenu::MainMenu()
{
	browser = 0;
	interact = 0;
	ptr = &interact;
	arrayName = new int(NULL);
	nameEvent = " ";
	dateEvent = " ";
	seatingEvent = 0;
	segmentsEvent = 0;
}

int MainMenu::getBrowser()
{
	return browser;
}

void MainMenu::setBrowser(int nBrowser)
{
	browser = nBrowser;
}

void MainMenu::cleanScreen()
{
#ifdef _WIN32
	system("cls"); // Limpia la pantalla en Windows
#else
	system("clear"); // Limpia la pantalla en Linux/macOS
#endif
}

//para la validacion de cedulas. 

bool MainMenu::validateID(string id) {
	if (id.length() != 9) {
		cout << "La cedula de identidad tiene que ser de '9' digitos." << endl;
		return false;
	}
	if (id[0] < '1' || id[0] > '8') {
		cout << "Ingrese su cedula de identidad correctamente." << endl;
		return false;
	}
	if (id[5] != '0') {
		cout << "Ingrese su cedula de identidad correctamente." << endl;
		return false;
	}
	for (int i = 0; i < id.length(); i++) { //https://docs.vultr.com/cpp/standard-library/cctype/isdigit
		if (!isdigit(id[i])) { // en el link me aparecio, tambien es para lo de ir haciendo la documentacion y poner bastantes cosas en la bibliografia
			cout << "Su cedula de identidad tiene que contener unicamente numeros." << endl;
			return false;
		}
	}
	return true;
} 
void MainMenu::inputIDs(string ids[], int maxIDs) {
	string id;
	int count = 0;

	while (count < maxIDs) {
		cout << "Ingrese su cedula de identidad:\n ";
		cin >> id;

		if (validateID(id)) {
			ids[count] = id;
			count++;
		}
		else {
			cout << "Cedula invalida. Por favor, intente nuevamente." << endl;
		}
	}
} 

//para la validacion de fechas. 

void MainMenu::askForDate() {
	string date;
	bool flag = false;

	while (!flag) {
		cleanScreen();
		cout << "Ingrese su fecha de nacimiento (formato DD/MM/YYYY): ";
		cin >> date;

		char dateNumbers[9];
		int aux = 0;


		for (int i = 0; date[i] != '\0'; i++) {
			if (isdigit(date[i])) {
				dateNumbers[aux++] = date[i];
			}
		}
		dateNumbers[aux] = '\0';

		if (aux != 8) {
			cout << "La fecha debe contener exactamente 8 digitos en el formato DDMMYYYY." << endl;
		}
		else {
			int day = (dateNumbers[0] - '0') * 10 + (dateNumbers[1] - '0');
			int month = (dateNumbers[2] - '0') * 10 + (dateNumbers[3] - '0');
			int year = (dateNumbers[4] - '0') * 1000 + (dateNumbers[5] - '0') * 100 + (dateNumbers[6] - '0') * 10 + (dateNumbers[7] - '0');
			int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			if (year > 2009) {
				cout << "Debe ser mayor de 15 a�os para comprar boletos." << endl;
			}
			else if (year < 1925) {
				cout << "El a�o debe ser mayor o igual a 1925. Ingrese una fecha v�lida." << endl;
			}
			else if (month < 1 || month > 12) {
				cout << "El mes debe estar entre 1 y 12." << endl;
			}
			else if (day < 1 || day > daysInMonth[month - 1]) {
				cout << "El dia no es valido para el mes ingresado." << endl;
			}
			else {
				cout << "Fecha valida." << endl;
				flag = true;
			}
		}

		if (!flag) {
			cout << "Fecha invalida. Intente nuevamente." << endl;
			cout << "Presione 'Enter' para continuar..." << endl;
			cin.ignore();
			cin.get();
			// https://www.minich.com/education/wyo/cplusplus/cplusplusch10/getfunction.htm
			// Para la bibliografia
		}
	}
}

void MainMenu::informationMenu()
{
	cleanScreen();
	cout << "1. Configurar Evento." << endl;
	cout << "2. Configurar descuentos." << endl;
	cout << "3. Vender entrada." << endl;
	cout << "4. Observar disponibilidad de asientos." << endl;
	cout << "5. Acerca de." << endl;
	cout << "6. Finalizar." << endl;
	cout << "Opcion: ";
}

void MainMenu::interfaseActivity()
{
	informationMenu();
	cin >> *ptr;
	if (*ptr == 1)
	{
		modifityEvent();
	}
	else if (*ptr == 2)
	{
		cout << "\n1. Volver atras" << endl;
		cout << "Opcion: ";
		cin >> *ptr;
		if (*ptr == 1)
		{
			interfaseActivity();
		}
	}
	else if (*ptr == 3)
	{
		cout << "\n1. Volver atras" << endl;
		cout << "Opcion: ";
		cin >> *ptr;
		if (*ptr == 1)
		{
			interfaseActivity();
		}
	}
	else if (*ptr == 4)
	{
		cout << "\n1. Volver atras" << endl;
		cout << "Opcion: ";
		cin >> *ptr;
		if (*ptr == 1)
		{
			interfaseActivity();
		}
	}
	else if (*ptr == 5)
	{
		cout << "\n1. Volver atras" << endl;
		cout << "Opcion: ";
		cin >> *ptr;
		if (*ptr == 1)
		{
			interfaseActivity();
		}
	}
	else if (*ptr == 6)
	{
		cout << "Saliendo del programa... " << endl;
	}
	else
	{
		cout << "\nEl indice es erroneo";
	}
}

void MainMenu::interMenuModifityEvent()
{
	cleanScreen();
	cout << "Configuracion del evento: " << endl;
	cout << "\n1. Crear un nuevo evento." << endl;
	cout << "2. Actualizar evento." << endl;
	cout << "3. Finalizar evento." << endl;
	cout << "4. Volver." << endl;
	cout << "Opcion: ";
}

void MainMenu::modifityEvent()
{
	interMenuModifityEvent();
	cin >> *ptr;
	if (*ptr == 1)
	{
		informationEvent();
	}
	if (*ptr == 2)
	{
		cout << "\nActualizacion de datos del evento" << endl;
	}
	if (*ptr == 3)
	{
		cout << "\n�Seguro que quieres eliminar un evento?" << endl;
	}
	if (*ptr == 4)
	{
		interfaseActivity();
	}
}

void MainMenu::informationEvent()
{
	cleanScreen();
	cout << "Informacion necesaria para la creacion del evento: " << endl;
	cout << "\nNombre del evento    |   " << endl;
	cout << "Fecha del evento     |   " << endl;
	cout << "Numero de segmentos  |   " << endl;
	cout << "Numero de asientos   |   " << endl;
	cout << "\nIngrese el nombre del evento: ";
	cin >> nameEvent;
	cout << "Ingrese la fecha del evento: ";
	cin >> dateEvent;
	cout << "Ingrese el numero de segmentos: ";
	cin >> segmentsEvent;
	cout << "Ingrese el numero de asientos: ";
	cin >> seatingEvent;


}

void MainMenu::createdEventNameInformation()
{
	informationEvent();
	cleanScreen();
	cout << "Informacion evento: " << endl;
	cout << "\nNombre del evento    |   " << nameEvent << endl;
	cout << "Fecha del evento     |   " << dateEvent << endl;
	cout << "Numero de segmentos  |   " << segmentsEvent << endl;
	cout << "Numero de asientos   |   " << seatingEvent << endl;
	cout << "\n1. Volver atras" << endl;
	cout << "Opcion: ";
	cin >> *ptr;
	if (*ptr == 1)
	{
		modifityEvent();
	}
}
