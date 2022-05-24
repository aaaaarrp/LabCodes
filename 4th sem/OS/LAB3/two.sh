#Write a Shell script that accepts an alphabet from the user and displays all filenames starting with that alphabet in the current working directory.

#!/bin/bash
read -p 'Enter alphabet to check: ' alp
ls | grep "^$alp"