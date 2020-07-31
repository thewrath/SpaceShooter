/**
 * @file Scene.cpp
 * @date 24-Jul-2020
 */

#include "Scene.h"

void Scene::OnCreate()
{
    orxConfig_SetBool("IsObject", orxTRUE);
}

void Scene::OnDelete()
{
}

void Scene::Update(const orxCLOCK_INFO& _rstInfo)
{
}
