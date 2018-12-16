#ifndef MENU_H
#define MENU_H

/*******************************************************************//**
*
* \file     Menu.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for Menu module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Game.h"
#include <stddef.h>
#include <psxgpu.h>

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/

enum tMenuResult
{
    MENU_RESULT_UNDEFINED,
    MENU_RESULT_EDITOR,
    MENU_RESULT_GAME_START
};

/* *************************************
 * Public variables declaration
 * *************************************/

extern GsSprite globalSprite;

/* *************************************
 * Public functions declaration
 * *************************************/

enum tMenuResult Menu(void);
enum tLevel MenuGetSelectedLevel(void);
size_t MenuGetSelectedPlayers(void);

#endif /* MENU_H */
