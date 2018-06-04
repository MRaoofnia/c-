start=$(date +%s)
xterm -T title -e /usr/bin/cb_console_runner LD_LIBRARY_PATH=$LD_LIBRARY_PATH ./test
end=$(date +%s)
diff=$(expr $end - $start )
echo it took $diff seconds to run 
