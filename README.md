# LinkAgainstMyLibs

Link against my libraries (Forth, OpenGL, Logger, SimCity/GlassBox ...) to check if standalone project using them can compile.

Each folder is a project built by [MyMakefile](https://github.com/Lecrapouille/MyMakefile) (the submodule `.makefile`), linking against a library installed on the system and found by pkg-config. The programs are built in `build/<configuration>/bin/`, for example `build/linux-gcc-release/bin/Zipper`.

## Download

```sh
git clone git@github.com:Lecrapouille/LinkAgainstMyLibs.git --recurse-submodules
```

## libSimForth

https://github.com/Lecrapouille/SimForth

Classic Forth interpreter:
```sh
cd Forth
make
make run-Forth
```

Extended Forth interpreter:
```sh
cd ExtendedForth
make
make run-ExtendedForth
```

## Compages (OpenGLCppWrapper)

https://github.com/Lecrapouille/Compages

Install Compages, then:

```sh
cd OpenGL
make
make run-Triangle
make run-HeadlessCompute
```

## liblogger

https://github.com/Lecrapouille/MyLogger

```sh
cd Logger
make
make run-Logger
```

## libopenglassbox

https://github.com/Lecrapouille/OpenGlassBox

```sh
cd OpenGlassBox
make
make run-OpenGlassBox
```

## libtimedpetrineteditor

https://github.com/Lecrapouille/TimedPetriNetEditor

```sh
cd TimedPetriNetEditor
make
make run-TimedPetriNetEditor
```

## libzipper

https://github.com/Lecrapouille/zipper

```sh
cd Zipper
make
make run-Zipper
```
