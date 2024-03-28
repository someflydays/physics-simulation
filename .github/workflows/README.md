# Initial CI tasks with GitHub Actions for syntax checking, light testing, and repo management

### Directory Structure
```
.github.workflows // Defines GitHub Actions workflows for CI.
└── ci.yaml		  // Automated build and test.
```

This GitHub Actions workflow serves as an initial step in the continuous integration pipeline for quick feedback on commits. For instance, it:

- Automatically checks the syntax of the C++ code upon every push.
- Runs a small subset of unit tests that don't require the full infrastructure.
- Automatically manages some GitHub repository tasks, like labeling merged pull requests or managing issues.

GitHub Actions are used for quick, lightweight tasks. Jenkins handles the heavy lifting of the CI/CD pipeline.