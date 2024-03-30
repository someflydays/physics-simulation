# Use an official C++ base image from Docker Hub.
FROM gcc:9.5

# Set the working directory in the container.
WORKDIR /usr/src/app

# Install cmake and other required dependencies.
RUN apt-get update && \
    apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

# Copy source code, header files, and CMakeLists.txt into the Docker image.
COPY ./src /usr/src/app/src
COPY ./include /usr/src/app/include
COPY CMakeLists.txt /usr/src/app/

# Compile the application from the root directory (physics-simulation/) where CMakeLists.txt is located.
RUN cmake . && make

# Ensure the path matches the location and name of the generated executable.
RUN chmod +x /usr/src/app/bin/app

# Specify the command to run on container start.
CMD ["./bin/app"]