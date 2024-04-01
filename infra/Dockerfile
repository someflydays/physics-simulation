# Use an official C++ base image from Docker Hub.
FROM gcc:9.5

# Set the working directory in the container.
WORKDIR /usr/src/app

# Install cmake and other required dependencies.
RUN apt-get update && \
    apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

# Copy source code, header files, test files, and CMakeLists.txt into the Docker image.
COPY ./src /usr/src/app/src
COPY ./include /usr/src/app/include
COPY ./test /usr/src/app/test
COPY CMakeLists.txt /usr/src/app/

# Create a build directory, run cmake and make from within that directory.
RUN mkdir build && cd build && cmake .. && make

# Set the working directory to the build directory.
WORKDIR /usr/src/app/build

# Specify the commands to run on container start.
CMD ["./bin/app"]