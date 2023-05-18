alias c='g++ -Wall -Wconversion -Wfatal-errors -g -std=gnu++20 \
	-fsanitize=undefined,address -static '
xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
