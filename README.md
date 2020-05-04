# LinkAgainstMyLibs

Link against my libraries (Forth, OpenGL, Logger ...) to check if standalone project using them can compile.

## Download

```sh
git clone git@github.com:Lecrapouille/LinkAgainstMyLibs.git --recurse-submodules
```

## libSimForth

https://github.com/Lecrapouille/SimForth

```sh
cd Forth
make -j8
./build/Forth
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
