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

#include "Timers.h"
#include "Interrupts.h"
#include <psx.h>
#include <stdint.h>
#include <stddef.h>
#include <thread.h>
#include <stdio.h>

/* *************************************
 * Defines
 * *************************************/

#define TIMER_COUNTER(t)    (*(unsigned int*)(0x1F801100 + ((t - 1) * 0x10)) & 0x0000FFFF)

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
#pragma message ("Why is this ISR being actually executed every 1 ms?")
}

unsigned int RootCounter1Get(void)
{
    return TIMER_COUNTER(1);
}

unsigned int RootCounter2Get(void)
{
    return TIMER_COUNTER(2);
}
