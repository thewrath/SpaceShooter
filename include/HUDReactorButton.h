/**
 * @file HUDReactorButton.h
 * @date 24-Jul-2020
 */

#ifndef __HUDREACTORBUTTON_H__
#define __HUDREACTORBUTTON_H__

#include "SpaceShooter.h"
#include "HUDButton.h"
#include "Reactor.h"

/** HUDReactorButton Class
 */
class HUDReactorButton : public HUDButton
{
    private:
        Reactor* reactor = nullptr;
        void BindToReactor();

    protected:
        void OnCreate() override;
        void OnStateSwitch() override;

};

#endif // __HUDREACTORBUTTON_H__
