# ImguiNVN
An imgui implementation for nvn (the graphics library used by Nintendo Switch) that can be used with Nintendo Switch applications/games.
This hooks nvn functions, so it might not work if you run this with another executable that also hooks nvn functions.

![hack](https://github.com/TudouHacks/imgui-nvn/raw/master/misc/screenshots/splatoon2.jpg)

# Note
- This project is a work in progress. If you have issues, ask me for support on the [official discord server](https://discord.gg/awq8S2HQq2) for the project.
- This doesnt support sysmodules/applets.

# Credit
- [exlaunch](https://github.com/shadowninja108/exlaunch): Tools for code injection.
- [imgui](https://github.com/ocornut/imgui): ImGui itself.

# How to use
- Inside main.cpp, you have all the necessary functions needed by the rendering code.
- The nvnImguiInitialize method is called during initialization, you can create your imgui context, add fonts etc.
- The nvnImguiCalc method is called every frame and is where you do your rendering. The method returns ImDrawData (you can return NULL if you dont want to draw anything right now) that will be drawn.
- Other methods shouldn't be edited.
- New methods might be introduced later to allow user to manually render to a different render target or in a different thread/render separate draw lists.
- Custom texture support will later be added.

# Some other info
- io.DisplaySize is locked at {1280.0, 720.0} (also defined as SCREEN_W and SCREEN_H). In docked mode it is still the same but the render viewport automatically resizes itself to the screen resolution.
- Like original exlaunch this is compiled with -Werror. This means that any compiler warnings will be treated as errors. If you wish to disable it you can edit the flags in misc/commom.mk

# Installation
- Compile your code by running the shell script (./exlaunch.sh build).
- Drop the contents from deploy folder into your game's exefs folder