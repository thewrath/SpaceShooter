/**
 * @file Planet.cpp
 * @date 24-Jul-2020
 */

#include "Planet.h"

void Planet::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    orxFLOAT percent = orxConfig_GetU32("RadiusPercent");
    this->angle = orxConfig_GetFloat("InitialAngle");
    this->rotationSpeed = orxConfig_GetFloat("RotationSpeed");

    // Get solar system radius from config
    orxConfig_PushSection("SolarSystem");
    this->solarSystemRadius = orxConfig_GetU32("MaxRadius");
    orxConfig_PopSection();

    // Compute initial position
    this->solarSystemRadius = (this->solarSystemRadius * percent) / 100;
    this->ComputePosition();
}

void Planet::OnDelete()
{
}

void Planet::Update(const orxCLOCK_INFO& _rstInfo)
{
    this->angle += this->rotationSpeed;
    this->ComputePosition();
}

void Planet::ComputePosition()
{
    orxVECTOR initialPosition = { orxMath_Cos(this->angle) * (orxFLOAT)this->solarSystemRadius, orxMath_Sin(this->angle) * (orxFLOAT)this->solarSystemRadius , 0.0 };
    this->SetPosition(initialPosition);
}
