/**
 * @file MiniMapPointer.cpp
 * @date 24-Jul-2020
 */

#include "MiniMapPointer.h"

void MiniMapPointer::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
}

void MiniMapPointer::OnDelete()
{
}

void MiniMapPointer::Update(const orxCLOCK_INFO& _rstInfo)
{
}
