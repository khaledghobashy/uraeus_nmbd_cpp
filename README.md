# **URAEUS**

# uraeus.nmbd.cpp

**Numerical Multi-Body Dynamics in C++** | A  numerical simulation environment developed in C++ for the numerical code-generation and numerical simulation of the symbolic models developed in **[uraeus.smbd]( https://github.com/khaledghobashy/uraeus-smbd )**.

*Please visit **[uraeus.mbd]( https://github.com/khaledghobashy/uraeus_mbd )** for more information about **audience** , **fields of applications** and **background**.*

---

## Features

#### Code-Generation

- Code-generation for symbolic standalone topologies.
- Cython wrappers for selected C++ classes, exposing a minimal API that can be used from the python side to interact with the generated models.
- CMakeLists.txt for automated cross-platform build-systems generation using CMake, building simulation executable and python extension modules.

#### Simulation

- Solver for **Kinematically Driven Systems** that can be used for forward and inverse kinematic analysis as well as inverse dynamic analysis.
- Solver for **Dynamically Driven Systems** that can be used for forward dynamic analysis and equilibrium analysis.

#### Usage

- Simple interaction with the generated models through a minimal API `Simulation` class,  exposing only the needed functionalities.
  - Loading model configuration data from JSON file.
  - Setting user-defined functions to control motion-actuators and generic force elements using normal C++ free-functions and lambda functions.
  - Simulating the model for the desired time period and desired step-size.
  - Saving the simulation results (positions, velocities, accelerations, reactions) as csv files, that can be used later for post-processing and visualizations in  [**uraeus.visenv.babylon**](https://github.com/khaledghobashy/uraeus_visenv_babylon).
- Simple interaction with the generated models through python.
  - Importing the model as a python module.
  - Having access to the same minimal API of the  `Simulation` class.
  - Defining functions to control motion-actuators and generic force-elements using your custom python functions.

---

## Installation

#### Prerequisites

- Python 3.6+.
  If new to scientific computing in python, [Anaconda](https://www.anaconda.com/download/) is a recommended free python distribution from Continuum Analytics  which provides a nice coherent platform with most of the tools needed. 
- The [uraeus.smbd](https://github.com/khaledghobashy/uraeus-smbd) python package.
- [Git](https://git-scm.com/downloads), for cloning the project repository.
- [CMake](https://cmake.org/download/), for build-systems generation. The project requires cmake 3.10 or higher.
- A modern C++ compiler supporting C++17 standards. 
  The project is tested with the **[gcc](https://gcc.gnu.org/)** 10 compiler on a Linux machine and the Microsoft C++ build tools [**MSVC**](https://visualstudio.microsoft.com/visual-cpp-build-tools/) on a Windows-10 machine.



#### Getting the source-code

You can clone or download the project on your machine. 
For cloning, make sure you have [git](https://git-scm.com/downloads) installed on your machine and your system have access to the `git` commands through your terminal, command-prompt or power-shell.

Open your terminal then type the below command:

```bash
git clone https://github.com/khaledghobashy/uraeus_nmbd_cpp.git
```

This will clone the project repository and download it on your machine in your current terminal directory.



#### Building the project binaries

On the same open terminal, go to the source-code directory via the command below:

```bash
cd uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine
```

then create a `/build` directory by:

```bash
mkdir build
cd build
```

Now, we generate the build-system using `cmake`:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

then we invoke the build process via `cmake --build`. For multiple configuration build systems, i.e. `msvc` use:

```bash
cmake --build . --config Release
```

For single configuration build systems, i.e. `make`, use:

```bash
cmake --build . 
```

This will build the project binaries and produce a shared library `uraeuslib` that will be used to link with the simulation executables and generated python extension modules.

Now, the project can be found via other `cmake` projects, where the paths for the headers and libraries binaries are automatically configured for projects using `uraeus.nmbd.cpp`.



*t.b.c ...*



## Examples

The repository provides several examples in a form of **jupyter notebooks** that can be tested on the cloud using [Google Colaboratory](https://colab.research.google.com/) without the need for any setup on your local machine. The notebooks uses [**uraeus.smbd**](https://https//github.com/khaledghobashy/uraeus-smbd) to model the system symbolically, then using [**uraeus.nmbd.cpp**](https://github.com/khaledghobashy/uraeus_nmbd_cpp) to perform the numerical simulation of the modelled system.

The implementation in this notebook can be broken down into **six** main steps as follows:

1. **Colab Machine Setup.**
   We first starts by setting up the Colab machine environment by installing the needed tools and packages.
2. **Symbolic Model Creation.**
   Here we create the symbolic topology of the system as well as a symbolic configuration.
3. **Numerical Environment Generation.**
   We then pass our symbolic model to code-generators to generate the code files needed for numerical simulation.
4. **Numerical Simulation.**
   We then use these code files to create our simulation instances and run the numerical simulation.
5. **Data Post-Processing.**
   Now, we can use the raw results' data to evaluate the required characteristics and create plots.
6. **3D Visualization.**
   Finally, we use **uraeus.visenv.babylon** to visualize and animate our system in 3D.



[**Double Wishbone Direct Acting**](https://colab.research.google.com/github/khaledghobashy/uraeus_nmbd_cpp/blob/master/demos/double_wishbone_direct_acting/double_wishbone_direct_acting.ipynb#scrollTo=oNp9xjb0vO4V)
A kinematically driven system representing an independent suspension mechanism used for automotive.

[**Spatial Fourbar**]( https://colab.research.google.com/github/khaledghobashy/uraeus_nmbd_cpp/blob/master/demos/spatial_fourbar/spatial_fourbar.ipynb )
A dynamically driven system representing a closed-chain four-bar linkage driven by a torque at the crank.

[**Pendulum**]( https://colab.research.google.com/github/khaledghobashy/uraeus_nmbd_cpp/blob/master/demos/pendulum/pendulum.ipynb )
A dynamically driven system representing a simple pendulum subjected to the gravitational forces only .



## Roadmap

*To be discussed ...*

## Implementation Details

*The **Implementation Details** will be provided in a separate documentation and linked here*

## Support

As the tool is developed and maintained by one developer for now, if you have any inquiries, do not hesitate to contact me at [khaled.ghobashy@live.com](mailto:khaled.ghobashy@live.com) or [kh.ghobashy@gmail.com](mailto:kh.ghobashy@gmail.com)

## License

*ToDo*