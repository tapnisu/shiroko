# Shiroko

### CLI tool to view videos and images in terminal

## Dependencies

* Opencv
* CMake
* git

## How to build this thing

1. Clone the repo: `git clone https://github.com/tapnisold/shiroko.git`
2. Move into it: `cd shiroko`
3. Create build directory: `mkdir build`
4. Move into it: `cd build`
5. Use cmake: `cmake ..`
6. Build it with make: `make`
7. Now you have `./shiroko-image` and `./shiroko-video` for images and videos

## How to use

* Images: `shiroko-image ./path-to-image.png 100` - where 100 is width
* Images: `shiroko-video ./path-to-video.mpv 100` - where 100 is width
