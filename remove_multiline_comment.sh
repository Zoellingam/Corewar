
remove_ansi_comment()
{
	eval file="\$$#"
	head -n12 "$file"
	sed 's/a/aA/g;s/__/aB/g;s/#/aC/g' "$file" |
       	gcc -P -E $arg - |
        sed 's/aC/#/g;s/aB/__/g;s/aA/a/g' |
        sed '/^$/N;/^\n$/D'
}

for i in $(find . -type f -name "*.[ch]"); do
	remove_ansi_comment $i;
done

