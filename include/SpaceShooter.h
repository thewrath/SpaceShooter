/**
 * @file SpaceShooter.h
 * @date 24-Jul-2020
 */

#ifndef __SpaceShooter_H__
#define __SpaceShooter_H__

#define __NO_SCROLLED__
#include "Scroll.h"

#include "string.h"

/** Game Class
 */
class SpaceShooter : public Scroll<SpaceShooter>
{
    public:
        template<class T> T* FindObjectByName(const orxSTRING);

    private:

        orxSTATUS       Bootstrap() const;

        void            Update(const orxCLOCK_INFO &Info);

        orxSTATUS       Init();
        orxSTATUS       Run();
        void            Exit();
        void            BindObjects();
};

// Inline include
#include "SpaceShooter.inl"

#endif // __SpaceShooter_H__
