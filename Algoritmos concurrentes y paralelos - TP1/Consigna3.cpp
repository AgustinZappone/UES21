#include<iostream>
#include<thread>
#include<string>
#include<chrono>


using namespace std;

//Declarando clases de electrodomesticos y sus metodos.

class AireAcondicionado {
public:
	bool encendido = 0;
	int temperatura = 24;

	void AumentarTemperatura() {
		if (temperatura < 30) {
			temperatura++;
		}
		else {
			cout << "La temperatura maxima es de 30 grados.\n";
		}
	}

	void DisminuirTemperatura() {
		if (temperatura > 16) {
			temperatura--;
		}
		else {
			cout << "La temperatura minima es de 16 grados.\n";
		}
	}

	void EncenderApagar() {
		if (encendido == 0) {
			encendido = 1;
		}
		else {
			encendido = 0;
		}
	}

	bool getEncendido() {
		return encendido;
	}

	int getTemperatura() {
		return temperatura;
	}

};

class Ventana {
public:
	bool abierta = 0;

	void AbrirCerrar() {
		if (abierta == 0) {
			abierta = 1;
		}
		else {
			abierta = 0;
		}
	}

	bool getAbierta() {
		return abierta;
	}

};

class Termotanque {
public:
	bool encendido = 0;

	void EncenderApagar() {
		if (encendido == 0) {
			encendido = 1;
		}
		else {
			encendido = 0;
		}
	}

	bool getEncendido() {
		return encendido;
	}


};



int main() {

	//

	AireAcondicionado AireSamsung;
	Ventana VentanaIkea;
	Termotanque TermotanqueSherman;

	thread P[3];

	P[0] = thread(&AireAcondicionado::EncenderApagar, AireSamsung ),
	P[1] = thread(&Ventana::AbrirCerrar, VentanaIkea ),
	P[2] = thread(&Termotanque::EncenderApagar, TermotanqueSherman );
	
	P[0].join();
	P[1].join();
	P[2].join();

	cout << "Fin \n";
}