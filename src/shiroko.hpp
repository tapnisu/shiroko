#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include "asciiFunctions.hpp"
#include "terminalFunctions.hpp"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif
