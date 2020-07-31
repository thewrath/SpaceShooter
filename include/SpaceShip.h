/**
 * @file SpaceShip.h
 * @date 24-Jul-2020
 */

#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "SpaceShooter.h"
#include "Reactor.h"

 /** SpaceShip Class
  */
class SpaceShip : public ScrollObject
{
    private:
        orxVECTOR velocity = { 0, -20, 0 };

        Reactor* centerReactor;
        Reactor* leftReactor;
        Reactor* rightReactor;

        ScrollObject* GetChildByName(const orxSTRING);
        void Rotate(orxFLOAT);
            
    protected:
        void OnCreate();
        void OnDelete();
        void Update(const orxCLOCK_INFO& Info);
};

#endif // __SPACESHIP_H__
