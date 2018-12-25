#ifndef KEYGENERATOR_H
#define KEYGENERATOR_H

#include "paramstypes.h"

class KeyGenerator
{
public:
    static QString generateKey(ProductRegisterFormParam *productData);
};

#endif // KEYGENERATOR_H
