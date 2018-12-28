/***************************************************************************//**
*
* \file     Paddle.c
*
* \brief    Paddle main module and entry point for game logic.
*
*******************************************************************************/

/* *****************************************************************************
 * Includes
 * ****************************************************************************/

#include "Paddle.h"
#include "Gfx.h"
#include "Pad.h"
#include "Player.h"
#include "Level.h"
#include <fixmath.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* *****************************************************************************
 * Defines
 * ****************************************************************************/

/* *****************************************************************************
 * Types definition
 * ****************************************************************************/

enum
{
    PADDLE_WIDTH = 48,
    PADDLE_HEIGHT = 8
};

static struct PaddleData
{
    bool used;

    struct Pos
    {
        short x;
        short y;
    } pos;

    struct FPos
    {
        fix16_t x;
        fix16_t y;
    } fpos;

    struct
    {
        fix16_t x;
        fix16_t y;
    } fspeed;

    struct PaddleColour
    {
        char r;
        char g;
        char b;
    } colour;
} paddlesData[MAX_PLAYERS];

/* *****************************************************************************
 * Global variables definition
 * ****************************************************************************/

/* *****************************************************************************
 * Local variables definition
 * ****************************************************************************/

/* *****************************************************************************
 * Local prototypes declaration
 * ****************************************************************************/

static void PaddlePosInit(const enum Player player);
static void PaddleSpeed(const enum Player player);
static void PaddlePos(const enum Player player);
static void PaddleAdjustSpeed(const enum Player player, fix16_t* const speed, const enum Key key, const fix16_t factor);
static void PaddleAdjustPos(fix16_t* const speed, fix16_t* const pos);

/* *****************************************************************************
 * Functions definition
 * ****************************************************************************/

/***************************************************************************//**
*
* \brief    Paddle logic entry point.
*
* \param    player
*               Selected \ref Player instance.
*
*******************************************************************************/
void PaddleInit(const enum Player player)
{
    PaddlePosInit(player);
}

/***************************************************************************//**
*
* \brief    Paddle logic entry point.
*
*******************************************************************************/
void Paddle(const enum Player player)
{
    if (player < MAX_PLAYERS)
    {
        /* Update paddle speed according to pad status. */
        PaddleSpeed(player);

        /* Update paddle position according
         * to newly calculated speed. */
        PaddlePos(player);
    }
    else
    {
        /* Invalid selected Player instance. Exit. */
    }
}

static void PaddleSpeed(const enum Player player)
{
    static const enum PaddleDirection
    {
        UNDEFINED,
        UP_DOWN,
        LEFT_RIGHT
    } directions[MAX_PLAYERS] =
    {
        [PLAYER_0] = LEFT_RIGHT,
        [PLAYER_1] = LEFT_RIGHT,
        [PLAYER_2] = UP_DOWN,
        [PLAYER_3] = UP_DOWN
    };

    /* Retrieve PaddleData instance given selected player. */
    struct PaddleData* const paddleData = &paddlesData[player];

    switch (directions[player])
    {
        case LEFT_RIGHT:
        {
            /* Retrieve current X position. */
            fix16_t* const speed = &paddleData->fspeed.x;

            PaddleAdjustSpeed(player, speed, KEY_LEFT, -1);
            PaddleAdjustSpeed(player, speed, KEY_RIGHT, 1);
        }
        break;

        case UP_DOWN:
        {
            /* Retrieve current Y position. */
            fix16_t* const speed = &paddleData->fspeed.y;

            PaddleAdjustSpeed(player, speed, KEY_UP, -1);
            PaddleAdjustSpeed(player, speed, KEY_DOWN, 1);
        }
        break;

        case UNDEFINED:
            /* Fall through. */
        default:
        break;
    }
}

static void PaddleAdjustSpeed(const enum Player player, fix16_t* const speed, const enum Key key, const fix16_t factor)
{
    enum
    {
        MAX_SPEED = 0x800,
        SPEED_DIFF = 0x10
    };

    if (PadKeyPressed(player, key))
    {
        if (factor > 0)
        {
            if ((*speed + (fix16_t)SPEED_DIFF) < ((fix16_t)MAX_SPEED))
            {
                /* Incrase X speed. */
                *speed += (fix16_t)SPEED_DIFF * factor;
            }
            else
            {
                /* Saturate negative X speed. */
                *speed = (fix16_t)MAX_SPEED * factor;
            }
        }
        else if (factor < 0)
        {
            if ((*speed - (fix16_t)SPEED_DIFF) < ((fix16_t)MAX_SPEED))
            {
                /* Incrase X speed. */
                *speed -= (fix16_t)SPEED_DIFF * factor;
            }
            else
            {
                /* Saturate negative X speed. */
                *speed = (fix16_t)MAX_SPEED * factor;
            }
        }
    }
    else if (*speed > ((fix16_t)SPEED_DIFF * factor))
    {
        //~ *speed -= (fix16_t)SPEED_DIFF * factor;
    }
    else
    {
        //~ *speed = 0;
    }
}

static void PaddlePos(const enum Player player)
{
    struct PaddleData* const paddleData = &paddlesData[player];

    PaddleAdjustPos(&paddleData->fspeed.x, &paddlesData->fpos.x);
    PaddleAdjustPos(&paddleData->fspeed.y, &paddlesData->fpos.y);

    dprintf("X speed = 0x%08X\n", paddleData->fspeed.x);
}

static void PaddleAdjustPos(fix16_t* const speed, fix16_t* const pos)
{
    if (*speed < 0)
    {
        if ((*pos + *speed) >= FIX16_FROM_INT(WALL_GAP))
        {
            *pos += *speed;
        }
        else
        {
            *pos = FIX16_FROM_INT(WALL_GAP);
            *speed = 0;
        }
    }
    else if (*speed > 0)
    {
        if ((*pos + *speed) <= FIX16_FROM_INT(LEVEL_SIZE - WALL_GAP))
        {
            *pos += *speed;
        }
        else
        {
            *pos = FIX16_FROM_INT(LEVEL_SIZE - WALL_GAP);
            *speed = 0;
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

#if 0
    static const struct PaddleColour
    {
        [PADDLE_P1] =
        {
            .r = 240,
            .g = 240,
            .b = 240
        },

        [PADDLE_P2] =
        {
            .r = 60,
            .g = 240,
            .b = 60
        },

        [PADDLE_P3] =
        {
            .r = 240,
            .g = 60,
            .b = 60
        },

        [PADDLE_P4] =
        {
            .r = 60,
            .g = 60,
            .b = 240
        }
    } paddlesColour[MAX_PLAYERS];
#endif

static void PaddlePosInit(const enum Player player)
{
    enum
    {
        PADDLE_0_1_X = FIX16_FROM_INT((LEVEL_X / 2) + (PADDLE_WIDTH / 2)),
        PADDLE_0_Y = FIX16_FROM_INT(LEVEL_Y - WALL_THICKNESS - WALL_GAP - PADDLE_HEIGHT),
        PADDLE_1_Y = FIX16_FROM_INT(WALL_THICKNESS + WALL_GAP),

        PADDLE_2_X = FIX16_FROM_INT(WALL_THICKNESS + WALL_GAP - PADDLE_WIDTH),
        PADDLE_3_X = FIX16_FROM_INT(LEVEL_X - WALL_THICKNESS - WALL_GAP),
        PADDLE_2_3_Y = FIX16_FROM_INT((LEVEL_Y / 2) - (PADDLE_WIDTH / 2))
    };

    static const struct FPos initPos[MAX_PLAYERS] =
    {
        [PLAYER_0] =
        {
            .x = PADDLE_0_1_X,
            .y = PADDLE_0_Y
        },

        [PLAYER_1] =
        {
            .x = PADDLE_0_1_X,
            .y = PADDLE_1_Y
        },

        [PLAYER_2] =
        {
            .x = PADDLE_2_X,
            .y = PADDLE_2_3_Y
        },

        [PLAYER_3] =
        {
            .x = PADDLE_3_X,
            .y = PADDLE_2_3_Y
        }
    };

    /* Copy initial coordinates into selected paddle. */
    memmove(&paddlesData[player].fpos, &initPos[player], sizeof (struct FPos));
}
