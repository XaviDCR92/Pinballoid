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
#include "Gfx.h"
#include <psxgpu.h>

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

static GsSprite globalSprite;

/* *************************************
 *  Local prototypes declaration
 * *************************************/

static bool MenuInit(void);
static enum tMenuResult MenuLoop(void);

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Reportedly, this function initializes the main menu.
*
************************************************************************/
static bool MenuInit(void)
{
    /* Load general sprite. */
    GfxSpriteFromFile("PB.EXE", &globalSprite);

    return true;
}

/*******************************************************************//**
*
* \brief    Game logic entry point.
*
************************************************************************/
enum tMenuResult Menu(void)
{
    if (MenuInit())
    {
        return MenuLoop();
    }
    else
    {
        /* An error has happened while
         * initialising main menu. */
    }

    /* This result will be returned in case
     * menu initialization fails. */
    return MENU_RESULT_UNDEFINED;
}

static enum tMenuResult MenuLoop(void)
{
    for (;;)
    {
        return MENU_RESULT_GAME_START;
    }
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
    return LEVEL_1;
}

size_t MenuGetSelectedPlayers(void)
{
    return 3;
}
