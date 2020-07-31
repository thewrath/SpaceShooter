/**
 * @file SpaceShooter.cpp
 * @date 24-Jul-2020
 */

#define __SCROLL_IMPL__
#include "SpaceShooter.h"
#undef __SCROLL_IMPL__

#include "Scene.h"
#include "Reactor.h"
#include "Tanker.h"
#include "HUDReactorButton.h"
#include "SpaceShip.h"
#include "ShipControlHUD.h"
#include "Planet.h"
#include "MiniMapPointer.h"

/** Update function, it has been registered to be called every tick of the core clock
 */
void SpaceShooter::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Should quit?
    if(orxInput_IsActive("Quit"))
    {
        // Send close event
        orxEvent_SendShort(orxEVENT_TYPE_SYSTEM, orxSYSTEM_EVENT_CLOSE);
    }
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS SpaceShooter::Init()
{
    // Create the scene
    CreateObject("Scene");

    // Done!
    return orxSTATUS_SUCCESS;
}

/** Run function, it should not contain any game logic
 */
orxSTATUS SpaceShooter::Run()
{
    // Return orxSTATUS_FAILURE to instruct orx to quit
    return orxSTATUS_SUCCESS;
}

/** Exit function, it is called before exiting from orx
 */
void SpaceShooter::Exit()
{
    // Let Orx clean all our mess automatically. :)
}

/** BindObjects function, ScrollObject-derived classes are bound to config sections here
 */
void SpaceShooter::BindObjects()
{
    // Bind the Object class to the Object config section
    ScrollBindObject<Scene>("Scene");
    ScrollBindObject<SpaceShip>("SpaceShip");
    ScrollBindObject<Reactor>("SpaceShipCenterReactor");
    ScrollBindObject<Reactor>("SpaceShipRightReactor");
    ScrollBindObject<Reactor>("SpaceShipLeftReactor");
    ScrollBindObject<Tanker>("SpaceShipHydrogenTanker");
    ScrollBindObject<HUDReactorButton>("ReactorCenterButtonShipControlHUD");
    ScrollBindObject<HUDReactorButton>("ReactorLeftButtonShipControlHUD");
    ScrollBindObject<HUDReactorButton>("ReactorRightButtonShipControlHUD");
    ScrollBindObject<ShipControlHUD>("ShipControlHUD");
    ScrollBindObject<Planet>("PlanetEarth");
    ScrollBindObject<Planet>("PlanetSaturn");
    ScrollBindObject<Planet>("PlanetJupyter");
    ScrollBindObject<Planet>("PlanetMars");
    ScrollBindObject<Planet>("PlanetSun");
    ScrollBindObject<MiniMapPointer>("MiniMapPointer");
}

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS SpaceShooter::Bootstrap() const
{
    // Add a config storage to find the initial config file
    orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, "../data/config", orxFALSE);

    // Return orxSTATUS_FAILURE to prevent orx from loading the default config file
    return orxSTATUS_SUCCESS;
}

/** Main function
 */
int main(int argc, char **argv)
{
    // Execute our game
    SpaceShooter::GetInstance().Execute(argc, argv);

    // Done!
    return EXIT_SUCCESS;
}
