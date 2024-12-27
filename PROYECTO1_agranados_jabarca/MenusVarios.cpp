#include "MainMenu.h"

MainMenu::MainMenu()
{
	browser = 0;
	interact = 0;
	ptr = &interact;
	arrayName = new int(size); 
	nameEvent = " ";
	dateEvent = " ";
	id = " "; 
	seatingEvent = 0;
	segmentsEvent = 0;
}

MainMenu::~MainMenu(){
	delete arrayName; 
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

void MainMenu::pauseScreen() { 
	cout << "\nIngrese cualquier tecla para continuar.....";
	string aux= " ";
	cin >> aux;
} 

//para la validacion de cedulas.  
void MainMenu::validateID() {
	string id;
	bool flag = false;
	int size = 0;
	string idClean = " ";

	while (!flag) {
		cleanScreen();
		cout << " Nota: Para poder ingresar su cedula de identidad correctamente tiene que\n";
		cout << "contener '9' numeros en formato '123450678' sin espacios u otros caracteres.\n";
		cout << "\n\t\tIngrese su cedula de identidad: ";
		cin >> id;

		for (int i = 0; id[i] != '\0'; i++) {
			if (id[i] != ' ') {
				idClean += id[i];
			}
		}

		if (idClean.length() != 9) {
			cleanScreen();
			cout << "La cedula de identidad debe contener exactamente 9 digitos." << endl;
			pauseScreen();
			continue;
		}

		if (idClean[0] < '1' || idClean[0] > '8') {
			cleanScreen();
			cout << "La cedula debe comenzar con un digito entre 1 y 8." << endl;
			pauseScreen();
			continue;
		}

		if (idClean[5] != '0') {
			cleanScreen();
			cout << "El sexto digito de la cedula debe ser '0'." << endl;
			pauseScreen();
			continue;
		}

		bool allDigits = true;
		for (int i = 0; i < idClean.length(); i++) {
			if (idClean[i] < '0' || idClean[i] > '9') {
				allDigits = false;
				break;
			}
		}
		if (!allDigits) {
			cleanScreen();
			cout << "La cedula solo debe contener numeros." << endl;
			pauseScreen();
			continue;
		}
		flag = true;
		cout << "Su cedula de identificacion se cargo correctamente." << endl;
	}
}

//para la validacion de fechas. 
void MainMenu::askForDate(string dateEvent) {
	bool flag = false;

	while (!flag) {
		cleanScreen();
		cout << "Ingrese su fecha de nacimiento (formato DD/MM/YYYY): ";
		cin >> dateEvent;

		char dateNumbers[9];
		int aux = 0;


		for (int i = 0; dateEvent[i] != '\0'; i++) {
			if (isdigit(dateEvent[i])) {
				dateNumbers[aux++] = dateEvent[i];
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
				cout << "Debe ser mayor de 15 años para comprar boletos." << endl;
			}
			else if (year < 1925) {
				cout << "El año debe ser mayor o igual a 1925. Ingrese una fecha válida." << endl;
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
		cout << "\n¿Seguro que quieres eliminar un evento?" << endl;
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
