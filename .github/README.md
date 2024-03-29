# Initial CI tasks with GitHub Actions for syntax checking, light testing, and repo management

### Directory Structure
```
.github/            // GitHub-specific configurations, including GitHub Actions.
└── workflows/      // Defines GitHub Actions workflows for CI.
    └── ci.yaml	    // Automated build and test.
```

This GitHub Actions workflow will serve as an initial step in the continuous integration pipeline for quick feedback on commits. For instance, it will:

- Automatically check the syntax of the C++ code upon every push.
- Run a small subset of unit tests that don't require the full infrastructure.
- Automatically manage some GitHub repository tasks, like labeling merged pull requests or managing issues.

GitHub Actions will be used for quick, lightweight tasks. Jenkins will handle the heavy lifting of the CI/CD pipeline.