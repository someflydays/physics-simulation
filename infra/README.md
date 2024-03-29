# Infrastructure as code configurations.

### Directory Structure
```
infra/            // Infrastructure as code configurations.
├── nomad/        // Nomad job specifications for deployment.
├── puppet/       // Puppet manifests for infrastructure setup and configuration.
├── Dockerfile    // Docker container configurations.
└── Jenkinsfile   // Jenkins pipeline for CI/CD.
```

### Docker Configuration

A specific version of the gcc image was chosen instead of 'FROM gcc:latest' to avoid potential inconsistencies due to the image being updated. I chose version 9.5 which is the most recent release as of March 28, 2024 <br>
<br>
To avoid architecture mismatch issues, the application is directly compiled within the Docker container rather than copying a pre-compiled binary. This ensures that the binary is compatible with the container's architecture.