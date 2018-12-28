#ifndef PAD_H
#define PAD_H

/*******************************************************************//**
*
* @file     Pad.h
*
* @author   Xavier Del Campo
*
* @brief    Include file for Pad module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Player.h"
#include <stdbool.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

enum Key
{
    KEY_L2,
    KEY_R2,
    KEY_L1,
    KEY_R1,
    KEY_TRIANGLE,
    KEY_CIRCLE,
    KEY_CROSS,
    KEY_SQUARE,
    KEY_SELECT,
    KEY_LANALOGB,
    KEY_RANALOGB,
    KEY_START,
    KEY_UP,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_LEFT,

    MAX_KEYS
};

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

void PadHandler(const enum Player player);
bool PadKeyPressed(const enum Player player, const enum Key key);

#endif /* PAD_H */
