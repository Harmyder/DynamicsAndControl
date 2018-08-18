#include "stdafx.h"

namespace Common
{
    const glm::vec4 kVecZero = { 0,0,0,0 };
    const glm::vec4 kVecUnitX = { 1,0,0,0 };
    const glm::vec4 kVecUnitY = { 0,1,0,0 };
    const glm::vec4 kVecUnitZ = { 0,0,1,0 };
    const glm::vec4 kVecUnitW = { 0,0,0,1 };
    const glm::mat4 kMatEye  = { kVecUnitX, kVecUnitY, kVecUnitZ, kVecUnitW };
    const glm::mat4 kMatHomo = { kVecZero, kVecZero, kVecZero, kVecUnitW };
}
