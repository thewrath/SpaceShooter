/**
 * @file Planet.h
 * @date 24-Jul-2020
 */

#ifndef _PLANET_H__
#define _PLANET_H__

#include "SpaceShooter.h"

 /** Planet Class
  */
class Planet : public ScrollObject
{
private:
    orxU32  solarSystemRadius = 0;
    orxFLOAT angle = 0.0f;
    orxFLOAT rotationSpeed = 0.0f;

    void ComputePosition();
protected:
    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO& Info);
};

#endif // _PLANET_H__
