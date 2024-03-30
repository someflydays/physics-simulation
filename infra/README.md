# Infrastructure as code configurations.

This directory contains configuration files and scripts for deployment and environment management of the physics simulation project.

## Directory Structure
```
infra/            // Infrastructure as code configurations.
├── nomad/        // Nomad job specifications for deployment.
├── puppet/       // Puppet manifests for infrastructure setup and configuration.
├── Dockerfile    // Docker container configurations.
└── Jenkinsfile   // Jenkins pipeline for continuous integration and continuous deployment (CI/CD).
```

## Docker Configuration

A specific version of the gcc image was chosen instead of 'FROM gcc:latest' to avoid potential inconsistencies due to the image being updated. I chose version 9.5 which is the most recent release as of March 2024. <br>
<br>
To prevent architecture mismatch issues and ensure compatibility, the application is compiled directly within the Docker container.