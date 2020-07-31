/**
 * @file ShipControlHUD.cpp
 * @date 24-Jul-2020
 */

#include "ShipControlHUD.h"

void ShipControlHUD::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
    this->gameCamera = orxCamera_Get("GameCamera");
    this->zoomStep = orxConfig_GetFloat("ZoomStep");
    this->maxZoom = orxConfig_GetFloat("MaxZoom");
    this->minZoom = orxConfig_GetFloat("MinZoom");
}

void ShipControlHUD::OnDelete()
{
}

void ShipControlHUD::Update(const orxCLOCK_INFO& _rstInfo)
{
    // Camera zoom
    orxFLOAT zoom = orxCamera_GetZoom(this->gameCamera);
    orxFLOAT supp = 0.0f;
    if (orxInput_IsActive("ZoomUp") && orxInput_HasNewStatus("ZoomUp")  && zoom + this->zoomStep < this->maxZoom) {
        supp = 0.1f;
    } else if (orxInput_IsActive("ZoomDown") && orxInput_HasNewStatus("ZoomDown") && zoom - this->zoomStep > this->minZoom) {
        supp = -0.1f;
    }

    if (supp != 0.0f) {
        // Update camera zoom 
        orxCamera_SetZoom(this->gameCamera, zoom + supp);
    }
}
