#include<iostream>
#include<thread>
#include<string>
#include<chrono>

using namespace std;

void misaludo(string m, int demora, int veces) {
	for (int i = 1; i <= veces; i++) {
		cout << m + "\n";

		this_thread::sleep_for(chrono::milliseconds(demora));
	}
}




int main() {

	srand(time(NULL));
	int dem0 = rand() % 2000 + 500;
	int dem1 = rand() % 2000 + 500;
	int dem2 = rand() % 2000 + 500;
	int dem3 = rand() % 2000 + 500;
	int dem4 = rand() % 2000 + 500;
	int dem5 = rand() % 2000 + 500;
	int dem6 = rand() % 2000 + 500;
	int dem7 = rand() % 2000 + 500;
	int dem8 = rand() % 2000 + 500;
	int dem9 = rand() % 2000 + 500;
	int dem10 = rand() % 2000 + 500;
	int dem11 = rand() % 2000 + 500;
	int dem12 = rand() % 2000 + 500;
	int dem13 = rand() % 2000 + 500;
	int dem14 = rand() % 2000 + 500;

	int freq0 = rand() % 10 + 1;
	int freq1 = rand() % 10 + 1;
	int freq2 = rand() % 10 + 1;
	int freq3 = rand() % 10 + 1;
	int freq4 = rand() % 10 + 1;
	int freq5 = rand() % 10 + 1;
	int freq6 = rand() % 10 + 1;
	int freq7 = rand() % 10 + 1;
	int freq8 = rand() % 10 + 1;
	int freq9 = rand() % 10 + 1;
	int freq10 = rand() % 10 + 1;
	int freq11 = rand() % 10 + 1;
	int freq12 = rand() % 10 + 1;
	int freq13 = rand() % 10 + 1;
	int freq14 = rand() % 10 + 1;




	thread P[15];

	P[0] = thread(&misaludo, "Soy 1", dem0, freq0);
	P[1] = thread(&misaludo, "\tSoy 2", dem1, freq1);
	P[2] = thread(&misaludo, "\t\tSoy 3", dem2, freq2);
	P[3] = thread(&misaludo, "\t\t\tSoy 4", dem3, freq3);
	P[4] = thread(&misaludo, "\t\t\t\tSoy 5", dem4, freq4);
	P[5] = thread(&misaludo, "\t\t\t\t\tSoy 6", dem5, freq5);
	P[6] = thread(&misaludo, "\t\t\t\t\t\tSoy 7", dem6, freq6);
	P[7] = thread(&misaludo, "\t\t\t\t\t\t\tSoy 8", dem7, freq7);
	P[8] = thread(&misaludo, "\t\t\t\t\t\t\t\tSoy 9", dem8, freq8);
	P[9] = thread(&misaludo, "\t\t\t\t\t\t\t\t\tSoy 10", dem9, freq9);
	P[10] = thread(&misaludo, "\t\t\t\t\t\t\t\t\t\tSoy 11", dem10, freq10);
	P[11] = thread(&misaludo, "\t\t\t\t\t\t\t\t\t\t\tSoy 12", dem11, freq11);
	P[12] = thread(&misaludo, "\t\t\t\t\t\t\t\t\t\t\t\tSoy 13", dem12, freq12);
	P[13] = thread(&misaludo, "\t\t\t\t\t\t\t\t\t\t\t\t\tSoy 14", dem13, freq13);
	P[14] = thread(&misaludo, "\t\t\t\t\t\t\t\t\t\t\t\t\t\tSoy 15", dem14, freq14);

	P[0].join();
	P[1].join();
	P[2].join();
	P[3].join();
	P[4].join();
	P[5].join();
	P[6].join();
	P[7].join();
	P[8].join();
	P[9].join();
	P[10].join();
	P[11].join();
	P[12].join();
	P[13].join();
	P[14].join();

	cout << "Fin \n";
}