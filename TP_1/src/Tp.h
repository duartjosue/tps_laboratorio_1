/*
 * Tp.h
 *
 *  Created on: 30 abr 2022
 *      Author: win 10
 */

#ifndef TP_H_
#define TP_H_

int menu();
int km(int * pflag);
int informar();
int carga_forzada();
void salir(char * x);

float calculosdebito (float const precio);
float calculosCredito(float const precio);
float calculoBitcoin(float const precio);
float calculoskm(float const precio,  float const km);
float precioDif(float const aereo, float const latam);


#endif /* TP_H_ */
