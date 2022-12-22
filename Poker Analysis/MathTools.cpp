//
// Created by Matthew Tapia on 12/9/22.
//

#include "MathTools.h"

int MathTools::gcd(int a, int b) {
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}
