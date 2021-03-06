// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma comment(lib, "../GL/glut32.lib")
#pragma comment(lib, "opengl32.lib")

#include <stdlib.h>
#include "../GL/glut.h"

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/mat3x3.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#define NOMINMAX
#include <Windows.h>


#include "Common/Types.h"
#include "Common/Consts.h"
using Common::kVecZero;
using Common::kVecUnitX;
using Common::kVecUnitY;
using Common::kVecUnitZ;
using Common::kVecUnitW;
using Common::kMatEye;
using Common::kMatHomo;
