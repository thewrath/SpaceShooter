/**
 * @file HUDButton.cpp
 * @date 24-Jul-2020
 */

#include "HUDButton.h"

void HUDButton::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    this->currentState = (orxConfig_GetString("State") == "Enable") ? State::ENABLE: State::DISABLE;
    this->mappedKeyName = orxConfig_GetString("MappedKey");
}

void HUDButton::OnDelete()
{
}

void HUDButton::Update(const orxCLOCK_INFO& _rstInfo)
{
    orxOBJECT* object = orxNULL;

    // Let's fetch the mouse's position
    orxVECTOR vPos;
    if (orxRender_GetWorldPosition(orxMouse_GetPosition(&vPos), orxNULL, &vPos) != orxNULL)
    {
        // Let's see what's currently under the mouse
        object = orxObject_Pick(&vPos, orxString_GetID("HUDButton"));
    }

    if (object && orxInput_IsActive("LeftClick") && orxInput_HasNewStatus("LeftClick") == orxTRUE)
    {
        // I'm the clicked one ? 
        if (orxString_Compare(orxObject_GetName(object), this->GetModelName()) == 0) {
            this->SwitchState();
        }
    }

    if (orxInput_IsActive(this->mappedKeyName) && orxInput_HasNewStatus(this->mappedKeyName)) {
        this->SwitchState();
    }
}

void HUDButton::SwitchState()
{
    // Switch state
    this->currentState = (this->currentState == HUDButton::State::ENABLE) ? HUDButton::State::DISABLE : HUDButton::State::ENABLE;
    // Call event handler 
    this->OnStateSwitch();
}

void HUDButton::OnStateSwitch()
{

}
