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

/* *************************************
 * Defines
 * *************************************/

#define CHECK_PAD(p) _Static_Assert((1 << KEY_#p) == PAD_#p, "Inconsistency between KEY_" #p " and PAD_" #);

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
    Player player;

    for (player = 0; player < MAX_PLAYERS; player++)
    {

    }
}

/*******************************************************************//**
*
* \brief
*
************************************************************************/
bool PadKeyPressed(const enum Key key, const enum Player player)
{
}

#endif /* 0 */
