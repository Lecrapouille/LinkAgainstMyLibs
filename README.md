# LinkAgainstMyLibs

Link against my libraries (Forth, OpenGL, Logger, SimCity/GlassBox ...) to check if standalone project using them can compile.

## Download

```sh
git clone git@github.com:Lecrapouille/LinkAgainstMyLibs.git --recurse-submodules
```

## libSimForth

https://github.com/Lecrapouille/SimForth

Classic Forth interpreter:
```sh
cd Forth
make -j8
./build/Forth
```

Extended Forth interpreter:
```sh
cd ExtendedForth
make -j8
./build/ExtendedForth
```

## libOpenGLCppWrapper

https://github.com/Lecrapouille/OpenGLCppWrapper

```sh
cd OpenGL
make -j8
./build/OpenGL
```

## liblogger

https://github.com/Lecrapouille/MyLogger

```sh
cd Logger
make -j8
./build/Logger
```

## libopenglassbox

https://github.com/Lecrapouille/OpenGlassBox

```sh
cd OpenGlassBox
make -j8
./build/OpenGlassBox
```

## libtimedpetrineteditor

https://github.com/Lecrapouille/TimedPetriNetEditor

```sh
cd TimedPetriNetEditor
make -j8
./build/TimedPetriNetEditor
```

## libzipper

https://github.com/Lecrapouille/zipper

```sh
cd Zipper
make -j8
./build/Zipper
```
