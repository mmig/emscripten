/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2007 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/


#include "btBulletDynamicsCommon.h"
#include "BenchmarkDemo.h"

#include <iostream>

#include <emscripten.h>

/// This is a Hello World program for running a basic Bullet physics simulation

BenchmarkDemo3 benchmarkDemo3;

int main(int argc, char** argv)
{
  EM_ASM({
    startSimulation();
  });

  emscripten_exit_with_live_runtime();
}

extern "C" {

void EMSCRIPTEN_KEEPALIVE simulate() {
  static int i = 0;
  if (i % 10 == 0) std::cout << "frame " << i << "starting" << std::endl;

  benchmarkDemo3.initPhysics();
	for (int i = 0; i < 1; i++) {
		benchmarkDemo3.clientMoveAndDisplay();
  }
  benchmarkDemo3.exitPhysics();

  if (i % 10 == 0) std::cout << "frame " << i << "complete" << std::endl;
  i++;
}

}
