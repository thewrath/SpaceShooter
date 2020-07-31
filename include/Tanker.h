/**
 * @file Tanker.h
 * @date 24-Jul-2020
 */

#ifndef _TANKER_H__
#define _TANKER_H__

#include "SpaceShooter.h"

 /** Tanker Class
  */
class Tanker : public ScrollObject
{
private:
    const orxSTRING type = "None";
    orxBOOL isFull = false;
    orxU32  size = 0;


protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO& Info);
};

#endif // _TANKER_H__
