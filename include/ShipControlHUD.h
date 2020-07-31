/**
 * @file ShipControlHUD.h
 * @date 24-Jul-2020
 */

#ifndef __SHIPCONTROLHUD_H__
#define __SHIPCONTROLHUD_H__

#include "SpaceShooter.h"

 /** ShipControlHUD Class
     This class handle inputs for SpaceShip control
  */
class ShipControlHUD : public ScrollObject
{
private:
    orxCAMERA* gameCamera = orxNULL;
    orxFLOAT    zoomStep = 0.05f;
    orxFLOAT    maxZoom = 1.5f;
    orxFLOAT    minZoom = 0.0f;

protected:

    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO& Info);
};

#endif // __SHIPCONTROLHUD_H__
