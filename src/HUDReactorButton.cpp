/**
 * @file HUDReactorButton.cpp
 * @date 24-Jul-2020
 */

#include "HUDReactorButton.h"

void HUDReactorButton::OnCreate()
{
    HUDButton::OnCreate();
    this->BindToReactor();
}

void HUDReactorButton::OnStateSwitch()
{
    // To prevent from first start no bind bug
    if (!this->reactor) {
        this->BindToReactor();
    }

    if (this->currentState == HUDButton::State::ENABLE) {
        this->SetAnim("ReactorButtonShipControlHUDEnable");
        this->reactor->TurnOn();
    } else {
        this->SetAnim("ReactorButtonShipControlHUDDisable");
        this->reactor->TurnOff();    
    }
}

void HUDReactorButton::BindToReactor()
{
    // Get reactor name from config file
    orxConfig_PushSection(this->GetModelName());
    const orxSTRING reactorName = orxConfig_GetString("SpaceShipReactor");
    if (reactorName) {
        this->reactor = SpaceShooter::GetInstance().FindObjectByName<Reactor>(reactorName);
    }
    orxConfig_PopSection();
}
