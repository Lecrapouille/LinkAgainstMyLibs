Standalone project linking against [Compages](https://github.com/Lecrapouille/Compages) (oldy OpenGLCppWrapper).

Install Compages from its tree, then refresh the loader cache (required on Fedora — `/usr/local/lib` is not searched until then):

```sh
sudo make install   # in OpenGLCppWrapper
sudo ldconfig
```

If `ldconfig` still does not pick up `/usr/local/lib`, add it once:

```sh
echo '/usr/local/lib' | sudo tee /etc/ld.so.conf.d/usrlocal.conf
sudo ldconfig
```

Then:

```sh
cd OpenGL
make -j8
./build/Triangle
./build/HeadlessCompute
```

Examples:

- **Triangle** — colored triangle with `compages::gpu::Drawable` and attributes set by name.
- **HeadlessCompute** — invisible 1×1 context, one compute dispatch, results printed to the terminal.

Both use GLFW only to create an OpenGL 4.5 context; rendering and compute go through Compages.
