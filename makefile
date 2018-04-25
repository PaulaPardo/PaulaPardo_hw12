all : correrc ejecutarc ejecutarpy

correrc	:
	g++ PaulaPardo_advection.cpp
ejecutarc :
	./a.out > advection.txt
ejecutarpy : advection.txt
	python PaulaPardo_graph.py
