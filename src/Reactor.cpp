/**
 * @file Reactor.cpp
 * @date 24-Jul-2020
 */

#include "Reactor.h"

void Reactor::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    // Get value from configuration file
    orxConfig_GetVector("EngineReversePosition", &this->reversePosition);
    // Restore Engine (set all with initial values)
    this->RestoreEngine();
}

void Reactor::OnDelete()
{
}

void Reactor::Update(const orxCLOCK_INFO& _rstInfo)
{
    this->RestoreEngine();
}

void Reactor::SetAlpha(orxFLOAT alpha)
{
    orxCOLOR lastColor;
    this->GetColor(lastColor);
    lastColor.fAlpha = alpha;
    this->SetColor(lastColor);
}

orxFLOAT Reactor::GetAlpha()
{
    orxCOLOR lastColor;
    this->GetColor(lastColor);
    return lastColor.fAlpha;
}

void Reactor::TurnOn()
{
    this->isOn = true;
    this->SetAlpha(1);
}

void Reactor::TurnOff()
{
    this->isOn = false;
    this->SetAlpha(0);
}

orxFLOAT Reactor::GetAngle()
{
    return (this->isOn) ? this->angle : 0;
}

orxVECTOR Reactor::GetVelocity()
{
    return (this->isOn) ? this->velocity : orxVECTOR_0;
}

void Reactor::ReverseEngine()
{
    orxVector_Neg(&this->velocity, &this->velocity);
    this->angle = -this->angle;

    this->SetPosition(this->reversePosition);

    this->SetScale(this->flipDown); 
}

void Reactor::RestoreEngine()
{
    // Restore all engine configuration to initial configuration
    // To access configuration we need to push section state
    orxVECTOR initialPosition = orxVECTOR_0;

    orxConfig_PushSection(this->GetModelName());
    this->angle = orxMATH_KF_PI / orxConfig_GetFloat("EngineAngle");
    orxConfig_GetVector("EngineVelocity", &this->velocity);
    orxConfig_GetVector("Position", &initialPosition);
    this->SetPosition(initialPosition);
    orxConfig_PopSection();
    this->SetScale(this->flipUp);
}
