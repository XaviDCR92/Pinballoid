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
#include "Player.h"
#include "Level.h"
#include <fixmath.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

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

/* *****************************************************************************
 * Functions definition
 * ****************************************************************************/

/***************************************************************************//**
*
* \brief    Paddle logic entry point.
*
*******************************************************************************/
void PaddleInit(const enum Player player)
{
    PaddlePosInit(player);
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
    memmove(&paddlesData[player], &initPos[player], sizeof (struct FPos));
}
