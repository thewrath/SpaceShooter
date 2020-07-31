/**
 * @file Scene.h
 * @date 24-Jul-2020
 */

#ifndef __SCENE_H__
#define __SCENE_H__

#include "SpaceShooter.h"

 /** Scene Class
  */
class Scene : public ScrollObject
{

    protected:
        void OnCreate();
        void OnDelete();
        void Update(const orxCLOCK_INFO& Info);

};

#endif // __SCENE_H__
