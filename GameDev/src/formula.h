/*
 * formula.h
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Paper
 */
#include <math.h>
#ifndef FORMULA_H_
#define FORMULA_H_

double distance( int x1, int y1, int x2, int y2 )
{
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

#endif /* FORMULA_H_ */
