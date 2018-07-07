/*******************************************************************//**
*
* \file     Game.c
*
* \brief    Game main module and entry point for game logic.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Game.h"
#include "Menu.h"

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

void GameStart(const enum tLevel eSelectedLevel);

/* *************************************
 *  Local prototypes declaration
 * *************************************/

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Game logic entry point.
*
************************************************************************/
void Game(void)
{
    /* Execute game main menu and determine
     * next steps depending on its result. */
    switch (Menu())
    {
        case MENU_RESULT_EDITOR:

        break;

        case MENU_RESULT_GAME_START:
        {
            /* Get selected level from Menu. */
            const enum tLevel eSelectedLevel = MenuGetSelectedLevel();

            if (eSelectedLevel < MAX_LEVELS)
            {
                /* Start gameplay given level number. */
                GameStart(eSelectedLevel);
            }
            else
            {
                /* Invalid level number has been selected.
                 * Exit function and return to start point. */
            }
        }
        break;

        case MENU_RESULT_UNDEFINED:
            /* Fall through. */
        default:
            /* Invalid result. Restart game. */
        break;
    }
}

/*******************************************************************//**
*
* \brief    Initializes a level indicated by eSelectedLevel and
*           all game structures.
*
* \param    eSelectedLevel
*
************************************************************************/
void GameStart(const enum tLevel eSelectedLevel)
{

}
