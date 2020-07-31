template<class T> T* SpaceShooter::FindObjectByName(const orxSTRING name)
{
    for (T* object = Scroll::GetNextObject<T>(); object != orxNULL; object = Scroll::GetNextObject<T>(object)) {
        if (orxString_Compare(object->GetModelName(), name) == 0) {
            return object;
        }
    }

    return orxNULL;
};
