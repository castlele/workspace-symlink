# Workspace symlink creator tool

This tool will produce an alias in yout _.zshrc_ file for fast chackout transitions to your common workspace directories.

## Usage

```bash
symwork name_of_the_link
```

This will write `alias name_of_the_link="path/to/dir/where/command/was/used` to _.zshrc_ file.

## Installation

```bash
git clone git@github.com:castlele/workspace-symlink.git \
&& cd workspace-symlink \
&& sudo ./setup.sh
```
