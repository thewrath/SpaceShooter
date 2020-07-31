/**
 * @file HUDButton.h
 * @date 24-Jul-2020
 */

#ifndef __HUDBUTTON_H__
#define __HUDBUTTON_H__

#include "SpaceShooter.h"

 /** HUDButton Class
  */
class HUDButton  : public ScrollObject
{
    private :
        const orxSTRING   mappedKeyName;

    public :
        enum class State { ENABLE, DISABLE };

    protected:
        State currentState;

        void OnCreate();
        void OnDelete();
        void Update(const orxCLOCK_INFO& Info);

        void SwitchState();
        virtual void OnStateSwitch();
};

#endif // __HUDBUTTON_H__
