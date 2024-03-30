# Physics Simulation of Heavy Ion Collisions

This project aims to simulate the dynamics of heavy ion collisions, akin to those observed in experiments conducted by the ALICE Collaboration at CERN. The simulation will generate synthetic data sets that mirror the outcomes of Pb-Pb collisions. This data will then serve as input for a suite of analysis tools designed to visualize, analyze, and draw insights from the collision events. An exact replication of LHC collision complexities are out of scope for this personal project, so this simulation will simplify certain aspects with the goal of generating meaningful data.

Beyond the simulation itself, this project will be driven by a comprehensive CI/CD pipeline that incorporates various technologies including Puppet, Nomad, Jenkins, and GitHub Actions. This pipline will automate the building, testing, and deployment of the data analysis tools. Software integration engineering best practices are prioritized. For more project documentation, please view the `docs/` directory.

## Project Structure

```
physics-simulation/
├── docs/               // Additional project documentation, setup guides, and notes.
├── scripts/            // Scripts for setup, build automation, and utilities.
├── .vscode/            // Configuration files for VS Code, including debug and task definitions.
│   ├── launch.json     // Defines configurations for debugging.
│   └── tasks.json      // Includes instructions for compiling C++ code.
├── include/            // Header files for the project's C++ code.
│   ├── particle.h      // Declares the Particle class with properties and methods for particles in the simulation.
│   └── simulation.h    // Declares the Simulation class managing the simulation and particle interactions.
├── src/                // Source files (*.cxx); the main codebase for the physics simulation.
│   ├── particle.cxx    // Implements the Particle class, defining a particle's properties.
│   ├── simulation.cxx  // Implements the Simulation class, orchestrating the simulation process.
│   └── main.cxx        // Main entry point for the simulation application.
├── test/               // Test scripts and files, including unit and integration tests.
├── .github/            // GitHub-specific configurations, including GitHub Actions.
│   └── workflows/      // Defines GitHub Actions workflows for CI.
│       └── ci.yaml     // Automated build and test.
├── infra/              // Infrastructure as code configurations.
│   ├── nomad/          // Nomad job specifications for deployment.
│   ├── puppet/         // Puppet manifests for infrastructure setup and configuration.
│   ├── Dockerfile      // Docker container configurations.
│   └── Jenkinsfile     // continuous integration and continuous deployment (CI/CD).
├── CMakeLists.txt      // CMake project configuration file; outlines build instructions.
├── LICENSE             // MIT License.
└── .gitignore          // Intentionally untracked files to ignore.
```

## License

Distributed under the MIT License. See [LICENSE](LICENSE) for more information.

## Contact

Derek Martin - derekmartinnj@gmail.com<br>
LinkedIn - https://www.linkedin.com/in/derekmartin0000/<br>
Project Link - https://github.com/someflydays/physics-simulation

## Acknowledgments

Hank Childs, for being an excellent professor. Thank you for teaching me about scientific data visualization at the University of Oregon.
