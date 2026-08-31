:- module(visited, [updateVisited/3, enleverCase/4]).

:- use_module(library(clpfd)).

next_pos(c{x:X,y:Y}, north, c{x:X,y:Y1}) :- Y1 #= Y + 1.
next_pos(c{x:X,y:Y}, south, c{x:X,y:Y1}) :- Y1 #= Y - 1.
next_pos(c{x:X,y:Y}, east, c{x:X1,y:Y}) :- X1 #= X + 1.
next_pos(c{x:X,y:Y}, west, c{x:X1,y:Y}) :- X1 #= X - 1.

updateVisited(forward, Certain_Fluents, New_Certain_Fluents) :-
	Certain_Fluents.fat_hunter = fat{c:OldPos, h:hunter{id:hunter}},
	Certain_Fluents.dir = [dir{d:Dir, h:hunter{id:hunter}}],

	next_pos(OldPos, Dir, NewPos),

	New_Certain_Fluents = Certain_Fluents
                        .put(fat_hunter/c,NewPos)
                        .put(visited, [_{from:OldPos,to:NewPos}|Certain_Fluents.visited]).


updateVisited(left, Certain_Fluents, Certain_Fluents).
updateVisited(right, Certain_Fluents, Certain_Fluents).
updateVisited(grab, Certain_Fluents, Certain_Fluents).
updateVisited(climb, Certain_Fluents, Certain_Fluents).
updateVisited(shoot, Certain_Fluents, Certain_Fluents).


enleverPremier([_|Ls], Ls).
enleverCase(forward, Visited, Certain_Fluents, New_Certain_Fluents) :-
	enleverPremier(Visited, NewVisited),
	Certain_Fluents.fat_hunter = fat{c:OldPos, h:hunter{id:hunter}},
	Certain_Fluents.dir = [dir{d:Dir, h:hunter{id:hunter}}],

	next_pos(OldPos, Dir, NewPos),

	New_Certain_Fluents = Certain_Fluents
                        .put(fat_hunter/c,NewPos)
                        .put(visited, NewVisited).


enleverCase(right, _, C, C).
enleverCase(left, _, C, C).
enleverCase(shoot, _, C, C).
enleverCase(climb, _, C, C).
enleverCase(grab, _, C, C).
