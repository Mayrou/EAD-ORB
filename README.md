# EAD-ORB

Official C++ implementation for the paper:  
**"EAD-ORB: Robust Feature Matching via Entropy-Guided Detection and Adaptive Description"** *(ZhiHeng Tang, Yan Dou, Xiaoya Wang, Lele Zhang)*

This repository contains the source code for the EAD-ORB feature matching algorithm, designed to overcome the limitations of standard ORB in challenging conditions such as drastic illumination changes and low-texture regions.

---

## Qualitative Results

A quick comparison between standard ORB (Top) and our EAD-ORB (Bottom) on the challenging `leuven` sequence (severe illumination change).

![Qualitative Comparison](https://i.imgur.com/your-image-link.gif)  
*(Note: Please replace this with a link to your actual result image or GIF)*

---

## Dependencies

The following dependencies are required to build the project:

* **CMake** (>= 3.10)
* **OpenCV** (>= 4.0)
* **C++14 compliant compiler** (e.g., g++ or Clang)

---

## Build Instructions

To build the project, clone this repository and run the following commands from the root directory:

```bash
git clone [https://github.com/your_username/EAD-ORB.git](https://github.com/your_username/EAD-ORB.git)
cd EAD-ORB
mkdir build
cd build
cmake ..
make
