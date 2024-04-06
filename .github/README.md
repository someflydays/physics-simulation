# Initial CI tasks with GitHub Actions

## Directory Structure
```
.github/            // GitHub-specific configurations, including GitHub Actions.
└── workflows/      // Defines GitHub Actions workflows for CI.
    └── ci.yaml	    // Automated build and test.
```

This GitHub Actions workflow serves as an initial step in the continuous integration (CI) pipeline for quick feedback on commits. This workflow:

- Automatically checks the syntax of the C++ code.
- Runs unit-tests with GoogleTest.

I am using GitHub Actions for quick, lightweight CI tasks. This pipeline is executed upon every push to the main branch, and upon pull requests targeting main, to catch issues early in the development cycle. 
<br>

In the settings for the project's repository, I have configured a Branch Protection Rule (for the main branch) that ensures pushes and pull requests only proceed if the unit-tests pass.
