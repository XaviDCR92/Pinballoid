/*******************************************************************//**
*
* \file     Pad.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of Pad module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Player.h"
#include "Pad.h"
#include <assert.h>
#include <psxpad.h>
#include <stdint.h>

/* *************************************
 * Defines
 * *************************************/

#define PAD_CHECK(p) STATIC_ASSERT((1 << KEY_##p) == PAD_##p);

/* *************************************
 * Types definition
 * *************************************/

/* *************************************
 * Global variables definition
 * *************************************/

/* *************************************
 * Local variables definition
 * *************************************/

static psx_pad_state padsState[MAX_PLAYERS];

/* *************************************
 *  Local prototypes declaration
 * *************************************/

/* *************************************
 * Functions definition
 * *************************************/

void PadInit(void)
{
    /* Perform compile-time assertions
     * in order to ensure consistency
     * between high-level and low-level definitions. */
    PAD_CHECK(LEFT);
    PAD_CHECK(RIGHT);
    PAD_CHECK(UP);
    PAD_CHECK(DOWN);
    PAD_CHECK(L2);
    PAD_CHECK(R2);
    PAD_CHECK(L1);
    PAD_CHECK(R1);
    PAD_CHECK(TRIANGLE);
    PAD_CHECK(CIRCLE);
    PAD_CHECK(CROSS);
    PAD_CHECK(SQUARE);
    PAD_CHECK(SELECT);
    PAD_CHECK(LANALOGB);
    PAD_CHECK(RANALOGB);
    PAD_CHECK(START);
}

void PadHandler(void)
{
    enum Player player;

    for (player = 0; player < MAX_PLAYERS; player++)
    {
        enum
        {
            RAW_DATA_SIZE = 16
        };

        static uint8_t padRawData[RAW_DATA_SIZE][MAX_PLAYERS];

        psx_pad_state* const padState = &padsState[player];

        pad_read_raw(player, padRawData[player]);
        PSX_PollPad_Fast(player, padState);
    }
}

enum psx_pad_types PadType(const enum Player player)
{
    if (player < MAX_PLAYERS)
    {
        return padsState[player].type;
    }

    return PADTYPE_UNKNOWN;
}

/*******************************************************************//**
*
* \brief
*
************************************************************************/
bool PadKeyPressed(const enum Key key, const enum Player player)
{
    if (player < MAX_PLAYERS)
    {
        if (key < MAX_KEYS)
        {
        }
    }

    return false;
}
