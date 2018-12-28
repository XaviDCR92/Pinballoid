#ifndef PADDLE_H
#define PADDLE_H

/*******************************************************************//**
*
* @file     Paddle.h
*
* @author   Xavier Del Campo
*
* @brief    Include file for Paddle module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Player.h"

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

void PaddleInit(const enum Player player);
void Paddle(const enum Player player);

#endif /* PADDLE_H */
