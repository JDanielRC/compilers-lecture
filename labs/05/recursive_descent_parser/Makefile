all:
	lex recursiveDown.l
	yacc -d recursiveDown.y
	cc lex.yy.c y.tab.c