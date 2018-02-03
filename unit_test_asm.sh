#!/bin/bash

echo "Setup for test";

make -j asm;

find . -type f -name "*.cor" -exec rm -f {} \;

cp -R docs/ressources/champions our_ch;
cp -R docs/ressources/champions zaz_ch;

find our_ch -type f -name "*.s" -exec ./asm/asm {} \; > /dev/null 2> /dev/null
find zaz_ch -type f -name "*.s" -exec ./docs/ressources/asm {} \; > /dev/null 2> /dev/null

for i in $(ls our_ch/*.cor); do
	printf "%s:" "$(basename "$i")";
	hexdump "our_ch/$(basename $i)" > "our_ch/res";
	hexdump "zaz_ch/$(basename $i)" > "zaz_ch/res";
	if [ "" == "$(diff "our_ch/res" "zaz_ch/res")" ]; then
		printf "\033[32;1mgood\n\033[0m";
	else
		printf "\033[31;1mbad\n\033[0m";
	fi
done

rm -rf our_ch;
rm -rf zaz_ch;