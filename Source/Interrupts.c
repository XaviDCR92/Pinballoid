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
*           According to NoCash specifications, I_MASK bits are
*           structured as follows:
*
*           0     IRQ0 VBLANK (PAL=50Hz, NTSC=60Hz)
*           1     IRQ1 GPU   Can be requested via GP0(1Fh) command
*           2     IRQ2 CDROM
*           3     IRQ3 DMA
*           4     IRQ4 TMR0  Timer 0 aka Root Counter 0
*           5     IRQ5 TMR1  Timer 1 aka Root Counter 1
*           6     IRQ6 TMR2  Timer 2 aka Root Counter 2
*           7     IRQ7 Controller and Memory Card - Byte Received Interrupt
*           8     IRQ8 SIO
*           9     IRQ9 SPU
*           10    IRQ10 Controller - Lightpen Interrupt
*           11-15 Not used (always zero)
*           16-31 Garbage
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
