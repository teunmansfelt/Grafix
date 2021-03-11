# Grafix Engine Project
---
### A project that explores what a possible game engine might look like
> This project follows a [series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) on building a game engine by [The Cherno](https://www.youtube.com/c/TheChernoProject) . This project serves as a personal learning experience and most code will be very similar to the series described above (for now at least).

##### Support
> As of today the game engine only supports Unix operating systems.
> The engine currently runs using GLFW and GLAD, for window creation and graphics API respectively.

##### Current features
- Engine-side Entrypoint.
- Application base-class that can be extended by the client application.
- Logging system built with [spdlog](https://github.com/gabime/spdlog).
- Basic event system for keyboard-, mouse-, and windowevents.
- Window abstraction and a Platform specific window implementation built with [GLFW](https://github.com/glfw/glfw).
- Layerstack and a Layer base-class that can be extended by the client.
- Gui editor layer built with [Dear ImGui](https://github.com/ocornut/imgui).

##### Build
> The project compiles with the use of Makefiles and the g++/gcc compiler. All external libraries are compiled into static libraries which are linked with the Grafix Engine. The engine itself compiles into a dynamic link library that can be used by the client application.
