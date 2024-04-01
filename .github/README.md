# Initial CI tasks with GitHub Actions

## Directory Structure
```
.github/            // GitHub-specific configurations, including GitHub Actions.
└── workflows/      // Defines GitHub Actions workflows for CI.
    └── ci.yaml	    // Automated build and test.
```

This GitHub Actions workflow serves as an initial step in the continuous integration (CI) pipeline for quick feedback on commits. Upon every push, it:

- Automatically checks the syntax of the C++ code.
- Runs a small subset of unit-tests with GoogleTest.

I am using GitHub Actions for quick, lightweight CI tasks.