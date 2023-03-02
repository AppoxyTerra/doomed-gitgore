# doomed-gitgore
A little program to run in the background to auto-commit-push-pull and force obliterate merge conflicts. That's radioactive stuff !  
It should be compatible with Windows, macOS and Linux, as long as `gitgore.py` is in the project's directory, and `git` commands are enabled in this directory.

### Use
- Copy `gitgore.py` in your project repo and create a `.gitgore` file.  
- Write in `.gitgore` the time in millis you want your repo to be synced.  
- Launch the Python3 script in the background.  
  It will output `Failed` if the sync fails.
