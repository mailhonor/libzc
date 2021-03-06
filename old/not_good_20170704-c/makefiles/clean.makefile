all: clean

clean:
	rm -f libzc.a
	rm -f tags gmon.out
	find -type f -name "*.o" -exec rm  {} \;
	find -type f -name "*.depend" -exec rm  {} \;
	find -type f -name "*~" -exec rm  {} \;
	find -type f -name "gmon.out" -exec rm  {} \;
	find -type f -name "*.c.orig" -exec rm  {} \;
	find -type f -name "*.h.orig" -exec rm  {} \;
	rm -rf OBJS_DEST/
