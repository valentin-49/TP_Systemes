#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "TPGPS.h"
using namespace std;


int main()
{

	bool serie;
	TPGPS * l = new TPGPS();
	do
	{
		serie = l->ouvrirPort();
		if (serie == true) { //Développer par Boeuf Bourgignon.
			int i = 0;
			int debutTrame = 0;
			int x = 0;
			char buffer[1] = { 0 };
			char buf[1028] = { 0 };
			int v = 0;
			do {
				if (l->lirePort(buffer)) {
					if (buffer[0] == '$') {
						debutTrame = 1;
					}
					if (debutTrame == 1) {
						if (buffer[0] != '\r') {
							for (int y = 0; y < strlen(buffer); y++) {
								buf[x] = buffer[y];
								x++;
								buffer[y] = { 0 };
							}
						}
						else {
							buf[x] = '\0';
							cout << buf << endl;
							x = 0;
							debutTrame = 0;
						}
					}
				}
				else i = 1;
			} while (i == 0);
		}
	} while (serie != true);
	l->fermerPort();

}
