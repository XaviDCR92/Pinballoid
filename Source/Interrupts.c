/*******************************************************************//***
*
* \file     Interrupts.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of Interrupts module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "Interrupts.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

/* *************************************
 * Defines
 * *************************************/

/*******************************************************************//***
*
* \brief    Interrupt mask register.
*
************************************************************************/
#ifndef I_MASK
#define I_MASK  (*(volatile unsigned int*)0x1F801074)
#endif /* I_MASK */

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

/*******************************************************************//***
*
* \brief    Enables an interrupt source given by eIntSource.
*
* \param    HW interrupt source.
*
* \see      \ref tIntSource for a list of possible HW interrupt causes.
*
************************************************************************/
void InterruptsEnableInt(const enum tIntSource eIntSource)
{
    if (eIntSource < MAX_INTERRUPT_SOURCES)
    {
        I_MASK |= 1 << eIntSource;
    }
    else
    {
        /* Invalid selected tIntSource instance. Exit. */
    }
}

/*******************************************************************//***
*
* \brief    Disables an interrupt source given by eIntSource.
*
* \param    HW interrupt source.
*
* \see      \ref tIntSource for a list of possible HW interrupt causes.
*
************************************************************************/
void InterruptsDisableInt(const enum tIntSource eIntSource)
{
    if (eIntSource < MAX_INTERRUPT_SOURCES)
    {
        I_MASK &= ~(1 << eIntSource);
    }
    else
    {
        /* Invalid selected tIntSource instance. Exit. */
    }
}
