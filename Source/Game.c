/***************************************************************************//**
*
* \file     Game.c
*
* \brief    Game main module and entry point for game logic.
*
*******************************************************************************/

/* *****************************************************************************
 * Includes
 * ****************************************************************************/

#include "Game.h"
#include "Menu.h"
#include "Timers.h"
#include "Paddle.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* *****************************************************************************
 * Defines
 * ****************************************************************************/

/* *****************************************************************************
 * Types definition
 * ****************************************************************************/

/* *****************************************************************************
 * Global variables definition
 * ****************************************************************************/

/* *****************************************************************************
 * Local variables definition
 * ****************************************************************************/

static void GameStart(const enum tLevel eSelectedLevel, const size_t players);
static bool GameInit(const size_t players);
static void GameLoop(const size_t players);

/* *****************************************************************************
 * Local prototypes declaration
 * ****************************************************************************/

/* *****************************************************************************
 * Functions definition
 * ****************************************************************************/

/***************************************************************************//**
*
* \brief    Game logic entry point.
*
*******************************************************************************/
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

            const size_t players = MenuGetSelectedPlayers();

            if (eSelectedLevel < MAX_LEVELS)
            {
                /* Start gameplay given level number. */
                GameStart(eSelectedLevel, players);
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

/***************************************************************************//**
*
* \brief    Initializes a level indicated by eSelectedLevel and
*           all game structures.
*
* \param    eSelectedLevel
*
*******************************************************************************/
static void GameStart(const enum tLevel eSelectedLevel, const size_t players)
{
    /* Game initialization. */

    if (GameInit(players))
    {
        GameLoop(players);
    }
    else
    {
        /* Game could not be initialized. Exit. */
    }
}

static bool GameInit(const size_t players)
{
    static bool initDone;

    if (!initDone)
    {
        const int seed = RootCounter1Get() ^ RootCounter2Get();

        /* Set random seed based on timer counters. */
        srand(seed);

        dprintf("Seed = %d\n", seed);

        /* Set first game initialization flag. */
        initDone = true;
    }

    PaddleInit(players);

    return true;
}

static void GameLoop(const size_t players)
{
}
