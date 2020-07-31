/**
 * @file Tanker.cpp
 * @date 24-Jul-2020
 */

#include "Tanker.h"

void Tanker::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    this->type = orxConfig_GetString("Type");
    this->isFull = orxConfig_GetBool("Full");
    this->size = orxConfig_GetU32("Size");
}

void Tanker::OnDelete()
{
}

void Tanker::Update(const orxCLOCK_INFO& _rstInfo)
{

}
