# The Brass Ring

This repository is used to hold files based on the Dead Souls mudlib (http://dead-souls.net) used to develop The Brass Ring mud.


Setup - I currently use Linux Mint x64 as my operating system.

download the dead souls mud library from http://dead-souls.net

compile dead souls per instructions and start the mud

connect and login as an admin character

logout and kill the mud processes: "startmud" and "driver"

replace the files in the ds3.9/lib directories with the files in this 
repository. BACKUP THE ORIGINAL FILES FIRST

start the mud again - login as the admin character and issue the following 
commands:

mudconfig selectclass no
mudconfig selectskills yes
mudconfig xpadvancement no
mudconfig skilladvancement yes
warmboot

connect and create a test character - you should now be able to select primary,
   secondary and other skills for your test character 
