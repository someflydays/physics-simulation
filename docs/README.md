# Additional project documentation, setup guides, and notes.

This documentation provides guidance on setting up and running the physics simulation project, both locally and within a Docker container. Follow the steps below to get started with the simulation.
<br>

**Table of Contents:**<br>
- [Running the Application Locally](#running-the-application-locally)
- [Running the Application in a Docker Container](#running-the-application-in-a-docker-container)

<br>

## Running the Application Locally

### 1. Generate the executable

To compile the simulation and generate the executable, navigate to the project's root directory (`physics-simulation`) and execute the following commands:
```bash
mkdir build && cd build
cmake ..
make
```
This will create an executable named app in the `physics-simulation/build/bin/` directory.

### 2. Run the executable

From the `physics-simulation/build/bin/` directory, run the simulation executable using the following command:
```bash
./app
```
You should see console output indicating the positions of several particles, verifying the simulation is running as expected.
<br>

## Running the Application in a Docker Container

### 1. Set up Docker
Ensure that Docker is installed on your machine. See Docker's official documentation for more details: [Getting Started with Docker Desktop](https://www.docker.com/blog/getting-started-with-docker-desktop/)

### 2. Build the Docker container
From the project's root directory (`physics-simulation`), build the Docker container using the following command:
```
docker build -t physics-simulation .
```

### 3. Run the Docker container
From the project's root directory (`physics-simulation`), run the simulation within the Docker container using the following command:
```
docker run --rm physics-simulation
```
The --rm flag automatically removes the container when it exits. Upon successful execution, you'll see console output indicating the positions of several particles, verifying the simulation is running as expected.
<br>