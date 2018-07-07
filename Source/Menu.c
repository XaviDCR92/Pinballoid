/*******************************************************************//**
*
* \file     Menu.c
*
* \brief    Main menu handling.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Menu.h"
#include "Game.h"
#include "stdbool.h"

/* *************************************
 * Defines
 * *************************************/

/* *************************************
 * Types definition
 * *************************************/

/* *************************************
 * Global variables definition
 * *************************************/

/* *************************************
 * Local variables definition
 * *************************************/

/* *************************************
 *  Local prototypes declaration
 * *************************************/

static bool MenuInit(void);

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Game logic entry point.
*
************************************************************************/
enum tMenuResult Menu(void)
{
    if (MenuInit() != false)
    {
        /* Main menu was initialized successfully. */
    }
    else
    {
        /* Something went wrong when intializing main menu. */
    }

    return MENU_RESULT_UNDEFINED;
}

/*******************************************************************//**
*
* \brief    Reportedly, this function initializes the main menu.
*
************************************************************************/
static bool MenuInit(void)
{
    return false;
}

/*******************************************************************//**
*
* \brief    This function returns level selected by user.
*
* \return   \ref tLevel selected by user.
*
************************************************************************/
enum tLevel MenuGetSelectedLevel(void)
{
    return LEVEL_UNDEFINED;
}
