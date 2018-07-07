/*******************************************************************//**
*
* \file     IO.c
*
* \author   Xavier Del Campo
*
* \brief    Implementation of IO module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include "IO.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

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

/* *************************************
 * Functions definition
 * *************************************/

/*******************************************************************//**
*
* \brief    Loads a file with absolute file path indicated by
*           strFileName.
*
*           File data is stored into a dynamically-allocated buffer
*           (via calls to malloc()) which can then be handled
*           by external modules.
*
* \param    strFilePath
*               Absolute file path e.g.:
*               "cdrom:\\DATA\\SPRITES\\TILESET1.TIM;1".
*
* \param    peSize
*               Pointer to size_t variable where file size will
*               be stored (we all know C does not support multi-return,
*               shamefully).
*
* \return   Address to a read-only buffer with file data if successful,
*           NULL pointer otherwise.
*
* \return   peSize
*  is assigned to actual file size in bytes
*           if successful, IO_INVALID_FILE_SIZE otherwise.
*
************************************************************************/
const uint8_t* IOLoadFile(const char* const strFilePath, size_t* const peSize)
{
    /* Get file data from input file path. */
    FILE* const pFile = fopen(strFilePath, "r");

    if (pFile != NULL)
    {
        /* File could be found successfully. */

        /* Move file pointer to end of file. */
        if (fseek(pFile, 0, SEEK_END) == 0 /* Success code. */)
        {
            enum
            {
                /* Reserve 128 kB for file data.
                 * This is more than enough for a
                 * 384 px * 240 px * 2 byte/px = 120 kB image. */
                FILE_BUFFER_SIZE = (128 << 10)
            };

            /* File pointer could be successfully
             * moved to the new position. */

            /* Return file size in bytes to upper layers. */
            *peSize = ftell(pFile);

            if (*peSize >= FILE_BUFFER_SIZE)
            {
                /* Buffer was successfully allocated according
                 * to file size. Now read file data into buffer. */

                /* Reset file pointer iterator position first. */
                if (fseek(pFile, 0, SEEK_SET) == 0 /* Sucess code. */)
                {
                    /* This buffer holds file data read from CD-ROM.
                     * It is cleared out on each call to IOLoadFile(),
                     * so copy its contents into an auxilar buffer if needed. */
                    static uint8_t au8FileBuffer[FILE_BUFFER_SIZE];

                    /* Read file data into newly allocated buffer. */
                    const size_t eReadBytes = fread(au8FileBuffer, sizeof (uint8_t), FILE_BUFFER_SIZE, pFile);

                    /* Close input opened file first. */
                    fclose(pFile);

                    if (eReadBytes == *peSize)
                    {
                        /* All bytes could be read from input file successfully. */

                        /* Finally, return address to buffer so it can be
                         * used by external modules. */
                        return au8FileBuffer;
                    }
                    else
                    {
                        /* Not all bytes from file were read.
                         * Fall through. */
                    }
                }
                else
                {
                    /* Something went wrong with fseek().
                     * Fall through. */
                }
            }
            else
            {
                /* Buffer cannot hold such amount of data.
                 * Fall through. */
            }
        }
        else
        {
            /* Something went wrong with fseek().
             * Fall through. */
        }
    }
    else
    {
        /* File does not exist. Fall through. */
    }

    /* Set file size to an invalid value. */
    *peSize = IO_INVALID_FILE_SIZE;

    /* Return failure code if this was reached. */
    return NULL;
}

#if 0
{
    struct CdFileInfo finfo;
    /* […init…] */

    if(CdFsFindFile(&bundleinfo, "FILE.EXT;1") == false)
    {
        /* [error handling] */
    }

    CdRead(buffer, no_of_sectors, finfo.lba+(2*5), CdlModeSpeed); CdReadSync(0);
}
#endif /* 0 */
