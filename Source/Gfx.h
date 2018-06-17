#ifndef GFX_H__
#define GFX_H__

/*******************************************************************//***
*
* @file     Gfx.h
*
* @author   Xavier Del Campo
*
* @brief    Include file for Gfx module.
*
************************************************************************/

/* *************************************
 * Includes
 * *************************************/

#include <psxgpu.h>
#include <stdbool.h>

/* *************************************
 * Defines
 * *************************************/

#define SPRITE_INDEX_INVALID    (size_t)(0xFFFFFFFF)

/* *************************************
 * Public types definition
 * *************************************/

enum
{
    X_SCREEN_RESOLUTION = 384,
    Y_SCREEN_RESOLUTION = 240
};

/* *************************************
 * Public variables declaration
 * *************************************/

/* *************************************
 * Public functions declaration
 * *************************************/

void GfxInit(void);
void GfxSortSprite(const GsSprite* const psSpr);
bool GfxSpriteFromFile(const char* const strFilePath, GsSprite* const pSpr);
void GfxSortSprite(const GsSprite* const psSpr);
bool GfxIsInsideScreenArea(const short x, const short y, const short w, const short h);
void GfxDrawScene(void);

#endif /* GFX_H__ */
