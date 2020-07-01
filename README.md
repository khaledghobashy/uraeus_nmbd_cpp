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

- [Git](https://git-scm.com/downloads), for cloning the project repository.
- [CMake](https://cmake.org/download/), for build-systems generation. The project requires cmake 3.10 or higher.
- A modern C++ compiler supporting C++17 standards. 
  The project is tested with the [GNU](https://gcc.gnu.org/) gcc compiler on a Linux machine and the Microsoft C++ build tools [MSVC](https://visualstudio.microsoft.com/visual-cpp-build-tools/) on a Windows-10 machine.



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



## Usage Examples & Tutorials

*ToDo*

### Detailed Example - Spatial Fourbar Mechanism

*ToDo*

## Roadmap

*To be discussed ...*

## Implementation Details

*The **Implementation Details** will be provided in a separate documentation and linked here*

## Support

As the tool is developed and maintained by one developer for now, if you have any inquiries, do not hesitate to contact me at [khaled.ghobashy@live.com](mailto:khaled.ghobashy@live.com) or [kh.ghobashy@gmail.com](mailto:kh.ghobashy@gmail.com)

## License

*ToDo*