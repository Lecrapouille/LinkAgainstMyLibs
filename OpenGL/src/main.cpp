//=====================================================================
// OpenGLCppWrapper: A C++11 OpenGL 'Core' wrapper.
// Copyright 2018-2019 Quentin Quadrat <lecrapouille@gmail.com>
//
// This file is part of OpenGLCppWrapper.
//
// OpenGLCppWrapper is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OpenGLCppWrapper is distributedin the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with OpenGLCppWrapper.  If not, see <http://www.gnu.org/licenses/>.
//=====================================================================

#include "BasicWindow.hpp"
#include <iostream>
#include <stdlib.h>
#include <limits.h>

#define WIDTH 800
#define HEIGHT 600

//------------------------------------------------------------------------------
int main()
{
  std::unique_ptr<GLWindow> win;
  try
    {
      win = std::make_unique<BasicWindow>(WIDTH, HEIGHT, "Hello OpenGLCppWrapper");
      return win->run() ? EXIT_SUCCESS : EXIT_FAILURE;
    }
  catch (const GL::Exception& e)
    {
      // Caught OpenGLException from constructors
      std::cerr << "Caught exception from constructors: " << e.message() << std::endl;
      return EXIT_FAILURE;
    }
}
