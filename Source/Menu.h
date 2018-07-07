#ifndef MENU_H__
#define MENU_H__

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

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Public types definition
 * *************************************/


/*******************************************************************//**
*
* \file     Menu.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for Menu module.
*
************************************************************************/
enum tMenuResult
{
    MENU_RESULT_UNDEFINED,
    MENU_RESULT_EDITOR,
    MENU_RESULT_GAME_START
};

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

enum tMenuResult Menu(void);
enum tLevel MenuGetSelectedLevel(void);

#endif /* MENU_H__ */
