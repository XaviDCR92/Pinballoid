/*******************************************************************//**
*
* \file     Player.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of Player module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Player.h"
#include "Paddle.h"
#include "Pad.h"
#include <stdint.h>

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

static struct PlayerData
{
    bool active;
    uint32_t score;
} playerData[MAX_PLAYERS];

/* *************************************
 *  Local prototypes declaration
 * *************************************/

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Player module initialization.
*
* \param    players
*               Number of active players.
*
************************************************************************/
void PlayerInit(const size_t players)
{
    enum Player player;

    for (player = 0; player < MAX_PLAYERS; player++)
    {
        /* Retrieve PlayerData instance for selected player. */
        struct PlayerData* const data = &playerData[player];

        /* Set active flag according to
         * selected number of players. */
        data->active = player < players;

        /* Reset player score. */
        data->score = 0;

        PaddleInit(player);
    }
}

bool PlayerIsActive(const enum Player player)
{
    if (player < MAX_PLAYERS)
    {
        return playerData[player].active;
    }

    return false;
}

void PlayerHandler(void)
{
    enum Player player;

    for (player = 0; player < MAX_PLAYERS; player++)
    {
        /* Retrieve PlayerData instance for selected player. */
        struct PlayerData* const pData = &playerData[player];

        if (pData->active)
        {
            PadHandler(player);
        }
        else
        {
            /* Selected player is not active. */
        }
    }
}
