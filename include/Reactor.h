/**
 * @file Reactor.h
 * @date 24-Jul-2020
 */

#ifndef __REACTOR_H__
#define __REACTOR_H__

#include "SpaceShooter.h"

 /** Reactor Class
  */
class Reactor : public ScrollObject
{
    private:
        orxBOOL isOn = false;
        orxFLOAT angle = 0;
        orxVECTOR velocity = { 0, 0, 0 };
        orxVECTOR flipUp = { 1, 1, 1 };
        orxVECTOR flipDown = { 1, -1, 1 };
        orxVECTOR reversePosition = orxVECTOR_0;

        void SetAlpha(orxFLOAT);
        orxFLOAT Reactor::GetAlpha();

    protected:
        void OnCreate();
        void OnDelete();
        void Update(const orxCLOCK_INFO& Info);

    public:
        void TurnOn();
        void TurnOff();
        orxFLOAT GetAngle();
        orxVECTOR GetVelocity();
        void ReverseEngine();
        void RestoreEngine();
};

#endif // __REACTOR_H__
