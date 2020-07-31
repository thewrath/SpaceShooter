/**
 * @file MiniMapPointer.h
 * @date 24-Jul-2020
 */

#ifndef __MINIMAPPOINTER_H__
#define __MINIMAPPOINTER_H__

#include "SpaceShooter.h"

 /** MiniMapPointer Class
  */
class MiniMapPointer : public ScrollObject
{
private:
    void FollowPlayer();

protected:

    void OnCreate();
    void OnDelete();
    void Update(const orxCLOCK_INFO& Info);
};

#endif // __MINIMAPPOINTER_H__
