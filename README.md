# LinkAgainstMyLibs

Link against my libraries (Forth, OpenGL ...) to check if standalone project using them can compile.

## Download

```sh
git clone git@github.com:Lecrapouille/LinkAgainstMyLibs.git --recurse-submodules
```

## libSimForth

```sh
cd Forth
make -j8
./build/Forth
```

## libOpenGLCppWrapper

```sh
cd OpenGL
make -j8
./build/OpenGL
```

## liblogger

```sh
cd Logger
make -j8
./build/Logger
```
