#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//variables globales necesarias
int p = 0;
int continuar= -1;
int sel = -1;
int fil = 30;
int col = 4;
int reserva=0;
int compra=0;
//estructura de los pasajeros
struct pasajeros
{

//datos del pasajero
    int id;
    string nombre;
    int edad;
    string genero;

    }pasajero[9999];

struct aviones {

    int filas = fil;
    int columnas = col;
    bool asientoReservado[30][4];
    bool asientoComprado[30][4];

}avion;

void cargar()
{
    ifstream lista("pasajeros.txt");

    int id;
    string nombre;
    int edad;
    string genero;

    int c = 0;
    while(lista >> id >> nombre >> edad >> genero)
    {

    pasajero[c].id = id;
    pasajero[c].nombre = nombre;
    pasajero[c].edad = edad;
    pasajero[c].genero = genero;

    cout << "Pasajero nro " << c+1 <<". \n" << endl;
    cout << "Identificacion: " << pasajero[c].id << endl;
    cout << "Nombre: " << pasajero[c].nombre << endl;
    cout << "Edad: " << pasajero[c].edad << endl;
    cout << "Genero: " << pasajero[c].genero << endl;

    c++;
    }
    p = c;
    system("pause");
    }


void verificar(int a, int b){

    if (avion.asientoComprado[a][b]=1){
        cout << "Este asiento ya ha sido comprado." << endl;
        system("pause");
        system("exit");
    }

    if (avion.asientoReservado[a][b]=1){

        char d;

        cout << "No se puede reservar, el asiento ha sido reservado previamente." << endl << endl;
        cout << "Si su compra es segura, podemos hacer una excepcion por usted ;) " << endl;
        cout << "¿Va a comprar el asiento con seguridad? [S/N]: " ;
        cin >> d;

        if (d == 's') {

        cout << "Procediendo...";
        system("pause");

    }

    if (d == 'n') {

        cout << "Adios" ;
        system("pause");
        system("exit");
    }

    }

}


void nuevareserva(){

    char d;
    int i, j;

    system("cls");

    cout << "Llene el siguiente formato de registro de pasajeros: \n\n" << endl;
    while(continuar!=0)
    {
    cout << "Nro. identificación del pasajero: ";
    cin >> pasajero[p].id;
    cout << "Nombre del pasajero: ";
    cin >> pasajero[p].nombre;
    cout << "Edad del pasajero, expresada en años: ";
    cin >> pasajero[p].edad;
    cout << "Género del pasajero ( Masculino = M,  Femenino = F): ";
    cin >> pasajero[p].genero;

    cout << "Tenemos un avión disponible con " << avion.columnas << "columnas y " << avion.filas << " filas. \n";
    cout << " <-- Seleccione su asiento -->\n";
    cout << "Fila: ";
    cin >> i;
    cout << "Columna: ";
    cin >> j;

    verificar(i, j);

    avion.asientoReservado[i][j]=1;
    reserva++;

    cout << "\nReserva guardada con exito. ¿Desea comprar el tiquete reservado? [S/N]: " << endl;
    cin  >> d;
    if (d == 's') {

            avion.asientoComprado[i][j]=1;
            compra++;
            cout << "Asiento comprado con exito.";

    }

    if (d == 'n') {

        avion.asientoComprado[i][j]=0;

        cout << "El asiento ha sido reservado pero queda pendiente de pago." ;
    }

    p++;
    i=0;
    j=0;


    cout << "\nOperacion terminada con exito." << endl;
    cout << "Presione 1 para reservar otro pasajero, presione 0 para continuar: ";
    cin >> continuar;
    }
    continuar=-1;
    system("cls");
}


void menu(){

cout << "VENTA Y COMPRA DE TIQUETES  \n " << endl ;
cout << " Seleccione \n\n 1. Reservar o Vender un tiquete \n 2. Cargar reservas desde el archivo (reservas.txt) \n 3. Imprimir informe compras y reservas  \n 4. Imprimir estadisticas \n 0. Guardar y Salir \n\n" << endl;
}

int main(){
{

		while(sel!=0){
		system("cls");
		menu();
		int opc;
		cout << "Ingrese -> ";
		cin >> opc;
		switch(opc){
		case 0: sel = 0; break;
		case 1: nuevareserva(); break;
		case 2: cargar(); break;

		break;
//		case 4: estadisticas(); break;

		default: cout << "Ha ingresado una opcion incorrecta" << endl; system("pause"); break;
		}
		cout << endl;
		}
    //guardar();
	system("pause");
	return 0;

}
}
