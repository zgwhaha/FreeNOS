/*
 * Copyright (C) 2009 Coen Bijlsma
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <String.h>
#include <string.h>
#include <URI.h>
#include <FileURL.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void usage(char*);

int main(int argc, char **argv)
{

    if( argc == 1 )
    {
        usage(argv[0]);
    }
    
    String u1(argv[1]);
    
    FileURL* url = new FileURL(*u1);
    printf("%s\n", url->getRawURI() );
    
    Vector<String>* splits = url->split();
    
    for(Size size = 0; size < splits->count(); size++)
    {
        String* s = splits->get(size);
        char* split = s->operator*();
        
        if( split )
        {
            printf("part: '%s'\n", split);
        } else {
            printf("part is NULL\n");
        }
    }
    
    delete url;
    return EXIT_SUCCESS;
}

void usage(char* prog)
{
    printf("usage: %s [--uri <uri> | <value>]\n", prog);
    exit(0);
}