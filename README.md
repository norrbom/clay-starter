# Clay Starter

## Raylib

Install required libraries for raylib

https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux

OR:

TL;DR - Ubuntu:

```shell
sudo apt-get update
sudo apt install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

Download and build raylib

```shell
git clone --branch 5.5 --depth 1 https://github.com/raysan5/raylib.git raylib-5.5
cd raylib-5.5/src/
make PLATFORM=PLATFORM_DESKTOP
sudo make install DESTDIR=../../raylib
cd ../../
sudo chown -R $(id -u):$(id -g) raylib
rm -fr raylib-5.5
```

## Download clay

```shell
git clone --depth=1 https://github.com/nicbarker/clay.git
rm -fr clay/.git clay/.github clay/.gitignore clay/cmake clay/CMakeLists.txt
```

## Build

```shell
make
```