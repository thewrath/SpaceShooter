/**
 * @file SpaceShip.cpp
 * @date 24-Jul-2020
 */

#include "SpaceShip.h"

void SpaceShip::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    orxConfig_GetVector("Velocity", &this->velocity);

    // Get all ship reactors
    this->centerReactor = (Reactor*)this->GetChildByName("SpaceShipCenterReactor");
    this->rightReactor = (Reactor*)this->GetChildByName("SpaceShipRightReactor");
    this->leftReactor = (Reactor*)this->GetChildByName("SpaceShipLeftReactor");

    // Set GameCamera to follow SpaceShip
    orxVIEWPORT* viewport = orxViewport_Get("GameViewport");
    orxCamera_SetParent(orxViewport_GetCamera(viewport), this->GetOrxObject());
    orxCamera_SetZoom(orxViewport_GetCamera(viewport), 0.3f);


    // Create viewport for HUD elements 
    orxViewport_CreateFromConfig("HUDViewport");

    // Set MiniMapCamera to follow SpaceShip
    // Create viewport for minimap
    orxVIEWPORT* miniMapViewport = orxViewport_CreateFromConfig("MiniMapViewport");
    orxCamera_SetParent(orxViewport_GetCamera(miniMapViewport), this->GetOrxObject());
    orxCamera_SetZoom(orxViewport_GetCamera(miniMapViewport), 0.03f);
}

void SpaceShip::OnDelete()
{
}

void SpaceShip::Update(const orxCLOCK_INFO& _rstInfo)
{
    orxVECTOR velocity = orxVECTOR_0;

    // Left and right reactor update rotation of the spaceShip
    this->Rotate(this->rightReactor->GetAngle());
    this->Rotate(this->leftReactor->GetAngle());

    // Velocity (addition of all activated engines velocity)
    orxVector_Add(&velocity, &velocity, &this->centerReactor->GetVelocity());
    orxVector_Add(&velocity, &velocity, &this->rightReactor->GetVelocity());
    orxVector_Add(&velocity, &velocity, &this->leftReactor->GetVelocity());

    // Apply velocity
    orxObject_SetRelativeSpeed(this->GetOrxObject(), &velocity);
}

ScrollObject* SpaceShip::GetChildByName(const orxSTRING childName) {

    for (ScrollObject* child = this->GetOwnedChild(); child; child = child->GetOwnedSibling()) {
        if (orxString_Compare(child->GetModelName(), childName) == 0) {
            return child;
        }
    }

    return orxNULL;
}

void SpaceShip::Rotate(orxFLOAT step)
{
    orxFLOAT currentRotation = this->GetRotation();
    this->SetRotation(currentRotation + step);
}
