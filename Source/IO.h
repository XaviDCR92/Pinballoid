#ifndef IO_H
#define IO_H

/*******************************************************************//**
*
* \file     IO.h
*
* \author   Xavier Del Campo
*
* \brief    Include file for IO module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include <stdint.h>
#include <stddef.h>

/* *************************************
 * Defines
 * *************************************/

#define IO_INVALID_FILE_SIZE    (size_t)(-1)

/* *************************************
 * Public types definition
 * *************************************/

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

const uint8_t* IOLoadFile(const char* const strFilePath, size_t* const fileSize);

#endif /* IO_H */
