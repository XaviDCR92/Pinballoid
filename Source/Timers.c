/*******************************************************************//**
*
* \file     Timers.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of Timers module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Interrupts.h"
#include "ThreadHandler.h"
#include <psx.h>
#include <stdint.h>
#include <stddef.h>
#include <thread.h>
#include <stdio.h>

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

static void ISR_RootCounter2(void);

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Timers module initialization.
*
************************************************************************/
void TimersInit(void)
{
    enum
    {
        /* Root counter (aka timer) index. */
        RCNT2_INDEX = 2,

        /* Value to be reached by the timer internal counter.
         * Configured to generate an interrupt every 10 ms. */
        RCNT2_COMPARE_VALUE = 0xA560
    };

    /* Configure interrupt address, index and
     * compare value to root counter 2. */
    SetRCntHandler(&ISR_RootCounter2, RCNT2_INDEX, RCNT2_COMPARE_VALUE);

    ChangeThread(0xFF000001);

    /* Enable RCnt2 interrupt. */
    InterruptsEnableInt(INT_SOURCE_RCNT2);
}

/*******************************************************************//**
*
* \brief    Root counter 2 interrupt handler.
*
*           Root counter 2 counter value is increased at a rate of
*           System clock / 8 (33.868800 / 8 = 4.2336 MHz).
*
* \remarks  Executed under interrupt context on timer compare value
*           reached (every 10 ms according to RCNT2_COMPARE_VALUE).
*
* \see      TimersInit() for timer compare value configuration.
*
************************************************************************/
static void ISR_RootCounter2(void)
{
    static uint8_t counter;

    if (++counter & 1)
    {
        ChangeThread(0xFF000001);
    }
    else
    {
        ChangeThread(0xFF000000);
    }
}

