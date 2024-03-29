# Additional project documentation, setup guides, and notes.
<br>

**Table of Contents:**<br>
- Setup Guide

<br>

# Setup Guide

To run the test application, please follow the guide below!
<br>
<br>

## Option 1: Running the application locally

### Generate the executable

From the project's root directory (`physics-simulation`), run the following commands:
```
mkdir build && cd build
cmake ..
make
```

### Run the executable

From the `physics-simulation/build/bin/` directory, run the following command:
```
./app
```
You should see a friendly message in the console: "Hello, World!"<br>
<br>
<br>

## Option 2: Running the application in a Docker container

### Set up Docker
Ensure that Docker Desktop is installed. See Docker's official documentation for more details: https://www.docker.com/blog/getting-started-with-docker-desktop/

### Build the Docker container
From the project's root directory (`physics-simulation`), run the following command:
```
docker build -t physics-simulation .
```

### Run the Docker container
From the project's root directory (`physics-simulation`), run the following command:
```
docker run --rm physics-simulation
```
You should see a friendly message in the console: "Hello, World!"