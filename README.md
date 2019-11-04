# Fillit

### Project description :  
Fillit is a project that let you discover and/or familiarize yourself with a recurring
problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing.  
In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square.  
  
A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to
the popular game Tetris.  
  
Fillit is not about recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter, which contains a list of Tetriminos (between 1 and 26 pieces), and arrange them
in order to create the smallest square possible.  
  
### Usage
```make``` then ```./fillit file```  
  
Here is an example of a valid file  
```
$> cat valid_sample.fillit
...#
...#
...#
...#

....
....
....
####

.###
...#
....
....

....
..##
.##.
....
$>
```
  
Obtained mark for this project : 100/100
