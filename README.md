# Physics Simulation

### Project Structure

```
physics-simulation/
├── docs/             // Additional project documentation, setup guides, and notes.
├── scripts/          // Scripts for setup, build automation, and utilities.
├── .vscode/          // Configuration files for VS Code, including debug and task definitions.
│   ├── launch.json   // Defines configurations for debugging.
│   └── tasks.json    // Includes instructions for compiling C++ code.
├── bin/              // Compiled binary executables; generated after build.
├── build/            // Temporary build files; used during compilation.
├── include/          // Header files for the project's C++ code.
├── src/              // Source files (*.cxx); the main codebase for the physics simulation.
├── test/             // Test scripts and files, including unit and integration tests.
├── .github/workflows // Defines GitHub Actions workflows for CI.
│   └── ci.yaml       // Automated build and test.
├── infra/            // Infrastructure as code configurations.
│   ├── nomad/        // Nomad job specifications for deployment.
│   ├── puppet/       // Puppet manifests for infrastructure setup and configuration.
│   ├── Dockerfile    // Docker container configurations.
│   └── Jenkinsfile   // Jenkins pipeline for CI/CD.
├── CMakeLists.txt    // CMake project configuration file; outlines build instructions.
├── LICENSE           // MIT License.
└── .gitignore        // Intentionally untracked files to ignore.
```
### License

Distributed under the MIT License. See [LICENSE](LICENSE) for more information.

### Contact

Derek Martin - derekmartinnj@gmail.com
LinkedIn - https://www.linkedin.com/in/derekmartin0000/
Project Link - https://github.com/someflydays/physics-simulation

### Acknowledgments

Hank Childs, for being an excellent professor and teaching me about scientific data visualization at the University of Oregon.