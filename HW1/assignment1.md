# Introduction to the OpenGL family

Zhang Qiuyi, 12330402

## What is OpenGL?

OpenGL(Open Graphics Library) is an **API** designed for rendering 2D and 3D graphics. It is usually used by applications to talk with GPU in order to get hardware-acceleration. Since OpenGL is just an API, it is not limited by programming languages or platforms.

OpenGL has many versions, extensions, and variations, including WebGL, OpenGL ES, OpenCL, OpenAL, etc. Most of them are now governed by the Khronos Group. You can discover more members on [their website](https://www.khronos.org/). Here in this essay, I will focus on OpenGL, OpenGL ES, WebGL, OpenCL, OpenAL, and OpenVG.

### OpenGL

The **OpenGL** specification is widely implemented by graphics card manufacturers, and almost every operating system provides binding for it. It is, in fact, a set of functions and constants for drawing 2D and 3D graphics, which are designed to be language-independent. Since OpenGL doesn't specify anything about the input, audio, or windowing, these details can be left to the operating system, which makes OpenGL cross-platform.

Beside what the OpenGL specifies, hardware manufacturers usually will implement extensions of their own. Popular extensions will be incooperated into new releases of the specification itself. The latest release of OpenGL currently is OpenGL 4.5.

### OpenGL ES

**OpenGL ES**(OpenGL for Embedded Systems) is a subset of OpenGL, tailored for  embedded systems like smart phones and tablets. It is implemented by most mobile devices including iPhones, iPads, Nexus, and most products of HTC, Samsung, and Sony, etc. The latest release of OpenGL ES is OpenGL 3.1.

### WebGL

Simply put, **WebGL** is "OpenGL for the Web". It is a JavaScript API based on OpenGL ES 2.0, designed for browsers to render 2D and 3D hardware-accelarated graphics without plugins. It is implemented by most latest browsers (both desktop browsers and mobile browsers), typically by providing a JavaScript binding to the underlying OpenGL API.

Since the windowing, audio, and I/O in the browser are specified in web standards and are also cross-platform, developers can use WebGL to write cross-platform graphics applications without too much code for porting.

### OpenCL

**OpenCL**(Open Computing Language) is a framework designed for computation on heterogeneous platforms(including CPUs, GPUs, DSPs, and FPGAs). It consists of a programming language based on C99 and an API to control the platform. OpenCL also provides convenience for parallel computing. It can help developers to use different platforms to do the same computation.

### OpenAL

**OpenAL**(Open Audio Library) is a cross-platform API for rendering multichannel three-dimensional positional audio. It deliberately resembles the OpenGL API, and is widely supported by popular gaming devices like Wii, Xbox, and PS2/3.

### OpenVG

**OpenVG** is similar to OpenGL ES in that it is tailored for mobile devices with small screens, but it is designed for rendering 2D vector graphics. The latest release is OpenVG 1.1. It is, however, not as popular as OpenGL ES, and is not widely implemented yet.

## Comparison of OpenGL family members

|        | OpenGL | OpenGL ES | WebGL | OpenCL | OpenAL | OpenVG |
|--------|--------|-----------|-------|--------|--------|--------|
| Main target   | Graphic cards | Mobile devices  | Browsers |  Heterogeneous platforms   | Sound cards | Mobile devices |
| Language | Language-independent  |Language-independent | JavaScript |  OpenCL C  | Language-independent  | Language-independent |
| Type of application |  2D / 3D  | Mainly 3D |  Mainly 3D | General computation | Audio | 2D |

## DirectX and Metal

**DirectX** is a set of APIs for developing multimedia applications, especially games. In addition to APIs for 3D and 2D rendering, it also provides APIs for audio, video, and input devices. It can only be used on Microsoft platforms, including Windows and Xbox. 

**Metal** is a low-level API for hardware-accelerated graphics. It is designed for Apple's System on Chip(Soc) and can provide better performance for these chips.

## Comparison of OpenGL, DirectX, and Metal

