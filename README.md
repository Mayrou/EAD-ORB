# EAD-ORB
### Official C++ Implementation of "Enhanced Feature Matching: Entropy-Guided ORB with Adaptive Descriptors"


This repository contains the source code for the EAD-ORB feature matching algorithm, designed to overcome the limitations of standard ORB in challenging conditions such as drastic illumination changes and low-texture regions.

---

## Dataset
The experiments in our paper were conducted on the following standard benchmarks. Our method is training-free, so these datasets are used for evaluation only.

1.  **HPatches Benchmark** A large-scale benchmark for evaluating local features under both significant viewpoint and illumination changes. This was our primary platform for quantitative evaluation.
    * **[Official Website & Download](https://hpatches.github.io/)**

2.  **Oxford Affine Dataset** A classic dataset for evaluating feature robustness to various affine transformations, including blur, JPEG compression, illumination, and viewpoint changes. We used sequences from this dataset for supplementary qualitative analysis.
    * **[Official Website & Download](https://www.robots.ox.ac.uk/~vgg/data/affine/)**


---

## Dependencies

The following dependencies are required to build the project:

* **OpenCV** (>= 4.0)
* **C++14 compliant compiler** (e.g., g++ or Clang)

---

## Structure and others

will be announced after the paper is accepted.
