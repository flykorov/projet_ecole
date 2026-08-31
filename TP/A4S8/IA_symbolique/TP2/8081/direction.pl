:- module(direction, [updateDir/3]).

turn_left(north, west).
turn_left(west, south).
turn_left(south, east).
turn_left(east, north).

turn_right(north, east).
turn_right(east, south).
turn_right(south, west).
turn_right(west, north).

updateDir(left, Certain_Fluents, New_Certain_Fluents) :-
	Certain_Fluents.dir = [dir{d:Dir, h:hunter{id:hunter}}],
	turn_left(Dir, NewDir),
	New_Certain_Fluents = Certain_Fluents.put(dir, [dir{d:NewDir, h:hunter{id:hunter}}]).


updateDir(right, Certain_Fluents, New_Certain_Fluents) :-
	Certain_Fluents.dir = [_{d:Dir, h:_{id:hunter}}],
	turn_right(Dir, NewDir),
	New_Certain_Fluents = Certain_Fluents.put(dir, [dir{d:NewDir, h:hunter{id:hunter}}]).

updateDir(shoot, Certain_Fluents, Certain_Fluents).
updateDir(climb, Certain_Fluents, Certain_Fluents).
updateDir(grab, Certain_Fluents, Certain_Fluents).
updateDir(forward, Certain_Fluents, Certain_Fluents).

