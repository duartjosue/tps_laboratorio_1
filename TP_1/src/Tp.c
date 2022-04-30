/*
 * Tp.c
 *
 *  Created on: 30 abr 2022
 *      Author: win 10
 */

#include "Tp.h"
#include <math.h>

/** \brief
 *  calcular precio de debito
 * \param aplica descuento
 * \param
 * \return debit
 *
 */
float calculosdebito (float const precio)
{
    float debit;
    debit = precio -((precio*10)/100);
    return debit;
}

/** \brief
 *
 * \param calcula interes sobre el precio
 * \param
 * \return credit
 *
 */




float calculosCredito(float const precio)
{
    float credit;
    credit = precio +((precio*25)/100);
    return credit;
}



/** \brief
 *
 * \param calculo bitcoin
 * \param
 * \return bitcoin
 *
 */

float calculoBitcoin(float const precio)
{
    float bitcoin;
    bitcoin = precio/4585976.61;
    return bitcoin;
}





/** \brief
 *
 * \param calculo precio unitario
 * \param
 * \return precioUnitario
 *
 */


float calculoskm(float const precio,float const  km)
{
    float precioUnitario;
    precioUnitario = precio/km;

    return precioUnitario;
}

/** \brief
 *
 * \param la diferecia de precios
 * \param
 * \return dif
 *
 */


float precioDif(float const aero, float const latam)
{

    float dif;

    dif = aero - latam;

    return dif;
}
