# Additional Project Documentation, Setup Guides, and Notes.

This documentation provides guidance on setting up and running the physics simulation project, both locally and within a Docker container. Follow the steps below to get started with the simulation.
<br>

**Table of Contents:**<br>
- [Running the Application Locally](#running-the-application-locally)
- [Running the Application in a Docker Container](#running-the-application-in-a-docker-container)

<br>

## Running the Application Locally

### 1. Generate the application's executable

To compile the simulation and generate the application's executable, navigate to the project's root directory (`physics-simulation/`) and execute the following commands:
```bash
mkdir build
cd build
cmake ..
make
```
This will create an executable named `app` in the `physics-simulation/build/bin/` directory. It will also create a unit-testing executable named `unit` in the `physics-simulation/build/` directory.

### 2. OPTIONAL: Run unit-tests with GoogleTest

After building the project in Step 1, navigate to the `physics-simulation/build/bin/` directory and execute the following command:
```
./unit
```
You should see console output indicating that all tests have passed. You should also see a list of the specific tests that have been run. If you would like to view the unit-tests, they are visible in the `physics-simulation/test/` directory.

### 3. Run the simulation

From the `physics-simulation/build/bin/` directory, run the simulation executable using the following command:
```bash
./app
```
You should see console output indicating properties of several particles, verifying the simulation is running as expected.

<br>

## Running the Application in a Docker Container

### 1. Set up Docker
Ensure that Docker is installed on your machine. See Docker's official documentation for more details: [Getting Started with Docker Desktop](https://www.docker.com/blog/getting-started-with-docker-desktop/)

### 2. Build the Docker container
From the project's root directory (`physics-simulation/`), build the Docker container using the following command:
```
docker build -t physics-simulation -f infra/Dockerfile .
```

### 3. OPTIONAL: Run unit-tests with GoogleTest
After building the container in Step 1, execute the following command:
```
docker run --rm physics-simulation /usr/src/app/build/unit
```
You should see console output indicating that all tests have passed. You should also see a list of the specific tests that have passed. If you would like to view the unit-tests, they are visible in the `usr/src/app/test/` directory.
<br>

If you would like to run an interactive container based on the Docker image and manually navigate through the filesystem, you can run the following command:
```
docker run -it --rm physics-simulation /bin/bash
```
Once you're in the `build/bin` directory within the container, you can run the unit-tests with the following command:
```
./unit
```
You should see console output indicating that all tests have been run. You should also see a list of the specific tests that have passed. If you would like to view the unit-tests, they are visible in the `usr/src/app/test/` directory.
<br>

To exit the interactive container, just run the `exit` command.

### 4. Run the simulation
If you are not inside the interactive container based on the Docker image, you can run the simulation from the project's root directory (`physics-simulation/`) using the following command:
```
docker run --rm physics-simulation
```
The --rm flag automatically removes the container when it exits. Upon successful execution, you'll see console output indicating properties of several particles, verifying the simulation is running as expected.
<br>

If you are inside the interactive container based on the Docker image, you can run the simulation by navigating to the  `build/bin` and using the following command:
```
./app
```
You should see console output indicating properties of several particles, verifying the simulation is running as expected.
<br>

To exit the interactive container, just run the `exit` command.