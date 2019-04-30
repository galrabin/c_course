ls -l $dir | grep -E '^d(r..){3}' | sed -r 's/(d.*([0-9]|:){4,5})//g'| tr '\n' ' '| sed -r 's/ .*$/&\n/' | sed -r 's/^ //'| tr -s ' '
