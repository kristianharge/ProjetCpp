#include <stdlib.h>
#include <iostream>
#include "rickmap.hh"

RickMap::RickMap(){
	int i;

	for (i = 0; i < taille[0]*taille[1]; i++){
    	*(matrix + i) = 0;

	}
}

RickMap::~RickMap(){}