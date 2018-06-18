#ifndef IO_H__
#define IO_H__

/*******************************************************************//**
*
* @file     IO.h
*
* @author   Xavier Del Campo
*
* @brief    Include file for IO module.
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

const uint8_t* IOLoadFile(const char* const strFilePath, size_t* const peSize);

#endif /* IO_H__ */
