/**
 * @file Object.h
 * @date 24-Jul-2020
 */

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "SpaceShooter.h"

/** Object Class
 */
class Object : public ScrollObject
{
public:


protected:

                void            OnCreate();
                void            OnDelete();
                void            Update(const orxCLOCK_INFO &Info);


private:
};

#endif // __OBJECT_H__
