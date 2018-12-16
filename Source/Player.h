#ifndef PLAYER_H
#define PLAYER_H

/*******************************************************************//**
*
* \file     Player.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for Player module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include <stddef.h>
#include <stdbool.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

enum Player
{
    PLAYER_0,
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,

    MAX_PLAYERS
};

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

void PlayerInit(const size_t players);
bool PlayerIsActive(const enum Player player);
void PlayerHandler(void);

#endif /* PLAYER_H */
