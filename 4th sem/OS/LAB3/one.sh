#Write a Shell script to read a user name and to find whether the user is currently logged or not.

#!/bin/bash

read -p 'Enter username to check: ' user
if who -u | grep -q "^$user "; then
    echo "User $user is logged in"
else
    echo "User $user is not logged in"
fi
