cp /share/ex_data/ex3/story.txt /share/ex_data/ex3/birthdays.txt .
grep -E '^[[:alpha:]]{1,4}:' birthdays.txt > names1-4.txt
grep '19[4-5][0-9]' birthdays.txt | sort -k1,1 | cut -d':' -f1 > years40-59.txt
egrep ': July ' birthdays.txt | sed 's/:/ was born on/' | sort -k 6n | sed 's/July//' | sed 's/  / /' | sed 's/, /\/7\//' | sed 's/19//' | sed 's/20//' > birthdays-july.txt
echo story.txt has `cat story.txt | tr '[:punct:][:space:]' '\n'| egrep ^[1-9]| egrep [[:digit:]]$ | sort -n | wc -l` numbers
cat story.txt | tr [[:punct:][:space:]] '\n' | tr [:upper:] [:lower:] | sort | uniq -c | tr -s [:space:] | egrep '^ [1-9][0-9]+' | tail -n1 | sed -E 's/([[:digit:]]+) ([[:alpha:]]+)/Word \"\2\" appears \1 times in story.txt/' | sed 's/ W/W/'

